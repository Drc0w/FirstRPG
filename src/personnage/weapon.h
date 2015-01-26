#ifndef ARME_H_
#define ARME_H_

#include <iostream>
#include <string>

class Weapon
{
	public:

	Weapon();
	Weapon(const std::string name, const int damages);
	Weapon(const Weapon &src);
	std::string Name() const;
	int Damages() const;

	private:
	std::string weaponName;
	int weaponDamages;
};

#endif
