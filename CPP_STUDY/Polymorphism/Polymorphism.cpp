#include <iostream>
#include "Shape.h"
#include "ShapeVirtual.h"
#include "FunctionPtr.h"

void main()
{
	//NoVirtual::ShapeTestMain();
	//NoVirtual::ShapeManagerMain();
	//�����Լ��� �Լ��������� ������ �̿��Ͽ� �����ȴ�.
	Virtual::ShapeTestMain();
	Virtual::ShapeManagerMain();
	FunctionTestMain();
}