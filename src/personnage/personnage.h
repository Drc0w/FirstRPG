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
	Personnage(const std::string name, const int level);
	~Personnage();
	void TakeDamages(const int damages);
	void DrinkPotion(const Potion potion);
	bool ChangeWeapon(Weapon *weapon);
	void Attack(Personnage *cible);
	bool IsAlive() const;
	std::string Name() const;
	int RemainingLife() const;
	int Mana() const;
	int Experience() const;
	int Level() const;
	Weapon* GetWeapon() const;
	void WinExperience(const int xp);
	void LevelUp();

	private:

	std::string charName;
	int charLevel;
	int charExperience;
	int charMaxExperience;
	int charLife;
	int charMaxLife;
	int charMana;
	Weapon *charWeapon;
};

#endif
