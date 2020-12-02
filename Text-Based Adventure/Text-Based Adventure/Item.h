#pragma once
#include <iostream>
#include <string>

class itemObject
{
public:
	int IDType;
	/*
		ID Key:
		1 = Equipable Weapon
		2 = Equipable Armour
		3 = Healing Item
		4 = Damaging Item
		5 = Quest Item
	*/
	std::string name;
	int useData;		//Has various uses, depending on the item.  Stat boost, amount healed, QuestItem flags
	int value;			//value in gold

	itemObject();
	~itemObject();
};