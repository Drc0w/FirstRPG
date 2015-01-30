#include "potion.h"

using namespace std;

Potion::Potion(const string name, const int lifeeffect) 
{
	potionName = name;
	potionEffect = lifeeffect;
}

Potion::Potion(const Potion &src) 
{
	potionName = src.Name();
	potionEffect = src.Effect();
}

string Potion::Name() const
{
	return potionName;
}

int Potion::Effect() const
{
	return potionEffect;
}
