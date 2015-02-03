#include "spell.h"

using namespace std;

Spell::Spell()
{
	spellName = "Petite boule de feu";
	spellAction = TRUEDMG;
	spellDamages = 5;
	//Par défaut il y a un sort actif qui fait 5 de dégâts, comme pour les armes
}

Spell::Spell(const string name, const ACTION action, const int level)
{
	//Par défaut, pas de dégâts si pas spécifiés
	spellName = name;
	spellAction = action;
	spellDamages = 0;
	spellLevel = level;
}

Spell::Spell(const string name, const ACTION action, const int damages, const int level) 
{
	spellName = name;
	spellAction = action;
	spellDamages = damages;
	spellLevel = level;
}

Spell::Spell(const Spell &src) 
{
	spellName = src.Name();
	spellAction = src.Action();
	spellDamages = src.Damages();
	spellLevel = src.Level();
}

string Spell::Name() const
{
	return spellName;
}

ACTION Spell::Action() const
{
	return spellAction;
}

int Spell::Damages() const
{
	return spellDamages;
}

int Spell::Level() const
{
	return spellLevel;
}

struct list<Spell>* ListOfSpell()
{
	struct list<Spell> *spells = NULL;
	spells = ListAdd(new Spell(), spells);
	spells = ListAdd(new Spell("Defense killer", ARMORDMG, 1), spells); 
	//Fait perdre un niveau d'amélioration de défense de l'ennemi
	spells = ListAdd(new Spell("Half weapon damage", WEAPONDMG, 2), spells);   
	//Réduit l'efficacité destructice d'une arme par deux pendant un tour
	spells = ListAdd(new Spell("Curse", BLOCKSPELL, 3), spells);    
	//Empêche l'usage des sorts pendant un tour
	spells = ListAdd(new Spell("Last chance", LIFESTEAL, 4), spells);  
	//Sort activable seulement quand le joueur a moins de 15% de vie. Ce sort permet voler 10% de vie sur l'autre joueur (néanmoins si l'autre joueur a moins 20% il peut contrer le sort et ne perdre que 5% de vie)
	spells = ListAdd(new Spell("Heal", HEAL, 5, 100), spells);
	//Dans ce cas, il faudra gérer les dégâts comme un bonus de vie !
	//Pour le LIFESTEAL, il faudra voir comment gérer ça aussi
	return spells;
}

bool operator==(Spell spell1, Spell spell2)
{
	return spell1.Action() == spell2.Action()
		&& spell1.Name() == spell2.Name();
}
