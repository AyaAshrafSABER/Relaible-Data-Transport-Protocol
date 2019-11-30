// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ClientManager.h"

using namespace std;

// Driver code
int main(){

    char filename1[] = "/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ClientSide/client.in";
    ifstream myfile (filename1);
    cout << "Read value from Server.in" << '\n';
    int port;
    string ip;
    string req_file;
    if (myfile.is_open())
    {
        myfile >> ip;
        myfile >> port;
        myfile >> req_file;
        myfile.close();
    }
    cout<< req_file<<endl;
    ClientManager *cm = new ClientManager(ip, port, req_file);
    cm->run_client();
    return 0;

}
