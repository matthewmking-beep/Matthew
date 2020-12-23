#include "Character.h"

std::string characterObject::talk()
{
	return script;
}

int characterObject::dealDamage()
{
	return stats.attack + inventory.equippedWeapon.effectValue; // add equipped weapon attack too
}

void characterObject::heal(int healing)
{
	stats.health += healing;
}

int characterObject::run()
{
	return 0;
}

void characterObject::levelUp()
{
	stats.level += 1;
}

characterObject::characterObject()
{
}

characterObject::~characterObject()
{
}

characterObject monsterCreateGoblin()
{
	characterObject goblin;
	goblin.stats.attack = 2;
	goblin.stats.health = 10;
	goblin.stats.defense = 0;
	goblin.stats.maxHealth = 10;
	goblin.stats.weak = -1;
	goblin.stats.exp = 2;
	goblin.stats.level = 1;
	return goblin;
}

characterObject monsterCreateLizardman()
{
	characterObject lizardman;
	lizardman.stats.health = 18;
	lizardman.stats.attack = 5;
	lizardman.stats.defense = 2;
	lizardman.stats.maxHealth = 18;
	lizardman.stats.weak = 1;
	return lizardman;
}

characterObject monsterCreateGrowler()
{
	characterObject growler;
	growler.stats.health = 25;
	growler.stats.attack = 10;
	growler.stats.defense = 5;
	growler.stats.maxHealth = 25;
	growler.stats.weak = 2;
	return growler;
}

characterObject monsterCreateGhost()
{
	characterObject ghost;
	ghost.stats.health = 15;
	ghost.stats.attack = 6;
	ghost.stats.defense = 0;
	ghost.stats.maxHealth = 15;
	ghost.stats.weak = 3;
	return ghost;
}

characterObject monsterCreateSpecter()
{
	characterObject specter;
	
	return specter;
}

characterObject monsterCreateDragon()
{
	characterObject dragon;

	return dragon;
}

//NPC Creators
NpcObject villagerCreator() 
{
	NpcObject villager;

	villager.name = "Villager";
	villager.introText = "Greetings traveller! Haven't seen you around these parts before.";
	villager.optionsClosed = false;
	villager.optionExplain = "Would you like this?";
	villager.optionYes = "Here ya go";
	villager.optionNo = "ok then";
	villager.GivenItem = FirecrackerCreator();
	villager.GivenUp = false;

	return villager;
}

NpcObject::NpcObject()
{
}
NpcObject::~NpcObject()
{
}