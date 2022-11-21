#pragma once
#include "..\Defs.h"
#include "..\Enemies\Enemy.h"
class Castle
{
	double Health;
	double STDhealth;
	int N; // that is the Max # of enemies it can attack
	double power; // the power of the castle, I made it double but it may be int as the formula in phase 2 will be

	//
	// TODO: Add More Data Members As Needed
	//

public:

	void SetHealth(double h);
	void DcreamentHealth(double DHealth);
	void SetSTDhealth(double h);
	void SetN(int n);
	void SetPower(double p);

	
	int GetN();
	double GetPower();
	double GetHealth() const;
	double GetSTDhealth() const;

	double Attack_Enemies(Enemy *p);
	//
	// TODO: Add More Member Functions As Needed
	//

};

