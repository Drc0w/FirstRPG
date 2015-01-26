#include "weapon.h"

using namespace std;

Weapon::Weapon(const string name, const int damages) 
	:weaponName(name), weaponDamages(damages)
{

}

Weapon::Weapon(const Weapon &src) 
	:weaponName(src.Name()), weaponDamages(src.Damages())
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
