#include <map>
#include <iostream>
#include <string.h>
#include <fstream>


class Patient
{
private:
    std:: string patientName;

    int caretime;

    int arrivalTime;

    static int maxcareTime;

    // Do i need to include a que number?? i don't think so because they will be given a priority based on illness
    
public:
    Patient(int arrivaltime);

    int get_arrivaltime() const;

    int get_caretime() const;

    std:: string get_PatientName();

    static void set_maxcaretime(int maxCare);
};


