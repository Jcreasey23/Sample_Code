#include <iostream>
#include <WaitingRoom.h>
#include <ctime>
#include <queue>

WaitingRoom :: WaitingRoom() {}//: numAppointments(0){}

    int WaitingRoom :: get_appointments() const
    {
        return numAppointments;
    }

    int WaitingRoom :: get_totPatTime() const
    {
        return totalpatTime;
    }


    void WaitingRoom :: checkArrival(int clock, bool showAll)
    {
        int randompat = rand()% 2000 +1;
        double temp = myRandom.next_double();
        if(temp < arrivalrate)
        {
            Patient p = Patient(clock);
            p.set_arrivaltime(clock);
            p.set_name(residents[randompat]);

            int probabilty;
            std:: srand (time(NULL));
            probabilty = rand() % 10 + 1;
            if(probabilty <= 7)
            {
                int temp = rand() % 10 + 1;
                p.set_Severity(temp);
                lowPriorityqueue.push(p);
                
            }
            if(probabilty >= 8 && probabilty <=9)
            {
                int temp = rand() % 4 + 11;
                p.set_Severity(temp);
                midPriorityqueue.push(p);

            }
            if(probabilty == 10)
            {
                int temp = rand() % 4 + 16;
                p.set_Severity(temp);
                highPriorityqueue.push(p);
            }
        }
    }

    void WaitingRoom :: setArrivalrate(double newArrivalrate)
    {
        arrivalrate = newArrivalrate / 60;
    }

    bool WaitingRoom :: empty() const
    {

    }

    int WaitingRoom :: waitingroomct()
    {
        return highPriorityqueue.size() + midPriorityqueue.size() + lowPriorityqueue.size();

    }

    Patient WaitingRoom :: nextPatient()
    {
        // Check queues in order
        if(highPriorityqueue.size() != 0)
        {
            // See what patient is next in high priority queue
             return highPriorityqueue.front();

        }else if(midPriorityqueue.size() != 0)
        {
            // See what patient is in the mid priority queue
            return midPriorityqueue.front();

        }else if(lowPriorityqueue.size() != 0)
        {
            // See what patient is in the low priority queue
            return lowPriorityqueue.front();
        }
        // Then waiting room is empty
        else
        {
            return NULL;
        }

    }

    void WaitingRoom :: removePatient(Patient pat)
    {
                
        int temp = pat.get_Severity();
        if(temp > 15)
        {
            highPriorityqueue.pop();
            processedPatients.push(pat);
        } else if(temp > 9 && temp < 16)
        {
            midPriorityqueue.pop();
            processedPatients.push(pat);
        } else if(temp > 0 && temp < 11)
        {
            lowPriorityqueue.pop();
            processedPatients.push(pat);
        }

    }