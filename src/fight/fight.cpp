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
	cout << main->Name() << " is fighting against " << ennemy->Name() << endl;
	Weapon *mainw = main->GetWeapon();
	cout << main->Name() << " uses " << mainw->Name() << " and deals " << mainw->Damages() << endl;
	Weapon *ennw = ennemy->GetWeapon();
	cout << ennemy->Name() << " uses " << ennw->Name() << " and deals " << ennw->Damages() << endl;
	cout << main->Name() << " has " << main->RemainingLife() << "HP left" << endl;
	cout << ennemy->Name() << " has " << ennemy->RemainingLife() << "HP left" << endl;
}

void Fight(Personnage *main, Personnage *ennemy)
{
	ClearConsole();
	cout << "Un " << ennemy->Name() << " apparait !" << endl;
	cout << main->Name() << " en avant !" << endl;
	cout << "Test de changement d'arme avec un niveau top élevé" << endl;
	main->ChangeWeapon(new Weapon("Epée de ouf !!", 195, 20));
	cout << "Test de changement d'arme avec un niveau correct" << endl;
	main->ChangeWeapon(new Weapon("Dagounette", 10, 1));
	do
	{
		int answer;
		if (main->IsAlive())
		{
			cout << endl;
			cout << "What do you wanna do?" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Show info" << endl;
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

					default:
						cin >> answer;
						ctinue = true;
						break;
				}

			} while(ctinue);
		}
		if (ennemy->IsAlive() && answer != 2)
		{
			ennemy->Attack(main);
		}
	} while(main->IsAlive() && ennemy->IsAlive());
}
