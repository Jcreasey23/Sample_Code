#include <map>
#include <iostream>
#include <string.h>
#include <fstream>
#include <Patient.h>


    Patient:: Patient(int arrivaltime)
    {
        arrivalTime = arrivaltime;  // sets patient arrival time to clock time in sim
    }

    int Patient :: get_arrivaltime() const
    {
        return arrivalTime; // gets arrival time of patient in waiting room
    }

    int Patient :: get_endtime()
    {
        return endcaretime; // gets clock time when patient is done being processed
    }

    std:: string Patient :: get_PatientfName()
    {
        return patientfName;    // gets patient's first name
    }

    std:: string Patient :: get_Patientlname()
    {
        return patientlName;    // gets patient's last name
    }

    int Patient :: get_Severity() const
    {
        return severity;    // gets patient's severity of illness
    }

    void Patient :: set_Severity(int sev)
    {
        severity = sev; // sets the severity of a patient's illness
    }

    int Patient :: get_averagetime(Patient pat)
    {
        int totaltime;  // returns total time patient is at ER
        totaltime = pat.get_endtime() - pat.get_arrivaltime();  // patient's done process - arrival to ER = total time at ER
        return totaltime;

    }

    void Patient :: set_arrivaltime(int time)
    {
        arrivalTime = time;     // sets arrival time of patient at ER
    }

    void Patient :: set_startcare(int time)
    {
        startcaretime = time;   // set when a patient's care begins
    }

    void Patient :: set_endcare(int time)
    {
        endcaretime = time; // set when patient's care is finished
    }

    void Patient :: set_name(std:: string fname, std:: string lname)
    {
        patientfName = fname;   // sets patient's first name
        patientlName = lname;   // sets patient's last name
    }