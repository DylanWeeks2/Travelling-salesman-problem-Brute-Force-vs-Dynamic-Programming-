//DYLAN WEEKS, 47343235, LAB 3
#include <iostream>
#include "algorithm.h"
#include "reader.h"
#include "algorithmType.h"


int main(int argc, const char * argv[])
{
    algorithm *type;
    reader fileRead;
    fileRead.fileLoader();
    algorithmType algorithm;
    
    for(int i = 0; i < 2; i++)
    {
        type = algorithm.type(i);
        type -> execute(fileRead);
        type -> output();
    }

    return 0;
}

