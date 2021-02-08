#pragma once

#include <iostream>
using namespace std;
//��ü�� ���� �����ϴ°��� ������ ���� ����ο� ���Ǻθ� �и��ؾ��Ѵ�.
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
	
	void Initialize();//��ü����
	void Release();//��ü����

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