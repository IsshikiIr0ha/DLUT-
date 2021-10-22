#include <iostream>
using namespace std;
/**
 * 抽象工厂模式
 * 产品族：一个工厂里生产的一组产品，一种具体工厂只能生产一个产品族的产品
 * 产品等级结构：不同工厂里生成的相同产品
 * 抽象工厂模式增加具体工厂和产品族很方便(直接继承对应的工厂抽象类和产品抽象类)
 * 增加产品对象比较麻烦，需要修改所有工厂中的接口
 * 
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
//A在前B在后的计算器
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

//B在前A在后的计算器
class ReverseAdd:public Operation{
    double getResult(){
        return this->getB() + this->getA();
    }
};

class ReverseMinus:public Operation{
    double getResult(){
        return this->getB() - this->getA();
    }
};

class ReverseMultiply:public Operation{
    double getResult(){
        return this->getB() * this->getA();
    }
};

class ReverseDevision:public Operation{
    double getResult(){
        if(this->getA()){
            return this->getB() / this->getA();
        }
        cout << "A can't be 0" << endl;
        return 0;
    }
};

class Calculator{
    public:
        virtual Operation *AddOperator() = 0;
        virtual Operation *MinusOperator() = 0;
        virtual Operation *MultiplyOperator() = 0;
        virtual Operation *DevisionOperator() = 0;
};

class NormalCalculator:public Calculator{
    public:
        Operation *AddOperator(){
            return new Add;
        }
        Operation *MinusOperator(){
            return new Minus;
        }
        Operation *MultiplyOperator(){
            return new Multiply;
        } 
        Operation *DevisionOperator(){
            return new Devision;
        }
};

class ReverseCalculator:public Calculator{
    public:
        Operation *AddOperator(){
            return new ReverseAdd;
        }
        Operation *MinusOperator(){
            return new ReverseMinus;
        }
        Operation *MultiplyOperator(){
            return new ReverseMultiply;
        } 
        Operation *DevisionOperator(){
            return new ReverseDevision;
        }
};

int main(){
    Calculator *Factory1 = new NormalCalculator;
    Operation *Op = Factory1->DevisionOperator();
    Op->setA(3);
    Op->setB(5);
    cout << "Normal Result is "<< Op->getResult() << endl;
    Calculator *Factory2 = new ReverseCalculator;
    Operation *ReverseOp = Factory2->DevisionOperator();
    ReverseOp->setA(3);
    ReverseOp->setB(5);
    cout << "Reverse Result is " << ReverseOp->getResult() << endl;
    return 0;
}
