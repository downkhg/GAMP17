#include <iostream>
#include "Shape.h"
#include "ShapeVirtual.h"
#include "FunctionPtr.h"

void main()
{
	//NoVirtual::ShapeTestMain();
	//NoVirtual::ShapeManagerMain();
	//가상함수는 함수포인터의 개념을 이용하여 성립된다.
	Virtual::ShapeTestMain();
	Virtual::ShapeManagerMain();
	FunctionTestMain();
}