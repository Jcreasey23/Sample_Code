#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
public:
    
    Random();

    Random(int seed);

    int next_int(int n);

    double next_double();


};