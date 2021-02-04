#pragma once

#include <iostream>
#include <vector>
using namespace std;
//������ ���� �𵨸��Ҷ��� ���������Ͽ� ����쳪.
//Ŀ����� ��ɿ� ���� �۵��ϴ°��� ����ϹǷ� ��������� ���Ҽ��ִ�.
class Unit
{
public:
	int x;
	int y;
	virtual void Attack(Unit* target)
	{
		cout << typeid(*this).name() << "Attack" << endl;
	}
	virtual void Move(int x, int y)
	{
		cout << typeid(*this).name() << "Move:" << x << "," << y << endl;
	}
	virtual void SkillA(Unit* target)
	{
		cout << "SkillA" << endl;
	}
	virtual void SkillB(Unit* target)
	{
		cout << "SkillB" << endl;
	}
	virtual void SkillC(Unit* target)
	{
		cout << "SkillC" << endl;
	}
};

class Marin : public Unit
{
	void SkillA(Unit* unit) override
	{
		cout << "Active StillPack" << endl;
	}
};

class Medic : public Unit
{
	void Attack(Unit* unit) override
	{
		Move(unit->x, unit->y);
	}

	void SkillA(Unit* unit) override
	{
		cout << "Active Hill" << endl;
	}

	void SkillB(Unit* unit) override
	{
		cout << "Recovery" << endl;
	}
};

class Commader
{

	vector<Unit*> group;
public:
	enum E_COMMAND { ATK, MOV };

	void AddGroup(Unit* unit)
	{
		group.push_back(unit);
	}

	bool RemvoeGroup(Unit* unit)
	{
		vector<Unit*>::iterator it;
		for (it = group.begin(); it != group.end(); it++)
		{
			if (&unit == &(*it))
				break;
		}
		if (it != group.end())
		{
			group.erase(it);
			return true;
		}
		return false;
	}
	//�δ뿡 ����� ������ ���
	void Command(E_COMMAND command, Unit* target)
	{
		switch (command)
		{
		case E_COMMAND::ATK:
			for (int i = 0; i < group.size(); i++)
				group[i]->Attack(target);
			break;
		case E_COMMAND::MOV:
			for (int i = 0; i < group.size(); i++)
				group[i]->Move(10, 10);
			break;
		default:
			break;
		}
	}
};

void main()
{
	Commader cCommder;
	Marin marins[10];
	Medic medics[10];

	for (int i = 0; i < 10; i++)
		cCommder.AddGroup(&marins[i]);

	for (int i = 0; i < 10; i++)
		cCommder.AddGroup(&medics[i]);

	cCommder.Command(Commader::E_COMMAND::ATK, &marins[0]);
}