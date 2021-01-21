#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
연구소에서 학생을 임명 시뮬레이션(연구소,학생)

학생
속성: 이름, 학번, 성취
동작: 연구하기

연구소
속성: 책임자(학생), 관리자(학생), 연구원(학생들), 연구과제진행도(정수)
동작: 책임자임명, 관리자임명, 연구하기
*/

class CStudent
{
	string m_strName;
	int m_nNumber;
	int m_nResarchDegree = 0;
public:
	string GetName()
	{
		return m_strName;
	}

	CStudent(string name, int number)
	{
		m_strName = name;
		m_nNumber = number;
		cout << "CStudent[" << this << "]:" << m_strName << endl;
	}
	~CStudent()
	{
		cout << "~CStudent[" << this << "]:" << m_strName << endl;
	}
	void Research()
	{
		m_nResarchDegree++;
	}
};
//연구소에 A는 책임자이며 관리자는 B이고 연구원은 C다.
class CLabatoryInStudent
{
	CStudent m_cChife = CStudent("A", 1);
	CStudent m_cManager = CStudent("B", 2);;
	CStudent m_arrStudent[3] = { CStudent("A", 1), CStudent("B", 2),CStudent("C", 3) };
	int m_nResarchDegree = 0;
public:
	
	void SetChife(CStudent student)
	{
		m_cChife = student;
	}
	void SetManager(CStudent student)
	{
		m_cManager = student;
	}
	void Research()
	{
		m_cManager.Research();
		m_cChife.Research();
		for (int i = 0; i < 3; i++)
		{
			m_arrStudent[i].Research();
		}
		m_nResarchDegree++;
	}
	void Rating()
	{
		cout << "책임자:" << m_cChife.GetName() << endl;
		cout << "관리자:" << m_cManager.GetName() << endl;
		cout << "연구도:" << m_nResarchDegree << endl;
	}
};

class CLabatoryRefStudent
{
	CStudent* m_pChife;
	CStudent* m_pManager;
	CStudent* m_pStudents[3];
	int m_nResarchDegree = 0;
public:

	void SetChife(CStudent* student)
	{
		m_pChife = student;
	}
	void SetManager(CStudent* student)
	{
		m_pManager = student;
	}
	void Research()
	{
		m_pManager->Research();
		m_pChife->Research();
		for (int i = 0; i < 3; i++)
		{
			m_pStudents[i]->Research();
		}
		m_nResarchDegree++;
	}
	void Rating()
	{
		cout << "책임자:" << m_pChife->GetName() << endl;
		cout << "관리자:" << m_pManager->GetName() << endl;
		cout << "연구도:" << m_nResarchDegree << endl;
	}
};

void LabatoryInStudentMain()
{
	//연구소가 생기면 연구원 A,B,C가 있고, 책임자는 학생과 동명이인 A,  매니저는 학생과 동명이인 B, 
	CLabatoryInStudent cLabatory;
	cLabatory.Rating();
	//연구평가가 좋지않아  책임자와 관리자를 A,B 제거하고 E,F로 바꿨다? 현실적으로 말이 안됨.
	cLabatory.SetChife(CStudent("E", 4));
	cLabatory.SetManager(CStudent("F", 5));
	cLabatory.Research();
	cLabatory.Rating();
}

void LabatoryMain()
{
	//학생목록을 이용하여 연구원과 연구소를 시나리오를 모델링해보고 만들어보자.
	vector<CStudent*> students; 

	students.push_back(new CStudent("A", 1));

	CLabatoryRefStudent cLabatory;
	cLabatory.SetChife(students[0]);
}

void main()
{
	LabatoryMain();
}