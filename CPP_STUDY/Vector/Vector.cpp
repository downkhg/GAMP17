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
	//���ʹ� ����� 1���� �����ϴ� ���� �����Ƿ� �������̽��� ������ ���� �����ؾ�
	//����� float���� ��� x���� ���� ������ �������ִ�.
	CVector() { x = 0; y = 0; }
	CVector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	//�����ڿ����ε�: �����ڸ� �������ϴ� ��.
	//������: ���ϰ�
	//������: operator��ȣ
	//�������ǿ�����: �Ű�����
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
	//�ǿ����ڰ� 2���̻��϶��� ��������ڸ� �̿��ؾ���.
	friend CVector operator*(float dist, CVector v)//��Į���(��ȯ��Ģ)
	{
		return CVector(v.x * dist, v.y * dist);
	}
	//�񱳿����ڸ����
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
	cout << "Dist:"<< fDist << endl;
	//���ϱ�
	vA.Print("A");
	vA = fDist * vDir;
	vA.Print("A");
	//������ ���� ��밡���ϳ� ���ܰ� �߻��Ҽ������Ƿ� ��������.
	cout << "A[0,1](" << vA[0] << ","<< vA[1] << ")" << endl;
	cout << "A['x','y'](" << vA['x'] << "," << vA['y'] << ")" << endl;
}

void main()
{
	VectorMain();
}