#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
�����ҿ��� �л��� �Ӹ� �ùķ��̼�(������,�л�)

�л�
�Ӽ�: �̸�, �й�, ����
����: �����ϱ�

������
�Ӽ�: å����(�л�), ������(�л�), ������(�л���), �����������൵(����)
����: å�����Ӹ�, �������Ӹ�, �����ϱ�
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
//�����ҿ� A�� å�����̸� �����ڴ� B�̰� �������� C��.
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
		cout << "å����:" << m_cChife.GetName() << endl;
		cout << "������:" << m_cManager.GetName() << endl;
		cout << "������:" << m_nResarchDegree << endl;
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
		cout << "å����:" << m_pChife->GetName() << endl;
		cout << "������:" << m_pManager->GetName() << endl;
		cout << "������:" << m_nResarchDegree << endl;
	}
};

void LabatoryInStudentMain()
{
	//�����Ұ� ����� ������ A,B,C�� �ְ�, å���ڴ� �л��� �������� A,  �Ŵ����� �л��� �������� B, 
	CLabatoryInStudent cLabatory;
	cLabatory.Rating();
	//�����򰡰� �����ʾ�  å���ڿ� �����ڸ� A,B �����ϰ� E,F�� �ٲ��? ���������� ���� �ȵ�.
	cLabatory.SetChife(CStudent("E", 4));
	cLabatory.SetManager(CStudent("F", 5));
	cLabatory.Research();
	cLabatory.Rating();
}

void LabatoryMain()
{
	//�л������ �̿��Ͽ� �������� �����Ҹ� �ó������� �𵨸��غ��� ������.
	vector<CStudent*> students; 

	students.push_back(new CStudent("A", 1));

	CLabatoryRefStudent cLabatory;
	cLabatory.SetChife(students[0]);
}

void main()
{
	LabatoryMain();
}