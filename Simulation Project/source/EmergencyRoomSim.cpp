#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <EmergencyRoomSim.h>
//#include <WaitingRoom.h>



    ER_Sim :: ER_Sim() {} 

    void ER_Sim :: run_Sim()     // runs simulation
    {
        std::ofstream summary;
        summary.open("Summary.txt");    // opens a file that keeps track of each minute of the simulation
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

            if(hospital.findCaretaker(clock,pat) == true)   // if there is someone available to help patient based on patient's severity
            {
                summary << "Patient has found a caretaker... " << std:: endl;
                summary << "Patient Name: " << pat.get_PatientfName() << " " << pat.get_Patientlname() << std:: endl;
                pat.set_endcare(clock);                     // ends time at ER for patient
                hospital.waitRoom.removePatient(clock,pat); // removes patient from waiting room queue
                summary << "Patient has been treated!" << std:: endl;
                
            }

            }

            
        }
        summary << "This week, " << hospital.waitRoom.get_appointments() << " patients were treated" << std:: endl;
        std:: cout << "Simulation complete. Please see Summary.txt for summary and statistics" << std:: endl;
    }

    void ER_Sim :: enter_data()  // Reads in the data for the simulation
    {
        // Enter data function obtains the specifications for the simulation

        hospital.waitRoom.readnames(); // Fill vectors with names

        std:: cout << "Please enter the hourly patient arrival rate. " << "Rate must be at or below 60 patients per hour." << std:: endl;
        std:: cin >> patientarrivalrate;

        hospital.waitRoom.setArrivalrate(patientarrivalrate);   // sets arrival rate of patients into waiting room

        std:: cout << "Please enter the number of Doctors working at the emergency room." << std:: endl;
        std:: cin >> numDoctors;

        hospital.createDoctors(numDoctors); // creates vector of doctors with size of numDoctors

        // Need to then create new doctor objects based on entered number from user

        std:: cout << "Please enter the number of Nurses working at the emergency room." << std:: endl;
        std:: cin >> numNurses;

        hospital.createNurses(numNurses);   // creates vector of nurses with size numNurses

    }

    void ER_Sim :: postSim(int userselection)
    {
        hospital.waitRoom.postSim(userselection);   // allows user to interact with results of sim
    }