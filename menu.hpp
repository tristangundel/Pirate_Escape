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
