#include "fight.h"

using namespace std;

void ClearConsole()
{
	#ifdef __WINDOWS__
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void PrintInformations(const Personnage *main, const Personnage *ennemy)
{
	cout << main->Name() << '(' << main->Level() << ')';
	cout << " is fighting against " << ennemy->Name() << '(' << ennemy->Level() << ')';
	cout << endl;
	Weapon *mainw = main->GetWeapon();
	cout << main->Name() << " uses " << mainw->Name() << " and deals " << mainw->Damages() << endl;
	Weapon *ennw = ennemy->GetWeapon();
	cout << ennemy->Name() << " uses " << ennw->Name() << " and deals " << ennw->Damages() << endl;
	cout << main->Name() << " has " << main->RemainingLife() << "HP left" << endl;
	cout << ennemy->Name() << " has " << ennemy->RemainingLife() << "HP left" << endl;
}


Weapon* ChooseWeapon(Personnage *mainChar, struct list<Weapon> *listofweapons)
{
	int listcount = ListCountElements(listofweapons);
	int show = 1;
	int current = 1;
	for (int i = 0; i < listcount; i++)
	{
		Weapon *weapon = ListElementAt(i, listofweapons);
		if (*(mainChar->GetWeapon()) != *weapon)
		{
			cout << (show)<< ". Name: " << weapon->Name();
			cout << "\tDamages: " << weapon->Damages();
			cout << "\tLevel required: Level " << weapon->Level();
			cout << endl;
			show++;
		}
		else
			current = i;
	}
	Weapon *charWeapon = mainChar->GetWeapon();
	cout << (show) << ". Keep " << charWeapon->Name();
	cout << "\tDamages: " << charWeapon->Damages();
	cout << "\tLevel required: Level " << charWeapon->Level();
	cout << endl;
	int choice;
	cin >> choice;
	if (choice > current && choice < listcount && choice > 0)
		return ListElementAt(choice, listofweapons);
	else if (choice <= current && choice > 0)
		return ListElementAt(choice - 1, listofweapons);
	else
		return NULL;
}

bool ChangeWeapon(Personnage *main, struct list<Weapon> *listofweapons)
{
	cout << "Which weapon do you want to use?" << endl;
	Weapon *new_weapon = ChooseWeapon(main, listofweapons);
	if (new_weapon != NULL)
		return main->ChangeWeapon(new_weapon);
	return false;

}

void Fight(Personnage *main, Personnage *ennemy, struct list<Weapon> *availableweapons)
{
	ClearConsole();
	cout << "Un " << ennemy->Name() << " apparait !" << endl;
	cout << main->Name() << " en avant !" << endl;
	do
	{
		int answer;
		bool changedweapon = false;
		if (main->IsAlive())
		{
			cout << endl;
			cout << "What do you wanna do?" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Show info" << endl;
			cout << "3. Change weapon" << endl;
			cin >> answer;
			bool ctinue = false;
			do
			{
				switch (answer)
				{
					case 1:
						ClearConsole();
						main->Attack(ennemy);
						break;

					case 2:
						ClearConsole();
						PrintInformations(main, ennemy);
						break;
					case 3:
						ClearConsole();
						changedweapon = ChangeWeapon(main, availableweapons);
						break;
					default:
						cin >> answer;
						ctinue = true;
						break;
				}

			} while(ctinue);
		}
		if (ennemy->IsAlive() && (answer == 1 || (answer == 3 && changedweapon)))
		{
			ennemy->Attack(main);
		}
	} while(main->IsAlive() && ennemy->IsAlive());
}

void FightManager(Personnage *mainChar)
{
	struct list<Weapon> *allweapons = ListOfWeapon();
	struct list<Weapon> *availableweapons = NULL;
	availableweapons = ListAdd(new Weapon(), availableweapons);
	availableweapons = ListAdd(ListElementAt(1, allweapons), availableweapons);
	do
	{
		Personnage *ennemy = new Personnage("Gobelin", 0);
		Fight(mainChar, ennemy, availableweapons);
		delete ennemy;
	} while(mainChar->IsAlive());

}
