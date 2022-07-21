#include <iostream>
#include <string>
#include <queue>
#include <WaitingRoom.h>
#include <EmergencyRoomSim.h>



    ER_Sim :: ER_Sim() : highPriorityque("High Priority Patients"), midPriorityque("Mid Priority Patients"), lowPriorityque("Low Priority Patients"), clock(0), finishTime(0){}     // Low Priority patient que, mid Prioroty patient que, High priority patient que

    void ER_Sim :: run_Sim()     // runs simulation
    {

    }

    void ER_Sim :: enter_data()  // Reads in the data for the simulation
    {
        // Enter data function obtains the specifications for the simulation

        // Rate of low, mid, high priority patients

        // Max processing time for both doctor and nurse

        // total time

        // bool show all - > displays minute by minute trace of sim
    }

    void ER_Sim :: show_stats()  // Display the summary statistics
    {
        std :: cout << "The number of low priority patients seen was " << lowPriorityque.get_appointments() << std :: endl;

        std :: cout << "The number of mid priority patients seen was " << midPriorityque.get_appointments() << std :: endl;

        std :: cout << "The number of high priority patients seen was " << highPriorityque.get_appointments() << std :: endl;


        std :: cout << "Patients in low priority que " << lowPriorityque.size() << std :: endl;

        std :: cout << "Patients in mid priority que " << midPriorityque.size() << std :: endl;

        std :: cout << "Patients in high priority que " << highPriorityque.size() << std :: endl;
    }