#pragma once

#include <iostream>
#include <string>

using namespace std;

class SingleObject
{
	static SingleObject* m_pInstance;
	SingleObject() { cout << "SingleObject:" << this << endl; };
	~SingleObject() { cout << "~SingleObject:" << this << endl; }
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
	static void Release()
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
};
//심화문제: 
//1.참조자와 정적지역변수를 이용하면 동적할당 관리를 안해도되는 싱글톤이 가능할까?
//2.스마트포인터를 활용하여 메모리 누수 실수를 없도록 만들어보기
SingleObject* SingleObject::m_pInstance = NULL;

//싱글톤: 객체가 1개이상 만들지 않도록 강제하는 것.
void SingleTonMain()
{
	//SingleObject cObject;//컴파일 오류.
	//SingleObject cObjects[100];//컴파일 오류.
	//SingleObject* pObject = NULL;
	SingleObject* pObject = SingleObject::GetInstance();
	//객체가 리턴받으며 복사생성이 된다. 그러므로, 복사생성자를 private하면 문제가 발생하지않도록 만듦수있음.
	//SingleObject cObject = pObject->GetInstance(); 
	//cout << "CSingleObject:" << &cObject << endl;
	//pObject->ShowMessage();//멤버변수가 있으면 멤버변수가 없어서 null참조가 발생한다.
	pObject = pObject->GetInstance(); //C++에서서는 메모리가 허용하면 문제가 발생하지않음.
	pObject = SingleObject::GetInstance(); //Java/C#은 해당문법밖에 사용할수없다.
	pObject->ShowMessage(); //객체가 생성되었으므로 멤버변수에 접근이 가능해진다.
	//delete pObject;//객체는 내부에서 생성되었는데 외부에서 삭제시에 문제가 발생할수있음.
	pObject->Release();//?
	SingleObject::Release(); //객체 생성전에도 객체가 할당될수있으므로, static을 붙이는 것이 좋다.
}