#pragma once
#include <iostream>
#include <string>
#include "Item.h"

class questObject
{
public: 
	//List of guides to what has happened/hint on what to do next.
	std::string description[10];
	
	//The flag system will be activated when quest objectives are done.  The objectives will look for this quest, and add 1 to the flag counter.
	int flags;
	int requiredFlags;
	int rewardXP;

	void questComplete();
};