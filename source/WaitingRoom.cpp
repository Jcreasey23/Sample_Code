#include <iostream>
#include <WaitingRoom.h>
#include <ctime>
#include <queue>

WaitingRoom :: WaitingRoom() {}//: numAppointments(0){}

    int WaitingRoom :: get_appointments() const
    {
        return numAppointments;
    }

    std:: string WaitingRoom ::  get_quename() const
    {
        return queName;
    }

    int WaitingRoom :: get_totPatTime() const
    {
        return totalpatTime;
    }

    // size_t WaitingRoom :: size() const
    // {
    //     return Waitingroom.size();
    // }

    void WaitingRoom :: checkArrival(int clock, bool showAll)
    {
        double temp = myRandom.next_double();
        if(temp < arrivalrate)
        {
            Patient p = Patient(clock);
            p.set_arrivaltime(clock);
            //pat_que.push(p);  //push inside rand section
            // if(showAll)
            // {
            //     std:: cout << "Time is " << clock << ": " << queName << " Arrival, new queue size is " << Waitingroom.size() << std:: endl;
            // }
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

    // int WaitingRoom :: update(int clock, bool showAll)
    // {
    //     Patient nextPat = lowPriorityqueue.front();
    //     pat_que.pop();
    //     int timeStamp = nextPat.get_arrivaltime();
    //     int wait = clock - timeStamp;
    //     totalpatTime =+ wait;
    //     numAppointments++;

    //     if(showAll)
    //     {
    //         std:: cout << "Time is " << clock << ": Treating " << queName << " with time stamp " << timeStamp << std:: endl;
    //     }

    //     return clock + nextPat.get_caretime();
    // }

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