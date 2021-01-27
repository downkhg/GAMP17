#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;
//���̾Ƹ������ ����
namespace DiamonInheritance
{
	class CVehicle
	{
	protected://�ڽİ�ü�� ���ٰ����� ���
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
		//�����ڿ��� �θ�����ڸ� ȣ��
		CBike(int seat) :CVehicle(seat)
		{
			cout << "CBike:" << this << endl;
			///m_nSeat = seat; //�����ڿ��� �̹� �ʱ�ȭ ��.
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
	//���̾Ƹ����: �����θ� ���� �ڽ�Ŭ������ ���ÿ� ��ӹ���.
	//��κ��� ��ü��������� �Ϲ�Ŭ������ ���߻���� ��������ʰ�,
	//�������̽��� ���߻���� �����Ѵ�.
	//���������̽�: ��������� ���� Ŭ����.
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
	//���߻��: �ڽ�Ŭ������ ��ӹ޴°�.
	void CarIsATestMain()
	{
		CVehicle cVehicle(0);
		CVehicle cBike(1);
		CEnginer cAutoBike(2, 900);
		CEnginer cBus(20, 5000);
		CTruck cTruck(2, 5000, 1000);
	}
}