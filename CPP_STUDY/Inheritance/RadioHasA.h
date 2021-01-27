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
		//�����ڸ� ���Ϲ޾Ƽ� �����Ͽ����Ƿ� ������ü�ȿ� 
		//������� �����Ҽ��ִ�.
		cRidio.Display();
	}

	void RadioTestMain()
	{
		CRadio cRidio;
		cRidio.GetSpeaker().Switch(true);
		//���ڵ�� ������ ���� �ڵ�� ����.
		CSpeaker  cSpeakerA = cRidio.GetSpeaker();
		cSpeakerA.Switch(true);
		cout << "SpeakerA:" << cSpeakerA.GetOn() << endl;
		cRidio.GetSpeaker().VolumeUp();
		//���ڵ�� ������ ���� �ڵ�� ����.
		CSpeaker  cSpeakerB = cRidio.GetSpeaker();
		cSpeakerB.VolumeUp();
		cout << "SpeakerB:" << cSpeakerB.GetVolume() << endl;
		cRidio.GetAntena().SetHertz(3.14f);
		//���ڵ�� ������ ���� �ڵ�� ����.
		CAntena cAntena = cRidio.GetAntena();
		cAntena.SetHertz(3.14f);
		cout << "Antena:" << cAntena.GetHertz() << endl;
		//���� ���� ��ü�� ���� �����Ͽ� ���� ������.
		//���� ��ü�� ��������� �����������.
		cRidio.Display();
	}

	void RadioPtrTestMain()
	{
		CRadioPtr cRidioEmpty;//������̵���� ����.
		//�� ����Ŀ�� ���³��� ���� ������ �ִ´�.
		CSpeaker* pSpeaker = new CSpeaker();
		CAntena* pAntena = new CAntena();
		cRidioEmpty.SetSpeaker(pSpeaker);
		cRidioEmpty.SetAntena(pAntena);
		//���׳��� ������ ��ǰ�� ���� ����.
		//��ǰ���� ��ü ���ο� �����Ƿ� �޸� ������ �߻���.
		//cRidioEmpty.SetSpeaker(new CSpeaker());
		//cRidioEmpty.SetAntena(new CAntena());
		cRidioEmpty.GetSpeaker()->Switch(true);
		cRidioEmpty.GetSpeaker()->VolumeUp();
		cRidioEmpty.GetAntena()->SetHertz(3.14f);
		//�����ڸ� ���Ϲ޾Ƽ� �����Ͽ����Ƿ� ������ü�ȿ� 
		//������� �����Ҽ��ִ�.
		cRidioEmpty.Display();
		//�ʿ���� ��ǰ�� ������.
		delete pSpeaker;
		delete pAntena;

		CRadioPtr cRiado;
		cRiado.Init(); //��ǰ�� ���ο� ������.
		cRiado.GetSpeaker()->Switch(true);
		cRiado.GetSpeaker()->VolumeUp();
		cRiado.GetAntena()->SetHertz(3.14f);
		cRiado.Display();
		cRiado.Release(); //���ο� ��ǰ�� ����.
	}
}