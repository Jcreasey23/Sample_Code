#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
public:
    
    Random()
    {
        std:: srand(std::time(0));
    }

    Random(int seed)
    {
        int sd = seed;
        std:: srand(sd);
    }

    int next_int(int n)
    {
        return int(next_double() * n);
    }

    double next_double()
    {
        return double(std::rand()) / RAND_MAX;
    }



};