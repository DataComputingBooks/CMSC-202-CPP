/***********************************************************
 ** File:    Rogue.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class Rogue.
 **********************************************************/

#include "Rogue.h"
const int MAX_DAMAGE = 12;
const int MIN_DAMAGE = 2;

// Name: Rogue() - Default Constructor
  // Description: Creates a new rogue
  // Preconditions: None
  // Postconditions: Can create a rogue
Rogue::Rogue() {
  SetName("");
  SetHealth(0);
}

// Name: Rogue(string name, int hp)
// Description: Creates a new rogue
// Preconditions: None
// Postconditions: Can create a rogue
Rogue::Rogue(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: ~Rogue - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Rogue::~Rogue() {}

// Name: SpecialAttack
// Description: Defines the Rogue's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Rogue::SpecialAttack() {
  //returns damage from 2 to 12.
  int damage = (rand() % (MAX_DAMAGE - MIN_DAMAGE)) + MIN_DAMAGE;
  cout << " performs a sneak attack!" << endl;
  return damage;
}
