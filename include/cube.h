#ifndef CUBE_H_
#define CUBE_H_

#include <cstdint>

class Cube{

    public:

        Cube();
        virtual ~Cube();

        auto get_leds() -> uint8_t (*) [8][8];
        void set_leds(uint8_t);
        void clear_leds();

    private:
        uint8_t leds[8][8][8] = {};

};

#endif