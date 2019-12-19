/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 09/19/2019
** Description: This file is one of 23 files that together form a
**              program with the capability of running a single player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include "menu.hpp"
#include <string>
#include <iostream>

// Default constructor for a Menu object
Menu::Menu()
{
	numOfOptions = 2;
	std::string options[2];
	options[0] = "Start";
	options[1] = "End";
	setMenuOptions(2);
	for (int i=0; i<numOfOptions; i++)
	{
		optionsList[i] = options[i];
	}
}

// Constructor for a Menu object with custom list of options
Menu::Menu(int numbers, std::string *options)
{
	setMenuOptions(numbers);   // assign number of menu options
	numOfOptions = numbers;
	for (int i=0; i<numbers; i++)      // assign each item in options array to the optionsList array
	{
		optionsList[i] = options[i];
	}
}

// public function to assign optionsList of custom length to a Menu object
// in order to reuse Menu objects and assign them new options lists
void Menu::setMenuOptions(int num)
{
	optionsList = new std::string[num];
}

// function to delete dynamically allocated memory for the list of options
void Menu::emptyMenuOptions()
{
	delete [] optionsList;
}

// function to print out menu options available to the user
void Menu::printMenu()
{
	std::cout << "\nPlease choose from one of the following options:\n\n " << std::endl;
	for (int i=1; i<=numOfOptions; i+=1)       // loop through options and print each one
	{
		int index = i-1;
		std::cout << i << ". ";
		std::cout << optionsList[index] << std::endl;
	}
	std::cout <<"\n\n";
}

// function to validate that user's selection is within menu options range
bool Menu::validateInput(std::string selection)
{
	bool validInput = false;
	for (int i=1; i<=numOfOptions; i+=1)
	{
		if (selection == (std::to_string(i)))
		{
			validInput = true;
		}
	}
	return validInput;
}

// function to prompt user to make a selection from the menu
void Menu::makeSelection()
{
	// user prompt to make a selection from previously printed options
	std::string selection;
	std::cout << "Please enter the number of the menu option you'd like to select." << std::endl;
	std::cin >> selection;

	// validate user input
	if (!(validateInput(selection)))
	{
		std::cout << "That is not a valid menu option, please select a valid option." << std::endl;
	}
	while (!(validateInput(selection)))  // loop user input until valid choice is entered
	{
		std::cin.clear();
		std::getline(std::cin, selection);
		std::cout << std::endl;
	}
	userSelection = std::stoi(selection);   //convert string to integer and set as current user selection
}

// funtion top return latest user menu selection
int Menu::getSelection()
{
	return userSelection;
}
