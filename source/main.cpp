#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <EmergencyRoomSim.h>

int main()
{


ER_Sim Simulation;
Simulation.enter_data(); // Collects the simulation boundaries/ expectations
Simulation.run_Sim();   // Runs simulation
Simulation.show_stats(); //Displays minute-minute recount of simulation

int userselec = 0;
std:: cout << "Post Simulation Menu" << std:: endl;
std:: cout << "1 - List all Patients by name " << std:: endl
           << "2 - Search for Patient by First name" << std:: endl;
std:: cin >> userselec;

           if(userselec == 1)
           {
            // call list all Patients

           }else if(userselec == 2)
           {
            std :: string lookupName;
            std :: cout << "Please enter the first name of the patient you are looking for." << std:: endl;
            std:: cin >> lookupName; 
            // call search for patient

           }

}
///////////////////
// End of Main
///////////////////
