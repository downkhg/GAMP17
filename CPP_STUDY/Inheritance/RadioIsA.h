#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace IsA
{
	class CSpeaker
	{
	protected:
		bool m_bOn = false;
		int m_nVolume = 0;
	public:
		void Switch(bool on)
		{
			m_bOn = on;
		}
		void VolumeUp()
		{
			m_nVolume++;
		}
		void VolumeDown()
		{
			m_nVolume--;
		}
	};

	class CAntena
	{
	protected:
		float m_fHertz = 0;
	public:
		void SetHertz(float hertz)
		{
			m_fHertz = hertz;
		}
	};
	//���߻��: �θ� 2���̻� ��ӹ���.
	class CRadio : public CSpeaker, public CAntena
	{
	public:
		void Display()
		{
			cout << "Radio Display" << endl;
			cout << "On:" << m_bOn << endl;
			cout << "Volume:" << m_nVolume << endl;
			cout << "Hertz:" << m_fHertz << endl;
		}
	};

	void RadioTestMain()
	{
		CRadio cRidio;
		cRidio.Switch(true);
		cRidio.VolumeUp();
		cRidio.VolumeDown();
		cRidio.Display();
	}
}