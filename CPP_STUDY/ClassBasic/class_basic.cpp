#include <iostream>
#include <string>

using namespace std;

//자동차 추상화하기
//속성(변경될수 있는 것): 속도, 기어
//동작: 가속(엑셀), 감속(브레이크), 기어변경(setter)
//자동차가 생산될때마다 각객체에서 생산된 자동차의 수를 확인하도록 만들기. 폐차되면 카운트 감소.
//생산: 생성자,복사생성자 폐차: 소멸자
//외부 기호를 확인할 수 없습니다.: 함수의 선언만 하고 정의하지않을때.
class CCar
{
//private: //클래스내부에만 접근 가능함.
	//최신컴파일러에서는 가능함.
	string m_strColor;
	int m_nSpeed = 0;
	int m_nGear= 0;
	static int m_nCount;// = 0; //정적멤버변수의 선언
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
		m_nCount++;
		cout << "Car(" << color<<")["<<m_nCount<<"]:" << this << endl;
		m_strColor = color;	
	}
	CCar(CCar& car)
	{
		*this = car;
		m_nCount++;
		cout << "CarCopy(" << this->m_strColor << ")[" << m_nCount << "]:" << this << endl;
	}
	//객체(인스턴스): 클래스를 이용하여 할당된 메모리(한번 사용되고 소멸되는 것)
	//소멸자: 객체가 소멸될때
	~CCar()
	{
		m_nCount--;
		cout << "~Car("<<m_strColor<<":[" << m_nCount << "]:"<< this << endl;
	}
	static int GetCount()//정적멤버변수: 객체생성전에 접근가능한 함수다.
	{
		//일반멤버변수는 객체가 생성되야만 존재가능하지만, 이함수는 객체 생성전에 호출이 가능해야함. 그러므로 이러한 호출은 불가함.
		//m_nSpeed++; 
		return m_nCount;
	}
	//setter/getter: private멤버에 접근하거나 설정하는데 사용됨.
	//속도는 자동차의 상태에 따라 결정되는것 이므로 getter와 setter가 있어서는 안된다.
	void SetColor(string color)
	{
		m_strColor = color;
	}
	string GetColor()  const
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
	void Display() const  //멤버변수를 변경할수없는 함수
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
};

int CCar::m_nCount = 0; //정적멤버변수의 정의
//정적멤버변수는 객체 생성전에 있어야한다. 그러므로 전역변수로 정의해야만 사용가능하다.

void CarMain()
{
	cout << "CarCount:" << CCar::GetCount() << endl;
	CCar cCar("red");
	cout << "CarCount:"<<cCar.GetCount() << endl;
	CCar* pCar = NULL;
	cout << "CarCount:" << pCar->GetCount() << endl;//포인터가 비어있더라도 정적멤버는 접근 가능하므로 컴파일오류가 나지않음.
	pCar = new CCar("blue");
	CCar arrCar[3];// = { CCar("green"),CCar("yellow"), CCar("white") }; //복사생성자 정의시 오류남.
	//정적지역변수는 가장 마지막에 소멸됨. 
	//정적지역변수가 여러개일때는 먼저생성된 정적변수가 먼저 소멸됨.
	static CCar static_cCar("pink");
	static CCar static_cCarA("deeppink");
	static CCar static_cCarB("lowpink");
	cout << "CarCount:" << static_cCarB.GetCount() << endl;
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

void ConstCarMain()
{
	const CCar cCar("red");

	//cCar.Accelerator(); //객체의 변수값을 변경할수없다.
	//cCar.SetColor("test");
}

void SwapCar(CCar a, CCar b)
{
	CCar temp = a;
	a = b;
	b = temp;
}

void SwapCarRef(CCar& a, CCar& b)
{
	CCar temp = a;
	a = b;
	b = temp;
}
//객체도 매개변수로 전달될때 복사된다.
void CarFuncionMain()
{
	CCar cCarA("red");
	CCar cCarB("blue");
	cCarA.Display();
	cCarB.Display();
	SwapCar(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
	SwapCarRef(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
}

void main()
{
	CarMain();
	//CarOrderMain();
	//CarFuncionMain();
}