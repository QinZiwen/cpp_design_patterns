#include "common/common.h"

// 抽象享元类
class Flyweight {
public:
    virtual ~Flyweight() = default;
    virtual void operation(int pos) = 0;
};

// 具体享元类
class ConcreteFlyweightOne : public Flyweight {
public:
    ~ConcreteFlyweightOne() { std::cout << "destroy ConcreteFlyweightOne" << std::endl; }

    virtual void operation(int pos) override {
        std::cout << "ConcreteFlyweightOne operation: pos: " << pos << std::endl;
    }
};

class ConcreteFlyweightTwo : public Flyweight {
public:
    ~ConcreteFlyweightTwo() { std::cout << "destroy ConcreteFlyweightTwo" << std::endl; }

    virtual void operation(int pos) override {
        std::cout << "ConcreteFlyweightTwo operation: pos: " << pos << std::endl;
    }
};

// 享元工厂类
class FlyWeightFactory {
public:
    ~FlyWeightFactory() {
        for (auto& it : m_flyweights) {
            delete it.second;
        }
        m_flyweights.clear();
    }

    Flyweight* getFlyweight(int key) {
        if (m_flyweights.find(key) != m_flyweights.end()) {
            return m_flyweights[key];
        } else {
            Flyweight* flyweight = nullptr;

            switch (key) {
            case 1:
                flyweight = new ConcreteFlyweightOne();
                break;
            case 2:
                flyweight = new ConcreteFlyweightTwo();
                break;
            default:
                std::cerr << "key err: " << key << std::endl;
                return nullptr;
            }

            m_flyweights[key] = flyweight;
            return flyweight;
        }
    }

private:
    std::map<int, Flyweight*> m_flyweights; // 享元对象的缓存池
};

int main() {
    FlyWeightFactory factory;
    Flyweight* flyweight1 = factory.getFlyweight(1);
    Flyweight* flyweight2 = factory.getFlyweight(2);
    flyweight1->operation(1);
    flyweight2->operation(2);
    return 0;
}
