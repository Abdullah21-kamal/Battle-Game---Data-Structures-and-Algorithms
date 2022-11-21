#include "Battle.h"
#include "GUI\GUI.h"
#include<iostream>
using namespace std;

int main()
{
	
	Battle* pGameBattle = new Battle;
	pGameBattle->RunSimulation();
	



	

	
	delete pGameBattle;
	
	return 0;
}
