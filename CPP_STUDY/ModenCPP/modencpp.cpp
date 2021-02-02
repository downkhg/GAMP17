#include <iostream>
#include <memory>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
#include "WeakPtrEx.h"

using namespace std;

//1.unique: ����X
//1.1. ���� -> �ٸ������� �ּҰ����� X.
//2.shared: ����O
//1.1. ���� -> �ٸ������� �ּҰ����� O.
//3.weak: ����ī��Ʈ�� �ø����ʰ� �����͸� ������. lock�̿��Ͽ� ������ ������ ȹ��(?)
void SmartPointerTestMain()
{
	unique_ptr<int> uniquePtr = make_unique<int>();
	shared_ptr<int> sharedPtr = make_shared<int>();
	cout << "uniquePt:" << &(*uniquePtr) << endl;
	cout << "sharedPtr:" << &(*sharedPtr) << endl;
	//int* pInt = new int();
	//unique_ptr<int>  pUniqueCopy = uniquePtr;
	cout << "SharedPtrCount:" << sharedPtr.use_count() << endl;
	shared_ptr<int> pShareCopy = sharedPtr;
	cout << "pShareCopy:" << &(*pShareCopy) << endl;
	cout << "SharedPtrCount:" << sharedPtr.use_count() << endl;
	//��Ƽ�������Ȳ�� �׽�Ʈ�� �ʿ���.
	weak_ptr<int> weakPtr = sharedPtr;
	cout << "weakPtr:" << &weakPtr << endl;
	weak_ptr<int> pWeakCopy = weakPtr.lock(); //�����ͺ���
	cout << "pWeakCopy:" << &pWeakCopy << endl;
	cout << "SharedPtrCount:" << sharedPtr.use_count() << endl;
}

void FunctorTestMain()
{

}

void RamdaTestMain()
{

}

void main()
{
	//_CrtSetBreakAlloc(156); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 
	SmartPointerTestMain();
	//WeakPtrRunTest();//weak_ptr:������������ ī��Ʈ�� ������Ű���ʰ�, ������ �ϴµ� ���ȴ�.
}