#include <iostream>
#include <string>
#include <queue>
#include <EmergencyRoomSim.h>
//#include <WaitingRoom.h>



    ER_Sim :: ER_Sim() {}//: clock(0), finishTime(0){}     // Low Priority patient que, mid Prioroty patient que, High priority patient que

    void ER_Sim :: run_Sim()     // runs simulation
    {
        for(clock = 0; clock < totTime; clock++)// while time is less than one full week... run all aspects of emergency room
        {
            hospital.waitRoom.checkArrival(clock, showAll);   // when a patient arrives, they are immediately triaged
            if(hospital.waitRoom.waitingroomct() == 0) // If all ques are empty, tell user that waiting room is empty
            {
                std :: cout << "The Waiting Room is Empty..." << std :: endl;
            }else
            {

            Patient pat =  hospital.waitRoom.nextPatient();    // look at waiting room queues in order don't pop patient off high priority queue

            // hospital.findCaretaker(clock, pat); // if bool returns true then remove patient from queue and move them into records
            // remove pat from queue and add it to queue of processed patients
            if(hospital.findCaretaker(clock,pat) == true)
            {
                hospital.waitRoom.removePatient(pat);
            }

            }

            
        }
        
    }

    void ER_Sim :: enter_data()  // Reads in the data for the simulation
    {
        // Hospital hospital;
        // Enter data function obtains the specifications for the simulation
        std:: cout << "Please enter the hourly patient arrival rate. " << "Rate must be at or below 60 patients per hour." << std:: endl;
        std:: cin >> patientarrivalrate;

        hospital.waitRoom.setArrivalrate(patientarrivalrate);

        std:: cout << "Please enter the number of Doctors working at the emergency room." << std:: endl;
        std:: cin >> numDoctors;

        hospital.createDoctors(numDoctors);

        // Need to then create new doctor objects based on entered number from user

        std:: cout << "Please enter the number of Nurses working at the emergency room." << std:: endl;
        std:: cin >> numNurses;

        hospital.createNurses(numNurses);

        // Need to then create new nurse objects based on entered number from user


        // Rate of low, mid, high priority patients

        // bool show all - > displays minute by minute trace of sim
    }

    void ER_Sim :: show_stats()  // Display the summary statistics
    {
        // std :: cout << "The number of low priority patients seen was " << lowPriorityque << std :: endl;

        // std :: cout << "The number of mid priority patients seen was " << midPriorityque.get_appointments() << std :: endl;

        // std :: cout << "The number of high priority patients seen was " << highPriorityque.get_appointments() << std :: endl;


        // Also need to include average wait time from patient arrival to after treatment

        // std :: cout << "Patients in low priority que " << lowPriorityque.size() << std :: endl;

        // std :: cout << "Patients in mid priority que " << midPriorityque.size() << std :: endl;

        // std :: cout << "Patients in high priority que " << highPriorityque.size() << std :: endl;
    }


    void careforPatient()
    {
        
        // if(Waitingroom.nextPatient() != NULL)
        // {
        //     findCaretaker();
        // }

    }

    // void findCaretaker(Patient p)
    // {
    //     if(p.get_Severity() >= 11)
    //     {
    //         for(int i = 0; i < doctors.size(); i++)
    //         {
    //             if(doctors[i] == available())
    //             {
    //                 int temp = rand() % 20 + 1;
    //                 busy(temp);
    //                 break;
    //             }
    //         }
    //     } 
    //     if(p.get_Severity() <=10)
    //     {
    //         for(int i = 0; i < nurses.size(); i++)
    //         {
    //             if(nurses[i] == available())
    //             {
    //                 int temp = rand() % 10 + 1;
    //                 busy(temp);
    //                 break;
    //             }
    //         }
    //     }
    // }

    double calclowPrior(int maxPatients)
    {
        double lowRate = (maxPatients * .70) / 60;  //Rate is low priority patients per minute   // 70% of maxPatients will be low priority in the que
        return lowRate;
    }

    double calcmidPrior(int maxPatients)
    {
        double midRate = maxPatients * .20; // Rate is mid priority patients per minute  // 20% of maxPatients will be mid priority in the que
        return midRate;
    }

    double calchighPrior(int maxPatients)
    {
        double highRate = maxPatients * .10; // Rate is high priority patients per minute // 10% of maxPatients will be mid priority in the que
        return highRate;
    }