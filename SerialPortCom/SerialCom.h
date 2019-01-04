#pragma once
#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <stdlib.h>
#define WAIT_TIME 2000
#define MAX_DATA_LENGTH 255
class SerialCom
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
    
public:
	SerialCom(char *portName);
    ~SerialCom();

    int readSerialPort(char *buffer, unsigned int buf_size);
    void Read(char *buffer, unsigned int buf_size);
    bool writeSerialPort(char *buffer, unsigned int buf_size);
    bool isConnected();

};

