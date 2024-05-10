#include <iostream>
#include <list>
using namespace std;

// Receiver类，知道如何实施与执行一个与请求相关的操作：
class Receiver {
public:
	virtual ~Receiver() {}
    virtual void Action() {
        cout << "Receiver" << endl;
    }
};

class ReceiverB : public Receiver {
public:
	virtual void Action() override {
		cout << "ReceiverB" << endl;
	}
};

// Command类，用来声明执行操作的接口
class Command {
public:
    virtual void Excute() = 0;
    virtual void setReceiver(Receiver* r) = 0;
    virtual ~Command(){};
};

// ConcreteCommand类，绑定一个Receiver，调用其相应操作以实现Excute：
class ConcreteCommand : public Command {
private:
    Receiver* receiver;
public:
    void setReceiver(Receiver* r) {
        receiver = r;
    }
    void Excute() {
        //cout << "ConcreteCommand" << endl;
        receiver->Action();
    }
};

// 要求该命令执行这个请求：
class Invoker {
private:
    list<Command* > commands;
public:
    void setCommand(Command* c) {
        commands.push_back(c);
    }
    void Notify() {
        for (auto c = commands.begin(); c != commands.end(); c++) {
            (*c)->Excute();
        }
    }
};

// 客户端实现代码：
int main() {
    Command* c = new ConcreteCommand();
    Receiver* r = new Receiver();
	ReceiverB* rb = new ReceiverB();
    c->setReceiver(r);

    Invoker I;
	I.setCommand(c);
	I.Notify();   // Receiver

	c->setReceiver(rb);
	I.Notify();

    delete r;
	delete rb;
    delete c;

	std::getchar();
    return 0;
}