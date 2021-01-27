#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace HierarchyIsA
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