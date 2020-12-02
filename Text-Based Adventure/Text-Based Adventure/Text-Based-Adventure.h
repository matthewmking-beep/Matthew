#pragma once


#include <iostream>
#include <string>


//Variables
bool isPlaying;
bool isExploring;
bool hasWon;
std::string userCommand;

std::string exploringCommandList[9];
std::string fightingCommandList[5];

//Functions
void initialSetup();
void exploringCommands();
void fightingCommands();