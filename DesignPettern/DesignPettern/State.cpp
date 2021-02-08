#include "State.h"
//���Ǻδ� ���� cpp���Ϸ� ������ �����Ѵ�.
//����, ���������� ���̺귯��ȭ �Ͽ� ó���κ��� ���涧�� ���ȴ�.
StateThree::StateThree()
{
	cout << typeid(*this).name() << endl;
}
StateThree::~StateThree()
{
	cout << "~" << typeid(*this).name() << endl;
}
void StateThree::GoNext(Context* context) 
{
	context->SetState(new StateOne());
}

StateTwo::StateTwo()
{
	cout << typeid(*this).name() << endl;
}
StateTwo::~StateTwo()
{
	cout << "~" << typeid(*this).name() << endl;
}
void StateTwo::GoNext(Context* context)
{
	context->SetState(new StateThree());
}

StateOne::StateOne()
{
	cout << typeid(*this).name() << endl;
}
StateOne::~StateOne()
{
	cout << "~" << typeid(*this).name() << endl;
}
void StateOne::GoNext(Context* context)
{
	context->SetState(new StateTwo());
}

void Context::Initialize()
{
	m_pState = new StateOne();
}

void Context::Release()
{
	if(m_pState)
		delete m_pState;
}

Context::Context()
{
	cout << typeid(*this).name() << endl;
}
Context::~Context()
{
	Release();
	cout << "~" << typeid(*this).name() << endl;
}
void Context::SetState(State* state)
{
	Release();
	m_pState = state;
}
void Context::GoNext()
{
	m_pState->GoNext(this);
}


void StateTestMain()
{
	Context cContext;

	//cContext.SetState(new StateOne());
	cContext.Initialize();
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
	cContext.Release();
}