#pragma once
#include "Text-Based-Adventure.h"

class EnvironmentObject
{
public:
	int identifier;
	int interactable[5];
	int moveableLocations[3];
	int NPCList;
	int puzzleSolution;
	int monsterList;
};