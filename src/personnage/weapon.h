#ifndef ARME_H_
#define ARME_H_

#include <iostream>
#include <string>
#include "../list/list.h"

class Weapon
{
	public:

	Weapon();
	Weapon(const std::string name, const int damages, const int level);
	Weapon(const Weapon &src);
	std::string Name() const;
	int Damages() const;
	int Level() const;

	private:
	std::string weaponName;
	int weaponDamages;
	int weaponLevel;
};

struct list<Weapon>* ListOfWeapon();

#endif
