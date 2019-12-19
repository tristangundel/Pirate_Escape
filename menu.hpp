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
#ifndef MENU_HPP
#define MENU_HPP
#include <string>

class Menu
{
	private:
		int numOfOptions;
		std::string *optionsList;
		int userSelection;
	public:
		Menu();
		Menu(int, std::string *options);
		void printMenu();
		bool validateInput(std::string);
		void makeSelection();
		int getSelection();
		void setMenuOptions(int);
		void emptyMenuOptions();
};

#endif
