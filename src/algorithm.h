//DYLAN WEEKS, 47343235, LAB 3
#ifndef Algorithm_h
#define Algorithm_h
#include "reader.h"

using namespace std;

class algorithm
{
public:
    virtual void execute(reader &r) = 0;
    virtual void output() = 0;

};


#endif /* Algorithm_h */

