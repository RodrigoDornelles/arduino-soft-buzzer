#ifndef SOFTBUZZER_HPP
#define SOFTBUZZER_HPP
#include <stdbool.h>


typedef unsigned long buzzer_cicle_t;
typedef unsigned char buzzer_pin_t;
typedef double buzzer_hertz_t;

class SoftBuzzer
{
    private:
        bool sinal;
        buzzer_pin_t pin;
        buzzer_hertz_t hertz;
        buzzer_cicle_t hertz_count;
        buzzer_cicle_t cicle_time;
        buzzer_cicle_t old_micro;

    public:
        void update();

        buzzer_pin_t getPin();
        void setPin(buzzer_pin_t pin);

        buzzer_hertz_t getHertz();
        buzzer_hertz_t getRealHertz();
        void setHertz(buzzer_hertz_t hertz);

        SoftBuzzer(buzzer_pin_t pin);
        ~SoftBuzzer();
};
#endif