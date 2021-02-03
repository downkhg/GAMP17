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
	//SingleObject cObject;//������ ����.
	//SingleObject cObjects[100];//������ ����.
	SingleObject* pObject = NULL;
	//��ü�� ���Ϲ����� ��������� �ȴ�. �׷��Ƿ�, ��������ڸ� private�ϸ� ������ �߻������ʵ��� ���������.
	//SingleObject cObject = pObject->GetInstance(); 
	//cout << "CSingleObject:" << &cObject << endl;
	//pObject->ShowMessage();//��������� ������ ��������� ��� null������ �߻��Ѵ�.
	pObject = pObject->GetInstance(); //C++�������� �޸𸮰� ����ϸ� ������ �߻���������.
	pObject = SingleObject::GetInstance(); //Java/C#�� �ش繮���ۿ� ����Ҽ�����.
	pObject->ShowMessage(); //��ü�� �����Ǿ����Ƿ� ��������� ������ ����������.
}