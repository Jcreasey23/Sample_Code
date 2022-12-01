#include <map>
#include <iostream>
#include <string.h>
#include <fstream>


class Patient
{
private:
    std:: string patientfName;

    std:: string patientlName;

    int startcaretime;

    int endcaretime;

    int arrivalTime;

    int severity;

    int admittedcount;

    bool treated;

public:
    Patient(int arrivaltime);   // Patient constructor

    int get_arrivaltime() const;    // gets the clock arrival time of patient

    int get_endtime();  // gets end time when patient has been processed

    std:: string get_PatientfName();    // gets patient's first name

    std:: string get_Patientlname();    // gets patient's last name

    int get_Severity() const;       // gets patient's severity of illness on arrival to Waiting room

    int get_averagetime(Patient pat);   // helps calculate avg. patient waiting time in waiting room

    void set_arrivaltime(int time); // sets arrival time of a new patient

    void set_startcare(int time);   // sets when a patient recieves care

    void set_Severity(int sev);     // sets severity of an illness

    void set_endcare(int time);     // sets time after processed patient
    
    void set_name(std:: string fname, std:: string lname);  // sets first and last names of a patient
};


