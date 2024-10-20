/*
Travieon Fields
Assignment 1 Assignment: Object Oriented Programming

I made a short game with the code I know I made it clear to Not over Work it.

*/


#include <iostream>
#include <string>

#include<Windows.h>
#include <time.h> 

using namespace std;


// This is all my methods I made for my code to work For the most part they are pretty easy to understand. And go in order.
void ClassChoice();
//Checks The stats of the player
void statChecker();
//Method for enemy encounter
void EnemyEncounter();
//Ninja combat 
void CombatNinja();
//pirate combat
void CombatPirate();
//if you were defeated
void gameOver();
 

 char playerChoice;

 // basically use for your class choice
 int classChoice;
 //Dmg for player and Enemy To use.
 int DmgAmount = 0;
 //for combat to pick your action
 int playersActions;
 //To check if you able to flee combat
 int fleeingNumber;

 //This is all you stats for you player that get changed when you pick you class
 int fullHP;
 //This is Hp if it goes to zero you lose 
 int pHp = 0;
 //This is you attack
 int pAtk = 0;
 //This is you defense
 int pDef = 0;
 //this is your speed if you can run away
 int pSpd = 0;
 //This is you leveling stat
 int statToLevel;
 // this is how many enemies you have defeated
 int enemyDefeated;
 // this is how many enemies you escape
 int enemyEscaped;
 //this is how many enemies you encounter
 int enemiesMet;

 //Checks to see if the player died
 bool playerIsDead;
 //This checks to see if you ran from the enemy
 bool ranFromEnemy;
 // this is for leveing up your character
 bool levelUpUsed;
 
 //This is for setting you class of your character.
 bool cLightClass = false;
 bool cMedClass = false;
 bool cHeavyClass = false;

 //I use this to be able to change the text of the Debug To make it more readable
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

 //This is the first class I made to change your characters stats
 class CharacterStatsMod {
 public:
	 //This method is called to Change your Stats To the light Class
	 void ClassLight() {
		 pHp = 5;
		 fullHP = pHp;
		 pAtk = 5;
		 pDef = 1;
		 pSpd = 6;
		 
	 }
	 //This method is called to Change your Stats To the Med Class
	 void ClassMed()
	 {
		 //sets your stats
		 pHp = 10;
		 //Makes it able to reset you health after you get out a fight.
		 fullHP = pHp;
		 pAtk = 7;
		 pDef = 3;
		 pSpd = 2;
		
	 }
	 //This method is called to Change your Stats To the heavy Class
	 void ClassHeavy()
	 {
		
		 pHp = 15;
		 fullHP = pHp;
		 pAtk = 3;
		 pDef = 5;
		 pSpd = 1;
	
	 }

	 //This method is use for Leveing your character After each fight
	 void LevelUp()
	 {
		 //Any time you see this code it is Changing The color of Text
		 SetConsoleTextAttribute(h, 2);
		 cout << "You level Up Please Choose a stat to level up!" << endl;
		 SetConsoleTextAttribute(h, 6);
		 cout << "0)Atk  1)Def  2)Spd" << endl;
		 //This method is For Seeing your Stats When you level up so you can see what your stats look like
		 statChecker();
		 //Wait for you choice of leveling
		 cin >> statToLevel;
		 // this is a While loop that has a Switch that makes sure you Pick a stat to level up
		 while (!levelUpUsed)
		 {
			 switch (statToLevel)
			 {
			 case 0:
				 //Basically it adds 2 to your Atk Stat, The same thing as saying "pAtk += 2" it is use for all stats on level choice
				 pAtk = pAtk + 2;
				 levelUpUsed = true;
				 break;

			 case 1:
				 pDef = pDef + 2;
				 levelUpUsed = true;
				 break;
			 case 2:
				 pSpd = pSpd + 2;
				 levelUpUsed = true;
				 break;
			 default:
				 //Makes it so if you don't make a actual choice it makes you choose one
				 SetConsoleTextAttribute(h, 1);
				 cout << "Please Choose a Level up" << endl;
				 cin >> statToLevel;
				 break;
			 }
		 }
		 //This is adding random Numbers to your stats The +1 at the end is so that It Never adds 0
		 //This Is to make sure that it changes your FULL health rather than you current health
		 pHp = fullHP + rand() % 3+1;
		 pAtk = pAtk + rand() % 3 + 1;
		 pDef = pDef + rand()% 3 +1;
		 pSpd =  pSpd + rand()% 3 +1;
		 //Sets you full Health to What your New full health should be
		 fullHP = pHp;
		 //Shows you your new stats 
		 statChecker();
		 
	 }

 };


 //This is mainly for the Enemies I create a class for combantants That attack you The parent if you will
