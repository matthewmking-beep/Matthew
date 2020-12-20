#include "Character.h"

std::string characterObject::talk()
{
	return script;
}

int characterObject::dealDamage()
{
	return stats.attack; // add equipped weapon attack too
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
	characterObject
}

characterObject monsterCreateSpecter()
{

}

characterObject monsterCreateDragon()
{

}