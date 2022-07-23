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

    WaitingRoom waitRoom;   // I feel lile this should be defined as a queue

    void createDoctors(int numDoc);

    void createNurses(int numNur);

    bool findCaretaker(int clock, Patient p);

    // Need to establish a way to create a file of records for each patient admitted to ER
    // Patient name, severity of illness on trip(s), and total number of trips

    



};

