#include "Battle.h"
#include <time.h>
// to fill loadin function
#include "PriorityQ.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Castle\Castle.h"
#include "Generic_DS\PQueue.h"
using namespace std;

enemy_Priority_Queue Fighters;
PQueue<Enemy*> Fighters_PQ;
Queue<Enemy*> dd;
Queue<Enemy*> Killed;
Queue<Enemy*> Frosted;
int NUMOFFREZZERS = 0;
Battle::Battle()
{	
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	DemoListCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}

void Battle::AddtoDemoList(Enemy* Ptr)
{
	DemoList[DemoListCount++] = Ptr;
	
	// Note that this function doesn't allocate any enemy objects
	// It just enqueue a pointer that is already allocated into the queue
}

void Battle::AddtoBEnemiesForDraw(Enemy* Ptr)
{
	BEnemiesForDraw[DemoListCount++] = Ptr;
}

void Battle::War()
{
	Enemy* ppEE;
	//cout << "\n" << KilledCount << "  kills \n";
	//Fighters_PQ.GetCounter();
	if ((KilledCount >= TotalNumOFenemies) && (myCastle.GetHealth() <= 0))
	{
		if (KilledCount >= TotalNumOFenemies)
		{
			//cout << "\n K " << KilledCount << "  Fcounter " << TotalNumOFenemies << " \n";
			cout << "\n Castle Won!! \n";
		}
		cout << "Drwan";
	}
	else
	{
		if (myCastle.GetN() > Fighters_PQ.GetCounter())
		{
			for (int i = 0; i < Fighters_PQ.GetCounter(); i++)
			{
				//cout << " N > \n";
			}
		}
		else
		{
			//cout << "the # of fighters before dequeue  " << Fighters_PQ.GetCounter() << " \n";
			//Castle is attacking the Enemies
			double Damage;
			for (int i = 0; i < myCastle.GetN(); i++)
			{
				//cout << "F > \n";
				Fighters_PQ.dePQueue(ppEE);

				Damage = myCastle.Attack_Enemies(ppEE);
				//cout << " DMGE CE " << Damage << " \n";
				ppEE->DecreaseHealth(Damage);
				//cout << "new health is " << ppEE->GetHealthOfEnemy() << " \n";

				Fighters_PQ.enPQueue(ppEE, ppEE->GetPriority());
				//cout << "the # of fighters after dequeue  " << Fighters_PQ.GetCounter() << " \n";
			}
		}
		double DamageEC;
		// Enemies are attacking the castle
		for (int i = 0; i < Fighters_PQ.GetCounter(); i++)
		{
			Fighters_PQ.dePQueue(ppEE);
			DamageEC = ppEE->Attack_Castle();
			myCastle.DcreamentHealth(DamageEC);
			Fighters_PQ.enPQueue(ppEE, ppEE->GetPriority());
		}
	}
	//cout << "\n killed are " << KilledCount << "\n";
	//pGUI->waitForClick();

	for (int i = 0; i < Fighters_PQ.GetCounter(); i++)
	{
		Fighters_PQ.dePQueue(ppEE);
		if (ppEE->GetHealthOfEnemy() <= 0)
		{
			ppEE->SetStatus(KILD);
			KilledCount++;
			ActiveCount--;
			Killed.enqueue(ppEE);
		}
		else
		{
			Fighters_PQ.enPQueue(ppEE, ppEE->GetPriority());
		}
		ppEE->DecrementDist();
	}
	if ((myCastle.GetHealth() <= 0)){
		
		cout << "\n Enemies Won!! \n";
    }
	else if (KilledCount >= TotalNumOFenemies)
	{
		//cout << "\n K " << KilledCount << "  Fcounter " << TotalNumOFenemies << " \n";
		cout << "\n Game Won!!" << "\n" << "Total Num OF enemies " << TotalNumOFenemies << "\n";
	}
}


Castle * Battle::GetCastle()
{
	return &BCastle;
}

	
void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		playing();
		break;
	case MODE_SLNT:
		break;
	}

	delete pGUI;
	
}


//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
//void Battle::Just_A_Demo()
//{	
//	
//	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
//	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer
//
//	pGUI->PrintMessage("Generating Enemies randomly... In next phases, Enemies should be loaded from a file...CLICK to continue");
//	pGUI->waitForClick();
//
//	CurrentTimeStep = 0;
//	//
//	// THIS IS JUST A DEMO Function
//	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
//	//
//	 
//	srand(time(NULL));
//	int Enemy_id = 0;
//	int ArrivalTime=1;
//	Enemy* pE= NULL; 
//	//Create Random enemies and add them all to inactive queue
//	for(int i=0; i<EnemyCount; i++)
//	{			
//		ArrivalTime += (rand()%3);	//Randomize arrival time
//		pE = new Enemy(++Enemy_id,ArrivalTime);
//		pE->SetStatus( INAC); //initiall all enemies are inactive
//		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
//	}	
//
//	AddAllListsToDrawingList();
//	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive
//
//	pGUI->waitForClick();
//	
//	while( KilledCount < EnemyCount )	//as long as some enemies are alive (should be updated in next phases)
//	{
//		CurrentTimeStep++;
//		ActivateEnemies();
//
//		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)
//
//		pGUI->ResetDrawingList();
//		AddAllListsToDrawingList();
//		pGUI->UpdateInterface(CurrentTimeStep);
//		Sleep(250);
//	}		
//}

