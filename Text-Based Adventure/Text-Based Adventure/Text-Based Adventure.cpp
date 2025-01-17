// Text-Based Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Text-Based-Adventure.h"


void setupPlayer()
{
	//Setting Up Stats
	Player.stats.level = 1;
	Player.stats.attack = 1;
	Player.stats.defense = 1;
	Player.stats.exp = 0;
	Player.stats.maxHealth = 10;
	Player.stats.health = 10;
}

void initialSetup()
{
	isPlaying = true;
	isExploring = true;
	hasWon = false;
	userCommand = "list";

	playerIsBlocking = false;
	monsterIsBlocking = false;

	srand(time(0));
	
	//All exploring commands
	exploringCommandList[0] = "list";
	exploringCommandList[1] = "look";
	exploringCommandList[2] = "inspect";
	exploringCommandList[3] = "talk";
	exploringCommandList[4] = "move";
	exploringCommandList[5] = "inventory";
	exploringCommandList[6] = "use";
	exploringCommandList[7] = "equip";
	exploringCommandList[9] = "quest";
	exploringCommandList[8] = "endgame";
	

	//All fighting commands
	fightingCommandList[0] = "list";
	fightingCommandList[1] = "attack";
	fightingCommandList[2] = "block";
	fightingCommandList[3] = "item";
	fightingCommandList[4] = "run";
	fightingCommandList[5] = "endgame";

	//Set Exp Goals

	//Create All Environments
	environmentArray[0] = TownCreator();
	environmentArray[1] = ForestCreator();
	environmentArray[2] = CastleCreator();
//	currentEnvironment = 0;
	currentEnvironment = environmentArray->identifier;

	//Create All Monsters
	monsterList[0] = monsterCreateGoblin();
	monsterList[1] = monsterCreateLizardman();
	monsterList[2] = monsterCreateGrowler();
	monsterList[3] = monsterCreateGhost();
	monsterList[4] = monsterCreateSpecter();
	monsterList[5] = monsterCreateDragon();

	//Create Inventory setup
	StartInv();

	//Set up player stats
	setupPlayer();
}

void startCombat(characterObject monster)
{
	isExploring = false;
	currentMonster = monster;
}

void enemyAI()
{
	//Okay, so the enemy can do 3 actions, block, attack, or use their ability.
}

bool endCombat()
{
	if (currentMonster.stats.health <= 0)
	{
		cout << "You have defeated the monster!  You gain " + to_string(currentMonster.stats.level) + " exp points." << endl;

		//exp and level up
		Player.stats.exp += currentMonster.stats.exp;
		if (Player.stats.exp >= expAmountArray[Player.stats.level - 1])
		{
			Player.stats.exp -= expAmountArray[Player.stats.level - 1];
			Player.levelUp();
			cout << "You've leveled up!  Your attack has increased to " + to_string(Player.stats.attack) + " and your defense has increased to " + to_string(Player.stats.defense) + "." << endl;
		}
		isExploring = true;
		return true;
	}
	return false;
}

