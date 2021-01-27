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

	class CRadioRef
	{
		CAntena m_cAntena;
		CSpeaker m_cSpeaker;
	public:
		CAntena& GetAntena()
		{
			return m_cAntena;
		}
		CSpeaker& GetSpeaker()
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

	class CRadioPtr
	{
		CAntena* m_pAntena;
		CSpeaker* m_pSpeaker;
	public:
		void Init()
		{
			m_pAntena = new CAntena();
			m_pSpeaker = new CSpeaker();
		}
		void Release()
		{
			delete m_pAntena;
			delete m_pSpeaker;
		}
		void SetAntena(CAntena* antena)
		{
			m_pAntena = antena;
		}
		void SetSpeaker(CSpeaker* speaker)
		{
			m_pSpeaker = speaker;
		}
		CAntena* GetAntena()
		{
			return m_pAntena;
		}
		CSpeaker* GetSpeaker()
		{
			return m_pSpeaker;
		}
		void Display()
		{
			cout << "Radio Display" << endl;
			cout << "On:" << m_pSpeaker->GetOn() << endl;
			cout << "Volume:" << m_pSpeaker->GetVolume() << endl;
			cout << "Hertz:" << m_pAntena->GetHertz() << endl;
		}
	};

	void RadioRefTestMain()
	{
		CRadioRef cRidio;
		cRidio.GetSpeaker().Switch(true);
		cRidio.GetSpeaker().VolumeUp();
		cRidio.GetAntena().SetHertz(3.14f);
		//참조자를 리턴받아서 변경하였으므로 라디오객체안에 
		//멤버들을 참조할수있다.
		cRidio.Display();
	}

	void RadioTestMain()
	{
		CRadio cRidio;
		cRidio.GetSpeaker().Switch(true);
		//위코드는 다음과 같은 코드와 같다.
		CSpeaker  cSpeakerA = cRidio.GetSpeaker();
		cSpeakerA.Switch(true);
		cout << "SpeakerA:" << cSpeakerA.GetOn() << endl;
		cRidio.GetSpeaker().VolumeUp();
		//위코드는 다음과 같은 코드와 같다.
		CSpeaker  cSpeakerB = cRidio.GetSpeaker();
		cSpeakerB.VolumeUp();
		cout << "SpeakerB:" << cSpeakerB.GetVolume() << endl;
		cRidio.GetAntena().SetHertz(3.14f);
		//위코드는 다음과 같은 코드와 같다.
		CAntena cAntena = cRidio.GetAntena();
		cAntena.SetHertz(3.14f);
		cout << "Antena:" << cAntena.GetHertz() << endl;
		//위와 같이 객체를 복사 생성하여 값을 변경함.
		//실제 객체에 멤버변수는 변경되지않음.
		cRidio.Display();
	}

	void RadioPtrTestMain()
	{
		CRadioPtr cRidioEmpty;//깡통라이디오를 만듦.
		//각 스피커와 안태나를 만들어서 라디오에 넣는다.
		CSpeaker* pSpeaker = new CSpeaker();
		CAntena* pAntena = new CAntena();
		cRidioEmpty.SetSpeaker(pSpeaker);
		cRidioEmpty.SetAntena(pAntena);
		//안테나와 라디오의 부품을 만들어서 넣음.
		//부품들이 객체 내부에 있으므로 메모리 누수가 발생함.
		//cRidioEmpty.SetSpeaker(new CSpeaker());
		//cRidioEmpty.SetAntena(new CAntena());
		cRidioEmpty.GetSpeaker()->Switch(true);
		cRidioEmpty.GetSpeaker()->VolumeUp();
		cRidioEmpty.GetAntena()->SetHertz(3.14f);
		//참조자를 리턴받아서 변경하였으므로 라디오객체안에 
		//멤버들을 참조할수있다.
		cRidioEmpty.Display();
		//필요없는 부품을 버린다.
		delete pSpeaker;
		delete pAntena;

		CRadioPtr cRiado;
		cRiado.Init(); //부품을 내부에 생성함.
		cRiado.GetSpeaker()->Switch(true);
		cRiado.GetSpeaker()->VolumeUp();
		cRiado.GetAntena()->SetHertz(3.14f);
		cRiado.Display();
		cRiado.Release(); //내부에 부품을 버림.
	}
}