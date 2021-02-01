#include <iostream>

using namespace std;

__interface IException
{
public:
	virtual void ShowException();
};

class NoPersonException : public IException
{
public:
	NoPersonException(int person = 0) { m_nPerson = person; }
	void ShowException() override
	{
		//typeid: 다형성관계에서 할당된 객체의 이름을 확인할수있다.
		cout << typeid(*this).name() << ":" << m_nPerson << endl;
	};
private:
	int m_nPerson;
};

class NoPizzaSlicesException : public IException
{
public:
	NoPizzaSlicesException(int pizza = 0) {m_nPizzaSlices = pizza; }
	void ShowException() override
	{
		cout << typeid(*this).name() << ":" << m_nPizzaSlices << endl;
	};
private:
	int m_nPizzaSlices;
};

void main()
{
	int nPizzaSlices = 0;
	int nPersons = -1;
	int nSlicesPerPersons;

	try
	{
		cout << "PizzaSlices:";
		cin >> nPizzaSlices;
		cout << "Persons?:";
		cin >> nPersons;

		//if (nPersons <= 0) throw nPersons;
		//if (nPizzaSlices <= 0) throw nPizzaSlices;
		//if (nPersons <= 0) throw "Persons is Err";
		//if (nPizzaSlices <= 0) throw "nPizzaSlices is Err";
		if (nPersons <= 0) throw new NoPersonException(nPersons);
		if (nPizzaSlices <= 0) throw new NoPizzaSlicesException(nPizzaSlices);
	}
	//던진값에 따라 걸림.
	catch (int e)
	{
		cout << "Persons/PizzaSlice:" << e << endl;
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	//catch (IException& e) //try문에서 객체가 소멸되었으므로 참조할수없어 컴파일오류
	catch(IException* e)
	{
		e->ShowException();
		delete e;
	}
	nSlicesPerPersons = nPizzaSlices / nPersons;
	cout << "SlicePerPesons:"<< nSlicesPerPersons << endl;
}
