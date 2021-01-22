#include <iostream>

using namespace std;
//����
//�Ӽ�: x,y
//����:
//�̵�_+: ����
//���̰Ÿ�_-: ����
//��Į���: ���⺤�Ϳ� �̵����� ���� �̵��� �Ÿ��� ����. ����*float
//����� �̵���_����ȭ:����, ��Į��:�̵���
class CVector
{
public:
	float x;
	float y;
	CVector(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	CVector operator+(CVector v)
	{
		CVector temp(this->x + v.x, this->y + v.y);
		return temp;
	}
	CVector operator-(CVector v)
	{
		CVector temp(this->x - v.x, this->y - v.y);
		return temp;
	}
	CVector operator*(float dist)//��Į���
	{
		CVector temp(this->x * dist, this->y * dist);
		return temp;
	}
	void Print(const char* msg)
	{
		cout << msg << "(" << x << ","<< y << ")" << endl;
	}
};

void VectorMain()
{
	CVector vA(0,0);
	CVector vB(1,1);
	//���ϱ�,����,���ϱ�
}

void main()
{

}