// Text-Based Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Text-Based-Adventure.h"



void initialSetup()
{
	isPlaying = true;
	isExploring = true;
	hasWon = false;
	userCommand = "list";
	
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
	fightingCommandList[3] = "run";
	fightingCommandList[4] = "endgame";

	//Create All Environments
	environmentArray [0] = TownCreator();
	currentEnvironment = 0;
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
	else if (userCommand == "inspect") //Inspects objects of interest
	{

	}
	else if (userCommand == "talk") //
	{

	}
	else if (userCommand == "move") //moves player to area
	{
		std::cout << "Where would you like to go?" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << environmentArray[currentEnvironment].moveableLocations[i] << std::endl;
		}
	}
	else if (userCommand == "inventory")
	{

	}
	else if (userCommand == "use")
	{

	}
	else if (userCommand == "equip")
	{

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
		std::cout << "Not a recognized command.  Input 'list' to list all commands.  Remember, all commands must be in all lowercase." << std::endl;
	}
}

void fightingCommands()
{
	if (userCommand == "list")
	{
		std::cout << "Here are all the available commands: " << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << fightingCommandList[i] << std::endl;
		}
	}
	else if (userCommand == "fight")
	{

	}
	else if (userCommand == "block")
	{

	}
	else if (userCommand == "run")
	{

	}
	else if (userCommand == "endgame")
	{
		isPlaying = false;
	}
	else
	{
		std::cout << "Not a recognized command.  Input 'list' to list all commands.  Remember, all commands must be in all lowercase." << std::endl;
	}
}

int main()
{
	//Sets up the locations and characters, etc.
	initialSetup();
	//Put opening blurb here.
	std::cout << "Welcome to 'The Castle of Mystery' text-based adventure.  In this game, you must solve puzzles, and battle monsters to try and find out what happened to the mysterious castle on the hill.\n" << std::endl;

	exploringCommands();

	do
	{
		std::cin >> userCommand;
		if (isExploring)
		{
			exploringCommands();
		}
		else
		{
			fightingCommands();
		}
	} while (isPlaying);

}
