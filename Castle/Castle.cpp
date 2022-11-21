#include "Castle.h"

#include <iostream>
using namespace std;



void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

void Castle::DcreamentHealth(double DHealth)
{
	if (DHealth > 0)
	{
		Health = Health - DHealth;
	}
}

void Castle::SetSTDhealth(double h)
{
	STDhealth = h;
}

void Castle::SetN(int n)
{
	N = n;
}

void Castle::SetPower(double p)
{
	power = p;
}

int Castle::GetN()
{
	return N;
}

double Castle::GetPower()
{
	return power;
}


double Castle::GetHealth() const
{
	return Health;
}

double Castle::GetSTDhealth() const
{
	return STDhealth;
}

double Castle::Attack_Enemies(Enemy* p)
{
	double Dce;
	//cout << "disatance " << Dce << "  \n";
	Dce = (1 /double( p->GetDistance())) * double(GetPower());
	//cout << "from the castle " << Dce << "  \n";
	return Dce;
	
}
