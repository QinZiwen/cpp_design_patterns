#include "common/common.h"

class Observer {
public:
    virtual void update(int data) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify(int data) {
        std::cout << "Subject is notifying observers with data: " << data << std::endl;
        for (auto observer : observers) {
            observer->update(data);
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update(int data) override {
        std::cout << "ConcreteObserver is notified with data: " << data << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    int data = 42;
    std::cout << "Notifying observers..." << std::endl;
    subject.notify(data);

    subject.detach(&observer2);

    data = 99;
    std::cout << "Notifying observers again..." << std::endl;
    subject.notify(data);

    return 0;
}