//modifided function to read the file and generate the enemies
void Battle::SetTotalNumOfenemies(int TNE)
{
	TotalNumOFenemies = TNE;
}

void Battle::Fill_Loading()
{


	pGUI->PrintMessage("click to load the Info file,click after time step to be 0 to start playing ");
	pGUI->waitForClick();

	CurrentTimeStep = 0;
	
	//Castle myCastle; // to fill the castle with Info from the loaded file
	int Enemy_id = 0;
	int ArrivalTime = 1;
	
	
	//Create Random enemies and add them all to inactive queue   ** it is ignored now**
	ifstream input("inputFile.txt");
	int i = 1;

	string line;
	if (!input.is_open()) {
		cout << "file is failed to be opened" << '\n';
		return;
	}
	
	// if it is still in the info of the castle and the nmber of enemies
	
	while ((i == 1) && input >> Health_loadedFile >> N_loadedFile >> Power_loadedFile) {
		//cout << Health_loadedFile << " " << N_loadedFile << " " << Power_loadedFile << endl;
		myCastle.SetHealth(Health_loadedFile);
		myCastle.SetSTDhealth(Health_loadedFile);
		myCastle.SetN(N_loadedFile);
		myCastle.SetPower(Power_loadedFile);
		//cout << "\n" << myCastle.GetN() << "  # enemies to be attacked  \n";
		i++;
	}



	while ((i == 2) && input >> total_enemies) {
		//cout << total_enemies << endl;
		TotalNumOFenemies = total_enemies;
		i++;
	}


	// to load the enemies 
	Enemy* pE = NULL;

	while (input >> id >> type >> arrivalTime >> health >> power >> reload_period >> speed && (i > 2))
	{
		pE = new Enemy(id, arrivalTime);
		pE->SetStatus( INAC); //initiall all enemies are inactive
		pE->SetType(type);
		pE->SetHealthOfEnemy(health);
		pE->SetSTDHealth(health);
		pE->SetPowerOfEnemy(power);
		pE->SetReload_PeriodEnemy(reload_period);
		pE->SetSpeedOfEnemy(speed);
		int dstnc = pE->Distance;
		pE->SetPriority(dstnc, power, health, reload_period);
		//cout << "<" << pE->GetSTDHealth() << "> ";
		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
	}
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);
	input.close();
}

void Battle::playing()
{
	Fill_Loading();
	pGUI->waitForClick();
	EnemyCount = total_enemies;
	//CurrentTimeStep++;
	ActivateEnemies();
	pGUI->ResetDrawingList();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);	
	
	while (KilledCount < TotalNumOFenemies)	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();

		EnemiesUpdate();

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);
		Sleep(250);


		//string num = to_string(ActiveCount);
		//cout << KilledCount << " kld  " << TotalNumOFenemies << " " << endl;
	}
}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{	
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const * EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
	{
		pGUI->AddToDrawingList(EnemyList[i]);
	}
	
	Enemy* const* FreezerList = Q_Freezers.toArray(NumOfActiveFreezer); // to draw freezers 
	for (int i = 0; i < NumOfActiveFreezer; i++)
	{ 
	    pGUI->AddToDrawingList(FreezerList[i]);
	}



	// int c = 0;
	int c;// to draw healers
	Enemy* const* HealerrList = S_Healers.toArray(c);
	for (int i = 0; i < c; i++)
	{
		//cout << c << endl;
		pGUI->AddToDrawingList(HealerrList[i]);
	}
	//int cc = 0;
	int cc;
	//dd = Fighters.to_queue();
	Enemy* const* FighterList = Fighters_PQ.toArray(cc);
	for (int i = 0; i < cc; i++)
	{
		//cout << cc << endl;
		pGUI->AddToDrawingList(FighterList[i]);
	}
	//Add other lists to drawing list
	//TO DO
	//In next phases, you should add enemies from different lists to the drawing list
	int killedNum;
	Enemy* const* KilledList = Killed.toArray(killedNum);
	for (int i = 0; i < killedNum; i++)
	{
		pGUI->AddToDrawingList(KilledList[i]);
	}
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	//vector<Enemy*> heapTree;
	
	Enemy *a,*b;
	while( Q_Inactive.peekFront(b) )	//as long as there are more inactive enemies
	{
		
		if(b->GetArrvTime() > CurrentTimeStep )	//no more arrivals at current time
			return;
		
		b->SetStatus(ACTV);	//make status active
		b->SetDistance(b->GetDistance());
		//cout << b->GetPriority();
		if (b->GetTypeOfEnemy() == 0 && (b->GetArrvTime() == CurrentTimeStep))
		{
			//Fighters.insert(*b);
			Fighters_PQ.enPQueue(b, b->GetPriority());
			//cout << "this is a fighter " << endl;
			ActiveCount++;
			
		}
		if (b->GetTypeOfEnemy() == 1 && (b->GetArrvTime() == CurrentTimeStep))
		{
			cout << "this is a Healer" << endl;
			S_Healers.push(b);
			ActiveCount++;
		}
		
		if (b->GetTypeOfEnemy() == 2 && (b->GetArrvTime() == CurrentTimeStep))			//pE to be added the DS of the Freezers
		{
			cout << "the Freezer" << endl;
			Q_Freezers.enqueue(b);
			NumOfActiveFreezer++;
			NUMOFFREZZERS++;
			ActiveCount++;
		}
		a = b;
		Q_Inactive.nxtEnemy(b);
	}
	War();
}


