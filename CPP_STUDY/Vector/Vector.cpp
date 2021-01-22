#include <iostream>

using namespace std;
//벡터
//속성: x,y
//동작:
//이동_+: 벡터
//사이거리_-: 벡터
//스칼라곱: 방향벡터와 이동량을 곱해 이동할 거리를 구함. 벡터*float
//방향과 이동량_평준화:벡터, 스칼라:이동량
class CVector
{
public:
	float x;
	float y;
	//벡터는 멤버를 1개만 셋팅하는 경우는 없으므로 인테페이스를 다음과 같이 정의해야
	//계산한 float값이 멤버 x에만 들어가는 현상을 막을수있다.
	CVector() { x = 0; y = 0; }
	CVector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	CVector operator+(CVector v)
	{
		CVector temp(this->x + v.x, this->y + v.y);
		return temp;
	}
	CVector operator-(CVector v)
	{
		CVector temp(this->x - v.x, this->y - v.y);
		return temp;
	}
	CVector operator*(float dist)//스칼라곱
	{
		CVector temp(this->x * dist, this->y * dist);
		return temp;
	}
	friend CVector operator*(float dist, CVector v)//스칼라곱(교환법칙)
	{
		return CVector(v.x * dist, v.y * dist);
	}
	float operator[](int idx)
	{
		if (idx == 0) return x;
		else return y;
	}
	float operator[](char c)
	{
		if (c == 'x') return x;
		else if(c == 'y') return y;
		return 0;
	}
	float Magnitude()
	{
		return sqrt(x*x + y * y);
	}
	CVector Normarlize()
	{
		float fDist = Magnitude();
		return CVector(x / fDist, y / fDist);
	}
	void Print(const char* msg)
	{
		cout << msg << "(" << x << ","<< y << ")" << endl;
	}
};

void VectorMain()
{
	CVector vPA(0,0);
	CVector vA(10,1);
	vPA.Print("PA");
	vA.Print("A");
	//더하기
	CVector vPB = vPA + vA;
	vPB.Print("PB");
	//빼기
	vA = vPB - vPA;
	vA.Print("A");
	vA = vPA - vPB;
	vA.Print("A");
	CVector vDir = vA.Normarlize();
	CVector fDist = vA.Magnitude();
	vDir.Print("Dir");
	fDist.Print("Dist");
	//곱하기
	vA.Print("A");
	//vA = fDist * vDir;
	vA.Print("A");
}

void main()
{
	VectorMain();
}