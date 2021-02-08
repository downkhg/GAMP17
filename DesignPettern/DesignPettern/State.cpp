#include "State.h"
//정의부는 보통 cpp파일로 나누어 생성한다.
//추후, 헤더만남기고 라이브러리화 하여 처리부분을 숨길때도 사용된다.
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