#pragma once
#include <iostream>
using namespace std;

__interface IException
{
public:
	virtual void ShowException()
	{
		//typeid: ���������迡�� �Ҵ�� ��ü�� �̸��� Ȯ���Ҽ��ִ�.
		cout << typeid(*this).name() << ":" ;
	};
};

class NoPersonException : public IException
{
public:
	NoPersonException(int person = 0) { m_nPerson = person; }
	void ShowException() override
	{
		IException::ShowException();
		cout << m_nPerson << endl;
	};
private:
	int m_nPerson;
};

class NoPizzaSlicesException : public IException
{
public:
	NoPizzaSlicesException(int pizza = 0) { m_nPizzaSlices = pizza; }
	void ShowException() override
	{
		IException::ShowException();
		cout << m_nPizzaSlices << endl;
	};
private:
	int m_nPizzaSlices;
};
