#pragma once
#include <iostream>
#include <string>
#include "Item.h"

struct combatData
{
	int level;
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

