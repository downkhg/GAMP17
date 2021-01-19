#include <iostream>
#include <string>

using namespace std;

void STDStringMain()//�⺻Ŭ������ Ȱ���Ͽ� ������,���������,�Ҹ��ڸ� �̿��ϱ�
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2 = "DataTest"; //������
	string srtCopyMsg = strMsg; //���������

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
	cout << strMsg2.c_str() << endl;
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
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
			cout << "MokeupString["<<this<<"]:"<< str << endl;
			int nSize = strlen(str);
			m_pStr = new char[nSize];
			strcpy(m_pStr, str);
		}
		~string()
		{
			cout << "~MokeupString[" << this << "]" << endl;
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
		string srtCopyMsg = strMsg; //���������

		cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ�
		printf("%d:%s\n", strMsg.c_str(), strMsg.c_str());
		cout << strMsg2.c_str() << endl;
		printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str());
		cout << "##### MokeupStringMain End######" << endl;
	};
}

void main()
{
	//STDStringMain();
	Mokeup::StringMain();
}