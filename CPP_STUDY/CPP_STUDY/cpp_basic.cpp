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
	//�����Ϸ��� � �Լ��� ȣ���ؾ����� �˼�����.
	//g_nData = 99;
	//PrintData(); 
}
//�Լ��� �����ε��� ��Ȯ�����ʾ� ������ �߻��ϴ� ��쵵 �ִ�.
int Sum3(int a, int b, int c) { return a + b + c; };
int Sum2(int a, int b) { return a + b; };
int Sum1(int a) { return a; };
//�Լ��� �����ε�: �Լ��� �̸��� �����̸����� �Ű������� ������ Ÿ���� �ٸ� �Լ��� �����ϴ°�.
//1. �Ű������� Ÿ�԰� ������ �������
//2. ���ϰ��� �ٸ����
//int Sum(int a, int b, int c) { return a + b + c; };
//int Sum(int a, int b) { return a + b; };
//int Sum(int a) { return a; };
//����Ʈ�Ű�����: �Ű������� ���� �Ҵ����������� �⺻���� ���� ��. ����ڿ��� ���� ���� �����ؾ���.
//1. Ư�� �Ű������� ����Ʈ�Ű������� ��������
inline int Sum(int a = 0, int b = 0, int c = 0) { return a + b + c; };
//�ζ����Լ�: �Լ�ȣ���� ���� ������ �ִ´�.(inline�� ���δٰ� �ٵǴ°��� �ƴ�)

//���޵� ������ ������ �Ѱܼ�, ������ ������ �� �ִ�.
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
//������: ������ ������ �����Ҽ��ְ� �����ִ� ��. null�� ��������ʰ�, �������� ������ �Ұ����ϴ�.
//�����ڴ� �ַ� �Ű������� ���� ���� ���������δ� �ܵ������� ����ϴ� ���� ��ġ�ʴ�.
//�����Ϳ� ������: null�ȵ�, ������ �ݵ�� �����ؾ� �ʱ�ȭ ����. ������ ���� ����� ������ �Ұ����ϴ�.
void RefenceTestMain()
{
	int nDataA = 10;
	int nDataB = 20;
	cout << "DataA:" << nDataA << endl; //10
	cout << "DataB:" << nDataB << endl; //20
	int& refData = nDataA; //�����ڴ� null�� �����������. �ݵ�� �ʱ�ȭ�Ǿ���.
	nDataA = 100;
	cout << "refData <- DataA:" << refData << endl; //100
	refData = 1000;
	//�����ڴ� �߰��� ������ �Ұ����ϴ�.
	refData = nDataB;//�����ϴ� A�� ���� B�� ������ ����
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
//������: Q -> ���ڿ�,A -> ����, ���� -> ���ڿ�
//�˰���: A�� �Է��� ���� Q�� �ִٸ� �ش� ���� �Էµȴ�.
//1.A�� �Է� //2.A�� ���信 �ִ��� Ȯ���Ѵ�. //3.�ִٸ�, Q�� �ִ´�. //4.����� Q�� �����ʴٸ� 1��
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