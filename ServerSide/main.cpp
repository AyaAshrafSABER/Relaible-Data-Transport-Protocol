// Server side implementation of UDP client-server model


#include "ServerManager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    char filename1[] = "server.in";
    ifstream myfile (filename1);
    cout << "Read value from Server.in" << '\n';
    int port;
    int randomGeneratorSeed;
    float probability = 0;
    if (myfile.is_open())
    {
        myfile >> port;
        myfile >> randomGeneratorSeed;
        myfile >> probability;
        myfile.close();
    }
    ServerManager *sm = new ServerManager(port, randomGeneratorSeed, probability);
    sm->start_server();
    return 0;
}