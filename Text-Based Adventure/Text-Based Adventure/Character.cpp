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
