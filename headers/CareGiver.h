#include <iostream>
#include <string>


class CareGiver
{

private:
    int busyUntil = 0;  // indicates clock time in which doctor is busyt helping patient

public:

    void treatPatient();    // Caregiver treats patient

    bool available();       // Is the caregiver available to help a patient

    void setbusy(int clock);    // Set busy until clock time


};

class Doctor : public CareGiver
{

private:

    int busyUntil = 0;  // indicates clock time in which doctor is busyt helping patient

public:

    void treatPatient(int clock, Doctor doc);   // Doctor treats patient at a clock time in sim

    bool available(int clock, Doctor doc);      // Doctor is available at clock time in sim

    void setbusy(int clock);                // sets doctor as busy until a new clock time
};

class Nurse : public CareGiver
{

private:

    int busyUntil = 0;  // indicates clock time in which nurse is busyt helping patient

public:

    void treatPatient(int clock, Nurse nurse);  // Nurse treats patient at clock time in sim

    bool available(int clock, Nurse nurse);     // Nurse is available at clock time in sim

    void setbusy(int clock);                // sets Nurse as busy until a new clock time

};

