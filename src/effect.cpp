#include "effect.h"

Effects::Effects(Protocol_handler * new_prot, Cube* new_cubo){
    prot = new_prot;
    cubo = new_cubo;
    cube_ptr = cubo->get_leds();
}

Effects::~Effects(){

}

void Effects::sleep_for(int ms){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Effects::meteors(){

    for(int x = 7; x >= 0; x--){
        for(int y = 7; y >= 0; y--){
            for(int z = 7; z >= 0; z--){

                if((*cube_ptr)[x][y][z] != 0){

                    (*cube_ptr)[x][y][z] = 0;

                    if(x != 7 && y != 0){
                        (*cube_ptr)[x + 1][y - 1][z] = 10;

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
            (*cube_ptr)[0][7 - ran_pos][ran_z] = 10;

        }else{
            (*cube_ptr)[ran_pos][7][ran_z] = 10;
        }

    }

}

void Effects::random_leds(){

    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            for(int z = 0; z < 8; z++){

                if((*cube_ptr)[x][y][z] > 0){
                    (*cube_ptr)[x][y][z]--;
                }
            }
        }
    }

    int ran_x, ran_y, ran_z;
    for(int i = 0; i < 4; i++){
        ran_x = dist_pos(gen);
        ran_y = dist_pos(gen);
        ran_z = dist_pos(gen);
        (*cube_ptr)[ran_x][ran_y][ran_z] = 10;
    }
}

void Effects::fill_with_planes(){

    uint8_t mat[8][8];

    for(int i = 0; i < 8; i++){
        for(int y = 7; y >= 0 + i; y--){

            sleep_for(200);

            if(y < 7){
                memset(mat, 0, 64);
                cubo->fill_plane_y(mat, y + 1);
            }
            memset(mat, 10, 64);
            cubo->fill_plane_y(mat, y);

            prot->send_cube(0, cube_ptr);
            prot->activate_cube(0);
        }
    }

    for(int i = 0; i < 6; i++){

        sleep_for(120);

        if((*cube_ptr)[4][4][4] == 10){
            memset(*cube_ptr, 0, 512);
        }else{
            memset(*cube_ptr, 10, 512);
        }

        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }
}

void Effects::cross_fill_up(){

    for(int x = 3; x <= 4; x++){
        for(int y = 3; y <= 4; y++){
            for(int z = 3; z <= 4; z++){
                (*cube_ptr)[x][y][z] = 10;
            }
        }
    }

    prot->send_cube(0, cube_ptr);
    prot->activate_cube(0);

    for(int x = 2; x >= 0; x--){
        sleep_for(100);

        for(int y = 3; y <= 4; y++){
            for(int z = 3; z <= 4; z++){
                (*cube_ptr)[x][y][z] = 10;
                (*cube_ptr)[7 - x][y][z] = 10;
            }
        }
        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }

    for(int z = 2; z >= 0; z--){
        sleep_for(100);

        for(int x = 3; x <= 4; x++){
            for(int y = 3; y <= 4; y++){
                (*cube_ptr)[x][y][z] = 10;
                (*cube_ptr)[x][y][7 - z] = 10;
            }
        }
        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }

    for(int y = 2; y >= 0; y--){
        sleep_for(100);

        for(int x = 3; x <= 4; x++){
            for(int z = 3; z <= 4; z++){
                (*cube_ptr)[x][y][z] = 10;
                (*cube_ptr)[x][7 - y][z] = 10;
            }
        }
        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }

    for(int i = 0; i < 3; i++){

        sleep_for(100);

        (*cube_ptr)[3 - i][3 - i][3 - i] = 10;
        (*cube_ptr)[3 - i][3 - i][4 + i] = 10;
        (*cube_ptr)[3 - i][4 + i][3 - i] = 10;
        (*cube_ptr)[3 - i][4 + i][4 + i] = 10;
        (*cube_ptr)[4 + i][3 - i][3 - i] = 10;
        (*cube_ptr)[4 + i][3 - i][4 + i] = 10;
        (*cube_ptr)[4 + i][4 + i][3 - i] = 10;
        (*cube_ptr)[4 + i][4 + i][4 + i] = 10;

        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }

    for(int i = 0; i < 3; i++){
        sleep_for(100);
        for(int x = 2 - i; x < 5 + i; i++){
            for(int y = 2 - i; y < 5 + i; i++){
                for(int z = 2 - i; z < 5 + i; z++){
                    (*cube_ptr)[x][y][z] = 10;
                }
            }
        }
        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }
    
    for(int i = 0; i < 6; i++){

        sleep_for(120);

        if((*cube_ptr)[4][4][4] == 10){
            memset(*cube_ptr, 0, 512);
        }else{
            memset(*cube_ptr, 10, 512);
        }

        prot->send_cube(0, cube_ptr);
        prot->activate_cube(0);
    }

}

