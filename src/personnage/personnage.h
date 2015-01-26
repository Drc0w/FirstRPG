#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <iostream>
#include "weapon.h"
#include "potion.h"
#include <string>

class Personnage
{
	public:

	Personnage(const std::string name);
	Personnage(const Personnage &src);
	void TakeDamages(const int damages);
	void DrinkPotion(const Potion potion);
	void ChangeWeapon(const std::string name, const int damages);
	void ChangeWeapon(Weapon weapon);
	void Attack(Personnage &cible);
	bool IsAlive() const;
	std::string Name() const;
	int RemainingLife() const;
	int Mana() const;
	Weapon GetWeapon() const;

	private:

	std::string charName;
	int charMaxLife;
	int charLife;
	int charMana;
	Weapon charWeapon;
};
#endif
