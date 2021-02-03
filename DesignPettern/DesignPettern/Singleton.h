#pragma once

#include <iostream>
#include <string>

using namespace std;

class SingleObject
{
	static SingleObject* m_pInstance;
	SingleObject() { cout << "SingleObject:" << this << endl; };
	SingleObject(SingleObject& obj) { cout << "SingleObject Copy:" << this << endl; };

	int m_nData = 0;
public:
	static SingleObject* GetInstance()
	{
		if (m_pInstance == NULL) m_pInstance = new SingleObject();
		return m_pInstance;
	}
	void ShowMessage()
	{
		cout << "SingleObject!:" << m_nData << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};

SingleObject* SingleObject::m_pInstance = NULL;

void SingleTonMain()
{
	//SingleObject cObject;//컴파일 오류.
	//SingleObject cObjects[100];//컴파일 오류.
	SingleObject* pObject = NULL;
	//객체가 리턴받으며 복사생성이 된다. 그러므로, 복사생성자를 private하면 문제가 발생하지않도록 만듦수있음.
	//SingleObject cObject = pObject->GetInstance(); 
	//cout << "CSingleObject:" << &cObject << endl;
	//pObject->ShowMessage();//멤버변수가 있으면 멤버변수가 없어서 null참조가 발생한다.
	pObject = pObject->GetInstance(); //C++에서서는 메모리가 허용하면 문제가 발생하지않음.
	pObject = SingleObject::GetInstance(); //Java/C#은 해당문법밖에 사용할수없다.
	pObject->ShowMessage(); //객체가 생성되었으므로 멤버변수에 접근이 가능해진다.
}