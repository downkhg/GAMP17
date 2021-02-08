#pragma once

#include <iostream>
using namespace std;
//객체가 서로 참조하는경우는 다음과 같이 선언부와 정의부를 분리해야한다.
class State;
class StateOne;
class StateTwo;
class StateThree;

class Context
{
	State* m_pState = NULL;
public:
	Context();
	~Context();
	
	void Initialize();//객체생성
	void Release();//객체제거

	void SetState(State* state);
	void GoNext();
};

class State
{
public:
	State()
	{
		cout << typeid(*this).name() << endl;
	}
	virtual ~State()
	{
		cout << "~" <<typeid(*this).name() << endl;
	}
	virtual void GoNext(Context* context) = 0;
};

class StateThree : public State
{
public:
	StateThree();
	~StateThree();
	void GoNext(Context* context) override;
};

class StateTwo : public State
{
public:
	StateTwo();
	~StateTwo();
	void GoNext(Context* context) override;
};

class StateOne : public State
{
public:
	StateOne();
	~StateOne();
	void GoNext(Context* context) override;
};

extern void StateTestMain();