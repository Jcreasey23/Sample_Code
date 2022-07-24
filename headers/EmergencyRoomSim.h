#include <iostream>
#include <string>
//#include <WaitingRoom.h>
#include <Hospital.h>


class ER_Sim
{
private:
    // sub queues based on priority
    Hospital hospital;  // Hospital object in which the simulation is going to occur

//////////////////////////////////////////////////////////////////
    int patientarrivalrate; // entered by user max 60 per hour

    int numDoctors;         // entered by user

    int numNurses;          // entered by user

    int caretimeDoc = 20;    // Maximum care time random between 1-20 min

    int careTimeNurse = 10;  // Maximum care time random between 1-10 min

    int totTime =  24*60;//(7*24*60);        // Total time one week

    bool showAll;       // A flag indicating whether to trace simulation
    
    int clock;          // Current clock time

    int finishTime;     // Time Current patient will be finished
////////////////////////////////////////////////////////////////////////////////////////////////////
public:


    ER_Sim();/// : clock(0), finishTime(0)

    void run_Sim();     // runs simulation

    void enter_data();  // Reads in the data for the simulation

    void postSim(int userselection);    // Allows user to interact with simulation results

};

