#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace NotIsA
{
	//중복된 부분이 많으므로 공통적인부분을 부모클래스로 만든다.
	//->CarIsA.h
	class CBike
	{
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
	public:
		CBike(int seat)
		{
			cout << "CBike:" << this << endl;
			m_nSeat = seat;
		}
		~CBike()
		{
			cout << "CBike:" << this << endl;
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

	class CAutoBike
	{
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
	public:
		CAutoBike(int engine, int seat)
		{
			cout << "CAutoBike:" << this << endl;
			m_nEngine = engine;
			m_nSeat = seat;
		}
		~CAutoBike()
		{
			cout << "CAutoBike:" << this << endl;
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

	class CBus
	{
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
	public:
		CBus(int engine, int seat)
		{
			cout << "CBus:" << this << endl;
			m_nEngine = engine;
			m_nSeat = seat;
		}
		~CBus()
		{
			cout << "~CBus:" << this << endl;
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

	class CTruck
	{
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
		int m_nWeight;
	public:
		CTruck(int engine, int seat, int weight)
		{
			cout << "CTruck:" << this << endl;
			m_nEngine = engine;
			m_nSeat = seat;
			m_nWeight = weight;
		}
		~CTruck()
		{
			cout << "~CTruck:" << this << endl;
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
		int GetWeight()
		{
			return m_nWeight;
		}
	};

	void CarIsATestMain()
	{
		CBike cBike(1);
		CAutoBike cAutoBike(2, 900);
		CBus cBus(20, 5000);
		CTruck cTruck(2, 5000, 1000);
	}
}