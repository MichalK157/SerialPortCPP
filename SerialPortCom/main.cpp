#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "SerialCom.h"
#include <thread>

using namespace std;
char *port_name = "\\\\.\\COM4";
char incomingData[MAX_DATA_LENGTH];

int main(int argc, char **argv)
{
    SerialCom port(port_name);
	if (port.isConnected()) cout << "Connection Established" << endl;
    else cout << "ERROR, check port name";
    thread Read (port.Read,incomingData,MAX_DATA_LENGTH);
    Read.join();
    /*while (port.isConnected()){
    //Check if data has been read or not
    int read_result = port.readSerialPort(incomingData, MAX_DATA_LENGTH);
    //prints out data*/
    puts(incomingData);
    //wait a bit
    Sleep(1100);
    system("pause");
    return 0;
}

