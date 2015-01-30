#ifndef FIGHT_H_
#define FIGHT_H_

#include <iostream>
#include <string>
#include "../personnage/personnage.h"
#include "../personnage/weapon.h"
#include <cstdlib>

void ClearConsole();
void Fight(Personnage *main, Personnage *ennemy);
void PrintListWeapon(struct list<Weapon> *listofweapons);

#endif
