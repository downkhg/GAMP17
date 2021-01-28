#pragma once

#include  <iostream>
#include <string>
#include <list>
using namespace std;


namespace NoVirtual
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
		void Draw()
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
		void Draw()
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
		void Draw()
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
		void Draw()
		{
			cout << "CTriangle::Draw:" << this << endl;
			sA.Draw("A");
			sB.Draw("B");
			sC.Draw("C");
		}
	};

	void ShapeTestMain()
	{
		CShape cShape;//형태라는 도형은 없음. 상위분류임.
		CRect cRect;
		CCircle cCircle;
		CTriangle cTriangle;

		cShape.Draw();
		cRect.Draw();
		cCircle.Draw();
		cTriangle.Draw();
	}

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
			(*it)->Draw();
		}
		cout << "###### All DrawShapes end ##########" << endl;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			delete (*it);
		}
	}
}

