#include <iostream>
#include <memory>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더
#include "WeakPtrEx.h"

using namespace std;

//1.unique: 공유X
//1.1. 공유 -> 다른포인터 주소값복사 X.
//2.shared: 공유O
//1.1. 공유 -> 다른포인터 주소값복사 O.
//3.weak: 공유카운트를 늘리지않고 포인터를 참조함. lock이용하여 포인터 사용권한 획득(?)
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
	//멀티쓰레드상황에 테스트가 필요함.
	weak_ptr<int> weakPtr = sharedPtr;
	cout << "weakPtr:" << &weakPtr << endl;
	weak_ptr<int> pWeakCopy = weakPtr.lock(); //포인터복사
	cout << "pWeakCopy:" << &pWeakCopy << endl;
	cout << "SharedPtrCount:" << sharedPtr.use_count() << endl;
}

void DisplayInt(int data)
{
	cout << "FuncPtr:"<<data << endl;
}

class DisplayIntFunc
{
public:
	void operator()(int data)
	{
		cout << "FuncObject:"<< data << endl;
	}
};

void FunctorLambdaTestMain()
{
	int nSize = 10;
	vector<int> vecDatas(nSize);
	for (int i = 0; i < nSize; i++)
		vecDatas[i] = i * 10;

	for_each(vecDatas.begin(), vecDatas.end(), DisplayInt);//함수포인터: 
	for_each(vecDatas.begin(), vecDatas.end(), [](int data) { cout << "Lamda:"<< data << endl; });//람다식: 무명함수. 이름이 없는 함수를 바로 정의해서 사용함.
	DisplayIntFunc cFunc;
	for_each(vecDatas.begin(), vecDatas.end(), cFunc); //함수객체:컴파일러가 인라인으로 처리한다고함.
}


void main()
{
	//_CrtSetBreakAlloc(156); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 
	//SmartPointerTestMain();
	//WeakPtrRunTest();//weak_ptr:공유포인터의 카운트를 증가시키지않고, 참조를 하는데 사용된다.
	FunctorLambdaTestMain();
}