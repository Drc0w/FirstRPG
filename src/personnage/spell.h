#ifndef SPELL_H_
#define SPELL_H_

#include <iostream>
#include <string>
#include "../list/list.h"

#define ACTION int
#define TRUEDMG 0
#define ARMORDMG 1
#define WEAPONDMG 2
#define BLOCKSPELL 3
#define LIFESTEAL 4
#define HEAL 5

class Spell
{
	public:

	Spell();
	Spell(const std::string name, const ACTION action, const int level, const int manacost);
	Spell(const std::string name, const ACTION action, const int damages, const int level, 
		const int manacost);
	Spell(const Spell &src);
	std::string Name() const;
	ACTION Action() const;
	int Damages() const;
	int Level() const;
	int Manaost() const;

	private:
	std::string spellName;
	ACTION spellAction;
	int spellDamages;
	int spellLevel;
	int spellMana;
};

struct list<Spell>* ListOfSpell();

bool operator==(Spell spell1, Spell spell2);

#endif
