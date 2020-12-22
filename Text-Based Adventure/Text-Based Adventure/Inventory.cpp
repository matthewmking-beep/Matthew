#include "Inventory.h"
#include "Item.h"

//invArray[] = IronSwordCreator();

std::vector <std::string> inv;

void Inventory() {

	inv.push_back(IronSwordCreator().name);
	inv.push_back(RustyShieldCreator().name);

	for (int i = 0; i < inv.size(); i++)
	{
		std::cout << inv[i] << std::endl;

	}
}