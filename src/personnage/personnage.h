#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <string>
#include <iostream>
#include "weapon.h"
#include "potion.h"
#include "spell.h"

#define CLASS int
#define Warrior 0
#define Wizzard 1

class Personnage
{
	public:

	Personnage(const std::string name, const CLASS type);
	Personnage(const Personnage &src);
	Personnage(const std::string name, const int level, const CLASS type);
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
	CLASS Class() const;
	Weapon* GetWeapon() const;
	Spell* GetSpell() const;
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
	CLASS charClass;
	Weapon *charWeapon;
	Spell *charSpell;
};

#endif
