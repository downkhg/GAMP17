#include "CarIsA.h"
#include "CarNotIsA.h"
#include "CarIiA_Hierarchy.h"
#include "RadioHasA.h"
#include "RadioIsA.h"

void main()
{
	//상속을 하는데는 만들어보고 공통적인 부분을 부모로 만들어서 상속한다.
	//기본적으로 클래스를 만들어보고,
	//리팩토링(재설계)을 통해 사용하기 편한 코드를 만들어야한다.
	//상속은 코드량이 적어서 편하긴하지만, 기존의 설계에서 변경되야할때,
	//상속으로 해결되지않는 기능이 추가된경우 변경이 매우어렵다.
	//오버라이딩: 부모객체위에 자식이 할당되는것.

	//상속을 하지않으면 각객체마다 같은 부분의 코드를 작성해야한다.
	//NotIsA::CarIsATestMain();
	//상속된 객체는 부모객체가 먼저생성되고 자식객체가 올라탄다.
	//IsA::CarIsATestMain();
	//HierarchyIsA::CarIsATestMain();

	//IsA::RadioTestMain();
	RadioHasA::RadioTestMain();
}
