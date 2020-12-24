#pragma once
	
#include "Environment.h"


EnvironmentObject TownCreator() {
	EnvironmentObject Town;

	Town.identifier = 0;
	Town.moveableLocations[0] = "Town";
	Town.description = "Welcome to the Town!";
	Town.interactable[0] = "Tavern";
	Town.interactable[1] = "Smithy";
	Town.NPCList[0] = villagerCreator();
	Town.NPCList[1] = childCreator();
	Town.NPCList[2] = elderCreator();

	Town.pickUpItem = HealthPotCreator();
	Town.pickedUp = false;

	return Town;
}

EnvironmentObject ForestCreator() {
	EnvironmentObject Forest;

	Forest.identifier = 1;
	Forest.moveableLocations[1] = "Forest";
	Forest.description = "An eerie forest";
	Forest.interactable[0] = "Hollowed Tree";
	Forest.interactable[1] = "Hallowed Tree";
	Forest.interactable[2] = "Rock Formation";
	Forest.NPCList[0] = hunterCreator();
	Forest.NPCList[1] = FoxgirlCreator();
	Forest.NPCList[2] = MaskedboyCreator();
	Forest.puzzleSolution = "Whittled Key";
	Forest.monsterList[0] = "Goblin";
	Forest.monsterList[1] = "Wolf";
	
	Forest.pickUpItem = WhittledKeyCreator();
	Forest.pickedUp = false;

	return Forest;
}

EnvironmentObject CastleCreator() {
	EnvironmentObject Castle;

	Castle.identifier = 2;
	Castle.moveableLocations[2] = "Castle";
	Castle.description = "A looming castle ravaging the skyline";
	Castle.interactable[0] = "Great Hall";
	Castle.interactable[1] = "Chapel";
	Castle.interactable[2] = "Kitchen";
	Castle.interactable[3] = "Bed Chambers";
	Castle.interactable[4] = "Guardhouse";
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
