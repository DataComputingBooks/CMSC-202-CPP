/***********************************************************
 ** File:    Wizard.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class wizard.
 **********************************************************/

#include "Wizard.h"
const int MAX_DAMAGE = 12;
const int MIN_DAMAGE = 3;

// Name: Wizard() -	Default Constructor
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard() {
  SetName("");
  SetHealth(0);
}

// Name: Wizard(string name, int hp)
// Description: Creates a new wizard
// Preconditions: None
// Postconditions: Can create a wizard
Wizard::Wizard(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: ~Wizard - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Wizard::~Wizard() {}

// Name: SpecialAttack
// Description: Defines the Wizard's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Wizard::SpecialAttack() {
  //return damage from 3 to 12.
  int damage = (rand() % (MAX_DAMAGE - MIN_DAMAGE)) + MIN_DAMAGE;
  cout << " casts magic missile!" << endl;
  return damage;
}