void exploringCommands()
{
	//I realize now that I cannot use a switch statement for strings... I am sad...
	if (userCommand == "list")
	{
		std::cout << "Here are all the available commands: " << std::endl;
		for (int i = 0; i < 9; i++)
		{
			std::cout << exploringCommandList[i] << std::endl;
		}
	}
	else if (userCommand == "look") //Describes Area
	{
		std::cout << environmentArray[currentEnvironment].description << std::endl;
	}
	else if (userCommand == "inspect") //Inspects and picks up objects of interest
	{
		std::cout << "You look around and find a ";

		if (environmentArray[currentEnvironment].pickedUp == false)
		{
			AddItem(environmentArray[currentEnvironment].pickUpItem);
			environmentArray[currentEnvironment].pickedUp = true;

			std::cout << environmentArray[currentEnvironment].pickUpItem.name << std::endl;
		}
		else
		{
			std::cout << "plain old leaf; nothing of value" << std::endl;
		}
	}
	else if (userCommand == "talk") //Talks to NPC
	{
		cout << "Who would you like to talk to?" << endl;
		for (int i = 0; i < (sizeof(environmentArray[currentEnvironment].NPCList)/sizeof(environmentArray[currentEnvironment].NPCList[0])); i++)
		{
			cout << environmentArray[currentEnvironment].NPCList[i].name << endl;
		}

		cin >> userCommand;

		for (int i = 0; i < (sizeof(environmentArray[currentEnvironment].NPCList) / sizeof(environmentArray[currentEnvironment].NPCList[0])); i++)
		{
			if (userCommand == environmentArray[currentEnvironment].NPCList[i].name)
			{
				cout << environmentArray[currentEnvironment].NPCList[i].introText << endl;
				if (environmentArray[currentEnvironment].NPCList[i].optionsClosed == false)
				{
					std::cout << environmentArray[currentEnvironment].NPCList[i].optionExplain << "\n(yes or no?)" << endl;

					std::cin >> userCommand;
					if (userCommand == "yes")
					{
						AddItem(environmentArray[currentEnvironment].NPCList[i].GivenItem);

						std::cout << environmentArray[currentEnvironment].NPCList[i].optionYes << std::endl;
						std::cout << "You received a " << environmentArray[currentEnvironment].NPCList[i].GivenItem.name << endl;

						environmentArray[currentEnvironment].NPCList[i].GivenUp = true;
						environmentArray[currentEnvironment].NPCList[i].optionsClosed = true;
					}
					else
					{
						std::cout << environmentArray[currentEnvironment].NPCList[i].optionNo << endl;
					}
				}
			}
		}
	}
	else if (userCommand == "move") //moves player to area
	{
		std::cout << "Where would you like to go?" << std::endl;
		for (int i = 0; i < (sizeof(environmentArray[currentEnvironment].moveableLocations)/sizeof(environmentArray[currentEnvironment].moveableLocations[0])); i++)
		{
			std::cout << environmentArray[i].moveableLocations[i] << std::endl;
		}

		std::cin >> userCommand;

		for (int i = 0; i < (sizeof(environmentArray[currentEnvironment].moveableLocations) / sizeof(environmentArray[currentEnvironment].moveableLocations[0])); i++)
		{
			if (userCommand == environmentArray[i].moveableLocations[i])
			{
				currentEnvironment = i;
			}
		}

		std::cout << "You go to the " << environmentArray[currentEnvironment].moveableLocations[currentEnvironment] << std::endl;
	}
	else if (userCommand == "inventory")	//opens inventory list
	{
		Inventory();
	}
	else if (userCommand == "use")
	{
		std::cout << "Which item would you like to use?" << endl;

		for (int i = 0; i < ReturnItems().size(); i++)		//lists useable items
		{
			if (ReturnItems()[i].IDType == 3 || ReturnItems()[i].IDType == 4 || ReturnItems()[i].IDType == 5)
			{
				std::cout << ReturnItems()[i].name << std::endl;
			}
		}

		std::cin >> userCommand;

		for (int i = 0; i < ReturnItems().size(); i++)		//compares user input to items
		{
			if (userCommand.compare(ReturnItems()[i].name) == 0)
			{
				if (ReturnItems()[i].IDType == 3 || ReturnItems()[i].IDType == 4 || ReturnItems()[i].IDType == 5)
				{
					UseItem(ReturnItems()[i]);

					break;
				}
			}
		}
	}
	else if (userCommand == "equip")
	{
		std::cout << "Which item would you like to equip?" << endl;

		for (int i = 0; i < ReturnItems().size(); i++)		//lists equipable items
		{
			if (ReturnItems()[i].IDType == 1 || ReturnItems()[i].IDType == 2)
			{
				std::cout << ReturnItems()[i].name << std::endl;
			}
		}
/*
		std::cin >> userCommand;

		for (int i = 0; i < ReturnItems().size(); i++)
		{
			if (userCommand.compare(ReturnItems()[i].name))
			{
				if (ReturnItems()[i].IDType == 1 || ReturnItems()[i].IDType == 2)
				{
					EquipItem(i);
				}
			}
		}
*/
	}
	else if (userCommand == "quest")
	{

	}
	else if (userCommand == "endgame")
	{
		isPlaying = false;
	}
	else
	{
		std::cout << "Not a recognized command.  Input 'list' to list all commands.  Remember, all commands are case sensitive." << std::endl;
	}
}

