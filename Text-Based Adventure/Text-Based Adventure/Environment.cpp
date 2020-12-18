#pragma once
	
#include "Environment.h"


EnvironmentObject TownCreator() {
	EnvironmentObject Town;

	Town.identifier = 0;
	Town.description = "Welcome to the Town!";
//	Town.interactable = {}//list of interactable places
	Town.moveableLocations[0] = "Tavern";
	Town.moveableLocations[1] = "Smithy";
	Town.NPCList[0] = "Villager";
	Town.NPCList[1] = "Elder";
	Town.NPCList[2] = "Child";

	return Town;
}

EnvironmentObject ForestCreator() {
	EnvironmentObject Forest;

	Forest.identifier = 1;
	Forest.description = "An eerie forest";
//	Forest.interactable = {	}//list of interactable places
	Forest.moveableLocations[0] = "Hollowed Tree";
	Forest.moveableLocations[1] = "Hallowed Tree";
	Forest.moveableLocations[2] = "Rock Formation";
	Forest.NPCList[0] = "Mysterious Hunter";
	Forest.puzzleSolution = "Whittled Key";
	Forest.monsterList[0] = "Goblin";
	Forest.monsterList[1] = "Wolf";
	
	return Forest;
}

EnvironmentObject CastleCreator() {
	EnvironmentObject Castle;

	Castle.identifier = 2;
	Castle.description = "A looming castle ravaging the skyline";
//	Castle.interactable = { }////list of interactable places
	Castle.moveableLocations[0] = "Great Hall";
	Castle.moveableLocations[1] = "Chapel";
	Castle.moveableLocations[2] = "Kitchen";
	Castle.moveableLocations[3] = "Bed Chambers";
	Castle.moveableLocations[4] = "Guardhouse";
	Castle.puzzleSolution = "Demonic Key";
	Castle.monsterList[0] = "Skeleton";
	Castle.monsterList[1] = "Imp";
	Castle.monsterList[2] = "Orc";
	Castle.monsterList[3] = "Giant Spider";

	return Castle;
}

EnvironmentObject::EnvironmentObject()
{
}

EnvironmentObject::~EnvironmentObject()
{
}
