#pragma once
#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

struct combatData
{
	int level;
	int exp;
	int maxHealth;
	int health;
	int attack;
	int defense;
	int weak;
};

struct stuff
{
	itemObject equipmentList[10];
	itemObject itemList[10];
	itemObject questItemList[10];
	itemObject equippedWeapon;
	itemObject equippedArmour;
	int gold;
};

class characterObject
{
public:
	int idType;		//0 for Player, 1 for NPC, 2 for Enemy
	std::string name;
	combatData stats;
	stuff inventory;
	std::string script;

	//Returns script
	std::string talk();
	int dealDamage();
	void heal(int healing);
	int run();
	void levelUp();

	characterObject();
	~characterObject();

};

//Creating the monsters
characterObject monsterCreateGoblin();
characterObject monsterCreateLizardman();
characterObject monsterCreateGrowler();
characterObject monsterCreateGhost();
characterObject monsterCreateSpecter();
characterObject monsterCreateDragon();

//NPC class
class NpcObject
{
public:
	std::string name;
	std::string introText;
	bool optionsClosed;
	std::string optionExplain;
	std::string optionYes;
	std::string optionNo;
	itemObject GivenItem;
	bool GivenUp;

	NpcObject();
	~NpcObject();
};
NpcObject villagerCreator();
NpcObject childCreator();
NpcObject elderCreator();