/***********************************************************
 ** File:    Goblin.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for the child class goblin
 **********************************************************/

#include "Goblin.h"
const int MAX_DAMAGE = 2;

// Name: Goblin() - Default Constructor
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin() {
  SetName("");
  SetHealth(0);
}
// Name: Goblin(string name, int hp)
// Description: Creates a new goblin
// Preconditions: None
// Postconditions: Can create a goblin
Goblin::Goblin(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}
// Name: SpecialAttack
// Description: Defines the Goblin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Goblin::SpecialAttack() {
  cout << " knaws at your ankles!" << endl;
  return MAX_DAMAGE;
}
