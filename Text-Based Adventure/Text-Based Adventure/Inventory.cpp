#include "Inventory.h"

//invArray[] = IronSwordCreator();

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