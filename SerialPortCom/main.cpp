#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "SerialCom.h"
#include <thread>

using namespace std;
char *port_name = "\\\\.\\COM4";
char incomingData[MAX_DATA_LENGTH];
char data;
void Read(SerialCom serial);
bool _countinue;
int main(int argc, char **argv)
{
    SerialCom port(port_name);
	if (port.isConnected())
        {
            cout << "Connection Established" << endl;
            _countinue=true;
        }
    else cout << "ERROR, check port name";
    thread _Read (Read,port);
    _Read.join();
    while(_countinue)
    {   
        cout<<"wprowadz data"<<endl;
        cin>>data;
        if(data==0x27)
            _countinue=false;
    }
    
    Sleep(1100);
    system("pause");
    return 0;
}

void Read(SerialCom serial)
{
    while (serial.isConnected()){
    //Check if data has been read or not
    int read_result = serial.readSerialPort(incomingData, MAX_DATA_LENGTH);
    }
    cout<<incomingData<<endl;
}