class Combantants {

public:
	//Created a few Var just for changing when an enemy is made.
	string EnemyName;
	string factionName;
	int eHp;
	int eDef;
	int eDmg;
	int eSpd;
	//This is how your player and your Enemy attack each other
	int BasicAttack(int Atk, int Def)
	{
		//Gets a random number from your attack and it can be 0 as well as one for defense
		Atk = rand() % Atk;
		Def = rand() % Def;
		//Makes DmgAmount the output Attack minus Defense
		DmgAmount = Atk -= Def;
		// if dmg is less than 0 It is just set to 0 so that you don't gain health for attacks 
		if (DmgAmount <= 0)
		{
			DmgAmount = 0;
		}

		return(DmgAmount);

	}
	//A hold over from an idea i was making but it didn't work out well so i kept it just as a in case
	int SpeicalSkill(Combantants enemy)
	{
		

		return(DmgAmount);
	}

	
	//Everytime you defeat an enemy it makes them stronger for the next fight 
	void enemySpawner(int levelUp)
	{
		EnemyName = factionName;
		eHp = levelUp + rand() % 4 +1;
		eDef = levelUp + rand() % 6 +1;
		eDmg = levelUp + rand() % 7+1;
		eSpd = levelUp + rand() % 9+1;
	}
	//What an enemy Says when they first enter the fight
	void enemyShoutOut()
	{
		cout << "I am Enemy!";

	}
	//When the enemy dies this is displayed
	void enemyDeathQuote()
	{
		cout << "I Was Defeated!";

	}

};


//This is the first child of Combantants
class cNinja : public Combantants {
public:



	//Give them the name ninja
	string factionName = "Ninja";


	//This is a call back from combantants and is change for the ninja class
	void enemySpawner(int levelUp)
	{
		eHp = levelUp + rand() % 4 + 1 +levelUp;
		eDef = levelUp + rand() % 6 + 1 + levelUp;
		eDmg = levelUp + rand() % 7 + 1 + levelUp;
		eSpd = levelUp + rand() % 9 + 1 + levelUp;
	}
	
	//This is a override for the enemy shout out
	void enemyShoutOut()
	{
		cout << "I stay In the Shadows!" << endl;

	}
	//This is a override death yell
	void enemyDeathQuote()
	{
		cout << "This. . Can't Be!" << endl;

	}

	




};

//This is the second child of the combantants It is all Basically the same but the Shout and Death is different
class cPirate : public Combantants {
public:

	string factionName = "Pirate";

	void enemySpawner(int levelUp)
	{
		eHp = levelUp + rand() % 4 + 1 + levelUp;
		eDef = levelUp + rand() % 6 + 1 + levelUp;
		eDmg = levelUp + rand() % 7 + 1 + levelUp;
		eSpd = levelUp + rand() % 9 + 1 + levelUp;
	}


	void enemyShoutOut()
	{
		cout << "YAR! You're Going OverBoard!" << endl ;

	}
	void enemyDeathQuote()
	{
		cout << "I drank tooo Much!" << endl;

	}



};
//This is the main Loop of the game
int main()
{
		SetConsoleTextAttribute(h, 1);
		cout << "Hello welcome to Pirates Vs Ninjas! A gauntlet Fighting game" << endl;

		cout << "You will Be put up against Very powerful Ninjas And pirates Alike" << endl;
		//This calls the class choice which makes you choose your class from light med or Heavy
		ClassChoice();
		//Creates A Character Class that I can use on the player
		CharacterStatsMod playerClass;
		//Checks To see which class you choice and then it Calls the method from characterStatsMod
		if (cLightClass)
		{
			playerClass.ClassLight();
		}
		else if (cMedClass)
		{
			playerClass.ClassMed();
		}
		else if (cHeavyClass)
		{
			playerClass.ClassHeavy();
		}
		//Checks to see if is dead and basically does the  main loop of combat
		while(!playerIsDead)
		{
			
			//Calls the enemy you might fight 
			EnemyEncounter();
			//Checks to see if you ran from the first fight or if you Died To make sure you don't level up from that
			if (!ranFromEnemy && enemyDefeated > 0 && pHp > 0)
			{
				//Calls the level up method from the player class
				playerClass.LevelUp();
			}
		
		}
		//If you died The Game will end
		if (playerIsDead)
		{
			//Calls Game over
			gameOver();
		}
	
}



