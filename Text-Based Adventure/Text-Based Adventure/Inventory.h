#pragma once
//#include <iostream>
//#include <string>
#include <vector>
#include "Item.h"

//std::vector <itemObject> inv;

void StartInv();
void Inventory();
void AddItem(itemObject);
void UseItem(int);
void EquipItem(int);

std::vector <itemObject> ReturnItems();