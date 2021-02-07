//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Caitlin J. Corbin																								//
//	 FINAL																											//
//	Last Updated - December 16, 2020																				//
//	"This program simulates a zombie battle."																		//
//	"Note: This project design was changed from the original proposal - hence marked out code."						//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>					// Including iostream file
#include <string>					// Including string file
#include <fstream>					// Including file stream file
#include <vector>					// Including vector file
#include <cstdlib>					// Including extra functions

using namespace std;				// Accessing general namespace library

//class Employee{
//protected:							// Access modifier (Encapsulation)
//	string name;
//	string employeeId;
//	double salary;
//public:
//	Employee(string Name, string EmployeeId, double Salary) {
//		name = Name;
//		employeeId = EmployeeId;
//		salary = Salary;
//	};
//	// Insert function
//};

class Fighter {																							//	Fighter Class
protected:
	string playerName;
	string weapon;
	float weaponPowerLvl;
	float pHealth;
	bool isPlayerDead = false;
	//bool israiseTheDead = false;
public:
	Fighter(string playerName, string weapon, float weaponPowerLvl, float pHealth) {					//	Fighter constructor
		this->playerName = playerName;
		this->weapon = weapon;
		this->weaponPowerLvl = weaponPowerLvl;
		this->pHealth = pHealth;
	};

	//void raiseTheDead() {
	//	if (israiseTheDead == true) {
	//		cout << "The zombies are already walking . . ." << endl;
	//	}
	//	else { cout << "The dead have been raised! Run!" << endl; israiseTheDead = true; };
	//};

	void deadPlayer(int x) {																			//	If player gets hit or dies, this prints.
		if (x > 0) {
			cout << "You are badly damaged, you cannot take another hit." << endl;
			isPlayerDead = false;
		}
		else if (x < 0) { cout << playerName << " has been bitten." << endl; cout << "GAME OVER" << endl; exit(0); }
	};

	// Getters //
	string getName() {
		return playerName;
	};
	string getWeapon() {
		return weapon;
	};
	float getWeaponPowerLevel() {
		return weaponPowerLvl;
	};
	float getPHealth() {
		return pHealth;
	};

	// Setters //
	void setWeapon(string x) {
		weapon = x;
	};
	void setWeaponPowerLevel(float x) {
		weaponPowerLvl = x;
	};
	void setPHealth(float x) {
		pHealth = x;
	};
};

class Zombie : public Fighter{				//	Zombie Class
protected:
	float zHealth;
	int zNum = 5;
	bool isZombieDead = false;
public:
	Zombie(string name, float weaponPowerLvl, float zHealth) : Fighter(name, weapon, weaponPowerLvl, pHealth) {		//	Zombie constructor
		this->playerName = name;
		this->weaponPowerLvl = weaponPowerLvl;
		this->zHealth = zHealth;
	};

// 	void damageZombie() {
// 		zHealth = zHealth - weaponPowerLvl;
// 	};
	void deadZombie(int x) {										//	Function that determines if zombie is dead.
		if (x > 0) {
			cout << "Zombie is still walking!" << endl;
			isZombieDead = false;
		}
		else cout << "Zombie has been vanquished!" << endl; 
		isZombieDead = true;
	};

	// Getters //
	float getZHealth() {
		return zHealth;
	};
	int getZNum() {
		return zNum;
	};

	// Setters// 
	void setZHeath(float x) {
		zHealth = x;		
	};
	int setZNum(int x) {
		zNum = x;
	};

	float* pointer = &zHealth;
};



//class Mortician : public Fighter {					// Derived class (Inheritance)
//public:
//	Mortician(string weapon, string weaponPowerLvl) : Fighter(weapon, weaponPowerLvl) {};
//
//
//};
//
//class Handyman : public Fighter {					// Derived class (Inheritance)
//public:
//	Handyman(string weapon, string weaponPowerLvl) : Fighter(weapon, weaponPowerLvl) {};
//
//
//};
//
//class Secretary : public Fighter {					// Derived class (Inheritance)
//public:
//	Secretary(string weapon, string weaponPowerLvl) : Fighter(weapon, weaponPowerLvl) {};
//
//
//};

