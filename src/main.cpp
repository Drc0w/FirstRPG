#include <iostream>
#include "personnage/personnage.h"
#include "personnage/weapon.h"
#include "personnage/potion.h"
#include "fight/fight.h"

using namespace std;

int main()
{
	ClearConsole();
	cout << "Enter the name of your character: ";
	string name;
	cin >> name;
	cout << endl;
	Personnage *me, *him;
	me = new Personnage(name);
	me->ChangeWeapon(new Weapon("Epée de folie", 25));
	him = new Personnage("Gobelin");
	Fight(me, him);
	delete me;
	delete him;
	return 0;
}
