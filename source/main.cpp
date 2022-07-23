#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <EmergencyRoomSim.h>

int main()
{


ER_Sim Simulation;
Simulation.enter_data(); // Collects the simulation boundaries/ expectations
Simulation.run_Sim();   // Runs simulation
Simulation.show_stats(); //Displays minute-minute recount of simulation



}
///////////////////
// End of Main
///////////////////
