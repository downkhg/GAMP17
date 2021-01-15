#include <iostream>
#include <string>

using namespace std;

//자동차
//속성(변경될수 있는 것): 속도, 기어
//동작: 가속(엑셀), 감속(브레이크)
class CCar
{
//private: //클래스내부에만 접근 가능함.
	//최신컴파일러에서는 가능함.
	string m_strColor;
	int m_nSpeed = 0;
	int m_nGear= 0;
public: //클래스외/내부 모두 접근가능함.
	enum E_GEAR_STATE { P, R, N ,D, ONE, TWO};
	//클래스생성시 기본값을 지정할때 사용.
	//생성자: 클래스가 생성될때 자동으로 호출되는 함수.
	//이름이 클래스와 같다. 리턴값이 없음. 오버로딩가능 하다. 디폴트매개변수 사용가능.
	//디폴트생성자: 아무런 매개변수가없는 생성자.
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
	//객체(인스턴스): 클래스를 이용하여 할당된 메모리(한번 사용되고 소멸되는 것)
	//소멸자: 객체가 소멸될때
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
	static CCar static_cCar("pink"); //정적지역변수는 가장 마지막에 소멸됨.
	static CCar static_cCarA("deeppink"); //정적지역변수는 가장 마지막에 소멸됨.
	static CCar static_cCarB("lowpink"); //정적지역변수는 가장 마지막에 소멸됨.

	//cCar.m_nSpeed = 0; //은닉
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