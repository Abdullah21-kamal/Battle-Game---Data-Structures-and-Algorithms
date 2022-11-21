# Battle-Game---Data-Structures-and-Algorithms
Data Structure and Algorithms in which I applied differnet structure to deal with the game based on the required description 
strucures like queues, pirority queses, linked lists and so on
#Description:
Back to the Middle Ages, assume you are the liege of a castle that you should protect against
enemies attacks. You need to use your programming skills and knowledge of data structures to
write a simulation program for a battle between your castle and enemies. You should simulate
the battle between them then calculate some statistics from this simulation.
Your system (your program) will receive the information about a list of enemies as input from an
input file. This list represents the scenario to be simulated. For each enemy the system will receive
the following information:
- Arrival Time stamp (Enemy Arrival Time): When the enemy arrives.
- Health: The starting health of the enemy.
- Power: The power of the enemy.
- Reload Period: Time for an enemy to reload its weapon.
- Speed: number of meters an enemy can move in a single time step.
- Type: fighter, freezer or healer
Simulation Approach & Assumptions

You will use incremental time simulation. You will divide the time into discrete time steps of 1 time
unit each and simulate the changes in the system in each time step.
Definitions

❑ Enemy Types: There are three types of enemies: fighter, healer, and freezer
▪ Fighter can attack castle and cause damage to castle.
▪ Healer can heal other enemies and does not attack castle.
▪ Freezer can throw ice on the castle to frost it for some time.
❑ Enemy Status:
At any time, an enemy should be in one of four states: inactive (not arrived yet), active,
frosted (both are described below) or killed (health <= 0). Only active enemies can act
(fight/heal/freeze).
❑ Active Enemy: is an enemy with Arrival Time ≤ current time step & Health > 0.
❑ Frosted Enemy:
Frosted enemies cannot move or attack castle. Any active enemy can be frosted for some
time steps (freezing time) due to an attack from the castle.
❑ Enemy distance: is the horizontal distance between the enemy and the castle.
❑ Reload Period: it is an interval where enemies are reloading their weapons. During
reload period enemies cannot act (i.e. cannot attack or heal) but can move. Once
reload period is over, enemies can act again.
▪ For example, Enemy e1(arrival time=5, reload period=3) will act at time step 5 then
wait to reload at time steps: 6, 7 and 8 then it will act again at time step 9 then wait to
reload at 10, 11 and 12 then act at 13 and so on.
