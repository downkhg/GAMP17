#pragma once
#include <iostream>
using namespace std;

int Add(int a, int b) { return  a + b; }
int Sub(int a, int b) { return  a - b; }
int Muttiply(int a, int b) { return  a * b; }
int Divide(int a, int b) { return  a / b; }

void FunctionTestMain()
{
	//함수포인터: 리턴값,타입과 매개변수의 수가 같은 함수의 주소값을 저장함.
	int(*pFunc)(int,int);

	pFunc = Add;
	cout << "Add:"<< pFunc(10, 20) << endl;
	pFunc = Sub;
	cout << "Sub:" << pFunc(10, 20) << endl;
	pFunc = Muttiply;
	cout << "Muttiply:" << pFunc(10, 20) << endl;
	pFunc = Divide;
	cout << "Divide:" << pFunc(10, 20) << endl;
}