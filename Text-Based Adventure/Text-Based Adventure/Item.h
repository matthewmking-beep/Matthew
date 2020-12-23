#pragma once
#include <iostream>
#include <string>

class itemObject
{
public:
	int IDType;

/*				
				1 = Equipable Weapon
				2 = Equipable Armour
				3 = Healing Item
				4 = Damaging Item
				5 = Quest Item
*/	
	std::string name;
	int effectValue;	//value of effect depending on the item. ex, Stat boost, amount healed, QuestItem flags
	int value;			//value in gold

	itemObject();
	~itemObject();
};

	itemObject IronSwordCreator();
	itemObject RustyShieldCreator();
	itemObject HealthPotCreator();
	itemObject FirecrackerCreator();
	itemObject WhittledKeyCreator();