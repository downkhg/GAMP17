#pragma once
#include <iostream>
using namespace std;

int Add(int a, int b) { return  a + b; }
int Sub(int a, int b) { return  a - b; }
int Muttiply(int a, int b) { return  a * b; }
int Divide(int a, int b) { return  a / b; }

void FunctionTestMain()
{
	//�Լ�������: ���ϰ�,Ÿ�԰� �Ű������� ���� ���� �Լ��� �ּҰ��� ������.
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