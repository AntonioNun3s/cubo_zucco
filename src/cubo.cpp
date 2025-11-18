#include "../include/cubo.h"
#include <cstring>

Cubo::Cubo(){

    leds = new int [512];
}

Cubo::~Cubo(){

}

int* Cubo::get_leds(){

    return leds;
}

void Cubo::set_leds(int* new_leds){

    memcpy(leds, new_leds, sizeof(int) * 512);

}