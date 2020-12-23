#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "Character.h"

class EnvironmentObject
{
public:
	int identifier;
	std::string moveableLocations[3];
	std::string description;
	std::string interactable[5];
	NpcObject NPCList[3];
	std::string puzzleSolution;
	std::string monsterList[4];
	itemObject pickUpItem;
	bool pickedUp;

	EnvironmentObject();
	~EnvironmentObject();
};

EnvironmentObject TownCreator();
EnvironmentObject ForestCreator();
EnvironmentObject CastleCreator();