#include <iostream>
#include <string>
using namespace std;
//템플릿: 함수나 객체내부에 들어갈 타입을 변경가능하도록 만드는것.
template <typename Type>
void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = a;
}
template <typename Type>
class Box
{
	Type data;
public:
	void SetData(Type data)
	{
		this->data = data;
	}
	Type GetData()
	{
		return data;
	}
};
template <typename TypeA, typename TypeB>
class Pear
{
	TypeA key;
	TypeB data;
public:
	Pear(TypeA  key, TypeB data)
	{
		this->key = key;
		this->data = data;
	}
	TypeB  operator[](TypeA key)
	{
		return data;
	}
};
void TemplateMain()
{
	Box<int> nBox;
	nBox.SetData(10);
	cout << nBox.GetData() << endl;
	Box<int> nBox2;
	nBox2.SetData(20);
	cout << nBox2.GetData() << endl;

	Swap(nBox, nBox2);
	cout << nBox.GetData() << endl;
	cout << nBox2.GetData() << endl;

	Pear<string, float> cPear("PI", 3.14f);
	cout << cPear["PI"] << endl;
}


void main()
{
	TemplateMain();
}