//This method is for selecting your class And use a switch statement for selecting it.
void ClassChoice()
{
	SetConsoleTextAttribute(h, 2);
	cout << "Please choose you Class type" << endl;
	cout << "This will decide your Stats of your character!" << endl;
	SetConsoleTextAttribute(h, 6);
	cout << "0)Light class 1)Medium Class 2)Heavy Class " << endl;
	cin >> classChoice;
	//Makes sure that there is no way that the other bools are true at a time. Fail safe.
	switch (classChoice)
	{

	case 0:
		cLightClass = true;
		cMedClass = false;
		cHeavyClass = false;
		
	break;
	case 1:
		cLightClass = false;
		cMedClass = true;
		cHeavyClass = false;

		break;
	case 2:

		cLightClass = false;
		cMedClass = false;
		cHeavyClass = true;

		break;

	default:
		cin >> classChoice;
		break;
	}




}

//Allows you to see you stats 
void statChecker()
{
	SetConsoleTextAttribute(h, 5);
	cout << "Players Health: " << pHp << endl;
	cout << "Players Attack: " << pAtk << endl;
	cout << "Players Defense: " << pDef << endl;
	cout << "Players Speed: " << pSpd << endl;
}

//Allows enemies to be called
void EnemyEncounter()
{
	//Sets run to false cause its a new encounter
	ranFromEnemy = false;
	// Use current time as seed to make sure the random number is random. 
	srand(time(0));
	//Makes a random based on 1 or 2
	int enemyType = rand() % 2+1;
	//If enemyType = 1 it calls a Ninja for combat And if its 2 it calls a pirate
	if (enemyType == 1)
	{
		CombatNinja();	
	}
	else if (enemyType == 2)
	{
		CombatPirate();
	}

}


