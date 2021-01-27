#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;
//다이아몬드상속의 문제
namespace DiamonInheritance
{
	class CVehicle
	{
	protected://자식객체서 접근가능한 멤버
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
	public:
		CVehicle(int seat)
		{
			cout << "CVehicle:" << this << endl;
			m_nSeat = seat;
		}
		~CVehicle()
		{
			cout << "~CVehicle:" << this << endl;
		}
		void Accelerator()
		{
			m_nSpeed++;
		}
		void Break()
		{
			m_nSpeed--;
		}
		int GetSeat()
		{
			return m_nSeat;
		}
	};

	class CBike : public CVehicle
	{
	public:
		//생성자에서 부모생성자를 호출
		CBike(int seat) :CVehicle(seat)
		{
			cout << "CBike:" << this << endl;
			///m_nSeat = seat; //생성자에서 이미 초기화 됨.
		}
		~CBike()
		{
			cout << "~CBike:" << this << endl;
		}
	};

	class CEnginer : public CVehicle
	{
		int m_nEngine;
	public:
		CEnginer(int seat, int engine) :CVehicle(seat)
		{
			cout << "CEnginer:" << this << endl;
			m_nEngine = engine;
		}
		~CEnginer()
		{
			cout << "~CEnginer:" << this << endl;
		}
		int GetEngine()
		{
			return m_nEngine;
		}
	};
	//다이아몬드상속: 같은부모를 가진 자식클래스를 동시에 상속받음.
	//대부분의 객체지향언어에서는 일반클래스는 다중상속을 허용하지않고,
	//인터페이스만 다중상속을 지원한다.
	//※인터페이스: 멤버변수가 없는 클래스.
	class CAutoBike : public CBike , public CEnginer
	{
	public:
		CAutoBike(int seat, int engine) :CBike(seat),CEnginer(seat,engine)
		{
			cout << "CAutoBike:" << this << endl;
		}
		~CAutoBike()
		{
			cout << "~CAutoBike:" << this << endl;
		}
	};

	class CTruck : public CEnginer
	{
		int m_nWeight;
	public:
		CTruck(int seat, int engine, int weight) : CEnginer(seat, engine)
		{
			m_nSeat = seat;
			m_nWeight = weight;
			cout << "CTruck:" << this << endl;
		}
		~CTruck()
		{
			cout << "~CTruck:" << this << endl;
		}
		int GetWeight()
		{
			return m_nWeight;
		}
	};
	//다중상속: 자식클래스를 상속받는것.
	void CarIsATestMain()
	{
		CVehicle cVehicle(0);
		CVehicle cBike(1);
		CEnginer cAutoBike(2, 900);
		CEnginer cBus(20, 5000);
		CTruck cTruck(2, 5000, 1000);
	}
}