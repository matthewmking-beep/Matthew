#pragma once
	
#include "Text-Based-Adventure.h"

<<<<<<< Updated upstream
class Environment
{
public:
	int identifier;
	std::string description;
	int interactable[5];
	int moveableLocations[3];
	int NPCList;
	int puzzleSolution;
	int monsterList;
};
=======
>>>>>>> Stashed changes


EnvironmentObject TownCreator() {
	EnvironmentObject Town;

	Town.identifier = 0;
	Town.description = "Welcome to the Town!";
//	Town.interactable = {	}//list of interactable places
	Town.moveableLocations;
	Town.NPCList;

	return Town;
}