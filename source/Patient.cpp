#include <map>
#include <iostream>
#include <string.h>
#include <fstream>
#include <Patient.h>


    Patient:: Patient(int arrivaltime)
    {
        arrivalTime = arrivaltime;
        caretime = 1; //+ myrandom.next_int(maxprocessing time)
        patientName;  // = random name from list of names
    }

    int Patient :: get_arrivaltime() const
    {
        return arrivalTime;
    }

    int Patient :: get_caretime() const
    {
        return caretime;
    }

    std:: string Patient :: get_PatientName()
    {
        return patientName;
    }

    static void set_maxcaretime(int maxCare)
    {
        // Max care for a nurse is 1-10 min
        // Max care for a Dr. is 1-20 min
    }