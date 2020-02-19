/***********************************************************
 ** File:    Monster.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class, Monster to
 ** make more monsters.
 **********************************************************/

#include "Monster.h"

// Name: Monster() - Default Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster() {
  SetName("");
  SetHealth(0);
}

// Name: Monster(string name, int hp) - Overloaded Constructor
// Description: Would be used to create a monster but abstracted
// Preconditions: None
// Postconditions: Used to populate child class data
Monster::Monster(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: Attack()
// Description: Describes attack statements for monster
// Preconditions: None
// Postconditions: Returns damage
int Monster::Attack() {
  //monsters always do 1 damage.
  return 1;
}

// Name: SpecialAttack()
// Description: Purely virtual SpecialAttack
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
//virtual 
//int Monster::SpecialAttack() = 0;
