#include "Item.h"

/*
Item ID Key
1 = Weapon
2 = Armour
3 = Healing Item
4 = Damage Item
5 = Quest Item
*/

itemObject IronSwordCreator() {
	itemObject IronSword;

	IronSword.IDType = 1;
	IronSword.name = "Iron Sword";
	IronSword.effectValue = 3; //does 3 damage
	IronSword.value = 5;

	return IronSword;
}

itemObject RustyShieldCreator() {
	itemObject RustyShield;

	RustyShield.IDType = 2;
	RustyShield.name = "Rusty Shield";
	RustyShield.effectValue = 3; //blocks 3 damage
	RustyShield.value = 2;

	return RustyShield;
}

itemObject HealthPotCreator() {
	itemObject HealthPot;

	HealthPot.IDType = 3;
	HealthPot.name = "Health Potion";
	HealthPot.effectValue = 10;	//restores 10 hp
	HealthPot.value = 4;

	return HealthPot;
}

itemObject FirecrackerCreator() {
	itemObject Firecracker;

	Firecracker.IDType = 4;
	Firecracker.name = "Firecracker";
	Firecracker.effectValue = 10;	//does 10 damage
	Firecracker.value = 8;

	return Firecracker;
}

itemObject WhittledKeyCreator() {
	itemObject WhittledKey;

	WhittledKey.IDType = 5;
	WhittledKey.name = "Whittled Key";

	return WhittledKey;
}

itemObject SteelSwordCreator() {
	itemObject SteelSword;

	SteelSword.IDType = 1;
	SteelSword.name = "Steel Sword";
	SteelSword.effectValue = 10; //does 10 damage
	SteelSword.value = 15;

	return SteelSword;
}

itemObject sickness() {
	itemObject sickness;

	sickness.name = "sore back and a grumpy morning walk";

	return sickness;
}

itemObject tattoo() {
	itemObject tattoo;

	tattoo.name = "funny drawing on your arm";

	return tattoo;
}

itemObject::itemObject()
{
}
itemObject::~itemObject()
{
}
