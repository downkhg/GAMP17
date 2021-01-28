#pragma once

#include  <iostream>
#include <string>
#include <list>
using namespace std;


namespace Virtual
{
	struct SPoint
	{
		float x;
		float y;
		void Draw(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class CShape
	{
	public:
		CShape()
		{
			cout << "CShape:" << this << endl;
		}
		~CShape()
		{
			cout << "~CShape:" << this << endl;
		}
		//�����Լ�: �θ��� �����Ϳ����� �ڽ��� ��ü �Լ��� ȣ���ϴ°�.
		virtual void Draw()
		{
			cout << "CShape::Draw:" << this << endl;
		}
	};

	class CRect : public CShape
	{
		SPoint sTopLeft;
		SPoint sTopRight;
		SPoint sBottomRight;
		SPoint sBottomLeft;
	public:
		CRect()
		{
			cout << "CRect:" << this << endl;
		}
		~CRect()
		{
			cout << "~CRect:" << this << endl;
		}
		//�������̵�: �θ� �ִ� �Լ��� �����̸��� �����Լ��� �������ϴ� ��
		void Draw() override
		{
			cout << "CRect::Draw()" << endl;
			sTopLeft.Draw("TL");
			sTopRight.Draw("TR");
			sBottomRight.Draw("BR");
			sBottomLeft.Draw("BL");
		}
	};

	class CCircle : public CShape
	{
		SPoint sPos;
		float fRadius;
	public:
		CCircle()
		{
			cout << "CCircle:" << this << endl;
		}
		~CCircle()
		{
			cout << "~CCircle:" << this << endl;
		}
		void Draw() override
		{
			cout << "CCircle::Draw:" << this << endl;
			sPos.Draw("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};

	class CTriangle : public CShape
	{
		SPoint sA;
		SPoint sB;
		SPoint sC;
	public:
		CTriangle()
		{
			cout << "CTriangle:" << this << endl;
		}
		~CTriangle()
		{
			cout << "~CTriangle:" << this << endl;
		}
		void Draw() override
		{
			cout << "CTriangle::Draw:" << this << endl;
			sA.Draw("A");
			sB.Draw("B");
			sC.Draw("C");
		}
	};

	void ShapeTestMain()
	{
		CShape cShape;//���¶�� ������ ����. �����з���.
		CRect cRect;
		CCircle cCircle;
		CTriangle cTriangle;
		//�������ε�: �޸𸮰� �Ҵ�ɶ� �Լ��� ����� ������.
		cShape.Draw();
		cRect.Draw();
		cCircle.Draw();
		cTriangle.Draw();
	}
	//����: �����Ϸ������ؼ������� ���ε�: �Լ��� ����� �����Ǵ°�
	//����: ���α׷� ������  
	//�θ������Ϳ��� �ڽ��� ��ü�� �Լ��� ���ٰ����ϴ�.
	void ShapeManagerMain()
	{
		list<CShape*> listShapes;

		listShapes.push_back(new CTriangle());
		listShapes.push_back(new CRect());
		listShapes.push_back(new CCircle());
		cout << "###### All DrawShapes start ##########" << endl;
		list<CShape*>::iterator it = listShapes.begin();
		for (; it != listShapes.end(); it++)
		{
			//�������ε�: �Ҵ�� �޸𸮿� ���� �Լ��� ����� �޶����°�.
			(*it)->Draw();
		}
		cout << "###### All DrawShapes end ##########" << endl;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			delete (*it);
		}
	}
}

