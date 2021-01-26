#pragma once

namespace NotIsA
{
	class CBike
	{
		int m_nGear;
		int m_nSpeed;
		int m_nSeat;
	public:
		CBike(int seat)
		{
			m_nSeat = seat;
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
			m_nEngine = engine;
			m_nSeat = seat;
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
			m_nEngine = engine;
			m_nSeat = seat;
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
			m_nEngine = engine;
			m_nSeat = seat;
			m_nWeight = weight;
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
}