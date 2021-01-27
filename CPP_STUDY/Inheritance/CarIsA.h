#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace IsA
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
			cout << "CVehicle:"<< this << endl;
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
		CBike(int seat):CVehicle(seat)
		{
			cout << "CBike:" << this << endl;
			///m_nSeat = seat; //생성자에서 이미 초기화 됨.
		}
		~CBike()
		{
			cout << "~CBike:" << this << endl;
		}
	};

	class CAutoBike : public CVehicle
	{
		int m_nEngine;
	public:
		CAutoBike(int seat, int engine) :CVehicle(seat)
		{
			cout << "CAutoBike:" << this << endl;
			m_nEngine = engine;
		}
		~CAutoBike()
		{
			cout << "~CAutoBike:" << this << endl;
		}
		int GetEngine()
		{
			return m_nEngine;
		}
	};

	class CBus : public CVehicle
	{
		int m_nEngine;
	public:
		CBus(int seat, int engine) :CVehicle(seat)
		{
			cout << "CBus:" << this << endl;
			m_nEngine = engine;
		}
		~CBus()
		{
			cout << "~CBus:" << this << endl;
		}
		int GetEngine()
		{
			return m_nEngine;
		}
	};

	class CTruck : public CVehicle
	{
		int m_nEngine;
		int m_nWeight;
	public:
		CTruck(int seat, int engine, int weight): CVehicle(seat)
		{
			m_nSeat = seat;
			m_nWeight = weight;
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

	void CarIsATestMain()
	{
		CVehicle cVehicle(0);
		//CBike cBike(1);
		CVehicle cBike(1);
		CAutoBike cAutoBike(2, 900);
		//CBus cBus(20, 5000);
		CAutoBike cBus(20, 5000);
		CTruck cTruck(2, 5000, 1000);
	}
}