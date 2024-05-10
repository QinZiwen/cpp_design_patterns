#include <string>
#include <iostream>
#include <vector>

/**
* @brief 简单概述
* @brief 访问者
*/
class Visitor
{
public:
	Visitor(std::string s) { m_sName = s; std::cout << "crete visitor: " << s << std::endl; }
	std::string GetName() { return m_sName; }

private:
	std::string m_sName;
};

/**
* @brief 简单概述
* @brief 接收者基类
*/
class Receiver
{
public:
	Receiver() {}
	virtual bool Accept(Visitor*) = 0;
	std::string GetName() { return name; }

protected:
	bool m_bFree;
	std::string name;
};

/**
* @brief 简单概述
* @brief 男性接收者
*/
class ReceiverMan :public Receiver
{
public:
	ReceiverMan(std::string s)
	{
		m_bFree = false;
		name = s;
	}
	bool Accept(Visitor* v)
	{
		if (!m_bFree)
		{
			std::cout << "ReceiverMan, Visitor name:" << v->GetName() << std::endl;
			m_bFree = true;
			return true;
		}
		return false;
	}
};

/**
* @brief 简单概述
* @brief 女性接收者
*/
class ReceiverWoman :public Receiver
{
public:
	ReceiverWoman(std::string s)
	{
		m_bFree = false;
		name = s;
	}
	bool Accept(Visitor* v)
	{
		if (!m_bFree)
		{
			std::cout << "ReceiverWoman, Visitor name:" << v->GetName() << std::endl;
			m_bFree = true;
			return true;
		}
		return false;
	}
};

/**
* @brief 简单概述
* @brief 接收者管理类
*/
class ReceiverMgr
{
public:
	ReceiverMgr() {}
	bool Accept(Visitor* v)
	{
		for (const auto& var : vec_recv)
		{
			if (var->Accept(v))
			{
				return true;
			}
		}
		std::cout << "Visit fail! visitor name:" << v->GetName() << std::endl;
		return false;
	}
	void AddReceiver(Receiver* rv)
	{
		vec_recv.push_back(rv);
	}

private:
	std::vector<Receiver*> vec_recv;
};

int main(int argc, char* argv[])
{
	Visitor vr_Lee("Lee");
	Visitor vr_John("John");
	Visitor vr_Tom("Tom");

	ReceiverMan		rv_man("man");
	ReceiverWoman	rv_woman("woman");
	ReceiverMgr		rv_mgr;
	rv_mgr.AddReceiver(&rv_man);
	rv_mgr.AddReceiver(&rv_woman);

	rv_mgr.Accept(&vr_Lee);
	rv_mgr.Accept(&vr_John);
	rv_mgr.Accept(&vr_Tom);

	getchar();
	return 0;
}