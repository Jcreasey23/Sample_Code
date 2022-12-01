#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <EmergencyRoomSim.h>

int main()
{


ER_Sim Simulation;  // simulation object
Simulation.enter_data(); // Collects the simulation boundaries/ expectations
Simulation.run_Sim();   // Runs simulation

int userselec = 0;
std:: cout << "Post Simulation Menu" << std:: endl;
while(userselec != 4)
{
    std:: cout << "1 - List all Patients by name " << std:: endl
            << "2 - Search for Patient by First name" << std:: endl
            << "3 - Get Simulation statistics" << std:: endl 
            << "4 - Exit Post Simulation" << std:: endl;
    std:: cin >> userselec;

        Simulation.postSim(userselec);  // allows user to interact with results of sim
}

}
///////////////////
// End of Main
///////////////////
