/***********************************************************
 ** File:    Room.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code to make a room.
 **********************************************************/

#include "Room.h"
const int NO_EXIT = -1;

//Name: Room (Overloaded Constructor)
//Precondition: Must have valid input for each part of a room
//Postcondition: Creates a new room
Room::Room(int iD, string name, string desc, int north, int east, int south, int west) {

  //inputs values for id, name, and description.
  m_ID = iD;
  m_name = name;
  m_desc = desc;
  
  //inputs the 4 different directions into the array.
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}

//Name: GetName
//Precondition: Must have valid room
//Postcondition: Returns room name as string
string Room::GetName() {
  return m_name;
}
//Name: GetID
//Precondition: Must have valid room
//Postcondition: Returns room id as int
int Room::GetID() {
  return m_ID;
}

//Name: GetDesc
//Precondition: Must have valid room
//Postcondition: Returns room desc as string
string Room::GetDesc() {
  return m_desc;
}

//Name: CheckDirection
//Precondition: Must have valid room
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the room in that direction
//Postcondition: Returns id of room in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection) {

  //if direction is north return int value of north.
  if (myDirection == 'N' || myDirection == 'n') {
    return m_direction[N];

  }else if (myDirection == 'E' || myDirection == 'e') {
    //return value of east
    return m_direction[E];
    
  }else if (myDirection == 'S' || myDirection == 's') { 
    //return value of south
    return m_direction[S];

  }else if (myDirection == 'W' || myDirection == 'w') {
    //return value of west
    return m_direction[W];

  }else {
    //otherwise return -1.
    return NO_EXIT;
  }
}

//Name: PrintRoom
//Precondition: Room must be complete
//Postcondition: Outputs the room name, room desc, then possible exits
void Room::PrintRoom() {
  //obtain the name and description.
  cout << GetName() << endl;
  cout << GetDesc() << endl;
  cout << "Possible Exits: ";

  //check the directions for a possible exit and prompt the user.
  if (CheckDirection('N') != NO_EXIT)
    cout << "N ";
  if (CheckDirection('E') != NO_EXIT)
    cout << "E ";
  if (CheckDirection('S') != NO_EXIT)
    cout << "S ";
  if (CheckDirection('W') != NO_EXIT)
    cout << "W ";
  cout << endl;
}
