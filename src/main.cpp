#include <iostream>
#include "personnage/personnage.h"
#include "personnage/weapon.h"
#include "personnage/potion.h"
#include "fight/fight.h"
#include "list/list.h"

using namespace std;

Personnage* CreateMainCharacter()
{
	ClearConsole();
	cout << "+--------------------+" << endl;
	cout << "|   Choose a class   |" << endl;
	cout << "+--------------------+" << endl;
	cout << "1. Warrior\t2.Wizzard" << endl;
	int type;
	cin >> type;
	if (type == 2)
		type = 1;
	else
		type = 0;
	cout << "Enter the name of your character: ";
	string name;
	cin >> name;
	cout << endl;
	Personnage *mainChar = new Personnage(name, type);
	return mainChar;
}

int menu()
{
	ClearConsole();
	cout << "+--------------------+" << endl;
   	cout << "|   First RPG Beta   |" << endl;
    	cout << "|   --------------   |" << endl;
    	cout << "|     By  Dr_c0w     |" << endl;
    	cout << "+--------------------+" << endl;
	cout << "Welcome, what's next : " << endl;
	cout << "1)  Start new game" << endl;
    	cout << "2)  Load saved game" << endl;
    	cout << "3)  Tutorial" << endl;
    	cout << "4)  Quit" << endl;
    	int choice;
	cin >> choice;
    	return choice;
}

int main()
{
	Personnage *me;
    	switch(menu())
    	{
        	case 1:
        	    me = CreateMainCharacter();
		    FightManager(me);
		    delete me;
        	    break;
        	case 2:
        	    cout << "New feature soon..." << endl;
        	    break;
        	case 3:
        	    cout << "New feature soon..." << endl;
        	    break;
        	case 4:
        	    cout << "Hope you had a great time, see you soon ;-)" << endl;
        	    break;
    	}
    	return 0;
}
