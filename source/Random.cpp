#include <iostream>
#include <Random.h>


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