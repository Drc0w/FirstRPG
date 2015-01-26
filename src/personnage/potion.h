#ifndef POTION_H_
#define POTION_H_

#include <string>
#include <iostream>

class Potion
{
	public:

	Potion(const std::string name, const int lifeeffect);
	Potion(const Potion &src);
	std::string Name() const;
	int Effect() const;

	private:

	std::string potionName;
	int potionEffect;
};

#endif
