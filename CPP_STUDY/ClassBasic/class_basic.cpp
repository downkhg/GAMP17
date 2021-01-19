#include <iostream>
#include <string>

using namespace std;

//�ڵ��� �߻�ȭ�ϱ�
//�Ӽ�(����ɼ� �ִ� ��): �ӵ�, ���
//����: ����(����), ����(�극��ũ), ����(setter)
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
	//�ڵ����� �ֹ��Ҷ�, �� �ӵ��� ���Ѵ�.
	//CCar(string color = "gray", int gear = 0, int speed = 0)
	CCar(string color = "gray")
	{
		//cout << "Car("<<color<<","<<gear<<","<< speed<<"):"<< this << endl;
		//m_nGear = gear;
		//m_nSpeed = speed;
		cout << "Car(" << color<<"):" << this << endl;
		m_strColor = color;	
	}
	//��ü(�ν��Ͻ�): Ŭ������ �̿��Ͽ� �Ҵ�� �޸�(�ѹ� ���ǰ� �Ҹ�Ǵ� ��)
	//�Ҹ���: ��ü�� �Ҹ�ɶ�
	~CCar()
	{
		cout << "~Car("<<m_strColor<<"):"<< this << endl;
	}
	//setter/getter: private����� �����ϰų� �����ϴµ� ����.
	//�ӵ��� �ڵ����� ���¿� ���� �����Ǵ°� �̹Ƿ� getter�� setter�� �־�� �ȵȴ�.
	void SetColor(string color)
	{
		m_strColor = color;
	}
	string GetColor()
	{
		return m_strColor;
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

void CarMain()
{
	CCar cCar("red");
	CCar* pCar = new CCar("blue");
	CCar arrCar[3] = { CCar("green"),CCar("yellow"), CCar("white") };
	//�������������� ���� �������� �Ҹ��. 
	//�������������� �������϶��� ���������� ���������� ���� �Ҹ��.
	static CCar static_cCar("pink");
	static CCar static_cCarA("deeppink");
	static CCar static_cCarB("lowpink");
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
//���� �ó������� �°� �ڵ��� Ŭ������ �����غ���
//1. ������ �����Ѵ�.
//2. �ڵ����� �����Ѵ�.
//3. �ڵ����� ����Ѵ�.
void CarOrderMain()
{
	////���� �ó������� ���� ������ ���ϰ� ���߿� �����ϴ°�.
	////�Ϲ����� ������� �̷��Ա��� ��������.
	//CCar cCar;
	//string strColor;
	//cCar.SetColor(strColor);
	string strColor;
	cout << "InputColor:";
	cin >> strColor;
	CCar cCar(strColor);
	//�� �����ϰ� �����Ѵ�.
	//������ �ӵ������������ʵ��� �����ϰ� �ӵ��� Ȯ���Ѵ�.
	cCar.SetGear(CCar::E_GEAR_STATE::D);
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Display();
	//��ȣ�� �ɷȴ�. �ڵ����� ���⶧���� �ӵ��� Ȯ���ϸ� �극��ũ�� ��´�.
	cCar.Break();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	cCar.SetGear(CCar::E_GEAR_STATE::N);
}
//TVŬ������ �ۼ��ϰ� TV�� �����ϵ� Ŭ������ Ȱ���ϱ� - ���������ϱ�
//https://classroom.google.com/c/MTU0MTc2ODE4MjY1/a/MjU1MTI1Mzc3NzA3/details

void main()
{
	CarMain();
	//CarOrderMain();
}