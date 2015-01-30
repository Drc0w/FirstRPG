#include "weapon.h"

using namespace std;

Weapon::Weapon()
	:weaponName("Hands"), weaponDamages(5), weaponLevel(0)
{

}

Weapon::Weapon(const string name, const int damages, const int level) 
	:weaponName(name), weaponDamages(damages), weaponLevel(level)
{

}

Weapon::Weapon(const Weapon &src) 
	:weaponName(src.Name()), weaponDamages(src.Damages()), weaponLevel(src.Level())
{

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

struct list<Weapon>* ListOfWeapon()
{
	struct list<Weapon> *weapons = NULL;
	Weapon *weapon = new Weapon("Dagounette", 10, 1);
	weapons = ListAdd(weapon, weapons);
	weapon = new Weapon("Arme2", 20, 2);
	weapons = ListAdd(weapon, weapons);
	ListRemoveAt(1, weapons);
	return weapons;
}
