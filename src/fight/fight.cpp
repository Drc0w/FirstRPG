#include "fight.h"

using namespace std;

void Fight(Personnage *main, Personnage *ennemy)
{
	system("clear");
	do
	{
		if (main->IsAlive())
		{
			cout << "What do you wanna do?" << endl;
			cout << "1. Attack" << endl;
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
