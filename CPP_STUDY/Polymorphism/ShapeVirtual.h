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
		//가상함수: 부모의 포인터에서도 자식의 객체 함수를 호출하는것.
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
		//오버라이딩: 부모가 있는 함수와 같은이름의 가상함수를 재정의하는 것
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
		CShape cShape;//형태라는 도형은 없음. 상위분류임.
		CRect cRect;
		CCircle cCircle;
		CTriangle cTriangle;
		//정적바인딩: 메모리가 할당될때 함수의 기능이 결정됨.
		cShape.Draw();
		cRect.Draw();
		cCircle.Draw();
		cTriangle.Draw();
	}
	//정적: 컴파일러에의해서결정됨 바인딩: 함수의 기능이 결정되는것
	//동적: 프로그램 실행중  
	//부모포인터에서 자식의 객체의 함수에 접근가능하다.
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
			//동적바인딩: 할당된 메모리에 따라서 함수의 기능을 달라지는것.
			(*it)->Draw();
		}
		cout << "###### All DrawShapes end ##########" << endl;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			delete (*it);
		}
	}
}

