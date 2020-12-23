#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Character.h"
#include "Environment.h"
#include "Inventory.h"
#include "Item.h"
#include "Quest.h"
using namespace std;


//Variables
bool isPlaying;
bool isExploring;
bool hasWon;
std::string userCommand;

//Command lists
std::string exploringCommandList[10];
std::string fightingCommandList[6];

//Environment Array
EnvironmentObject environmentArray[5];
int currentEnvironment;

//Player Character
characterObject Player;

//Monster Array
characterObject monsterList[6];

characterObject currentMonster;

//Combat Variables
bool playerIsBlocking;
bool monsterIsBlocking;

int expAmountArray[10];

//Functions
void initialSetup();
void setupPlayer();
void startCombat(characterObject monster);
void enemyAI();
void exploringCommands();
void fightingCommands();
void endCombat();