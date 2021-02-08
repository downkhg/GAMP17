#include "State.h"

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
void StateTwo::GoNext(Context* context)// override
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
void StateOne::GoNext(Context* context)// override
{
	context->SetState(new StateTwo());
}

Context::Context()
{
	cout << typeid(*this).name() << endl;
}
Context::~Context()
{
	cout << "~" << typeid(*this).name() << endl;
}
void Context::SetState(State* state)
{
	m_pState = state;
}
void Context::GoNext()
{
	m_pState->GoNext(this);
}


void StateTestMain()
{
	Context cContext;

	cContext.SetState(new StateOne());
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}