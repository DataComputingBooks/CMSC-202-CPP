/***********************************************************
 ** File:    Game.cpp
 ** Project: UMBC Adventure, Fall 2019
 ** Author:  Paul Roh
 ** Date     11/12/2019
 ** Section: 14
 ** E-mail:  groh1@umbc.edu
 ** This file contains the code to run the game.
 **********************************************************/

#include "Game.h"

//index of player choices.
const int LOOK = 1, MOVE = 2, ATTACK = 3, REST = 4, STATS = 5, QUIT = 6;

//index of classes.
const int ROGUE = 1, WIZARD = 2, PALADIN = 3, CHARACTER = 4;
const int BABY_DRAGON = 1, GOBLIN = 2, SKELETON = 3;

//number of different monster encounters with 1 being no monster.
const int DIFF_ENCOUNT = 4;

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: After asking for a file name, loads map, creates char and starts.
Game::Game() {
}

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Uses filesname to LoadMap, calls create character,
//                 and sets both numRests and m_numSpecial using constants.
Game::Game(string fileName) {
  cout << "Welcome to UMBC Adventure!" << endl;

  //place holder value for a monster
  m_curMonster = new Skeleton("bob", 0);

  //load the map and make a character.
  LoadMap(fileName);
  CharacterCreation();

  //rests and specials set in StartGame()
  StartGame();
}

// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game() {

  //delete character and monster at the end.
  delete m_myCharacter;
  m_myCharacter = nullptr;
  delete m_curMonster;
  m_curMonster = nullptr;
  
  //go through the list and delete all the rooms.
  for (unsigned int i = 0; i < m_myMap.size(); i++) {delete m_myMap[i]; m_myMap[i] = NULL;}
}

// Name: LoadMap(string fileName)
// Description: Dynamically creates rooms and inserts them into the m_myMap vector
// Precondition: File contains map information
// Postcondition: Map is populated with Room objects.
void Game::LoadMap(string fileName) {

  //open the file.
  ifstream mapFile(fileName);

  //initialize the string and int inputs.
  string iD, name, desc, north, east, south, west, endString;
  int intID, intNorth, intEast, intSouth, intWest;

  //Get the iD of the file first to determine that the file is not empty.
  getline(mapFile, iD, '|');

  //While not empty, keep running.
  while(!mapFile.eof()) {

    //Get the values of each variable.
    getline(mapFile, name, '|');
    getline(mapFile, desc, '|');
    getline(mapFile, north, '|');
    getline(mapFile, east, '|');
    getline(mapFile, south, '|');
    getline(mapFile, west, '|');
    getline(mapFile, endString, '\n');

    /*Checker to see that files are loading in properly.
    cout << desc << endl;
    cout << north << endl;*/

    //Convert necessary strings to int.
    intID = stoi(iD);
    intNorth = stoi(north);
    intEast = stoi(east);
    intSouth = stoi(south);
    intWest = stoi(west);

    //Add the dynamically allocated Room onto the array.
    m_myMap.push_back(new Room(intID, name, desc, intNorth, intEast, intSouth, intWest));

    //Check next line to see if empty. If not set the next iD.
    getline(mapFile, iD, '|');
    
  }
  
  //Output for if mapFile was not opened properly and close it if it is.
  if (!mapFile.is_open()) 
    cout << "File not opened properly." << endl;
  else
    mapFile.close();
  
}

// Name: CharacterCreation()
// Description: Allows user to create a new character (or child) to play with. May
//              be either character, paladin, rogue, or wizard.
// Preconditions: None
// Postconditions: m_myCharacter is populated
void Game::CharacterCreation() {
  string name = "";

  //obtain a character name.
  do {
    cout << "Character Name: ";

    //obtain a name and cut it off at a space.
    getline(cin, name);

    //prompt again if they did not enter anything.
    if (name == "")
      cout << "Please enter a name." << endl;
  } while (name == "");

  //initialize an int for the while loop.
  int characterType = 0;

  //while less than 1 or greater than 4.
  do {
    cout << "Select a class" << endl;
    cout << "1. Rogue" << endl;
    cout << "2. Wizard" << endl;
    cout << "3. Paladin" << endl;
    cout << "4. No Class" << endl;

    //get valid input.
    cin >> characterType;

    //prompt user to make good choices.
    if (characterType < ROGUE || characterType > CHARACTER)
      cout << "Please choose a class from the ones listed." << endl;
    
  } while (characterType < ROGUE || characterType > CHARACTER);

  //make a character based on the chosen type.
  if (characterType == ROGUE)
    m_myCharacter = new Rogue(name, ROGUE_HEALTH);
  else if (characterType == WIZARD)
    m_myCharacter = new Wizard(name, WIZARD_HEALTH);
  else if (characterType == PALADIN)
    m_myCharacter = new Paladin(name, PALADIN_HEALTH);
  else if (characterType == CHARACTER)
    m_myCharacter = new Character(name, 10);

  //space out to make it look cleaner.
  cout << endl;
}

