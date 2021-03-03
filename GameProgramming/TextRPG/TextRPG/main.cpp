#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	void operator+=(const int value)
	{
		this->nHP += value;
		this->nMP += value;
		this->nStr += value;
		this->nDef += value;
		this->nInt += value;
	}
	Status operator+(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP + status.nHP;
		sResult.nMP = nMP + status.nMP;
		sResult.nStr = nStr + status.nStr;
		sResult.nDef = nDef + status.nDef;
		sResult.nInt = nInt + status.nInt;
		return sResult;
	}
	Status operator-(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP - status.nHP;
		sResult.nMP = nMP - status.nMP;
		sResult.nStr = nStr - status.nStr;
		sResult.nDef = nDef - status.nDef;
		sResult.nInt = nInt - status.nInt;
		return sResult;
	}
	void Show()
	{
		cout << "HP:" << nHP << endl;
		cout << "MP:" << nMP << endl;
		cout << "STR:" << nStr << endl;
		cout << "INT:" << nInt << endl;
		cout << "DEF:" << nDef << endl;
	}
};

class Effect
{
	virtual void Use(Player& caster, Player& target) = 0;
};

class Hill : public Effect
{
	void Use(Player& caster, Player& target)
	{
		 target.GetStatus().nHp += caster.GetStatus().nInt;
	}
};

class Attack : public Effect
{
	void Use(Player& caster, Player& target)
	{
		target.GetStatus().nHp -= caster.GetStatus().nStr;
	}
};

class Skill
{
	vector<Effect*> listEffect;
	void AddEffect(Effect* effect)
	{
		listEffect.push_back(effect);
	}
	virtual void Ative(Player& caster, Player& Target) = 0;
};

class HoliAttack : public Skill
{
	void Ative(Player& caster, Player& target)
	{
		for(int i = 0; listEffect.size(); i++)
			listEffect[i]->Use(caster, target);
	}
};

class EffectHill : public Skill
{
	void Ative(Player& caster, Player& Target)
	{

	}
};

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, POTION, THROW };
	E_ITEM_KIND eItemKind;
	string strName;
	string strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = THROW, string name = "none", string comment = "none", Status status = Status(), int gold = 0)
	{
		Set(kind, name, comment, status, gold);
	}
	void Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
	{
		eItemKind = kind;
		strName = name;
		strComment = comment;
		sFuction = status;
		nGold = gold;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager()
	{
		/*m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "목검", "데미지증가", Status(0, 0, 10, 0, 0), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "본소드", "데미지증가", Status(0, 0, 20, 0, 0), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "나무갑옷", "방어력증가", Status(0, 0, 0, 10, 0), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "본아머", "방어력증가", Status(0, 0, 0, 20, 0), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "나무반지", "체력증가", Status(10,0,0,0,0), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "해골반지", "체력증가", Status(20, 0, 0, 0, 0), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, "힐링포션", "HP회복", Status(100, 0, 0, 0, 0), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, "마나포션", "MP회복", Status(0,100, 0, 0, 0), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, "짱돌", "단일적대미지", Status(0, 0, 50, 0, 0), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, "목검", "다수적대미지", Status(0, 0, 50, 0, 0), 100);*/
		//SaveFile();
		LoadFile();
	}

	void SaveFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "wt");
		if (pFile)
		{
			fprintf(pFile, "%d\n", m_listItems.size());
			vector<Item>::iterator it = m_listItems.begin();
			for (; it != m_listItems.end(); it++)
			{
				Item sItem = *(it);
				fprintf(pFile, "%d,%s,%s,%d,%d,%d,%d,%d\n", sItem.eItemKind, sItem.strName.c_str(), sItem.strComment.c_str(), sItem.nGold,
					sItem.sFuction.nHP, sItem.sFuction.nMP, sItem.sFuction.nStr, sItem.sFuction.nInt, sItem.sFuction.nDef);
			}
			fclose(pFile);
		}
		else
			cout << " Save Failed!" << endl;
	}

	void LoadFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "rt");
		if (pFile)
		{
			int nSize;
			fscanf(pFile, "%d", &nSize);

			for (int i = 0; i < nSize; i++)
			{
				char strTemp[1024];
				fscanf(pFile, "%s\n", strTemp);
				cout << strTemp << endl;
				char  arrStrs[8][128];
				char* strTemps = strtok(strTemp, ",");
				int idx = 0;
				while (strTemps != NULL)
				{
					//memcpy(arrStrs[idx], strTemps, 128);
					strcpy(arrStrs[idx], strTemps);
					cout << arrStrs[idx] << ",";
					//cout << strTemps << ",";
					strTemps = strtok(NULL, ",");
					idx++;
				}
				cout << endl;
				string name = arrStrs[1];
				string info = arrStrs[2];
				Item sItem((Item::E_ITEM_KIND)atoi(arrStrs[0]), name, info,
					Status(atoi(arrStrs[4]), atoi(arrStrs[5]), atoi(arrStrs[6]), atoi(arrStrs[7])),
					atoi(arrStrs[3]));
				m_listItems.push_back(sItem);
			}
			fclose(pFile);
		}
		else
			cout << " Save Failed!" << endl;
	}
	Item* GetItem(int idx)
	{
		return &m_listItems[idx];
	}
};

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
	vector<Skill*> m_listSkills;
