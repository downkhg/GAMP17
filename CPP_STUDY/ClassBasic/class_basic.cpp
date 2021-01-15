#include <iostream>
#include <string>

using namespace std;

//�ڵ���
//�Ӽ�(����ɼ� �ִ� ��): �ӵ�, ���
//����: ����(����), ����(�극��ũ)
class CCar
{
//private: //Ŭ�������ο��� ���� ������.
	//�ֽ������Ϸ������� ������.
	string m_strColor;
	int m_nSpeed = 0;
	int m_nGear= 0;
public: //Ŭ������/���� ��� ���ٰ�����.
	enum E_GEAR_STATE { P, R, N ,D, ONE, TWO};
	//Ŭ���������� �⺻���� �����Ҷ� ���.
	//������: Ŭ������ �����ɶ� �ڵ����� ȣ��Ǵ� �Լ�.
	//�̸��� Ŭ������ ����. ���ϰ��� ����. �����ε����� �ϴ�. ����Ʈ�Ű����� ��밡��.
	//����Ʈ������: �ƹ��� �Ű����������� ������.
	//CCar()
	//{
	//	m_nGear = 0;
	//	m_nSpeed = 0;
	//}
	CCar(string color = "gray", int gear = 0, int speed = 0)
	{
		cout << "Car("<<color<<","<<gear<<","<< speed<<"):"<< this << endl;
		m_strColor = color;
		m_nGear = gear;
		m_nSpeed = speed;
	}
	//��ü(�ν��Ͻ�): Ŭ������ �̿��Ͽ� �Ҵ�� �޸�(�ѹ� ���ǰ� �Ҹ�Ǵ� ��)
	//�Ҹ���: ��ü�� �Ҹ�ɶ�
	~CCar()
	{
		cout << "~Car("<<m_strColor<<"):"<< this << endl;
	}

	void SetGear(int gear)
	{
		m_nGear = gear;
	}
	void Accelerator()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void Display()
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
};

void main()
{
	
	CCar cCar("red");
	CCar* pCar = new CCar("blue");
	CCar arrCar[3] = { CCar("green"),CCar("yellow"), CCar("white")};
	static CCar static_cCar("pink"); //�������������� ���� �������� �Ҹ��.
	static CCar static_cCarA("deeppink"); //�������������� ���� �������� �Ҹ��.
	static CCar static_cCarB("lowpink"); //�������������� ���� �������� �Ҹ��.

	//cCar.m_nSpeed = 0; //����
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR_STATE::D);
	cCar.Accelerator();
	cCar.Display();
	cCar.Break();
	cCar.SetGear(CCar::E_GEAR_STATE::P);
	cCar.Display();

	pCar->Display();
	pCar->SetGear(CCar::E_GEAR_STATE::D);
	pCar->Display();
	pCar->Accelerator();
	pCar->Break();
	pCar->SetGear(CCar::E_GEAR_STATE::P);
	pCar->Display();

	delete pCar;
}