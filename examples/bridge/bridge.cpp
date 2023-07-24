#include "common/common.h"

// ʵ�ֽӿ�
class Implementor {
public:
    virtual void operationImpl() = 0;
};

// ����ʵ����A
class ConcreteImplementorA : public Implementor {
public:
    virtual void operationImpl() override {
        std::cout << "Concrete Implementor A" << std::endl;
    }
};

// ����ʵ����B
class ConcreteImplementorB : public Implementor {
public:
    virtual void operationImpl() override {
        std::cout << "Concrete Implementor B" << std::endl;
    }
};

// ������
class Abstraction {
public:
    explicit Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void operation() = 0;

protected:
    Implementor* implementor;
};

// ���������A
class ConcreteAbstractionA : public Abstraction {
public:
    ConcreteAbstractionA(Implementor* impl) : Abstraction(impl) {}

    virtual void operation() override {
        std::cout << "Concrete Abstraction A: ";
        implementor->operationImpl();
    }
};

// ���������B
class ConcreteAbstractionB : public Abstraction {
public:
    ConcreteAbstractionB(Implementor* impl) : Abstraction(impl) {}

    virtual void operation() override {
        std::cout << "Concrete Abstraction B: ";
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Abstraction* absA = new ConcreteAbstractionA(implA);
    absA->operation();

    Implementor* implB = new ConcreteImplementorB();
    Abstraction* absB = new ConcreteAbstractionB(implB);
    absB->operation();

    delete implA;
    delete absA;
    delete implB;
    delete absB;

    return 0;
}