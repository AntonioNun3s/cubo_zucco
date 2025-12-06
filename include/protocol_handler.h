#if !defined(PROTOCOL_HANDLER_H_)
#define PROTOCOL_HANDLER_H_

#if defined(_WIN32)

    #include <windows.h>
    
#endif

#define SNC 0xD3
#define ATX 0xD8
#define CLR 0xC3
#define CID 0x80

#define ACK 0x41
#define NAK 0x4E
#define MND 0x4D
#define NID 0x49
#define TOUT 0x44

#define TO_STRING(x) #x

class Protocol_handler{

    public:

        Protocol_handler();
        virtual ~Protocol_handler();

        int open();
        int send_cube(char cid);
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