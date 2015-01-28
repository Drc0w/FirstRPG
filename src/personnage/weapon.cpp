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
