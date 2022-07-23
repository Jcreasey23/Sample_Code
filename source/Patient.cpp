#include <map>
#include <iostream>
#include <string.h>
#include <fstream>
#include <Patient.h>


    Patient:: Patient(int arrivaltime)
    {
        arrivalTime = arrivaltime;
        patientName;  // = random name from list of names
    }

    int Patient :: get_arrivaltime() const
    {
        return arrivalTime;
    }

    std:: string Patient :: get_PatientName()
    {
        return patientName;
    }

    int Patient :: get_Severity() const
    {
        return severity;
    }

    void Patient :: set_Severity(int sev)
    {
        severity = sev;
    }

    void Patient :: set_arrivaltime(int time)
    {
        arrivalTime = time;
    }

    void Patient :: set_startcare(int time)
    {
        startcaretime = time;
    }

    void Patient :: set_endcare(int time)
    {
        endcaretime = time;
    }