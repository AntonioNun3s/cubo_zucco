#include "protocol_handler.h"
#include <iostream>
#include <cstring>

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

int Protocol_handler::send_cube(char cid, Cube cubo){

    in[0] = SNC;
    in[1] = cid + CID;

    WriteFile(pcom, in, 2, &n, NULL);

    ReadFile(pcom, out, 1, &n, NULL);

    if(out[0] != MND){

        cerr << "resposta invalida. codigo de erro: " << answers_name[out[0]] << endl;
        return 1;
    }

    cout << "autorizado!. codigo de envio: " << answers_name[out[0]] << endl;

    WriteFile(pcom, cubo.get_leds(), 512, &n, NULL);

    ReadFile(pcom, out, 1, &n, NULL);

    if(out[0] != ACK){
        cerr << "nao foi possivel enviar a imagem. codigo de erro: " << answers_name[out[0]] << endl;
        return 2;
    }

    cout << "imagem " << (int)cid << " enviada" << endl;

    return 0;

}

void Protocol_handler::activate_cube(char cid){

    in[0] = ATX;
    in[1] = cid + CID;
    
    WriteFile(pcom, in, 2, &n, NULL);
}

void Protocol_handler::clear_cube(){

    in[0] = CLR;
    in[1] = CLR;

    WriteFile(pcom, in, 2, &n, NULL);
}

