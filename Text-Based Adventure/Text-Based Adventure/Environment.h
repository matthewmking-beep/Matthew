#pragma once
#include <iostream>
#include <string>

class EnvironmentObject
{
public:
	int identifier;
	int interactable[5];
	int moveableLocations[3];
	int NPCList;
	int puzzleSolution;
	int monsterList;
	std::string description;


	EnvironmentObject();
	~EnvironmentObject();
};

EnvironmentObject TownCreator();