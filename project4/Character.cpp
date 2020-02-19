/***********************************************************
 ** File:    Character.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class character
 **********************************************************/

#include "Character.h"
const int maxBaseDMG = 6;

// Name: Character() - Default Constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can create a character
Character::Character(){
  SetName("");
  SetHealth(0);
}

// Name: Character(string name, int hp) - Overloaded constructor
// Description: Creates a new character
// Preconditions: None
// Postconditions: Can be used to populate character or child classes
Character::Character(string name, int hp){
  SetName(name);
  SetHealth(hp);
}

// Name: ~Character - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Character::~Character(){}

// Name: Attack()
// Description: Describes attack statements for character
// Preconditions: None
// Postconditions: Returns damage
int Character::Attack(){
  //chooses a random number from 1 to 6 as a base attack.
  int damage = (rand() % maxBaseDMG) + 1;
  return damage;
}

// Name: SpecialAttack()
// Description: Tells player that character does not have special attack
// may be used for child class special attacks
// Preconditions: None
// Postconditions: May be used to call child class SpecialAttack
//virtual
int Character::SpecialAttack(){
  cout << "moves around in a flashy way but nothing happens." << endl;
  cout << "Classless characters do not have a special attack" << endl;
  return 0;
}
