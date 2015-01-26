#include <iostream>
#include "personnage.h"

using namespace std;

Personnage::Personnage(const string name) 
	:charName(name), charLife(100), charMaxLife(100), charMana(100), charWeapon("Hands", 5)
{

}

Personnage::Personnage(const Personnage &src) 
	:charName(src.Name()), charLife(src.RemainingLife()), charMaxLife(100), charMana(src.Mana()), charWeapon(src.GetWeapon())
{

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

void Personnage::ChangeWeapon(const std::string new_name, const int new_damages)
{
	Weapon weapon(new_name, new_damages);
	charWeapon = weapon;
	cout << charName << " changes his weapon: " << charWeapon.Name() << ", damages: " << charWeapon.Damages() << endl;
}

void Personnage::ChangeWeapon(const Weapon weapon)
{
	charWeapon = weapon;
	cout << charName << " changes his weapon: " << charWeapon.Name() << ", damages: " << charWeapon.Damages() << endl;
}

void Personnage::Attack(Personnage &cible)
{
	cout << charName + " attacks " + cible.Name() + " with " + charWeapon.Name() << endl;
	cible.TakeDamages(charWeapon.Damages());
	if (cible.IsAlive())
	{
		cout << "The ennemy has " << cible.RemainingLife() << " HP left" << endl;
	}
	else
	{
		cout << charName <<" killed " << cible.Name() << endl;
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

int Personnage::Mana() const
{
	return charMana;
}

int Personnage::RemainingLife() const
{
	return charLife;
}

Weapon Personnage::GetWeapon()  const
{
	return charWeapon;
}
