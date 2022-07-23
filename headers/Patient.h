#include <map>
#include <iostream>
#include <string.h>
#include <fstream>


class Patient
{
private:
    std:: string patientName;

    int startcaretime;

    int endcaretime;

    int arrivalTime;

    int severity;

    int admittedcount;

    bool treated;

public:
    Patient(int arrivaltime);

    int get_arrivaltime() const;

    int get_caretime() const;

    std:: string get_PatientName();

    int get_Severity() const;

    void set_Severity(int sev);

    void set_arrivaltime(int time);

    void set_startcare(int time);

    void set_endcare(int time);
    
    void set_name(std:: string name);
};


