#include <iostream>
#include "personnage.h"

using namespace std;

Personnage::Personnage(const string name) 
	:charName(name), charLife(100), charMaxLife(100), charMana(100), charLevel(1), charExperience(0)
{
	charWeapon = new Weapon();
}

Personnage::Personnage(const string name, const int level)
	:charName(name), charLevel(level), charExperience(0)
{
	charMaxLife = 100;
	for (int i = 0; i < level; i++)
	{
		charMaxLife *= 1.10;
	}
	charMana = charMaxLife;
	charLife = charMaxLife;
	charWeapon = new Weapon();
}

Personnage::Personnage(const Personnage &src) 
	:charName(src.Name()), charLife(src.RemainingLife()), charMaxLife(100), charMana(src.Mana()), 
	charLevel(src.Level()), charExperience(src.Experience())
{
	Weapon *weapon = src.GetWeapon();
	charWeapon = new Weapon(weapon->Name(), weapon->Damages(), weapon->Level());
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

/*
void Personnage::ChangeWeapon(const std::string new_name, const int new_damages)
{
	charWeapon = new Weapon(new_name, new_damages);
	cout << charName << " changed his weapon: " << charWeapon->Name();
	cout << ", damages: " << charWeapon->Damages() << endl;
}
*/

void Personnage::ChangeWeapon(Weapon *weapon)
{
	if (weapon->Level() <= charLevel)
	{
		charWeapon = weapon;
		cout << charName << " changes his weapon: " << charWeapon->Name();
		cout << ", damages: " << charWeapon->Damages() << endl;
	}
	else
	{
		cout << charName << " can't equip this weapon. " << charName; 
		cout << " doesn't have the required level" << endl;
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

int Personnage::Experience() const
{
	return charExperience;
}

int Personnage::Level() const
{
	return charLevel;
}

int Personnage::Mana() const
{
	return charMana;
}

int Personnage::RemainingLife() const
{
	return charLife;
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

Weapon* Personnage::GetWeapon()  const
{
	return charWeapon;
}

Personnage::~Personnage()
{
	delete charWeapon;
}
