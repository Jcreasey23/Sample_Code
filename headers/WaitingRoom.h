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

    std :: queue<Patient> processedPatients;

    std :: vector<std::string> firstNames;

    std:: vector<std::string> lastnames;

    std:: string queName;

    int totalpatTime;

    int numAppointments = 0;

    double arrivalrate;

    Random myRandom;

public:
    WaitingRoom();// : numAppointments(0){};

    int get_appointments() const;

    int get_totPatTime() const;

    size_t size() const;

    void checkArrival(int clock, bool showAll);

    int update(int clock, bool showAll);

    void setArrivalrate(double newArrivalrate);

    bool empty() const;

    int waitingroomct();

    Patient nextPatient();

    void removePatient(Patient pat);

    void readnames();


};