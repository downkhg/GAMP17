#include "CarIsA.h"
#include "CarNotIsA.h"
#include "CarIiA_Hierarchy.h"
#include "RadioHasA.h"
#include "RadioIsA.h"

void main()
{
	//����� �ϴµ��� ������ �������� �κ��� �θ�� ���� ����Ѵ�.
	//�⺻������ Ŭ������ ������,
	//�����丵(�缳��)�� ���� ����ϱ� ���� �ڵ带 �������Ѵ�.
	//����� �ڵ差�� ��� ���ϱ�������, ������ ���迡�� ����Ǿ��Ҷ�,
	//������� �ذ�����ʴ� ����� �߰��Ȱ�� ������ �ſ��ƴ�.
	//�������̵�: �θ�ü���� �ڽ��� �Ҵ�Ǵ°�.

	//����� ���������� ����ü���� ���� �κ��� �ڵ带 �ۼ��ؾ��Ѵ�.
	//NotIsA::CarIsATestMain();
	//��ӵ� ��ü�� �θ�ü�� ���������ǰ� �ڽİ�ü�� �ö�ź��.
	//IsA::CarIsATestMain();
	//HierarchyIsA::CarIsATestMain();

	//IsA::RadioTestMain();
	RadioHasA::RadioTestMain();
}
