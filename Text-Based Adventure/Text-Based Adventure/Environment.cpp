#pragma once
	
#include "Environment.h"


EnvironmentObject TownCreator() {
	EnvironmentObject Town;

	Town.identifier = 0;
	Town.description = "Welcome to the Town!";
//	Town.interactable = {	}//list of interactable places
	Town.moveableLocations;
	Town.NPCList;

	return Town;
}

EnvironmentObject::EnvironmentObject()
{
}

EnvironmentObject::~EnvironmentObject()
{
}
