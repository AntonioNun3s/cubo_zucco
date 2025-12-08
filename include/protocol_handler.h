#if !defined(PROTOCOL_HANDLER_H_)
#define PROTOCOL_HANDLER_H_

#include <unordered_map>
#include <string>
#include <cube.h>

std::unordered_map<int, std::string> answers_name = { // used for handling the answers of the cube
    {0x41, "ACK"},
    {0x4E, "NAK"},
    {0x4D, "MND"},
    {0x49, "NID"},
    {0x44, "TOUT"}};

#if defined(_WIN32)

#include <windows.h>

#endif

#define SNC 0xD3
#define ATX 0xD8
#define CLR 0xC3
#define CID 0x80 // possible commands

#define ACK 0x41
#define NAK 0x4E
#define MND 0x4D
#define NID 0x49
#define TOUT 0x44 // answers of the cube

class Protocol_handler{

public:
    Protocol_handler();
    virtual ~Protocol_handler();

    int open();
    int send_cube(char cid, Cube cubo);
    void activate_cube(char cid);
    void clear_cube();

private:
    char port[6];
    char in[2];
    char out[2];
    int baudrate;
    HANDLE pcom;
    unsigned long n;
};

#endif