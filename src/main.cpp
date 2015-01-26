#include <iostream>
#include "personnage/personnage.h"
#include "personnage/weapon.h"
#include "personnage/potion.h"

using namespace std;

int main()
{
	Personnage me("PHP"), him("Test");
	me.Attack(him);
	Potion potionoflife("Potion de vie", 200);
	him.DrinkPotion(potionoflife);
	Weapon new_weapon("Epée de la mort qui tue", 100);
	me.ChangeWeapon(new_weapon);
	me.Attack(him);
	return 0;
}
