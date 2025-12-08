#ifndef CUBE_H_
#define CUBE_H_

#include <cstdint>
#include <cstring>

class Cube{

public:
    Cube();
    virtual ~Cube();

    auto get_leds() -> uint8_t (*)[8][8][8];
    uint8_t get_led(int x, int y, int z);
    void set_leds(uint8_t (*p)[8][8][8]);
    void set_led(uint8_t value, int x, int y, int z);
    void fill_plane_y(uint8_t (*p)[8][8][8], int y);
    void clear_leds();

private:
    uint8_t leds[8][8][8] = {};
};

#endif