//This Code Is so that I could make make two different enemy encounters For some reason it didn't allow me tyo combine them
//So i had to make double the code that does the same thing.
void CombatNinja()
{
	//Creates A enemy class combantant
	cNinja enemy;
	//calls the method Enemy spawn which sets the enemy stats Enemies met changes how strong the enemy is
	enemy.enemySpawner(enemiesMet);
	SetConsoleTextAttribute(h, 7);
	cout << "A " << enemy.factionName <<  " Has shown up to slay you!" << endl;
	//Makes the enemy do its callout
	enemy.enemyShoutOut();
	//Combat to where as long as the enemy is at 0 or the player it will keep the combat going
	while (enemy.eHp >= 1 && pHp > 0) {
		SetConsoleTextAttribute(h, 2);
		cout << "You have a few choices on how to handle this enemy!" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "1)Attack 2)Run Away 3)View stats" << endl;
		cin >> playersActions;
		//Checks the players action and if you attack use the Enemy.Basic Attack to attack the enemy and the player right afterwards
		if (playersActions == 1)
		{
			DmgAmount = enemy.BasicAttack(pAtk, enemy.eDef);
			enemy.eHp -= DmgAmount;
			SetConsoleTextAttribute(h, 1);
			cout << "You hit the Enemy for: " << DmgAmount << " " << enemy.EnemyName << " Hp is: " << enemy.eHp << endl;
			//Checks if the enemy is alive so they can attack
			if (enemy.eHp >= 1)
			{
				DmgAmount = enemy.BasicAttack(enemy.eDmg, pDef);
				pHp -= DmgAmount;
				SetConsoleTextAttribute(h, 4);
				cout << "You were attack by the Enemy for: " << DmgAmount << " Points of Dmg " << "You current Hp is " << pHp << endl;
			}
			//If the enemy is dead The fight is over and goes back to the while that allows you to level up
			else if (enemy.eHp <= 0)
			{
				SetConsoleTextAttribute(h, 1);
				cout << enemy.EnemyName << " Was Defeated! There Last Words Were . . " << endl;
				//makes the enemy say its death line
				enemy.enemyDeathQuote();
				//Adds to the players score on kills
				enemyDefeated++;
				//Makes the next enemy stronger
				enemiesMet++;
			}
		}
		//This is if you try to run
		else if (playersActions == 2)
		{
			//fleeing is given a random number base on players speed
			fleeingNumber = pSpd + rand() % 7;
			//if you are number is highier you get away but it doesnt add it to your enemies defeated and makes your ran from enemy true
			if (fleeingNumber >= enemy.eSpd)
			{
				enemy.eHp = 0;
				SetConsoleTextAttribute(h, 1);
				cout << "You successfully got away" << endl;
				enemyEscaped++;
				ranFromEnemy = true;
				pHp = fullHP;
			}
			//If its not high enough Your player is attacked
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "You were not quick enough to get away!" << endl;
				DmgAmount = enemy.BasicAttack(enemy.eDmg, pDef);
				pHp -= DmgAmount;
				cout << "You were attack by the Enemy for: " << DmgAmount << " Points of Dmg " << "You current Hp is " << pHp << endl;
			}
		}
		else if (playersActions == 3)
		{
			//Allows you to check your stats 
			statChecker();
		}
		else
		{

		}

	}
	//if your hp is zero you are defeated and consider dead
	if (pHp <= 0)
	{
		playerIsDead = true;
	}

}
//This is the same as the Ninja cause i was running into some Issues making them the same Method.
//This is ok cause I can still add as many enemies changes as i want though.
void CombatPirate()
{
	//makes a enemy combantant
	cPirate enemy;
	//calls the method Enemy spawn which sets the enemy stats Enemies met changes how strong the enemy is
	enemy.enemySpawner(enemiesMet);
	SetConsoleTextAttribute(h, 7);
	cout << "A " << enemy.factionName << " Has shown up to slay you!" << endl;
	//Makes the enemy do its callout
	enemy.enemyShoutOut();
	//Combat to where as long as the enemy is at 0 or the player it will keep the combat going
	while (enemy.eHp >= 1 && pHp > 0) {
		SetConsoleTextAttribute(h, 2);
		cout << "You have a few choices on how to handle this enemy!" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "1)Attack 2)Run Away 3)View stats" << endl;
		cin >> playersActions;
		//Checks the players action and if you attack use the Enemy.Basic Attack to attack the enemy and the player right afterwards
		if (playersActions == 1)
		{
			DmgAmount = enemy.BasicAttack(pAtk, enemy.eDef);
			enemy.eHp -= DmgAmount;
			SetConsoleTextAttribute(h, 1);
			cout << "You hit the Enemy for: " << DmgAmount << " " << enemy.EnemyName << " Hp is: " << enemy.eHp << endl;
			//Checks if the enemy is alive so they can attack
			if (enemy.eHp >= 1)
			{
				DmgAmount = enemy.BasicAttack(enemy.eDmg, pDef);
				pHp -= DmgAmount;
				SetConsoleTextAttribute(h, 4);
				cout << "You were attack by the Enemy for: " << DmgAmount << " Points of Dmg " << "You current Hp is " << pHp << endl;
			}
			//If the enemy is dead The fight is over and goes back to the while that allows you to level up
			else if (enemy.eHp <= 0)
			{
				SetConsoleTextAttribute(h, 1);
				cout << enemy.EnemyName << " Was Defeated! There Last Words Were . . " << endl;
				//makes the enemy say its death line
				enemy.enemyDeathQuote();
				//Adds to the players score on kills
				enemyDefeated++;
				//Makes the next enemy stronger
				enemiesMet++;
			}
		}
		//This is if you try to run
		else if (playersActions == 2)
		{
			//fleeing is given a random number base on players speed
			fleeingNumber = pSpd + rand() % 7;
			//if you are number is highier you get away but it doesnt add it to your enemies defeated and makes your ran from enemy true
			if (fleeingNumber >= enemy.eSpd)
			{
				enemy.eHp = 0;
				SetConsoleTextAttribute(h, 1);
				cout << "You successfully got away" << endl;
				enemyEscaped++;
				ranFromEnemy = true;
				pHp = fullHP;
			}
			//If its not high enough Your player is attacked
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "You were not quick enough to get away!" << endl;
				DmgAmount = enemy.BasicAttack(enemy.eDmg, pDef);
				pHp -= DmgAmount;
				cout << "You were attack by the Enemy for: " << DmgAmount << " Points of Dmg " << "You current Hp is " << pHp << endl;
			}
		}
		else if (playersActions == 3)
		{
			//Allows you to check your stats 
			statChecker();
		}
		else
		{

		}

	}
	//if your hp is zero you are defeated and consider dead
	if (pHp <= 0)
	{
		playerIsDead = true;
	}


}


//This ends the game
void gameOver()
{

	SetConsoleTextAttribute(h, 4);
	cout << "You were defeated." << endl;
	cout << "You defeated :" << enemyDefeated << " Combantants" << endl;
	cout << "You escaped :" << enemyEscaped << " Combantants" << endl;
	cout << "Thank you for playing!" << endl;

}