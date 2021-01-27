#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace RadioHasA
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
		bool GetOn()
		{
			return m_bOn;
		}
		int GetVolume()
		{
			return m_nVolume;
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
		float GetHertz()
		{
			return m_fHertz;
		}
	};
\
	class CRadio 
	{
		CAntena m_cAntena;
		CSpeaker m_cSpeaker;
	public:
		CAntena GetAntena()
		{
			return m_cAntena;
		}
		CSpeaker GetSpeaker()
		{
			return m_cSpeaker;
		}
		void Display()
		{
			cout << "Radio Display" << endl;
			cout << "On:" << m_cSpeaker.GetOn() << endl;
			cout << "Volume:" << m_cSpeaker.GetVolume() << endl;
			cout << "Hertz:" << m_cAntena.GetHertz() << endl;
		}
	};

	void RadioTestMain()
	{
		CRadio cRidio;
		cRidio.GetSpeaker().Switch(true);
		cRidio.GetSpeaker().VolumeUp();
		cRidio.GetAntena().SetHertz(3.14f);
		cRidio.Display();
	}
}