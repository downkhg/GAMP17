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
	friend CVector operator*(float dist, CVector v)//��Į���(��ȯ��Ģ)
	{
		return CVector(v.x * dist, v.y * dist);
	}
	float operator[](int idx)
	{
		if (idx == 0) return x;
		else return y;
	}
	float operator[](char c)
	{
		if (c == 'x') return x;
		else if(c == 'y') return y;
		return 0;
	}
	float Magnitude()
	{
		return sqrt(x*x + y * y);
	}
	CVector Normarlize()
	{
		float fDist = Magnitude();
		return CVector(x / fDist, y / fDist);
	}
	void Print(const char* msg)
	{
		cout << msg << "(" << x << ","<< y << ")" << endl;
	}
};

void VectorMain()
{
	CVector vPA(0,0);
	CVector vA(10,1);
	vPA.Print("PA");
	vA.Print("A");
	//���ϱ�
	CVector vPB = vPA + vA;
	vPB.Print("PB");
	//����
	vA = vPB - vPA;
	vA.Print("A");
	vA = vPA - vPB;
	vA.Print("A");
	CVector vDir = vA.Normarlize();
	float fDist = vA.Magnitude();
	vDir.Print("Dir");
	cout << "Dist:" << fDist << endl;
	//���ϱ�
	vA.Print("A");
	vA = fDist * vDir;
	vA.Print("A");
}

void main()
{
	VectorMain();
}