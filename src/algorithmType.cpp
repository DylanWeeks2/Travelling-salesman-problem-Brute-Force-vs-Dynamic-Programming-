//DYLAN WEEKS, 47343235, LAB 3
#include <stdio.h>
#include "algorithmType.h"
#include "tspBruteForce.h"
#include "tspDynamicProgramming.h"
#include "algorithm.h"

algorithm* algorithmType::type(int s)
{
    if(s == 0)
    {
        //CREATES NEW ALGORITHM OBECT BASED ON SELECTION VALUE
        algorithm *algo1 = new tspBruteForce();
        
        
        return algo1;
    }
    else
    {
        //CREATES NEW ALGORITHM OBECT BASED ON SELECTION VALUE
        algorithm *algo2 = new tspDynamicProgramming();
        
        
        return algo2;
    }
    return NULL;
}
