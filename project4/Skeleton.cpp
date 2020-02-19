/***********************************************************
 ** File:    Skeleton.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code for child class skeleton
 **********************************************************/
#include "Skeleton.h"
const int MAX_DAMAGE = 1;

// Name: Skeleton() - Default Constructor
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton() {
  SetName("");
  SetHealth(0);
}
// Name: Skeleton(string name, int hp)
// Description: Creates a new skeleton
// Preconditions: None
// Postconditions: Can create a skeleton
Skeleton::Skeleton(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Name: SpecialAttack
// Description: Defines the Skeleton's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Skeleton::SpecialAttack() {
  //Skeletons are weak and only do 1 damage.
  cout << " bashes you with it's own arm!" << endl;
  return MAX_DAMAGE;
}
