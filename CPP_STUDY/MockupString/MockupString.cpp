#include <iostream>
#include <string>

using namespace std;

void STDStringMain()//기본클래스를 활용하여 생성자,복사생성자,소멸자를 이용하기
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //생성자
	string strMsg2 = "DataTest"; //생성자
	string strCopyMsg = strMsg; //복사생성자

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수
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
		//복사생성자: 객체가 복사될때 호출되는 함수
		string(string& str)
		{
			//*this = str;//얕은복사: 객체의 값을 메모리 그대로 복사함.
			//깊은복사: 새로운메모리를 동적할당해서 기존객체의 문자열을 복사함.
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

	void StringMain()//기본클래스를 활용하여 생성자,복사생성자,소멸자를 이용하기
	{
		cout << "##### MokeupStringMain Start######" << endl;
		string strMsg("Test"); //생성자
		string strMsg2 = "DataTest"; //생성자
		string strCopyMsg = strMsg; //복사생성자

		cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수
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