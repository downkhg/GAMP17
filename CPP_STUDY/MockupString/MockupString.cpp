#include <iostream>
#include <string>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

using namespace std;

void STDStringMain()//�⺻Ŭ������ Ȱ���Ͽ� ������,���������,�Ҹ��ڸ� �̿��ϱ�
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2 = "DataTest"; //������
	string strCopyMsg = strMsg; //���������
	strCopyMsg = strMsg2; //���Կ�����

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
	cout << strCopyMsg.c_str() << endl;
	printf("%d:%s\n", strCopyMsg.c_str(), strCopyMsg.c_str());
	cout << "##### STDStringMain End######" << endl;
}

namespace Mokeup
{
	class string
	{
		char* m_pStr;
	public:
		string(const char* str)
		{
			int nSize = strlen(str);
			m_pStr = new char[nSize+1];
			strcpy(m_pStr, str);
			cout << "MokeupString[" << this << "]:" << (int)m_pStr << endl;
		}
		//���������: ��ü�� ����ɶ� ȣ��Ǵ� �Լ�
		string(string& str)
		{
			//*this = str;//��������: ��ü�� ���� �޸� �״�� ������.
			//��������: ���ο�޸𸮸� �����Ҵ��ؼ� ������ü�� ���ڿ��� ������.
			int nSize = str.size();
			m_pStr = new char[nSize + 1];
			strcpy(m_pStr, str.c_str());
			cout << "MokeupString Copy[" << this << "]:" << (int)m_pStr << endl;
		}
		void operator=(string& str)
		{
			int nSize = str.size();
			if (nSize != size())
			{
				delete[] m_pStr; //�����޸������Ѵ�.
				m_pStr = new char[nSize + 1];
			}
			strcpy(m_pStr, str.c_str());
			cout << "MokeupString ==[" << this << "]:" << (int)m_pStr << endl;
		}
		int size()
		{
			return strlen(m_pStr);
		}
		~string()
		{
			cout << "~MokeupString[" << this << "]:"<< (int)m_pStr << endl;
			delete[] m_pStr;
		}
		const char* c_str()
		{
			return m_pStr;
		}
	};

	void StringMain()//�⺻Ŭ������ Ȱ���Ͽ� ������,���������,�Ҹ��ڸ� �̿��ϱ�
	{
		cout << "##### MokeupStringMain Start######" << endl;
		string strMsg("Test"); //������
		string strMsg2 = "DataTest"; //������
		string strCopyMsg = strMsg; //���������
		strCopyMsg = strMsg2; //���Կ�����

		cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
		printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
		cout << strMsg2.c_str() << endl;
		printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
		cout << strCopyMsg.c_str() << endl;
		printf("%d:%s\n", strCopyMsg.c_str(), strCopyMsg.c_str());
		cout << "##### MokeupStringMain End######" << endl;
	};
}

void main()
{
	//_CrtSetBreakAlloc(198); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 
	//STDStringMain();
	Mokeup::StringMain();
}