#include "fight.h"

using namespace std;

void PrintInformations(const Personnage *main, const Personnage *ennemy)
{
	cout << main->Name() << " is fighting agaisnt " << ennemy->Name() << endl;
	Weapon *mainw = main->GetWeapon();
	cout << main->Name() << " uses " << mainw->Name() << " and deals " << mainw->Damages() << endl;
	Weapon *ennw = ennemy->GetWeapon();
	cout << ennemy->Name() << "  uses " << ennw->Name() << " and deals " << ennw->Damages() << endl;
	cout << main->Name() << " has " << main->RemainingLife() << "HP left" << endl;
	cout << ennemy->Name() << "has " << ennemy->RemainingLife() << "HP left" << endl;
}

void Fight(Personnage *main, Personnage *ennemy)
{
	system("clear");
	cout << "Un " << ennemy->Name() << " apparait !" << endl;
	cout << main->Name() << " en avant !" << endl;
	do
	{
		if (main->IsAlive())
		{
			cout << endl;
			cout << "What do you wanna do?" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Show info" << endl;
			int answer;
			cin >> answer;
			bool ctinue = false;
			do
			{
				switch (answer)
				{
					case 1:
						system("clear");
						main->Attack(ennemy);
						break;

					case 2:
						system("clear");
						PrintInformations(main, ennemy);
						break;

					default:
						cin >> answer;
						ctinue = true;
						break;
				}

			} while(ctinue);
		}
		if (ennemy->IsAlive())
		{
			ennemy->Attack(main);
		}
	} while(main->IsAlive() && ennemy->IsAlive());
}