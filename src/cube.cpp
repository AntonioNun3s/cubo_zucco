#include "../include/cube.h"
#include <cstring>

Cube::Cube(){

    
}

Cube::~Cube(){

}

int* Cubo::get_leds(){

    return leds;
}

void Cubo::set_leds(int* new_leds){

    memcpy(leds, new_leds, sizeof(int) * 512);

}