#include "protocol_handler.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Protocol_handler::Protocol_handler(){
    baudrate = 115200;
}

Protocol_handler::~Protocol_handler(){

}

int Protocol_handler::open(){
    DCB cdcb;
    COMMTIMEOUTS comto;
    pcom = CreateFile(
        (const WCHAR *)port,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (pcom == INVALID_HANDLE_VALUE) {
        cerr << "Nao abriu a " << port;
        return 1;
    }

    GetCommState(pcom, &cdcb);

    cdcb.BaudRate = baudrate;
    cdcb.ByteSize = 8;
    cdcb.StopBits = ONESTOPBIT;
    cdcb.Parity = 2;

    if (!SetCommState(pcom, &cdcb)) {
        cerr << "SetCommState" << stderr;
        return 2;
    }

    GetCommTimeouts(pcom, &comto);
    comto.ReadIntervalTimeout = MAXDWORD;
    comto.ReadTotalTimeoutMultiplier = 0;
    comto.ReadTotalTimeoutConstant = 0;
    comto.WriteTotalTimeoutMultiplier = 0;
    comto.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(pcom, &comto);
    return 0;
}

int Protocol_handler::send_cube(char cid){

    in[0] = SNC;
    in[1] = cid + CID;

    WriteFile(pcom, in, 2, &n, NULL);

    char temp_out[2];
    memcpy(temp_out, out, 2);

    while(memcmp(temp_out, out, 2) == 0){
        ReadFile(pcom, out, 1, &n, NULL);
    }

    if(out[0] != MND){

        cerr << "resposta invalida. codigo de erro:" << TO_STRING(out) << stderr;

    }