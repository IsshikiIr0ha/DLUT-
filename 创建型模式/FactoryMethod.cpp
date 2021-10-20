#include <iostream>
using namespace std;
/**
 * 工厂方法与简单工厂相比，最大的特点就是多了抽象工厂。因为简单工厂是不符合开闭原则的(增加方法需要修改工厂的源代码)
 * 但类的个数会增加许多，不好维护
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

class AbstractFactory{
    public:
        virtual Operation *ConcreteOperation() = 0;
};

class AddFactory:public AbstractFactory{
    public:
        Operation *ConcreteOperation(){
            return new Add;
        }
};

class MinusFactory:public AbstractFactory{
    public:
        Operation *ConcreteOperation(){
            return new Minus;
        }
};

class MultiplyFactory:public AbstractFactory{
    public:
        Operation *ConcreteOperation(){
            return new Multiply;
        }
};

class DevisionFactory:public AbstractFactory{
    public:
        Operation *ConcreteOperation(){
            return new Devision;
        }
};

int main(){
    AbstractFactory* Factory = nullptr;
    Operation *Op = nullptr;
    Factory = new AddFactory;
    Op = Factory->ConcreteOperation();
    Op->setA(5);
    Op->setB(10);
    cout << Op->getResult() << endl;
}
