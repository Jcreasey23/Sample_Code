#include <iostream>
#include <string>


class CareGiver
{

private:

    // int max_severity;
    // int max_CareTime;
    int busyUntil = 0;

public:

    void treatPatient();

    bool available();

    void setbusy(int clock);


};

class Doctor : public CareGiver
{

private:

    int max_severity = 20;
    int max_CareTime = 20;
    int busyUntil = 0;

public:

    void treatPatient(int clock, Doctor doc);

    bool available(int clock, Doctor doc);

    void setbusy(int clock);
};

class Nurse : public CareGiver
{

private:

    int max_severity = 10;
    int max_CareTime = 10;
    int busyUntil = 0;

public:

    void treatPatient(int clock, Nurse nurse);

    bool available(int clock, Nurse nurse);

    void setbusy(int clock);

};

