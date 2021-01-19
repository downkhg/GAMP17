#include <iostream>
#include <string>

using namespace std;

void STDStringMain()//기본클래스를 활용하여 생성자,복사생성자,소멸자를 이용하기
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //생성자
	string strMsg2 = "DataTest"; //생성자
	string srtCopyMsg = strMsg; //복사생성자

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수
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

	void StringMain()//기본클래스를 활용하여 생성자,복사생성자,소멸자를 이용하기
	{
		cout << "##### MokeupStringMain Start######" << endl;
		string strMsg("Test"); //생성자
		string strMsg2 = "DataTest"; //생성자
		string srtCopyMsg = strMsg; //복사생성자

		cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수
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