#ifndef SPELL_H_
#define SPELL_H_

#include <iostream>
#include <string>
#include "../list/list.h"

class Spell
{
	public:

	Spell();
	Spell(const std::string name, const int action);
	Spell(const Spell &src);
	std::string Name() const;
	int Spell() const;

	private:
	std::string spellName;
	int spellAction;
};

struct list<Spell>* ListOfSpell();

#endif