// Name: StartGame()
// Description: After LoadMap and CharacterCreation, current room
//              is set (0 by default) and Action is called
// Preconditions: LoadMap and CharacterCreation must have been completed
// Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame() {

  //initialize the rests and specials count.
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;

  //Start off in the beginning room.
  m_curRoom = START_ROOM;
  m_myMap[m_curRoom]->PrintRoom();

  //There are 4 different scenarios.
  int typeMonster = (rand() % DIFF_ENCOUNT) + 1;

  //if 1 the player does not encounter any monsters.
  if (typeMonster != 1) {
    delete m_curMonster;
    m_curMonster = nullptr;
    RandomMonster();
  }else {
    cout << "It is peaceful here." << endl;
  }

  //start the actions.
  Action();
  
}

// Name: Action()
// Description: Menu for game
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action() {

  //save the original health of the character.
  int origHealth = m_myCharacter->GetHealth();
  //initialized choice to start the while loop.
  int userChoice = 0;
  
  //Keep playing until the user quits or dies. Check if good choices are made.
  while (userChoice != QUIT && m_myCharacter->GetHealth() > 0) {
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Monster" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;

    cin >> userChoice;

    //if user chooses 1, print the room and tell about anything in the room.
    if (userChoice == LOOK) {
      m_myMap[m_curRoom]->PrintRoom();

      //Use name to compare
      string monsterName = m_curMonster->GetName();

      //place holder value to stop the first option from occuring.
      string bob = "bob";
      //strings of monsters so as to not compare literals.
      string goblin = "Goblin", dragon = "Baby dragon", skeleton = "Skeleton";

      //Determine if there is any dead or living monsters in the room.
      if (m_curMonster->GetHealth() <= 0 && monsterName.compare(bob) != 0)
	cout << "There is a dead monster in the room" << endl;
      else if (monsterName.compare(dragon) == 0) 
	cout << "A baby dragon huffs and makes itself known." << endl;
      else if (monsterName.compare(goblin) == 0)
	cout << "A goblin is here picking his nose." << endl;
      else if (monsterName.compare(skeleton) == 0)
	cout << "A skeleton lumbers around the room." << endl;
      else
	//prompt when there is nothing in the room.
	cout << "It is peaceful here." << endl;
	
      
    }else if (userChoice == MOVE) {

      //remind the user they cannot move with a monster in the way.
      if (m_curMonster->GetHealth() > 0)
	cout << "You cannot move while there is a monster in the room" << endl;
      else
	Move();

    }else if (userChoice == ATTACK) {
      
      //a pseudo value to tell the program that the room is empty.
      string bob = "bob";
      string monsterName = m_curMonster->GetName();

      //sees if the room is empty
      if (monsterName.compare(bob) == 0)
	cout << "It is peaceful here. There are no monsters to attack." << endl;

      else
	//fight the monster and tell who dies.
	Attack();

    }else if (userChoice == REST) {

      //if the number of rests is not 0 or there is no monster in the room.
      if (m_numRests > 0 && m_curMonster->GetHealth() <= 0) {
	int health = m_myCharacter->GetHealth();

	if (origHealth >= (health + REST_HEAL)){
	  //set the new health to health + healing amount and lower the available rests by 1.
	  m_myCharacter->SetHealth(health + REST_HEAL);
	  cout << "Health +" << REST_HEAL << endl;
	  
	}else {
	  //set health to the original amount if heal exceeds max health.
	  m_myCharacter->SetHealth(origHealth);
	  cout << "Health +" << (origHealth - health) << endl;
	}
	
	m_numRests--;

      }else if (m_curMonster->GetHealth() > 0) {
	cout << "You cannot heal while there is a monster in the room" << endl;
	
      }else {
	//No more rests available
	cout << "You cannot rest right now" << endl;
	cout << "Rests available: " << m_numRests << endl;
      }

    }else if (userChoice == STATS) {
      //Check your stats.
      Stats();
    }
  }
  
  cout << "Thank you for playing!" << endl;
 }

// Name: RandomMonster()
// Description: Used to randomly create a dynamically allocated monster
//              of Baby Dragon, Goblin, or Skeleton
// Preconditions: Has an entity pointer to hold monster child
// Postconditions: Returns object of type Baby Dragon, Goblin, or Skeleton
Entity* Game::RandomMonster() {
  int typeMonster = (rand() % DIFF_ENCOUNT) + 1;

  if (typeMonster == BABY_DRAGON) {
    //make a new Dragon
    m_curMonster = new BabyDragon("Baby dragon", DRAGON_HEALTH);
    cout << "A baby dragon huffs and makes itself known." << endl;

  }else if (typeMonster == GOBLIN) {
    //make a new Goblin
    m_curMonster = new Goblin("Goblin", GOBLIN_HEALTH);
    cout << "A goblin is here picking his nose." << endl;

  }else if (typeMonster == SKELETON) {
    //make a new Skeleton
    m_curMonster = new Skeleton("Skeleton", SKELETON_HEALTH);
    cout << "A skeleton lumbers around the room." << endl;

  }else{
    //make bob, a name for when there is no monster in the room.
    m_curMonster = new Skeleton("bob", 0);
    cout << "It is peaceful here." << endl;
  }

  return m_curMonster;
}

