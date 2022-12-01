#include <iostream>
#include <CareGiver.h>
//#include <Patient.h>



    // is a doctor available to help a patient?
    bool Doctor :: available(int clock, Doctor doc)
    {
        if(clock >= busyUntil)  // if the current clock time is past clock time when doctor is busy until
        {
            return true;    // doctor is available
        }else
        return false;   // doctor is not available
    }

    // make a doctor busy
    void Doctor :: setbusy(int newtime)
    {
        busyUntil = newtime;
    }

    // is a nurse available to help a patient?
    bool Nurse :: available(int clock, Nurse nurse)
    {
        if(clock >= busyUntil)
        {
            return true;
        }else
        return false;
    }

    // make a nurse busy
    void Nurse :: setbusy(int newtime)
    {
        busyUntil = newtime;
        
    }