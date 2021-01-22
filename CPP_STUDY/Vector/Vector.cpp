#include <iostream>

using namespace std;
//º¤ÅÍ
//¼Ó¼º: x,y
//µ¿ÀÛ:
//ÀÌµ¿_+: º¤ÅÍ
//»çÀÌ°Å¸®_-: º¤ÅÍ
//½ºÄ®¶ó°ö: ¹æÇâº¤ÅÍ¿Í ÀÌµ¿·®À» °öÇØ ÀÌµ¿ÇÒ °Å¸®¸¦ ±¸ÇÔ. º¤ÅÍ*float
//¹æÇâ°ú ÀÌµ¿·®_ÆòÁØÈ­:º¤ÅÍ, ½ºÄ®¶ó:ÀÌµ¿·®
class CVector
{
public:
	float x;
	float y;
	CVector(float x = 0, float y = 0)
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
	CVector operator*(float dist)//½ºÄ®¶ó°ö
	{
		CVector temp(this->x * dist, this->y * dist);
		return temp;
	}
	void Print(const char* msg)
	{
		cout << msg << "(" << x << ","<< y << ")" << endl;
	}
};

void VectorMain()
{
	CVector vA(0,0);
	CVector vB(1,1);
	//´õÇÏ±â,»©±â,°öÇÏ±â
}

void main()
{

}