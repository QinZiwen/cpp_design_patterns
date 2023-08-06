#include "common/common.h"

class ProductA {
public:
    virtual void use() = 0;
};

class ChinaConcreteProductA1 : public ProductA {
public:
    virtual void use() override {
        std::cout << "Using ChinaConcreteProductA1" << std::endl;
    }
};

class USAConcreteProductA2 : public ProductA {
public:
    virtual void use() override {
        std::cout << "Using USAConcreteProductA2" << std::endl;
    }
};

class ProductB {
public:
    virtual void use() = 0;
};

class ChinaConcreteProductB1 : public ProductB {
public:
    virtual void use() override {
        std::cout << "Using ChinaConcreteProductB1" << std::endl;
    }
};

class USAConcreteProductB2 : public ProductB {
public:
    virtual void use() override {
        std::cout << "Using ConcreteProductB2" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class ChinaConcreteFactory1 : public AbstractFactory {
public:
    virtual ProductA* createProductA() override {
        return new ChinaConcreteProductA1();
    }
    virtual ProductB* createProductB() override {
        return new ChinaConcreteProductB1();
    }
};

class USAConcreteFactory2 : public AbstractFactory {
public:
    virtual ProductA* createProductA() override {
        return new USAConcreteProductA2();
    }
    virtual ProductB* createProductB() override {
        return new USAConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ChinaConcreteFactory1();
    ProductA* productA1 = factory1->createProductA();
    ProductB* productB1 = factory1->createProductB();

    productA1->use();
    productB1->use();

    delete productA1;
    delete productB1;
    delete factory1;

    AbstractFactory* factory2 = new USAConcreteFactory2();
    ProductA* productA2 = factory2->createProductA();
    ProductB* productB2 = factory2->createProductB();

    productA2->use();
    productB2->use();

    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}