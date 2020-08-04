//DYLAN WEEKS, 47343235, LAB 3
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include "reader.h"

using namespace std;

void reader::fileLoader()
{
    vector<float> positions;
    file.open("/Users/dylanweeks/Downloads/Positions.txt");
    //OPENS FILE
    
    string line;
    string stringVertex;
    string p1,p2,p3;
    int vertex;
    float position1,position2,position3;
    while(file.good())
    {
        file >> line;
        stringstream positionLine(line);
        getline(positionLine, stringVertex, ',');
        stringstream positionVertex(stringVertex);
        positionVertex >> vertex;
        verticies.push_back(vertex);
        //SETS VERTICIES
        
        getline(positionLine, p1, ',');
        stringstream positionP1(p1);
        positionP1 >> position1;
        positions.push_back(position1);
        
        getline(positionLine, p2, ',');
        stringstream positionP2(p2);
        positionP2 >> position2;
        positions.push_back(position2);
        
        getline(positionLine, p3, '\n');
        stringstream positionP3(p3);
        positionP3 >> position3;
        positions.push_back(position3);
        //SETS ALL POSITIONS
    }
    
    for(int i = 0; i < verticies.size(); i++)
    {
        verticies[i] = verticies[i] - 1;
    }
    
    vector<vector<float>> dM(verticies.size(), vector<float>(verticies.size()));
    float pos[verticies.size()-1][3];
    int vertexCount = 0;
    int graphCount = 0;
    
    //CREATES A 2D ARRAY OF FLOATS FOR JUST THE POSITIONS
    //THIS WAS MORE SO I COULD VISUALIZE HOW TO MAKE DISTANCE MATRIX EASIER
    for(int i = 0; i < positions.size(); i++)
    {
        if(i != 0 && i % 3 == 0)
        {
            vertexCount++;
            graphCount = 0;
        }
        pos[vertexCount][graphCount] = positions[i];
        graphCount++;
    }
    
    float distance = 0;
    
    //PUTS POSITIONS INTO DISTANCE MATRIX
    for(int i = 0; i < verticies.size(); i++)
    {
        for(int j = i + 1; j < verticies.size(); j++)
        {
            distance = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2) + pow(pos[i][2] - pos[j][2], 2) * 1.0);
            dM[i][j] = distance;
            dM[j][i] = distance;
        }

        dM[i][i] = 0;
    }
    distanceMatrix = dM;
}
