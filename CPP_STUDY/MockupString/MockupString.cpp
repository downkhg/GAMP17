#include <iostream>
#include <string>

using namespace std;

void STDStringMain()//�⺻Ŭ������ Ȱ���Ͽ� ������,���������,�Ҹ��ڸ� �̿��ϱ�
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2 = "DataTest"; //������
	string strCopyMsg = strMsg; //���������

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
			m_pStr = new char[nSize];
			strcpy(m_pStr, str);
			cout << "MokeupString[" << this << "]:" << (int)m_pStr << endl;

		}
		//���������: ��ü�� ����ɶ� ȣ��Ǵ� �Լ�
		string(string& str)
		{
			//*this = str;//��������: ��ü�� ���� �޸� �״�� ������.
			//��������: ���ο�޸𸮸� �����Ҵ��ؼ� ������ü�� ���ڿ��� ������.
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
	//STDStringMain();
	Mokeup::StringMain();
}