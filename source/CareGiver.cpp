#include <iostream>
#include <CareGiver.h>
//#include <Patient.h>




    bool Doctor :: available(int clock, Doctor doc)
    {
        if(clock >= busyUntil)
        {
            return true;
        }else
        return false;
    }

    void Doctor :: setbusy(int newtime)
    {
        busyUntil = newtime;
    }


    void Nurse :: treatPatient(int clock, Nurse nurse)
    {
        if(available(clock, nurse) == true)
        {
            
        }
    }   

    bool Nurse :: available(int clock, Nurse nurse)
    {
        if(clock >= busyUntil)
        {
            return true;
        }else
        return false;
    }

    void Nurse :: setbusy(int newtime)
    {
        busyUntil = newtime;
        
    }