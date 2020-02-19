/***********************************************************
 ** File:    BabyDragon.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the child class code for baby dragon.
 **********************************************************/

#include "BabyDragon.h"
const int MAX_DAMAGE = 4;

// Name: BabyDragon() - Default Constructor
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon() {
  SetName("");
  SetHealth(0);
}

// Name: Baby Dragon(string name, int hp)
// Description: Creates a new baby dragon
// Preconditions: None
// Postconditions: Can create a baby dragon
BabyDragon::BabyDragon(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: SpecialAttack
// Description: Defines the Baby Dragon's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int BabyDragon::SpecialAttack() {
  cout << " breaths a cone of fire at you!" << endl;
  return MAX_DAMAGE;
}