// Name: Move
// Description: Moves a player from one room to another (updates m_curRoom)
// Preconditions: Must be valid move (room must exist)
// Postconditions: Displays room information, checks for new monster (deletes old)
void Game::Move() {
  char myDirection;

  //Get a valid input for the direction.
  do {
    cout << "Which direction? (N E S W)" << endl;
    cin >> myDirection;
  } while (m_myMap[m_curRoom]->CheckDirection(myDirection) == -1);

  //check direction and print room.
  m_curRoom = m_myMap[m_curRoom]->CheckDirection(myDirection);
  m_myMap[m_curRoom]->PrintRoom();

  //goes to random monster where it determines if theres a monster and what kind.
  delete m_curMonster;
  m_curMonster = nullptr;
  RandomMonster();
}

// Name: Attack
// Description: Allows player to attack an enemy entity.
// Preconditions: Must have enemy monster in room
// Postconditions: Indicates who wins and updates health(hp) as battle continues.
//                 May need to deallocate enemy monster to prevent memory leaks.
void Game::Attack() {

  //if the monster is already dead
  if (m_curMonster->GetHealth() <= 0)
    cout << m_curMonster->GetName() << " is already dead." << endl;
  
  while (m_myCharacter->GetHealth() > 0 && m_curMonster->GetHealth() > 0) {

    //int value that tells what kind of attack is being used. 2 is special for both entities.
    int typeAttack = 0;
    
    //1 is a normal attack and 2 is a special attack.
    while (typeAttack != 1 && typeAttack != 2) {
      cout << "1. Normal Attack" << endl;
      cout << "2. Special Attack" << endl;
      cin >> typeAttack;
    }
    
    int characterDMG = 0;
    
    //if user wants to normal attack, call the attack function.
    if (typeAttack == 1) {
      characterDMG = m_myCharacter->Attack();
      
      cout << m_myCharacter->GetName() << " attacks dealing " << characterDMG << " points of damage!" << endl;
      
    }else if (typeAttack == 2 && m_numSpecial > 0) {
      //call the special attack function and deal that damage.
      cout << m_myCharacter->GetName();
      characterDMG = m_myCharacter->SpecialAttack();
      
      //decrease the number of available specials.
      m_numSpecial--;
      
      cout << m_myCharacter->GetName() << " deals " << characterDMG << " damage!" << endl;
	
    }else if (typeAttack == 2 && m_numSpecial <= 0){
      //if the user chooses 2 and there is no more specials left, tell them.
      cout << m_myCharacter->GetName() << " deals no damage..." << endl;
      cout << "You have no specials left" << endl;

    }else
      //when attack doesn't occur.
      cout << m_myCharacter->GetName() << " fails to attack..." << endl;

    //initialized damage of the monster.
    int monsterDMG = 0;

    //different types of attacks* with 1 being the special attack.
    typeAttack = (rand() % DIFF_ENCOUNT) + 1; //rate of doing a special attack.

    if (typeAttack == 1) {
      //special attack. Yell out the move.
      cout << m_curMonster->GetName();
      monsterDMG = m_curMonster->SpecialAttack();

      cout << m_curMonster->GetName() << " deals " << monsterDMG << " damage!" << endl;

    }else {
      //normal attack.
      monsterDMG = m_curMonster->Attack();

      cout << m_curMonster->GetName() << " deals " << monsterDMG << " point(s) of damage!" << endl;
    }

    //determine the new health of monster and character.
    int monsterHP = m_curMonster->GetHealth() - characterDMG;
    int characterHP = m_myCharacter->GetHealth() - monsterDMG;

    //set the new health.
    m_curMonster->SetHealth(monsterHP);
    m_myCharacter->SetHealth(characterHP);

    //output if the user died.
    if (characterHP <= 0) {
      cout << "***********************" << endl;
      cout << "* ~+ You have died +~ *" << endl;
      cout << "*      GAME OVER      *" << endl;
      cout << "***********************" << endl;
      
    }else if (monsterHP <= 0){
      //user successfully beat the enemy.
      cout << "You have defeated the " << m_curMonster->GetName() << endl;
      break;

    }else {
      //if the monster's hp > 0 and the character's hp > 0
      cout << m_myCharacter->GetName() << "'s health: " << characterHP << endl;
      cout << m_curMonster->GetName() << "'s health: " << monsterHP << endl;
    }
    
  }
}

// Name: Stats()
// Description: Displays the information about the player (name, hp, rests, specials)
// Preconditions: None
// Postconditions: None
void Game::Stats() {
  cout << "**********************************************" << endl;
  //overloaded <<
  cout << *m_myCharacter;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
  cout << "**********************************************" << endl;
}
