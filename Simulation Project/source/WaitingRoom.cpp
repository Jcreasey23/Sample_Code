#include <iostream>
#include <WaitingRoom.h>
#include <ctime>
#include <queue>

WaitingRoom :: WaitingRoom() {}

    int WaitingRoom :: get_appointments() const // gets the number of appointments in the whole sim
    {
        return numAppointments;
    }

    int WaitingRoom :: get_totPatTime() const // gets total time patient was at ER
    {
        return totalpatTime;
    }

    void WaitingRoom :: checkArrival(int clock, bool showAll)
    {
        // checks to see of there is a new patient in the waiting room
        std:: srand (clock);    // random seed for clock time
        int randompat = rand() % 1999;  // selects random patient from available citizens
        double temp = myRandom.next_double();   // holds random value less than one and greater than 0
        if(temp < arrivalrate)  // compares two values between 0-1... if true
        {
            Patient p = Patient(clock); // creates new patient at time clock
            p.set_arrivaltime(clock);   // sets arrival time for patient at time clock
            p.set_name(firstNames[randompat],lastnames[randompat]); // sets name based on random selction from citizens
            numAppointments++;  // new appointment so increase counter
            int probabilty; // probability of severity assignment
            probabilty = rand() % 10 + 1;
            if(probabilty <= 7) // 70% will be low priority patients
            {
                int temp = rand() % 10 + 1; // assign rand severity 1- 10
                p.set_Severity(temp);
                lowPriorityqueue.push(p);   // places patient into low priority queue
                
            }
            if(probabilty >= 8 && probabilty <=9)   // 20% will be mid priority patients
            {
                int temp = rand() % 4 + 11; // assign rand severity 11-15
                p.set_Severity(temp);
                midPriorityqueue.push(p);   // places patient into mid priority queue

            }
            if(probabilty == 10)    // 10% will be high priority patients
            {
                int temp = rand() % 4 + 16; // assign rand severity 16-20
                p.set_Severity(temp);
                highPriorityqueue.push(p);  // places patient into high priority queue
            }
        }
    }

    void WaitingRoom :: setArrivalrate(double newArrivalrate)
    {
        arrivalrate = newArrivalrate / 60;  // sets arrival rate to per minute rather than per hour compares for rand val to make waiting room more random
    }

    int WaitingRoom :: waitingroomct()
    {
        return highPriorityqueue.size() + midPriorityqueue.size() + lowPriorityqueue.size();    // num people in waiting room is size of all three queues together

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
            //return NULL;
        }

    }

    void WaitingRoom :: removePatient(int clock, Patient pat)
    {
        // removes patient from waiting room queue and places them into map of processed patients    
        int temp = pat.get_Severity();
        if(temp >= 16)  // if patient's severity belongs in high priority queue
        {
            highPriorityqueue.pop();    // take patient off of queue
            processedPatients.emplace(pat.get_PatientfName(),pat);  // place patient in multimap
        } else if(temp >= 11 && temp <= 15) // if patient belongs in midpriority queue
        {
            midPriorityqueue.pop(); // take patient off of queue
            processedPatients.emplace(pat.get_PatientfName(),pat);  // place patient in multimap
        } else if(temp >= 1 && temp <= 10)  // if patient belongs in low priority queue
        {
            lowPriorityqueue.pop(); // take patient offo of queue
            processedPatients.emplace(pat.get_PatientfName(),pat);  // place patient in multimap
        }

    }

    void WaitingRoom :: readnames()
    {   // reads names of individuals in city
    // I duplicated last names and assumed we have couples in the town so 2 people with same last name
        std::ifstream firstnames ("residents.txt"); // reads first names
        std::ifstream lastname ("surnames.txt");    // reads last names

        std:: string fname;
        std:: string lname;

        for(int i = 0; i < 2000; i++)
        {
            firstnames >> fname;
            lastname >> lname;
            firstNames.push_back(fname); // adds first name to frist name vector
            lastnames.push_back(lname); // adds last name to last name vector
        }
    }

    void WaitingRoom :: postSim(int userselection)
    {   // allow user to interact with results of simulation
        std:: multimap<std::string, Patient> :: iterator it;
        typedef std::multimap<std::string, Patient>::iterator multiMap;

    // if user wants to see all patients treated in simulated week at ER
        if(userselection == 1)
           {
            // call list all Patients
            for(it = processedPatients.begin(); it != processedPatients.end(); it++)
            {
                std:: cout << it->first << " " << it->second.get_Patientlname() << " | Severity at arrival: " << it->second.get_Severity()<< " | Total wait time: " << it->second.get_averagetime(it->second) << " minutes" << std:: endl;
                // prints first name, last name, severity of illness, total wait time in ER
            }
    // if user wants to look for particular person that has been treated
           }else if(userselection == 2)
           {
            std :: string lookupName;
            std :: cout << "Please enter the first name of the patient you are looking for." << std:: endl;
            std:: cin >> lookupName; 
            // call search for patient
            std::pair<multiMap, multiMap> result = processedPatients.equal_range(lookupName);   // look in multimap for a key that matches what the user entered

            // Iterate over the range
            for (multiMap it = result.first; it != result.second; it++)
            {

                std:: cout << it->first << " " << it->second.get_Patientlname() << " | Severity at arrival: " << it->second.get_Severity() << " | Total time in ER: " << it->second.get_averagetime(it->second) << std:: endl;
                // prints first name, last name, severity of illness, total wait time in ER
                // for each time they went in the simulated week
            }
           }
           else if(userselection == 3)
           {
            // Prints simulation statistics to user in terminal
                std:: cout << "Total patients helped: " << processedPatients.size() << std:: endl;  // total patients helped
                double avgWait;
                int avgSeverity;
                for(it = processedPatients.begin(); it != processedPatients.end(); it++)
                {
                    avgWait = avgWait + it->second.get_averagetime(it->second); // calculates avg wait for any given patient
                    avgSeverity = avgSeverity + it->second.get_Severity();  // calculates avg severity for any given patient
                }
                avgWait = avgWait / processedPatients.size();
                avgSeverity =avgSeverity / processedPatients.size();

                std:: cout << "The average wait time for a patient was " << avgWait << " minutes" << std:: endl;    // avg. wait time
                std:: cout << "The average wait Severity for a patient was " << avgSeverity << std:: endl;  // avg. severity
           }

    }