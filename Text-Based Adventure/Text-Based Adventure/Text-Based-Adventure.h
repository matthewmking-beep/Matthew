#pragma once
#include <iostream>
#include <string>
#include "Character.h"
#include "Environment.h"
#include "Item.h"
#include "Quest.h"


//Variables
bool isPlaying;
bool isExploring;
bool hasWon;
std::string userCommand;

//Command lists
std::string exploringCommandList[10];
std::string fightingCommandList[5];

//Environment Array
EnvironmentObject environmentArray[5];
int currentEnvironment;

//Player Character
characterObject Player;

//Monster Array
characterObject monsterList[10];

//Functions
void initialSetup();
void exploringCommands();
void fightingCommands();