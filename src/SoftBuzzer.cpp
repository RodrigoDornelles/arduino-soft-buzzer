#include <Arduino.h>
#include <SoftBuzzer.hpp>

SoftBuzzer::SoftBuzzer(buzzer_pin_t pin)
{
    this->setPin(pin);
}

SoftBuzzer::~SoftBuzzer()
{

}

buzzer_pin_t SoftBuzzer::getPin()
{
    return this->pin;
}

void SoftBuzzer::setPin(buzzer_pin_t pin)
{
    pinMode(pin, OUTPUT);
    this->pin = pin;
}

buzzer_hertz_t SoftBuzzer::getRealHertz()
{
    buzzer_hertz_t hertz = this->hertz_count;
    static long int last_second = 0;
    long int m = millis();

    if (last_second != (m/1000) ) {
        last_second = m/10000;
        this->hertz_count = 0;
    }

    return hertz;
}

buzzer_hertz_t SoftBuzzer::getHertz()
{
    return this->hertz;
}

void SoftBuzzer::setHertz(buzzer_hertz_t hertz)
{
    this->hertz = hertz;
    this->cicle_time = (1/hertz) * 1000000;
}

void SoftBuzzer::update()
{
    buzzer_cicle_t m = micros();

    // buzzer has not signal 
    if (this->cicle_time == 0){
        return digitalWrite(this->pin, LOW);
    }

    // generate cicle
    if (this->old_micro + this->cicle_time <= m) {
        this->sinal ^= true;  
        this->old_micro = m; 
        this->hertz_count += 1;
    }

    // output sinal
    digitalWrite(this->pin, this->sinal);
}