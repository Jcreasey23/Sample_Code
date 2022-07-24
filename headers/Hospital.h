#include <iostream>
#include <CareGiver.h>
#include <WaitingRoom.h>
//#include <Patient.h>
#include <vector>
#include <map>
#include <fstream>


class Hospital
{
public:
    std:: vector<Doctor> doctors;   // Fill with # of doctors objects specified by user
    
    std:: vector<Nurse> nurses;    // Fill with # of nurses objects specified by user

    WaitingRoom waitRoom;   // An instance of a ER waiting room in the hospital object

    void createDoctors(int numDoc); // Creates number of doctors specified by the user

    void createNurses(int numNur);  // Creates number of nurses specified by the user

    bool findCaretaker(int clock, Patient p);   // Finds a caretaker for a patient in the waiting room
    
};

