#include <iostream>
#include <string>
#include <WaitingRoom.h>


class ER_Sim
{
private:
        // Data fields
    WaitingRoom lowPriorityque;

    WaitingRoom midPriorityque;

    WaitingRoom highPriorityque;

    int maxCaretime;    // Maximum care time

    int totTime;        // Total time

    bool showAll;       // A flag indicating whether to trace simulation
    
    int clock;          // Current clock time

    int finishTime;     // Time Current patient will be finished

    public:

    ER_Sim() : highPriorityque("High Priority Patients"), midPriorityque("Mid Priority Patients"), lowPriorityque("Low Priority Patients"), clock(0), finishTime(0){}     // Low Priority patient que, mid Prioroty patient que, High priority patient que

    void run_Sim();     // runs simulation

    void enter_data();  // Reads in the data for the simulation

    void show_stats();  // Display the summary statistics



};

