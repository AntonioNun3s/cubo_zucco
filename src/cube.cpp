#include "cube.h"

Cube::Cube(){

    
}

Cube::~Cube(){

}

auto Cube::get_leds() -> uint8_t (*)[8][8][8]{

    return &leds;
}

uint8_t Cube::get_led(int x, int y, int z){

    return leds[x][y][z];
}

void Cube::set_leds(uint8_t (*p)[8][8][8]){

    memcpy(leds, p, 512);
}

void Cube::set_led(uint8_t value, int x, int y, int z){

    leds[x][y][z] = value;
}

void Cube::fill_plane_y(uint8_t mat[8][8], int y){


    for(int x = 0; x < 8; x++){
        for(int z = 0; z < 8; z++){
            leds[x][y][z] = mat[x][z];
        }
    }
}

void Cube::clear_leds(){

    memset(leds, 0, 512);
}