/*LOGIN*/
void login() {
	bool loginSuccess = false;
	int attempt = 2;
	string username = "";
	string password = "";
	do {
		cout << "Username: "; cin >> username;
		cout << "Password: "; cin >> password;

		if (attempt != 0) {
			if (username == "Darkwoods" && password == "admin") { cout << "Credentials Accepted" << endl; loginSuccess = true; }
			else { cout << "Login failed " << attempt << " attempts remaining." << endl; attempt--; }
		}
		else { 
			cout << "Attempts exceeded, shutting down . . . "; 
			cout << "GAVE OVER" << endl;
			(exit(0)); }
	} while (!loginSuccess);
};

///*DISPLAYS MENU*/
//void printMenu() {
//	cout << "######################################" << endl;
//	cout << "1 - View Employees" << endl;
//	cout << "2 - Add Employee" << endl;
//	cout << "3 - View Occupant History" << endl;
//	cout << "4 - Add Occupant" << endl;
//	cout << "5 - Exit" << endl;
//	cout << "######################################" << endl;
//
//};

///*VIEW EMPLOYEE*/
//void viewEmployee() {
//	string info;
//	int count = 0;
//
//	ifstream file;
//	file.open("employees.txt");
//	while (!file.eof()) {
//		file >> info;
//		cout << info << " " << endl;
//		count++;
//	};
//};

/*ADD EMPLOYEE*/
//void addEmployee() {
//	int size;
//	string name, position;
//	double salary;
//
//	cout << "How many employees are you adding today? "; cin >> size;
//	cout << "Enter the employee's name, position, and salary: " << endl;
//
//	vector<string> n; vector<string> p; vector<double> s;
//
//	ofstream file;
//	file.open("employees.txt");
//	while (file.is_open()) {
//		while (size != 0) {
//			cin >> name;
//			file << name << " ";
//			n.push_back(name);
//			cin >> position;
//			file << position << " ";
//			p.push_back(position);
//			cin >> salary;
//			file << salary << " " << endl;
//			s.push_back(salary);
//			size--;
//		};
//		if (size == 0) { file.close(); };
//	};
//};

///*VIEW OCCUPANT*/
//void viewOccupant() {
//	string info;
//	int count = 0;
//
//	ifstream file;
//	file.open("occupants.txt");
//	while (!file.eof()) {
//		file >> info;
//		cout << info << " " << endl;
//		count++;
//	};
//};
//
///*ADD OCCUPANT*/
//void addOccupant() {
//	int size;
//	string name, position;
//	double salary;
//
//	cout << "How many employees are you adding today? "; cin >> size;
//	cout << "Enter the employee's name, position, and salary: " << endl;
//
//	vector<string> n; vector<string> p; vector<double> s;
//
//	ofstream file;
//	file.open("employees.txt");
//	while (file.is_open()) {
//		while (size != 0) {
//			cin >> name;
//			file << name << " ";
//			n.push_back(name);
//			cin >> position;
//			file << position << " ";
//			p.push_back(position);
//			cin >> salary;
//			file << salary << " " << endl;
//			s.push_back(salary);
//			size--;
//		};
//		if (size == 0) { file.close(); };
//	};
//};


int subtract(int x, int y) {
	x = x - y;
	return x;
};


