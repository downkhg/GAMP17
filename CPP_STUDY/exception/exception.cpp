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
	//�������� ���� �ɸ�.
	catch (int e)
	{
		cout << "Persons/PizzaSlice:" << e << endl;
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	//catch (IException& e) //try������ ��ü�� �Ҹ�Ǿ����Ƿ� �����Ҽ����� �����Ͽ���
	catch (IException* e)
	{
		e->ShowException();
		delete e;
	}
	nSlicesPerPersons = nPizzaSlices / nPersons;
	cout << "SlicePerPesons:" << nSlicesPerPersons << endl;
}
//�����Ҵ�� ������ ĳ������. �ܿ� �����Ͽ���
void StaticCastMain()
{
	int nData = 9;
	double fData = 3.14f;
	int* pInt = &nData;
	double* pDouble = &fData;

	nData = static_cast<int>(fData);
	//pInt = static_cast<int*>(pDouble); //�����Ͽ���
}

class CParent{};
class CChildA:public CParent {};

void DynamicCastMain()
{
	CChildA* pChildA = new CChildA();
	CParent* pParentA = dynamic_cast<CParent*>(pChildA);

	//downcasting�� �Ұ����ϴ�.
	CParent* pParentB = new CParent();
	//pChildA = dynamic_cast<CChildA*>(pParentB); //�����Ͽ���

	//�Ҵ�Ȱ�ü�� �ڽ��� �θ������Ͷ� ĳ���úҰ�
	CParent* pParentC = new CChildA();
	//pChildA = dynamic_cast<CChildA*>(pParentC);//�����Ͽ���

	//���������迡���� ĳ������ �����ϴ�.
	IException* pException = new NoPersonException();
	NoPersonException* pNoPerson = dynamic_cast<NoPersonException*>(pException);

	if (pNoPerson) pNoPerson->ShowException();
	else cout << "pNoPerson: null" << endl;

	//���������迡�� ĳ���ÿ� �����ϸ� null�� �����Ѵ�.
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
