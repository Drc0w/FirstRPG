#include "weapon.h"

using namespace std;

Weapon::Weapon()
{
	weaponName = "Hands";
	weaponDamages = 5;
	weaponLevel = 0;
}

Weapon::Weapon(const string name, const int damages, const int level) 
{
	weaponName = name;
	weaponDamages = damages;
	weaponLevel = level;
}

Weapon::Weapon(const Weapon &src) 
{
	weaponName = src.Name();
	weaponDamages = src.Damages();
	weaponLevel = src.Level();
}

string Weapon::Name() const
{
	return weaponName;
}

int Weapon::Damages() const
{
	return weaponDamages;
}

int Weapon::Level() const
{
	return weaponLevel;
}

bool operator==(const Weapon weapon1, const Weapon weapon2)
{
	return (weapon1.Name() == weapon2.Name() 
		&& weapon1.Damages() == weapon2.Damages()
		&& weapon1.Level() == weapon2.Level());
}

bool operator!=(const Weapon weapon1, const Weapon weapon2)
{
	return !(weapon1 == weapon2);
}

struct list<Weapon>* ListOfWeapon()
{
	struct list<Weapon> *weapons = NULL;
	weapons = ListAdd(new Weapon(), weapons);
	weapons = ListAdd(new Weapon("Dague", 10, 1), weapons);
	weapons = ListAdd(new Weapon("Epée", 15, 2), weapons);
	weapons = ListAdd(new Weapon("Axe", 20, 3), weapons);
	weapons = ListAdd(new Weapon("Mace", 25, 4), weapons);
	return weapons;
}
