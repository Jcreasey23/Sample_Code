#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Hospital.h>


    void Hospital :: createDoctors(int numDoc)  // fills vector with doctor objects
    {
        for(int i = 0; i < numDoc; i++)
        {
            Doctor d;
            doctors.push_back(d);
        }
    }

    void Hospital :: createNurses(int numNur)   // fills vector with Nurse objects
    {
        for(int j = 0; j < numNur; j++)
        {
            Nurse n;
            nurses.push_back(n);
        }
    }

    bool Hospital :: findCaretaker(int clock, Patient p)
    {
        if(p.get_Severity() >= 11)// if a patient's severity is 11 or greater
        {
            for(int i = 0; i < doctors.size(); i++) // look for available doctors
            {
                if(doctors[i].available(clock, doctors[i]) == true) // if doctor is available... make him busy for rand time
                {

                    int temp = rand() % 20 + 1;
                    p.set_startcare(clock); // start care for patient
                    doctors[i].setbusy(clock + temp);   // make busy until done caring for patient
                    p.set_endcare(clock + temp);    // set end care for patient
                    return true;    // caretaker was found for patient
                }
            }
        } 
        if(p.get_Severity() <=10)   // if patient severity is 10 or lower
        {
            for(int i = 0; i < nurses.size(); i++)  // look for available Nurses
            {
                if(nurses[i].available(clock,nurses[i]))    // if nurse is available... make them busy for rand time
                {
                    int temp = rand() % 10 + 1;
                    p.set_startcare(clock); // start care for patient
                    nurses[i].setbusy(clock + temp); // make busy until done caring for patient
                    p.set_endcare(clock + temp);    // set end care for patient
                    return true;    // caretaker was found for patient
                }
            }
            // If all nurses are busy then check for available doctors
            for(int i = 0; i < doctors.size(); i++)
            {
                if(doctors[i].available(clock, doctors[i]) == true) // if doctor is available... make him busy for rand time
                {

                    int temp = rand() % 20 + 1;
                    p.set_startcare(clock); // start care for patient
                    doctors[i].setbusy(clock + temp);   // make busy until done caring for patient
                    p.set_endcare(clock + temp);    // set end care for patient
                    return true;    // caretaker was found for patient
                }
            }
        }
        return false;   // if no caretakers are available to help patient.. return false as no one can help at clock time
    }

   