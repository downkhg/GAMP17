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

//�̱���: ��ü�� 1���̻� ������ �ʵ��� �����ϴ� ��.
void SingleTonMain()
{
	//SingleObject cObject;//������ ����.
	//SingleObject cObjects[100];//������ ����.
	//SingleObject* pObject = NULL;
	SingleObject* pObject = SingleObject::GetInstance();
	//��ü�� ���Ϲ����� ��������� �ȴ�. �׷��Ƿ�, ��������ڸ� private�ϸ� ������ �߻������ʵ��� ���������.
	//SingleObject cObject = pObject->GetInstance(); 
	//cout << "CSingleObject:" << &cObject << endl;
	//pObject->ShowMessage();//��������� ������ ��������� ��� null������ �߻��Ѵ�.
	pObject = pObject->GetInstance(); //C++�������� �޸𸮰� ����ϸ� ������ �߻���������.
	pObject = SingleObject::GetInstance(); //Java/C#�� �ش繮���ۿ� ����Ҽ�����.
	pObject->ShowMessage(); //��ü�� �����Ǿ����Ƿ� ��������� ������ ����������.
	//delete pObject;//��ü�� ���ο��� �����Ǿ��µ� �ܺο��� �����ÿ� ������ �߻��Ҽ�����.
	pObject->Release();//?
	SingleObject::Release(); //��ü ���������� ��ü�� �Ҵ�ɼ������Ƿ�, static�� ���̴� ���� ����.
}