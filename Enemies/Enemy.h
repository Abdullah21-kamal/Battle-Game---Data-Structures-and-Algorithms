#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

//protected:
public:
	//const int ID;         //Each enemy has a unique ID (sequence number) 
	int ID;
	//const int ArrvTime;	//arrival time (time it starts to join battle)
	int ArrvTime;

	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health,STD_health;	//Enemy health

	double Priority;
	//
	// TODO: Add More Data Members As Needed
	int Type, PowerOfEnemy, Reload_PeriodEnemy, SpeedOfEnemy;
	
	int KTS; // the time at which it is killed

//public:
	Enemy();
	Enemy(int id, int arrTime, int d = MaxDistance);
	virtual ~Enemy();
	int Distance;
	int Enemy::GetID() const;
	
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);
	
	void DecrementDist();

	void SetDistance(int d);
	int GetDistance() const;

	int GetArrvTime() const;
	
	void SetPriority(int Distance, int power, int helth,int ReloadT);
	double GetPriority();
	
	void SetType(int ty);

	void SetPowerOfEnemy(int PE); // I made the power of the enemy as integer 
	int GetPowerOfEnemy();

	void SetReload_PeriodEnemy(int RP);

	void SetSpeedOfEnemy(int SPD);
	int GetSpeedOfEnemy();

	void SetHealthOfEnemy(int HLTH);
	double GetHealthOfEnemy();
	void DecreaseHealth(double DCHLTH);

	void SetSTDHealth(int HLTH);
	double GetSTDHealth();

	int GetTypeOfEnemy() const;
	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing
	double Attack_Castle();
	//
	// TODO: Add More Member Functions As Needed
	//
	void SetKTS(int T);
	int GetKTS();
};

