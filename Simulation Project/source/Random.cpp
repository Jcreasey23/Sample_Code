#include <iostream>
#include <Random.h>


// Random class was borrowed from textbook to help generate random numbers and generate a more random arrival rate of patients to the ER
/////////////////////////////////////////////////////////////////////////////////
 Random :: Random()
    {
        std:: srand(std::time(0));
    }

    Random :: Random(int seed)
    {
        int sd = seed;
        std:: srand(sd);
    }

    int Random :: next_int(int n)
    {
        return int(next_double() * n);
    }

    double Random :: next_double()
    {
        return double(std::rand()) / RAND_MAX;
    }
    /////////////////////////////////////////////////////////////////////////////////