//Randomly update enemies distance/status (for demo purposes)
//void Battle::Demo_UpdateEnemies()	
//{
//	Enemy* pE;
//	int Prop;
//	//Freeze, activate, and kill propablities (for sake of demo)
//	int FreezProp = 5, ActvProp = 10, KillProp = 1;	
//	srand(time(0));
//	for(int i=0; i<DemoListCount; i++)
//	{
//		pE = DemoList[i];
//		switch(pE->GetStatus())
//		{
//		case ACTV:
//			pE->DecrementDist();	//move the enemy towards the castle
//			Prop = rand()%100;
//			if(Prop < FreezProp)		//with Freeze propablity, change some active enemies to be frosted
//			{
//				pE->SetStatus(FRST); 
//				ActiveCount--;
//				FrostedCount++;
//			}
//			else	if (Prop < (FreezProp+KillProp) )	//with kill propablity, kill some active enemies
//					{
//						pE->SetStatus(KILD);	
//						ActiveCount--;
//						KilledCount++;
//					}
//			
//			break;
//		case FRST:
//			Prop = rand()%100;
//			if(Prop < ActvProp)			//with activation propablity, change restore some frosted enemies to be active again
//			{
//				pE->SetStatus(ACTV);
//				ActiveCount++;
//				FrostedCount--;
//			}
//
//			else	if (Prop < (ActvProp+KillProp) )			//with kill propablity, kill some frosted enemies
//					{
//						pE->SetStatus(KILD);	
//						FrostedCount--;
//						KilledCount++;
//					}
//
//			break;
//		}
//	}
//}
void Battle::EnemiesUpdate()
{
	Enemy* pE, *pE2, *pE3, * pE4, * pE5, * pE6;
	ArrayStack<Enemy*> S;
	//S = S_Healers;
	//pGUI->waitForClick();
	int sizze = S_Healers.top + 1;
	for (int i = 0; i < S_Healers.top + 1; i++)
	{	
		S_Healers.pop(pE2);
		pE2->DecrementDist();
		S.push(pE2);
	}
	
	
	//Q_Freezers.enqueue(pE);
	//cout << "the # of NumOfActiveFreezer " <<NumOfActiveFreezer << endl;
	for (int i = 0; i < NUMOFFREZZERS; i++)
	{
		Q_Freezers.dequeue(pE);
		pE->DecrementDist();
		//cout << pE->GetDistance() << "Distance";
		Q_Freezers.enqueue(pE);
	}
	//cout << Fighters_PQ.GetCounter() << " I am here! \n";
	/*for (int i = 0; i < Fighters_PQ.GetCounter(); i++)
	{
		
		Fighters_PQ.dePQueue(pE);
		pE->DecrementDist();
		Fighters_PQ.enPQueue(pE,pE->GetPriority());
	}

	for (int i = 0; i < sizze; i++)
	{
		S.pop(pE3);
		S_Healers.push(pE3);
	}*/
	
	
	//if (CurrentTimeStep % 2 == 0)
	//{
	//	Fighters_PQ.dePQueue(pE);
	//	pE->SetStatus(FRST);
	//	cout << pE->GetDistance() << "Distance";
	//	Fighters_PQ.enPQueue(pE,pE->GetPriority());
	//	FrostedCount++;
	//	ActiveCount--;
	//}

	//if (CurrentTimeStep % 3 == 0)
	//{
	//	Fighters_PQ.dePQueue(pE);
	//	if(pE->status == FRST)
	//	{ 
	//	pE->SetStatus(ACTV);
	//	FrostedCount--;
	//	ActiveCount++;
	//	}
	//	//cout << pE->GetDistance() << "Distance";
	//	Q_Freezers.enqueue(pE);
	//}
	
}

