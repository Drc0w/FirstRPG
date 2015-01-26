#include <iostream>
#include "personnage/personnage.h"
#include "personnage/weapon.h"
#include "personnage/potion.h"

using namespace std;

int main()
{
	Personnage *me, *him;
	me = new Personnage("PHP");
	him = new Personnage("Test");
	me->Attack(*him);
	Potion potionoflife("Potion de vie", 200);
	him->DrinkPotion(potionoflife);
	me->ChangeWeapon("Epée de la mort qui tue", 150);
	me->Attack(*him);
	delete me;
	delete him;
	return 0;
}
