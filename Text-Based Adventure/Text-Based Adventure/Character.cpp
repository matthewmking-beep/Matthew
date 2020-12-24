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

	villager.name = "villager";
	villager.introText = "Greetings traveller! Haven't seen you around these parts before";
	villager.optionsClosed = false;
	villager.optionExplain = "Would you like this?";
	villager.optionYes = "Here ya go";
	villager.optionNo = "ok then";
	villager.GivenItem = FirecrackerCreator();
	villager.GivenUp = false;

	return villager;
}

NpcObject childCreator() {
	NpcObject child;

	child.name = "girl";
	child.introText = "Hiya adventurer! Are you off to kill the dragon at the Castle!? Good luck!";
	child.optionsClosed = true;

	return child;
}

NpcObject elderCreator() {
	NpcObject elder;

	elder.name = "elder";
	elder.introText = "Ahh, a mighty warrior here to slay the dragon, eh? For the sake of the town, I wish you the best of luck";
	elder.optionsClosed = false;
	elder.optionExplain = "it is dangerous to go alone; here, take this";
	elder.optionYes = "the lands beyond the gates are filled with evil monsters and spirits";
	elder.optionNo = "No? We have a daring one here, don't we?";
	elder.GivenItem = SteelSwordCreator();
	elder.GivenUp = false;

	return elder;
}

NpcObject hunterCreator() {
	NpcObject hunter;

	hunter.name = "hunter";
	hunter.introText = "Watch your step soldier, I got traps everywhere";
	hunter.optionsClosed = false;
	hunter.optionExplain = "I found this while hunting, but it's not really my style. You can have it if you want";
	hunter.optionYes = "there's one less thing slowing me down";
	hunter.optionNo = "hmm, I guess I could see if I can salvage it or something...";
	hunter.GivenItem = FirecrackerCreator();
	hunter.GivenUp = false;

	return hunter;
}

NpcObject FoxgirlCreator() {
	NpcObject foxgirl;

	foxgirl.name = "foxgirl";
	foxgirl.introText = "Welcome to the Wilds weary scout, what can I~ do for you~ today?";
	foxgirl.optionsClosed = false;
	foxgirl.optionExplain = "Follow me! Let's go play in my cave; I have a nice~ surprise waiting for you!";
	foxgirl.optionYes = "Hehehee, what an obedient person you are. I always love~ new playthings...\nYou wake up the next day deposed on the side of the trail. Thankfully, none of your equipment was stolen.";
	foxgirl.optionNo = "Why do you have to be so mean!?\nBefore you can try to comfort her from crying, she scurries off into the depths of the forest";
	foxgirl.GivenItem = sickness();
	foxgirl.GivenUp = false;

	return foxgirl;
}

NpcObject MaskedboyCreator() {
	NpcObject maskedboy;

	maskedboy.name = "maskedboy";
	maskedboy.introText = "You almost smell like that fairy boy who taught me that song long ago...";
	maskedboy.optionsClosed = false;
	maskedboy.optionExplain = "I disposed of that fairy boy long ago after he crushed my hopes and dreams, but I think his death was too swift; I should have crushed him with the moon or something... What's this? Are you scared of me?";
	maskedboy.optionYes = "Rightfully so! Did you think you stood a chance agaisnt me as I am now!? FOOL!!!\nYou wake up at dusk with a splitting headache.";
	maskedboy.optionNo = "Don't speak to me like that! You... you stupid fairy!";
	maskedboy.GivenItem = tattoo();
	maskedboy.GivenUp = false;

	return maskedboy;
}

NpcObject::NpcObject()
{
}
NpcObject::~NpcObject()
{
}