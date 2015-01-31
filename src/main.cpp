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
	cout << "Enter the name of your character: ";
	string name;
	cin >> name;
	cout << endl;
	Personnage *mainChar = new Personnage(name);
	return mainChar;
}

int main()
{
	Personnage *me = CreateMainCharacter();
	FightManager(me);
	delete me;
	return 0;
}
