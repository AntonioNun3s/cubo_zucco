#ifndef EFFECTS_H_
#define EFFECTS_H_
#include <protocol_handler.h>
#include <cube.h>

#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist_x_y(0, 2);
std::uniform_int_distribution<> dist_pos_half(0, 4);
std::uniform_int_distribution<> dist_pos(0, 8);

class Effects{

public:
    Effects(Protocol_handler *new_prot);
    virtual ~Effects();

    void meteors();
    void cross_fill_up();
    void random_leds();
    void fill_with_planes();

private:
    Protocol_handler *prot;
    uint8_t (*cube_ptr)[8][8][8];
    Cube *cubo;
};

#endif