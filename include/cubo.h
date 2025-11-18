#ifndef CUBO_H_
#define CUBO_H_

class Cubo{

    public:

        Cubo();
        virtual ~Cubo();

        int* get_leds();
        void set_leds(int* new_leds);

    private:
        int* leds;

};

#endif