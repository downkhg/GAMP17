#include <iostream>
#include <string>

using namespace std;

//자동차 추상화하기
//속성(변경될수 있는 것): 속도, 기어
//동작: 가속(엑셀), 감속(브레이크), 기어변경(setter)
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
	//자동차를 주문할때, 기어나 속도를 못한다.
	//CCar(string color = "gray", int gear = 0, int speed = 0)
	CCar(string color = "gray")
	{
		//cout << "Car("<<color<<","<<gear<<","<< speed<<"):"<< this << endl;
		//m_nGear = gear;
		//m_nSpeed = speed;
		cout << "Car(" << color<<"):" << this << endl;
		m_strColor = color;	
	}
	//객체(인스턴스): 클래스를 이용하여 할당된 메모리(한번 사용되고 소멸되는 것)
	//소멸자: 객체가 소멸될때
	~CCar()
	{
		cout << "~Car("<<m_strColor<<"):"<< this << endl;
	}
	//setter/getter: private멤버에 접근하거나 설정하는데 사용됨.
	//속도는 자동차의 상태에 따라 결정되는것 이므로 getter와 setter가 있어서는 안된다.
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
	//정적지역변수는 가장 마지막에 소멸됨. 
	//정적지역변수가 여러개일때는 먼저생성된 정적변수가 먼저 소멸됨.
	static CCar static_cCar("pink");
	static CCar static_cCarA("deeppink");
	static CCar static_cCarB("lowpink");
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
//다음 시나리오에 맞게 자동차 클래스를 생성해보기
//1. 색상을 지정한다.
//2. 자동차를 제조한다.
//3. 자동차를 사용한다.
void CarOrderMain()
{
	////다음 시나리오는 차를 색상을 정하고 나중에 변경하는것.
	////일반적인 사람들은 이렇게까지 하지않음.
	//CCar cCar;
	//string strColor;
	//cCar.SetColor(strColor);
	string strColor;
	cout << "InputColor:";
	cin >> strColor;
	CCar cCar(strColor);
	//기어를 변경하고 운행한다.
	//적당히 속도위반을하지않도록 가속하고 속도를 확인한다.
	cCar.SetGear(CCar::E_GEAR_STATE::D);
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Accelerator();
	cCar.Display();
	//신호에 걸렸다. 자동차가 멈출때까지 속도를 확인하며 브레이크를 밟는다.
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
//TV클래스를 작성하고 TV를 조작하듯 클래스를 활용하기 - 과제재출하기
//https://classroom.google.com/c/MTU0MTc2ODE4MjY1/a/MjU1MTI1Mzc3NzA3/details

void main()
{
	CarMain();
	//CarOrderMain();
}