/***********************************************************
 ** File:    Paladin.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class Paladin.
 **********************************************************/

#include "Paladin.h"
const int MAX_DAMAGE = 8;

// Name: Paladin() - Default Constructor
  // Description: Creates a new paladin
  // Preconditions: None
  // Postconditions: Can create a paladin
Paladin::Paladin() {
  SetName("");
  SetHealth(0);
}

// Name: Paladin(string name, int hp)
// Description: Creates a new paladin
// Preconditions: None
// Postconditions: Can create a paladin
Paladin::Paladin(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: ~Paladin - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Paladin::~Paladin() {}

// Name: SpecialAttack
// Description: Defines the Paladin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Paladin::SpecialAttack() {
  //damage is between 1 and 8
  int damage = (rand() % MAX_DAMAGE) + 1;
  cout << " uses smite evil!" << endl;
  return damage;
}
