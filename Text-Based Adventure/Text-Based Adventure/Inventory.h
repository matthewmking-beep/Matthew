#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

void StartInv();
void Inventory();
void AddItem(itemObject);
void UseItem();

std::vector <itemObject> ReturnItems();