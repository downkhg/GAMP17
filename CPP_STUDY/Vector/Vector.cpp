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
	//연산자오버로딩: 연산자를 재정의하는 것.
	//연산결과: 리턴값
	//연산자: operator기호
	//오른쪽피연산자: 매개변수
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
	//피연산자가 2개이상일때는 프랜즈연산자를 이용해야함.
	friend CVector operator*(float dist, CVector v)//스칼라곱(교환법칙)
	{
		return CVector(v.x * dist, v.y * dist);
	}
	//비교연산자만들기
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
	float fDist = vA.Magnitude();
	vDir.Print("Dir");
	cout << "Dist:"<< fDist << endl;
	//곱하기
	vA.Print("A");
	vA = fDist * vDir;
	vA.Print("A");
	//다음과 같이 사용가능하나 예외가 발생할수있으므로 좋지않음.
	cout << "A[0,1](" << vA[0] << ","<< vA[1] << ")" << endl;
	cout << "A['x','y'](" << vA['x'] << "," << vA['y'] << ")" << endl;
}

void main()
{
	VectorMain();
}