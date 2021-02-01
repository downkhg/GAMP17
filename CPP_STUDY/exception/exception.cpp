#include <iostream>
#include "Excption.h"

using namespace std;

void TryCatchMain()
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
	catch (IException* e)
	{
		e->ShowException();
		delete e;
	}
	nSlicesPerPersons = nPizzaSlices / nPersons;
	cout << "SlicePerPesons:" << nSlicesPerPersons << endl;
}
//정적할당된 변수만 캐스팅함. 외에 컴파일오류
void StaticCastMain()
{
	int nData = 9;
	double fData = 3.14f;
	int* pInt = &nData;
	double* pDouble = &fData;

	nData = static_cast<int>(fData);
	//pInt = static_cast<int*>(pDouble); //컴파일오류
}

class CParent{};
class CChildA:public CParent {};

void DynamicCastMain()
{
	CChildA* pChildA = new CChildA();
	CParent* pParentA = dynamic_cast<CParent*>(pChildA);

	//downcasting은 불가능하다.
	CParent* pParentB = new CParent();
	//pChildA = dynamic_cast<CChildA*>(pParentB); //컴파일오류

	//할당된객체가 자식인 부모포인터라도 캐스팅불가
	CParent* pParentC = new CChildA();
	//pChildA = dynamic_cast<CChildA*>(pParentC);//컴파일오류

	//다형성관계에서는 캐스팅이 가능하다.
	IException* pException = new NoPersonException();
	NoPersonException* pNoPerson = dynamic_cast<NoPersonException*>(pException);

	if (pNoPerson) pNoPerson->ShowException();
	else cout << "pNoPerson: null" << endl;

	//다형성관계에서 캐스팅에 실패하면 null을 리턴한다.
	NoPizzaSlicesException* pNoPizza = new NoPizzaSlicesException();
	pNoPerson = dynamic_cast<NoPersonException*>(pNoPizza);

	if (pNoPerson) pNoPerson->ShowException();
	else cout << "pNoPerson: null" << endl;

	pException = pNoPizza;
	pNoPerson = dynamic_cast<NoPersonException*>(pException);

	if (pNoPerson) pNoPerson->ShowException();
	else cout << "pNoPerson: null" << endl;
}

void main()
{
	//TryCatchMain();
	DynamicCastMain();
}
