#include <iostream>
#include "personnage.h"

using namespace std;

Personnage::Personnage(const string name, const CLASS type) 
{
	charName = name;
	charLevel = 1;
	charExperience = 0;
	charMaxExperience = 100;
	charLife = 100;
	charMaxLife = 100;
	charMana = 100;
	charClass = type;
	charWeapon = new Weapon();
	charSpell = new Spell();
}

Personnage::Personnage(const string name, const int level, const CLASS type)
{
	charName = name;
	charLevel = level;
	charExperience = 0;
	charMaxExperience = 100;
	charMaxLife = 100;
	for (int i = 0; i < charLevel; i++)
	{
		charMaxLife *= 1.10;
		charMaxExperience *= 1.50;
	}
	charMana = charMaxLife;
	charLife = charMaxLife;
	charWeapon = new Weapon();
	charClass = type;
}

Personnage::Personnage(const Personnage &src) 
{
	charName = src.Name();
	charLife = src.RemainingLife();
	charMaxLife = 100;
	charExperience = src.Experience();
	charMaxExperience = 100;
	for (int i = 0; i < charLevel; i++)
	{
		charMaxLife *= 1.10;
		charMaxExperience *= 1.50;
	}
	charMana = src.Mana();
	charWeapon = new Weapon(*(src.GetWeapon()));
	charSpell = new Spell(*(src.GetSpell()));
	charClass = src.Class();
}

Personnage::~Personnage()
{
	delete charWeapon;
	delete charSpell;
}

void Personnage::TakeDamages(const int damages)
{
	charLife -= damages;
	if (charLife < 0)
		charLife = 0;
}

void Personnage::DrinkPotion(const Potion potion)
{
	cout << charName << " drinks " << potion.Name() << endl;
	string effect;
	if (potion.Effect() > 0)
		effect = " increased";
	else
		effect = " decreased";
	cout << charName << "'s life" << effect << " by " << potion.Effect() <<  endl;
	charLife += potion.Effect();
	if (charLife > charMaxLife)
		charLife = charMaxLife;
	else if (charLife < 0)
		charLife = 0;
}

bool Personnage::ChangeWeapon(Weapon *weapon)
{
	if (weapon->Level() <= charLevel)
	{
		charWeapon = weapon;
		cout << charName << " changes his weapon: " << charWeapon->Name();
		cout << ", damages: " << charWeapon->Damages() << endl;
		return true;
	}
	else
	{
		cout << charName << " can't equip this weapon. " << charName; 
		cout << " doesn't have the required level" << endl;
		return false;
	}
}

void Personnage::Attack(Personnage *cible)
{
	cout << charName + " attacks " + cible->Name() + " with " + charWeapon->Name() << endl;
	cible->TakeDamages(charWeapon->Damages());
	if (cible->IsAlive())
	{
		cout << cible->Name() <<"  has " << cible->RemainingLife() << " HP left" << endl;
	}
	else
	{
		cout << charName <<" killed " << cible->Name() << endl;
	}
}

bool Personnage::IsAlive() const
{
	return charLife > 0;
}

string Personnage::Name() const
{
	return charName;
}

int Personnage::RemainingLife() const
{
	return charLife;
}

int Personnage::Mana() const
{
	return charMana;
}

int Personnage::Experience() const
{
	return charExperience;
}

int Personnage::Level() const
{
	return charLevel;
}

CLASS Personnage::Class() const
{
	return charClass;
}

Weapon* Personnage::GetWeapon()  const
{
	return charWeapon;
}

Spell* Personnage::GetSpell() const
{
	return charSpell;
}
void Personnage::WinExperience(const int xp)
{
	cout << charName << " wins " << xp << " XP" << endl;
	charExperience += xp;
	LevelUp();
}

void Personnage::LevelUp()
{
	if (charExperience >= charMaxLife)
	{
		int nblv = charExperience / charMaxLife;
		charExperience %= charMaxLife;
		charLevel += nblv;
		for (int i = 0; i < nblv; i++)
		{
			charMaxLife *= 1.10;
			charLife *= 1.50;
			charMana *= 1.50;
		}
			cout << Name() << " has reached level " << charLevel << endl;
	}
}
