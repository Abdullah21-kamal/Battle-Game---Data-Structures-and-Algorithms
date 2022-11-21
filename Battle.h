#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "GUI\GUI.h"
#include "ArrayStack.h"	
// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;
	Castle myCastle;
	int EnemyCount;	//the actual number of enemies in the game
	int ActiveCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far) 
	int NumOfActiveFreezer = 0;
	int DangerousFighters = 0;
	int NormalFighters = 0;
	int CurrentTimeStep;
	int TotalNumOFenemies; // added recently
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	
	Queue<Enemy*> Q_Freezers;

	//Queue<Enemy*> Q_DangerousFighters;
	//Queue<Enemy*> Q_NormalFighters;
	//const int N = 110;
	//int Ngg = 100;
	ArrayStack<Enemy*> S_Healers;
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue for all enemies in the battle
	int DemoListCount;
	int EnemiesNum;

	Enemy* DemoList[MaxEnemyCount];	//Important: This is just for demo
	/// ==>


	//
	// TODO: Add More Data Members As Needed
	int Health_loadedFile, N_loadedFile, Power_loadedFile, total_enemies;
	int id, type, arrivalTime, health, power, reload_period, speed;
	

public:
	void SetTotalNumOfenemies(int TNE);
	Battle();
	void AddAllListsToDrawingList();		//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle * GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived

	
	void AddtoDemoList(Enemy* Ptr);		//Add Enemy to the demo queue of enemies (for demo purposes only)
	
	void Fill_Loading();	//just a demo function ------> fill loading function
	void playing();
	//void Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes)
	void EnemiesUpdate();
	//
	// TODO: Add More Member Functions As Needed
	void AddtoBEnemiesForDraw(Enemy* Ptr);
	void War();
	//
};

