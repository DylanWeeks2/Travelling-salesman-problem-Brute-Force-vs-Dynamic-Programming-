//DYLAN WEEKS, 47343235, LAB 3
#ifndef reader_h
#define reader_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class reader
{
public:
    void fileLoader();
    vector<vector<float>> distanceMatrix;
    vector<int> verticies;
    
protected:
    ifstream file;
};
#endif /* reader_h */

