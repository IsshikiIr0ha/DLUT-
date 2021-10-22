#include <iostream>
using namespace std;
/**
 * 建造者模式(Builder Pattern)
 * 建造者可以屏蔽产品复杂的建造过程，适用于构造函数复杂,或对构造顺序有要求的类。
 * 例如肯德基套餐，不同套餐的食品种类不同，如果重载构造函数，会很复杂
 * 弊病是如果产品内部复杂，可能需要很多建造者来实现，例如肯德基有100种套餐。
 */
class Combo{
    private:
        string Hamburger;//必点
        string Drink;//必点
        string Chinken;
        string Chip;
    public:
        Combo(string Hamburger,string Drink){
            this->Hamburger = Hamburger;
            this->Drink = Drink;
        }
        void setChinken(string Chinken){
            this->Chinken = Chinken;
        }
        void setChip(string Chip){
            this->Chip = Chip;
        }
        friend ostream& operator<<(ostream & out,const Combo& C){
            out << "Your Combo has " << C.Hamburger << " " << C.Drink << " " << C.Chinken << " " << C.Chip << endl;
            return out;
        }
};

class ComboBuilder{
    public:
        Combo* Meal;
        virtual void setCombo(string Hamburger,string Drink) = 0;
};

class BasicCombo:public ComboBuilder{//只有汉堡和饮料
    public:
        void setCombo(string Hamburger,string Drink){
            this->Meal = new Combo(Hamburger, Drink);
        }
};

class NormalCombo:public ComboBuilder{//有薯条
    public:
        void setCombo(string Hamburger,string Drink){
            this->Meal = new Combo(Hamburger, Drink);
        }
        void setChip(string Chip){
            this->Meal->setChip(Chip);
        }
};

class LuxuryCombo:public ComboBuilder{//豪华套餐
    public:
        void setCombo(string Hamburger,string Drink){
            this->Meal = new Combo(Hamburger, Drink);
        }
        void setChip(string Chip){
            this->Meal->setChip(Chip);
        }
        void setChinken(string Chinken){
            this->Meal->setChinken(Chinken);
        }
};

class Custmoer{
    private:
        ComboBuilder *Builder;
    public:
        void setBuilder(ComboBuilder* Builder){
            this->Builder = Builder;
        }
        Combo* getCombo(){
            return this->Builder->Meal;
        }
};

int main(){
    BasicCombo *MealB = new BasicCombo;
    MealB->setCombo("King Burger", "Cola");
    Custmoer* C = new Custmoer;
    C->setBuilder(MealB);
    Combo* KFC = C->getCombo();
    cout << *KFC;
}

