#include <iostream>
#include <string>

using namespace std;

namespace A
{
	int g_nData;

	void PrintData()
	{
		cout << g_nData << endl;
	}
}

namespace B
{
	int g_nData;

	void PrintData()
	{
		cout << g_nData << endl;
	}
}

using namespace A;
using namespace B;

void NamespaceTestMain()
{
	A::g_nData = 10;
	A::PrintData();
	B::g_nData = 100;
	B::PrintData();
	//컴파일러가 어떤 함수를 호출해야할지 알수없음.
	//g_nData = 99;
	//PrintData(); 
}
//함수의 오버로딩은 명확하지않아 문제가 발생하는 경우도 있다.
int Sum3(int a, int b, int c) { return a + b + c; };
int Sum2(int a, int b) { return a + b; };
int Sum1(int a) { return a; };
//함수의 오버로딩: 함수의 이름을 같은이름으로 매개변수의 갯수나 타입이 다른 함수를 정의하는것.
//1. 매개변수의 타입과 갯수가 같은경우
//2. 리턴값이 다른경우
//int Sum(int a, int b, int c) { return a + b + c; };
//int Sum(int a, int b) { return a + b; };
//int Sum(int a) { return a; };
//디폴트매개변수: 매개변수에 값을 할당하지않으면 기본으로 들어가는 값. 가장뒤에서 부터 값을 지정해야함.
//1. 특정 매개변수의 디폴트매개변수를 지워보기
inline int Sum(int a = 0, int b = 0, int c = 0) { return a + b + c; };
//인라인함수: 함수호출대신 값의 계산식을 넣는다.(inline을 붙인다고 다되는것은 아님)

//전달된 변수의 참조를 넘겨서, 원본을 수정할 수 있다.
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void FunctionTestMain()
{
	cout << Sum(10, 20, 30) << endl;
	cout << Sum(10, 20) << endl;
	cout << Sum(10) << endl;
}
//참조자: 변수의 원본에 접근할수있게 도와주는 것. null을 허용하지않고, 참조값을 변경이 불가능하다.
//참조자는 주로 매개변수로 많이 쓰고 실질적으로는 단독변수로 사용하는 일이 흔치않다.
//포인터와 차이점: null안됨, 원본이 반드시 존재해야 초기화 가능. 원본이 없는 대상은 참조가 불가능하다.
void RefenceTestMain()
{
	int nDataA = 10;
	int nDataB = 20;
	cout << "DataA:" << nDataA << endl; //10
	cout << "DataB:" << nDataB << endl; //20
	int& refData = nDataA; //참조자는 null을 허용하지않음. 반드시 초기화되야함.
	nDataA = 100;
	cout << "refData <- DataA:" << refData << endl; //100
	refData = 1000;
	//참조자는 중간에 변경이 불가능하다.
	refData = nDataB;//참조하는 A의 값을 B의 값으로 변경
	cout << "refData:" << refData << endl;
	cout << "DataA:" << nDataA << endl;
	cout << "DataB:" << nDataB << endl;
	nDataB = 200;
	cout << "refData <- DataB:" << refData << endl; //200
	refData = 2000;
	cout << "DataA:" << nDataA << endl; //1000
	cout << "DataB:" << nDataB << endl; //2000 X //200 O
}

void StringTestMain()
{

}
//GAME
//Q:_ _ _ _
//A:A
//Q:_ A _ _
//A...
//Q:G A M E
//데이터: Q -> 문자열,A -> 문자, 정답 -> 문자열
//알고리즘: A에 입력한 값이 Q에 있다면 해당 값이 입력된다.
//1.A를 입력 //2.A가 정답에 있는지 확인한다. //3.있다면, Q에 넣는다. //4.정답과 Q가 같지않다면 1번
void HangManMain()
{
	string strR = "GAME";
	string strQ = "____";
	char cInput;

	cout << "A:";
	cin >> cInput;

	int idx = strQ.find(cInput, 0);
	if (idx != -1)
		strQ[idx] = cInput;

	if (strQ == strR) return;
	cout << "Q:" << strQ << endl;
}

void main()
{
	//NamespaceTestMain();
	//FunctionTestMain();
	//RefenceTestMain();
	HangManMain();
}