void fightingCommands()
{
	playerIsBlocking = false;

	if (userCommand == "list")
	{
		std::cout << "Here are all the available commands: " << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << fightingCommandList[i] << std::endl;
		}
		return;  //Don't want the enemy attacking just because the player asked on what to do.
	}
	else if (userCommand == "fight")
	{
		int damage = -Player.dealDamage();
		if (monsterIsBlocking)
		{
			damage = damage / 2;
		}
		currentMonster.heal(damage);

		if (endCombat())
		{
			return;
		}

		cout << "You dealt " + to_string(damage) + " points of damage!  The monster is at " + to_string(currentMonster.stats.health) + "health points." << endl;

	}
	else if (userCommand == "block")
	{
		cout << "You ready yourself for a blow.  Damage is halved." << endl;
		playerIsBlocking = true;
	}
	else if (userCommand == "run")
	{
		int chance = (Player.stats.level - currentMonster.stats.level);
		int success = rand() % 10;
		if ((chance + success) > 5 || chance > 4)
		{
			cout << "You gave the monster the slip!  No exp though..." << endl;
			isExploring = true;
		}
	}
	else if (userCommand == "item")
	{
		cout << "What item would you like to use?" << endl;

		Inventory();

		cin >> userCommand;
		//Meant to look through items, check if it's combat, and then use and delete if so.
		for (int i = 0; i < ReturnItems().size(); i++)
		{
			if (ReturnItems()[i].name == userCommand)
			{
				switch (ReturnItems()[i].IDType)
				{
				case 3:
					Player.heal(ReturnItems()[i].effectValue);
					cout << "You heal " + to_string(ReturnItems()[i].effectValue) + "health points.  Your health is now " + to_string(Player.stats.health) + "." << endl;
					break;
				case 4:
					currentMonster.heal(-ReturnItems()[i].effectValue);
					if (endCombat())
					{
						return;
					}
					cout << "The monster takes " + to_string(ReturnItems()[i].effectValue) + "damage.  It's health is now " + to_string(currentMonster.stats.health) + "." << endl;
					break;
				default:
					cout << "This item is not a combat item.  It cannot be used" << endl;
					return;
					break;
				}
			}
		}
	}
	else if (userCommand == "endgame")
	{
		isPlaying = false;
		return;	//No sense in making them wait
	}
	else
	{
		cout << "Not a recognized command.  Input 'list' to list all commands.  Remember, all commands are case sensitive." << endl;
		return;	//Don't want the enemy attacking for a mistype
	}

	enemyAI();
}

int main()
{
	//Sets up the locations and characters, etc.
	initialSetup();
	//Put opening blurb here.
	cout << "Welcome to 'The Castle of Mystery' text-based adventure.  In this game, you must solve puzzles, and battle monsters to try and find out what happened to the mysterious castle on the hill.\n" << endl;

	exploringCommands();

	do
	{
		cin >> userCommand;
		if (isExploring)
		{
			exploringCommands();
		}
		else
		{
			fightingCommands();
		}
	} while (isPlaying);

	if (hasWon = true)
	{
		cout << "Congratulations on winning the game!  You have solved the mystery of the castle!" << endl;
		system("pause");
	}
}
