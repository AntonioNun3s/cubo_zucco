#include "effect.h"

Effects::Effects(Protocol_handler * new_prot){
    prot = new_prot;
}

Effects::~Effects(){

}

void Effects::meteors(){
    cube_ptr = cubo->get_leds();

    for(int x = 7; x >= 0; x--){
        for(int y = 7; y >= 0; y--){
            for(int z = 7; z >= 0; z--){

                if((*cube_ptr)[x][y][z] != 0){

                    (*cube_ptr)[x][y][z] = 0;

                    if(x != 7 && y != 0){
                        (*cube_ptr)[x + 1][y - 1][z] = 5;

                    }
                }
            }
        }
    }

    int ranx_y, ran_pos, ran_z;

    for(int i = 0; i < 2; i++){

        ranx_y = dist_x_y(gen);
        ran_pos = dist_pos_half(gen);
        ran_z = dist_pos(gen);

        if(ranx_y == 0){
            (*cube_ptr)[0][7 - ran_pos][ran_z] = 5;

        }else{
            (*cube_ptr)[ran_pos][7][ran_z] = 5;
        }

    }

}

void Effects::random_leds(){

}

