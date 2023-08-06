#include "common/common.h"

class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
        step3();
    }

    virtual void step1() = 0;
    virtual void step2() = 0;

    virtual void step3() {
        std::cout << "AbstractClass: step3" << std::endl;
    }
};

class ConcreteClassA : public AbstractClass {
public:
    virtual void step1() override {
        std::cout << "ConcreteClassA: step1" << std::endl;
    }

    virtual void step2() override {
        std::cout << "ConcreteClassA: step2" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass {
public:
    virtual void step1() override {
        std::cout << "ConcreteClassB: step1" << std::endl;
    }

    virtual void step2() override {
        std::cout << "ConcreteClassB: step2" << std::endl;
    }

    virtual void step3() override {
        std::cout << "ConcreteClassB: step3" << std::endl;
    }
};

int main() {
    AbstractClass* obj1 = new ConcreteClassA();
    obj1->templateMethod();

    AbstractClass* obj2 = new ConcreteClassB();
    obj2->templateMethod();

    delete obj1;
    delete obj2;

    return 0;
}