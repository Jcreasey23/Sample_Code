#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <EmergencyRoomSim.h>
//#include <WaitingRoom.h>



    ER_Sim :: ER_Sim() {}//: clock(0), finishTime(0){}     // Low Priority patient que, mid Prioroty patient que, High priority patient que

    void ER_Sim :: run_Sim()     // runs simulation
    {
        std::ofstream summary;
        summary.open("Summary.txt");
        std:: cout << "Begin Simulation " << std:: endl;
        for(clock = 0; clock < totTime; clock++)// while time is less than one full week... run all aspects of emergency room
        {

            summary << "Simulation minute: " << clock << std:: endl;
            hospital.waitRoom.checkArrival(clock, showAll);   // when a patient arrives, they are immediately triaged
            if(hospital.waitRoom.waitingroomct() == 0) // If all ques are empty, tell user that waiting room is empty
            {
                
                summary << "The Waiting Room is Empty..." << std :: endl;
            }else
            {
            
            summary << "There are " << hospital.waitRoom.waitingroomct() << " patients in the waiting room" << std::endl;
            Patient pat =  hospital.waitRoom.nextPatient();    // look at waiting room queues in order don't pop patient off high priority queue

            // hospital.findCaretaker(clock, pat); // if bool returns true then remove patient from queue and move them into records
            // remove pat from queue and add it to queue of processed patients
            if(hospital.findCaretaker(clock,pat) == true)
            {
                summary << "Patient has found a caretaker... " << std:: endl;
                summary << "Patient Name: " << pat.get_PatientfName() << " " << pat.get_Patientlname() << std:: endl;
                hospital.waitRoom.removePatient(pat);
                summary << "Patient has been treated!" << std:: endl;
                
            }

            }

            
        }
        summary << "This week, " << hospital.waitRoom.get_appointments() << " patients were treated" << std:: endl;
        std:: cout << "Simulation complete. Please see Summary.txt for summary and statistics" << std:: endl;
    }

    void ER_Sim :: enter_data()  // Reads in the data for the simulation
    {
        // Hospital hospital;
        // Enter data function obtains the specifications for the simulation

        hospital.waitRoom.readnames(); // Fill vectors with names

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


        // std:: ifstream readfirst ("residents.txt");
        // std:: ifstream readlast ("surnames.txt");

        // std::string fname;
        // std::string lname;
        // std::string fullname;

        // int counter = 0;
        // while(counter < 2000)
        // {

        //     readfirst >> fname;
        //     readlast >> lname;
        //     fullname = fname + " " + lname;
        //     residents.push_back(fullname);

        // }

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