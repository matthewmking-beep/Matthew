#include "Inventory.h"

std::vector <itemObject> inv;

void StartInv() {
	inv.push_back(IronSwordCreator());
	inv.push_back(RustyShieldCreator());
}

void Inventory() {
	for (int i = 0; i < inv.size(); i++)
	{
		std::cout << inv[i].name << std::endl;
	}
}

void AddItem(itemObject item) {
	inv.push_back(item);
}

void UseItem(itemObject item) {
	std::cout << item.name << " used" << std::endl;

	for (int i = 0; i < inv.size(); i++)
	{
		if (inv[i].name == item.name)
		{
			inv.erase(inv.begin() + i);
		}
	}
	//inv.erase(inv.begin() + i);
}

void EquipItem(int i) {
	std::cout << inv[i].name << " equipped" << std::endl;
}

std::vector <itemObject> ReturnItems() {
	return inv;
}