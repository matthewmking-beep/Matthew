#pragma once
#include <iostream>
#include <string>

class EnvironmentObject
{
public:
	int identifier;
	std::string moveableLocations[3];
	std::string description;
	std::string interactable[5];
	std::string NPCList[3];
	std::string puzzleSolution;
	std::string monsterList[4];

	EnvironmentObject();
	~EnvironmentObject();
};

EnvironmentObject TownCreator();
EnvironmentObject ForestCreator();
EnvironmentObject CastleCreator();