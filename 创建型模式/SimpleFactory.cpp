#include <iostream>
#include <cstdio>
using namespace std;
/**
 * 简单工厂模式，只需要某种类的一个参数，就能返回一个相应的类指针。
 * 将产品抽象，由具体子类实现
 */
class Operation{
    private:
        double a = 3, b = 3;
    public:
        virtual double getResult() = 0;
        double getA() { return a; }
        double getB() { return b; }
        void setA(double a) { 
            this->a = a; 
        }
        void setB(double b) { 
            this->b = b; 
        }
};

class Add:public Operation{
    double getResult(){
        return this->getA() + this->getB();
    }
};

class Minus:public Operation{
    double getResult(){
        return this->getA() - this->getB();
    }
};

class Multiply:public Operation{
    double getResult(){
        return this->getA() * this->getB();
    }
};

class Devision:public Operation{
    double getResult(){
        if(this->getB())
            return this->getA() / this->getB();
        cout << "B can't be 0" << endl;
        return 0;
    }
};

class Factory{
    public:
    static Operation* getOperation(char c){
        switch (c)
            {
            case '+':
                return new Add;
                break;
            case '-':
                return new Minus;
                break;
            case '*':
                return new Multiply;
                break;
            case '/':
                return new Devision;
                break;
            default:
                return nullptr;
            }
    }
};

int main(){
    Operation *op = Factory::getOperation('/');
    printf("%f", op->getResult());
}