public:
	Player()
	{
		m_listEqument.resize(3);
	}

	void SetIventory(Item* item)
	{
		m_listIventory.push_back(item);
	}
	Item* GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}

	bool UseItem(int idx)
	{
		Item* pItem = GetIventoryIdx(idx);

		if (pItem->eItemKind == Item::E_ITEM_KIND::THROW)
			return false;

		int nIdx = pItem->eItemKind;
		m_listEqument[nIdx] = pItem;
		m_sStatus = m_sStatus + pItem->sFuction;
		DeleteIventory(idx);

		return true;
	}

	void ReleaseEqument(int idx)
	{
		Item* pItem = m_listEqument[idx];
		m_sStatus = m_sStatus - pItem->sFuction;
		SetIventory(pItem);
	}

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
	{
		m_strName = strName;
		m_sStatus.nHP = _hp;
		m_sStatus.nMP = _mp;
		m_sStatus.nStr = _str;
		m_sStatus.nInt = _int;
		m_sStatus.nDef = _def;
		m_nExp = _exp;
		m_nLv = 1;
	}
	void Attack(Player& taget)
	{
		taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
	}
	void StillItem(Player& taget)
	{
		//타겟이 가지고 있는 아이템 중 첫번째 아이템을 뺏어오고,
		//타겟의 경험치를 가져와서 내 경험치에 올린다.
		this->SetIventory(taget.GetIventoryIdx(0));
		taget.DeleteIventory(0);
		this->m_nExp = taget.m_nExp;
	}
	bool Buy(Player& target, int idx)
	{
		Item* item = target.GetIventoryIdx(idx);
		if (item->nGold <= m_nGold)
		{
			SetIventory(item);
			m_nGold -= item->nGold;
			return true;
		}
		return false;
	}
	void Sell(int idx)
	{
		Item* item = GetIventoryIdx(idx);
		DeleteIventory(idx);
		m_nGold += item->nGold;
	}
	bool LvUp()
	{
		//만약 경험치가 100 이상되면, 레벨+1, 모든 능력치 10증가, 경험치 초기화.
		if (m_nExp >= 100)
		{
			m_sStatus += 10;
			m_nLv++;
			m_nExp -= 100;
			return true;
		}
		return false;
	}

	bool Dead()
	{
		if (m_sStatus.nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		m_sStatus.Show();
		cout << "######### Equment #########" << endl;
		for (int i = 0; i < m_listEqument.size(); i++)
			if (m_listEqument[i])
				cout << i << ":" << m_listEqument[i]->strName << endl;
			else
				cout << i << ": null" << endl;
		cout << "######### Inventory ######### " << endl;
		for (int i = 0; i < m_listIventory.size(); i++)
			cout << i << ":" << m_listIventory[i]->strName << endl;
	}
};

