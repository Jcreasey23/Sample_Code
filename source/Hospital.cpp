#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Hospital.h>


    void Hospital :: createDoctors(int numDoc)
    {
        for(int i = 0; i < numDoc; i++)
        {
            Doctor d;
            doctors.push_back(d);
        }
    }

    void Hospital :: createNurses(int numNur)
    {
        for(int j = 0; j < numNur; j++)
        {
            Nurse n;
            nurses.push_back(n);
        }
    }

    bool Hospital :: findCaretaker(int clock, Patient p)
    {
        if(p.get_Severity() >= 11)
        {
            for(int i = 0; i < doctors.size(); i++)
            {
                if(doctors[i].available(clock, doctors[i]) == true) // if doctor is available... make him busy for rand time
                {

                    int temp = rand() % 20 + 1;
                    p.set_startcare(clock);
                    doctors[i].setbusy(clock + temp);
                    p.set_endcare(clock + temp);
                    return true;
                }
            }
        } 
        if(p.get_Severity() <=10)
        {
            for(int i = 0; i < nurses.size(); i++)
            {
                if(nurses[i].available(clock,nurses[i]))
                {
                    int temp = rand() % 10 + 1;
                    p.set_startcare(clock);
                    nurses[i].setbusy(clock + temp);
                    p.set_endcare(clock + temp);
                    return true;
                }
            }
            // If all nurses are busy then check for available doctors
            for(int i = 0; i < doctors.size(); i++)
            {
                if(doctors[i].available(clock, doctors[i]) == true) // if doctor is available... make him busy for rand time
                {

                    int temp = rand() % 20 + 1;
                    p.set_startcare(clock);
                    doctors[i].setbusy(clock + temp);
                    p.set_endcare(clock + temp);
                    return true;
                }
            }
        }
        return false;
    }

   