int main() {

	string selection;		// Variables
	int choice;
	int zNum[10] = { 1,2,3,4,5,6,7,8,9,10 };							// Arrays
	int zHealth[10] = { 150,175,200,225,250,275,300,325,350,400 };

	enum Weapon {book, shovel, pen};									// Enumerator for weapons.

	Fighter player("Jose", "Book", 100, 500);							// Fighter object

	Zombie zombie1( "Zombie 1", 499, 150 );								// Zombie objects
	Zombie zombie2( "Zombie 2", 499, 175 );
	Zombie zombie3( "Zombie 3", 499, 200 );
	Zombie zombie4( "Zombie 4", 499, 225 );
	Zombie zombie5( "Zombie 5", 499, 250 );
	

	//vector<Fighter> Player;
	vector<Zombie> zombies;												// Vector container for zombies
	zombies.push_back(zombie1);
	zombies.push_back(zombie2);
	zombies.push_back(zombie3);
	zombies.push_back(zombie4);
	zombies.push_back(zombie5);


	// Story 
	cout << "| | | | | | | | | | | | | |" << endl;
	cout << "	Darkwoods			"	  << endl;
	cout << "| | | | | | | | | | | | | |" << endl; cout << endl;

		cout << "The night air is frigid, the air bites your skin as you walk down a a desolate road deep into the dark woods." << endl;
		cout << "Continue walking? (y/n) "; cin >> selection;
		if (selection != "y") {																		// Selection statement
			cout << "You decide to stop where you are. It's so cold, and you are tired." << endl;
			cout << "You lay down against a tree, and fall asleep, never to wake up again." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);};	// Ends game

		cout << endl;
		cout << "It's been an hour, you stopped feeling your toes 13 minutes ago. Time to find shelter." << endl;
		cout << "Alas! In the distance you see a small burning light. It looks like an old funeral home . ." << endl;
		cout << "Maybe they will take you in for the night?" << endl;
		cout << "Continue walking? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide to stop where you are. It's so cold, and you are tired." << endl;
			cout << "You lay down against a tree, and fall asleep, never to wake up again." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);
		};

		cout << endl;
		cout << "Hesitantly, you approach the building. There are tombstones scattered everywhere." << endl;
		cout << "You knock on the door. No one answers. As you begin to walk around back, the front door creaks open." << endl;
		cout << "Go inside? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide the funeral home looked too . . off." << endl;
			cout << "You walked away, eventually finding a road. A kind hitchhiker picked you, taking you far away from that place." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);
		};

		cout << endl;
		cout << "Slowly you drift inside. It smells of mold. Isn't anyone home?" << endl;
		cout << "Towards your right, you hear the subtle laughter of an old man. You decide to look for him." << endl; 
		cout << "(you are in his place after all)" << endl;
		cout << "Find the man? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide the funeral home looked too . . off." << endl;
			cout << "You walked away, eventually finding a road. A kind hitchhiker picked you, taking you far away from that place." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);
		};

		cout << endl;
		cout << "You walk towards the source of the laughter. Upon doing so you enter a room." << endl;
		cout << "Ugh, there is dust everywhere." << endl;
		cout << "Look around? (y/n) "; cin >> selection;
	
			if (selection != "y") {
				cout << "You decide the funeral home looked too . . off." << endl;
				cout << "You walked away, eventually finding a road. A kind hitchhiker picked you, taking you far away from that place." << endl;
				cout << "GAME OVER";
				cout << endl;	exit(0);	
			};

		cout << endl;
		cout << "There are old trinkets, books, dead flowers, and . . . a curtain?" << endl;
		cout << "You approach the back of the room, passing the benches facing forward towards the drapery." << endl;
		cout << "Through the sheen, you see a dark silhouette of a person. Is this the laughing man?" << endl;
		cout << "Pull back the curtain? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide the funeral home looked too . . off." << endl;
			cout << "You walked away, eventually finding a road. A kind hitchhiker picked you, taking you far away from that place." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);
		};

		cout << endl;
		cout << "You pull back the curtain. The man is gone." << endl;
		cout << "However, there is a closed coffin sat on an marble podium. It looks so . . . clean." << endl;
		cout << "How strange. Your curiosity wonders if there is a body inside." << endl;
		cout << "Take a peak? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide the funeral home looked too . . off." << endl;
			cout << "You walked away, eventually finding a road. A kind hitchhiker picked you, taking you far away from that place." << endl;
			cout << "GAME OVER";
			cout << endl;	exit(0);
		};

		cout << endl;
		cout << "You open the coffin. You see a man looking up at you, smiling." << endl;
		cout << "You scream and fall backwards, knocking a jar over as you do." << endl;
		cout << "Heart racing, you look up at the coffin. The man is dead." << endl;
		cout << "The contents of the jar release a cherry red ash. That doesn't look right." << endl;
		cout << "You get up, outside you hear moans and gurgling sounds. What is going on??" << endl;
		cout << "You look out the window, and see zombies! You need to get out of there!" << endl;
		cout << "Run? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide to hide. After 15 minutes, something enters the room." << endl;
			cout << "You stay deathly quiet, then something grabs you from behind." << endl;
			cout << "IT'S THE SMILING MAN!!!" << endl;
			system("pause");		// For ~added dramatic effect ! Hit enter.
			while (true) {
				cout << "GAME OVER";
			};
		};

		cout << endl;
		cout << "You sprint out of the room and hide in a closet. Adrenaline is pumping through your veins." << endl;
		cout << "You come up with a plan. You will take a makeshift weapon and fight your way out." << endl;
		cout << "You see 3 options: a heavy book, a shovel, and a pen." << endl;
		cout << "Which do you take? (0 - book / 1 - shovel / 2 - pen) "; cin >> choice;
		try {																								// Exception handler
			while (!cin.good()) {
				cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "Try again. " << endl;  cin >> choice;		// Input validation
			} throw 99;
		}
		catch (int w) { cout << "Error (INVALID INPUT): " << w << endl; };

		
		switch (choice) {																					// Switch with enumerator weapon.
		case book: player.setWeapon("Book"); player.setWeaponPowerLevel(100);
			break;
		case shovel: player.setWeapon("Shovel"); player.setWeaponPowerLevel(75);
			break;
		case pen: player.setWeapon("Pen"); player.setWeaponPowerLevel(50);
			break;
		default: exit(0);	// Pick smthn or get booted
		};

		cout << endl;
		cout << "You have equipped the " << player.getWeapon() << ", power lvl: " << player.getWeaponPowerLevel() << endl;
		cout << "Time to leave. You approach the door, ready for battle." << endl; 
		cout << "You grab the knob and turn, but it wont budge.You're trapped." << endl;
		cout << "You take a closer look and notice a keypad." << endl;
		cout << "Look around? (y/n) "; cin >> selection;
		if (selection != "y") {
			cout << "You decide to stay quiet instead. After 15 minutes, something rattles behind you." << endl;
			cout << "You turn around slowly." << endl;
			cout << "IT'S THE SMILING MAN!!!" << endl;
			system("pause");
			while (true) {
				cout << "GAME OVER";
			};
		};

		cout << endl;
		cout << "You scour around the closet, it's so dark in here . . ." << endl;
		cout << "You find a sticky note under the shelf rack. You pick it up." << endl;
		cout << "Username: Darkwoods Password: admin" << endl;
		cout << "Perfect. You walk to to keypad: " << endl;
		login();	// Calls login function

		cout << endl;
		cout << "The door makes a noise resembling that of grinding gears. It unlocked." << endl;
		cout << "Holding your weapon close, you take a deep breath, and sprint outside." << endl;
		cout << "There are zombies everywhere! Time to fight." << endl; cout << endl;

		cout << "Zombie " << zNum[0] << " approaches!" << endl;
		do {																				// Loops until someone dies
			cout << "Attack - 1 " << endl; cin >> choice;
			switch (choice) {
			case 1:
				zombie1.setZHeath(zombie1.getZHealth() - player.getWeaponPowerLevel());		// Player damages zombie
				cout << "Zombie 1 health is now " << *zombie1.pointer << endl;
				zombie1.deadZombie(*zombie1.pointer);										// Calls the dead zombie function to print info
				break;
			default:
				player.setPHealth(player.getPHealth() - zombie1.getWeaponPowerLevel());		// If player doesn't fight, they get hit.
				cout << "Your health is now " << player.getPHealth() << endl;				// Zombie damages the player.
				player.deadPlayer(player.getPHealth());										// Calls the dead player function to print info.
			};
		} while (zombie1.getZHealth() > 0); 
		cout << "The zombie falls to the ground, dead once more." << endl;
		cout << "4 zombies left." << endl; cout << endl;
																							// Repeats
		cout << "Zombie " << zNum[1] << " approaches!" << endl;
		do {
			cout << "Attack - 1 " << endl; cin >> choice;
			switch (choice) {
			case 1:
				zombie2.setZHeath(zombie2.getZHealth() - player.getWeaponPowerLevel());
				cout << "Zombie 2 health is now " << *zombie2.pointer << endl;
				zombie2.deadZombie(*zombie2.pointer);
				break;
			default:
				player.setPHealth(player.getPHealth() - zombie2.getWeaponPowerLevel());
				cout << "Your health is now " << player.getPHealth() << endl;
				player.deadPlayer(player.getPHealth());
			};
		} while (zombie2.getZHealth() > 0);
		cout << "The zombie falls to the ground, dead once more." << endl;
		cout << "3 zombies left." << endl; cout << endl;

		cout << "Zombie " << zNum[2] << " approaches!" << endl;
		do {
			cout << "Attack - 1 " << endl; cin >> choice;
			switch (choice) {
			case 1:
				zombie3.setZHeath(zombie3.getZHealth() - player.getWeaponPowerLevel());
				cout << "Zombie 3 health is now " << *zombie3.pointer << endl;
				zombie3.deadZombie(*zombie3.pointer);
				break;
			default:
				player.setPHealth(player.getPHealth() - zombie3.getWeaponPowerLevel());
				cout << "Your health is now " << player.getPHealth() << endl;
				player.deadPlayer(player.getPHealth());
			};
		} while (zombie3.getZHealth() > 0);
		cout << "The zombie falls to the ground, dead once more." << endl;
		cout << "2 zombies left." << endl; cout << endl;

		cout << "Zombie " << zNum[3] << " approaches!" << endl;
		do {
			cout << "Attack - 1 " << endl; cin >> choice;
			switch (choice) {
			case 1:
				zombie4.setZHeath(zombie4.getZHealth() - player.getWeaponPowerLevel());
				cout << "Zombie 4 health is now " << *zombie4.pointer << endl;
				zombie4.deadZombie(*zombie4.pointer);
				break;
			default:
				player.setPHealth(player.getPHealth() - zombie4.getWeaponPowerLevel());
				cout << "Your health is now " << player.getPHealth() << endl;
				player.deadPlayer(player.getPHealth());
			};
		} while (zombie4.getZHealth() > 0);
		cout << "The zombie falls to the ground, dead once more." << endl;
		cout << "1 zombies left." << endl; cout << endl;

		cout << "Zombie " << zNum[4] << " approaches!" << endl;
		do {
			cout << "Attack - 1 " << endl; cin >> choice;
			switch (choice) {
			case 1:
				zombie5.setZHeath(zombie5.getZHealth() - player.getWeaponPowerLevel());
				cout << "Zombie 5 health is now " << *zombie5.pointer << endl;
				zombie5.deadZombie(*zombie5.pointer);
				break;
			default:
				player.setPHealth(player.getPHealth() - zombie5.getWeaponPowerLevel());
				cout << "Your health is now " << player.getPHealth() << endl;
				player.deadPlayer(player.getPHealth());
			};
		} while (zombie5.getZHealth() > 0);
		cout << "The zombie falls to the ground, dead once more." << endl;
		cout << "All zombies have been defeated." << endl;

		cout << endl;																						// End of the game
		cout << "Your body aches, grime coats your skin, and the cold nips your fingertips." << endl;
		cout << "Yet, you are alive. For now. . . " << endl;
		cout << "The laughing man appears behind you. Smiling, he leans in close." << endl;
		cout << "One day, you will end up in my garden as well Jose." << endl;
		cout << "End" << endl;

	system("pause > 0");
}