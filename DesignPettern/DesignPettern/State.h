#pragma once

#include <iostream>
using namespace std;

class State;
class StateOne;
class StateTwo;
class StateThree;

class Context
{
	State* m_pState;
public:
	Context();
	~Context();
	void SetState(State* state);
	void GoNext() ;
};


class State
{
public:
	State()
	{
		cout << typeid(*this).name() << endl;
	}
	~State()
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