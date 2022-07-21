#include <iostream>
#include <string>
#include <queue>
#include <Patient.h>



class WaitingRoom
{
    // This class will act as the patient que and summary data about
private:
    std:: queue<Patient> pat_que;

    std:: string queName;

    int numAppointments;

    double arrivalrate;

public:
    WaitingRoom(std:: string my_name) : numAppointments(0), queName(my_name){};

    int get_appointments() const;

    std:: string  get_quename() const;

    size_t size() const;

    void checkArrival(int clock, bool showAll);

    int update(int clock, bool showAll);

    void setArrivalrate(double newArrivalrate);

    bool empty() const;



};