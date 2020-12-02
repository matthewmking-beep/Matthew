#pragma once
#include <iostream>
#include <string>
#include "Character.h"


//Variables
bool isPlaying;
bool isExploring;
bool hasWon;
std::string userCommand;

//Command lists
std::string exploringCommandList[9];
std::string fightingCommandList[5];

//Environment Array
//Environment environmentArray[5];
int currentEnvironment;

//Functions
void initialSetup();
void exploringCommands();
void fightingCommands();