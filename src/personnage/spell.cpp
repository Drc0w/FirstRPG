#include "spell.h"

using namespace std;

Spell::Spell()
{
	spellName = "Aucun sort";
	spellAction = 0;    //Par défaut, il n'y a aucun sort actif
}

Spell::Spell(const string name, const int action) 
{
	spellName = name;
	spellAction = action;
}

Spell::Spell(const Spell &src) 
{
	spellName = src.Name();
	spellAction = src.Action();
}

string Spell::Name() const
{
	return spellName;
}

int Spell::Action() const
{
	return spellAction;
}

struct list<Spell>* ListOfSpell()
{
	struct list<Spell> *spells = NULL;
	spells = ListAdd(new Spell(), spells);
	spells = ListAdd(new Spell("Defense killer", 1), spells); //Fait perdre un niveau d'amélioration de défense de l'ennemi
	spells = ListAdd(new Spell("Half weapon damage", 2), spells);   //Réduit l'efficacité destructice d'une arme par deux pendant un tour
	spells = ListAdd(new Spell("Curse", 3), spells);    //Empêche l'usage des sorts pendant un tour
	spells = ListAdd(new Spell("Last chance", 4), spells);  //Sort activable seulement quand le joueur a moins de 15% de vie. Ce sort permet voler 10% de vie sur l'autre joueur (néanmoins si l'autre joueur a moins 20% il peut contrer le sort et ne perdre que 5% de vie)
	return spells;
}
