#include <iostream>
#include <list>
using namespace std;

// Receiver�֪࣬�����ʵʩ��ִ��һ����������صĲ�����
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

// Command�࣬��������ִ�в����Ľӿ�
class Command {
public:
    virtual void Excute() = 0;
    virtual void setReceiver(Receiver* r) = 0;
    virtual ~Command(){};
};

// ConcreteCommand�࣬��һ��Receiver����������Ӧ������ʵ��Excute��
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

// Ҫ�������ִ���������
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

// �ͻ���ʵ�ִ��룺
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