class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	void Init()
	{
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::STONE));
		m_cShop.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::BOOM));

		m_cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
		m_cMonster.SetIventory(m_cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	}

	void EventCreate()
	{
		string name;
		cout << "케릭터 이름을 입력하세요!:";
		cin >> name;
		m_cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
		m_eStage = E_STAGE::TOWN;
	}
	void EventInvetory()
	{
		m_cPlayer.Show();
		int nSelect;
		cout << "메뉴를 선택하세요!(1: 아이템사용. 2: 장비해제 etc: 마을):";
		cin >> nSelect;
		if (nSelect == 1)
		{
			cout << "사용할 아이템을 구하세요!:";
			cin >> nSelect;
			if (!m_cPlayer.UseItem(nSelect))
				cout << "사용할수없습니다!" << endl;
		}
		else if (nSelect == 2)
		{
			cout << "장비해제할 장비함에서 선택하세요!:";
			cin >> nSelect;
			m_cPlayer.ReleaseEqument(nSelect);
		}
		else
			m_eStage = E_STAGE::TOWN;
	}
	void EventShop()
	{
		m_cShop.Show();
		int nInput;
		cout << "상점입니다. 무엇을 하시겠습니까? 1: 구매, 2: 팔기, etc:마을";
		cin >> nInput;
		switch (nInput)
		{
		case 1:
		{
			cout << "구매할 아이템을 목록에서 선택하세요! -1:마을";
			cin >> nInput;
			if (nInput != -1)
				m_cPlayer.Buy(m_cShop, nInput);
			else
				m_eStage = E_STAGE::TOWN;
		}
		break;
		case 2:
		{
			m_cPlayer.Show();
			cout << "판매할 아이템을 목록에서 선택하세요! -1:마을";
			cin >> nInput;
			if (nInput != -1)
				m_cPlayer.Sell(nInput);
			else
				m_eStage = E_STAGE::TOWN;
		}
		break;
		default:
		{
			m_eStage = E_STAGE::TOWN;
		}
		break;
		}
	}
	void EventTown()
	{
		const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

		cout << "마을 입니다." << endl;
		cout << "어디로 가시겠습니까?" << endl;
		for (int i = E_STAGE::CRATE + 1; i < E_STAGE::BATTLE; i++)
			cout << i << ":" << strStageName[i] << ",";
		cin >> m_eStage;
	}
	void EventFiled()
	{
		const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
		int nSelect;
		cout << "어디로 가시겠습니까?";
		for (int i = 0; i < E_MONSTER::MON_MAX; i++)
			cout << i << ":" << strMonsterName[i] << ",";
		cin >> nSelect;
		switch (nSelect)
		{
		case E_MONSTER::SILME:
			m_cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
			break;
		case E_MONSTER::SKELETON:
			m_cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
			break;
		case E_MONSTER::BOSS:
			m_cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
			break;
		}
		m_eStage = E_STAGE::BATTLE;
	}
	void EventBattle()
	{
		if (m_cPlayer.Dead() == false)
			m_cPlayer.Attack(m_cMonster);
		else
		{
			m_eStage = GAME_OVER;
		}
		m_cMonster.Show();
		if (m_cMonster.Dead() == false)
			m_cMonster.Attack(m_cPlayer);
		else
		{
			m_cPlayer.StillItem(m_cMonster);
			if (m_cPlayer.LvUp())
				cout << "랩업!" << endl;
			m_eStage = TOWN;
		}
	}

	void Update()
	{
		switch (m_eStage)
		{
		case E_STAGE::CRATE:
			EventCreate();
			break;
		case E_STAGE::IVNETORY:
			EventInvetory();
			break;
		case E_STAGE::SHOP:
			EventShop();
			break;
		case E_STAGE::TOWN:
			EventTown();
			break;
		case E_STAGE::FILED:
			EventFiled();
			break;
		case E_STAGE::BATTLE:
			EventBattle();
			break;
		case E_STAGE::GAME_OVER:
			printf("GAME\OVER");
			break;
		case E_STAGE::THE_END:
			printf("THE EMD");
			break;
		default:
			break;
		}
	}

	int GetStage()
	{
		return m_eStage;
	}

	Status GetStatus()
	{
		return m_sStatus;
	}
private:
	int m_eStage = E_STAGE::CRATE;

	ItemManager m_cItemManager;
	Player m_cPlayer;
	Player m_cMonster;
	Player m_cShop;
};

//상점을 플레이를 이용하여 만들어보기. //사기,팔기
void main()
{
	GameManager cGameManager;
	cGameManager.Init();
	while (cGameManager.GetStage() != GameManager::E_STAGE::EXIT)
	{
		cGameManager.Update();
	}
}