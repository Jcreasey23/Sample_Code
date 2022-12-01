#include <iostream>
#include <string>
#include <queue>
#include <Patient.h>
#include <Random.h>



class WaitingRoom
{
    // This class will act as the patient que and summary data about
private:
    std:: queue<Patient> lowPriorityqueue;

    std:: queue<Patient> midPriorityqueue;

    std:: queue<Patient> highPriorityqueue;

    std :: multimap<std::string, Patient> processedPatients;

    std :: vector<std::string> firstNames;

    std:: vector<std::string> lastnames;

    std:: string queName;

    int totalpatTime;

    int numAppointments = 0;

    double arrivalrate;

    Random myRandom;

public:
    WaitingRoom();

    int get_appointments() const;       // gets numner of appointments in simulation

    int get_totPatTime() const;         // determines how long patient was at ER

    void checkArrival(int clock, bool showAll); // Checks for the arrival of a new patient in the waiting room

    void setArrivalrate(double newArrivalrate); // sets arrival rate of patients coming into the waiting room

    int waitingroomct();    // current size of the waiting room

    Patient nextPatient();  // Looks for next patient to be helped

    void removePatient(int clock, Patient pat); // removes patient from waiting room queue and adds them to a processed patient map

    void readnames();   // reads names of 2000 potential patients in the city of 273ville

    void postSim(int userselection);    // Allows user to interact with simulation results


};