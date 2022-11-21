#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(int id, int arrTime, int d):ID(id),ArrvTime(arrTime)
{
	SetDistance(d);
}

Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}



void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
	{
		Distance = Distance - GetSpeedOfEnemy();
	}
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}

void Enemy::SetPriority(int distance, int power, int helth, int reloadT)
{
	Priority = (power * helth) / (distance * reloadT);
}

double Enemy::GetPriority()
{
	Priority = (PowerOfEnemy * Health) / (Distance * Reload_PeriodEnemy);
	return Priority;
}



void Enemy::SetType(int ty)
{
	Type = ty;
}

void Enemy::SetPowerOfEnemy(int PE)
{
	PowerOfEnemy = PE;
}

int Enemy::GetPowerOfEnemy()
{
	return PowerOfEnemy;
}

void Enemy::SetReload_PeriodEnemy(int RP)
{
	Reload_PeriodEnemy = RP;
}

void Enemy::SetSpeedOfEnemy(int SPD)
{
	SpeedOfEnemy = SPD;
}

int Enemy::GetSpeedOfEnemy()
{
	return SpeedOfEnemy;
}

void Enemy::SetHealthOfEnemy(int HLTH)
{
	Health = HLTH;
}

double Enemy::GetHealthOfEnemy()
{
	return Health;
}

void Enemy::DecreaseHealth(double DCHLTH)
{
	if (Health > 0)
	{
		Health = Health - DCHLTH;
	}
}

void Enemy::SetSTDHealth(int HLTH)
{
	STD_health = HLTH;
}

double Enemy::GetSTDHealth()
{
	return STD_health;
}

int Enemy::GetTypeOfEnemy() const
{
	return Type;
}

double Enemy::Attack_Castle()
{
	double Dfc;
	if (GetHealthOfEnemy() <= 0.5 * GetSTDHealth())
	{
		Dfc = (1 / double(GetDistance())) * double(GetPowerOfEnemy());
	}
	else
		Dfc = (0.5 / double(GetDistance())) * double(GetPowerOfEnemy());

	return Dfc;
}

void Enemy::SetKTS(int T)
{
	KTS = T;
}

int Enemy::GetKTS()
{
	return KTS;
}


