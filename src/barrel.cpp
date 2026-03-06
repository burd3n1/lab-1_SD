#include <iostream>
#include "barrel.hpp"

Barrel::Barrel(double cap, double init_vol, double init_alcohol){
    capacity = cap;
    current_volume = init_vol;
    alcohol_volume = init_alcohol;
}


double Barrel::getConcentrationAl() const
{
    if (current_volume <= 0.0)
        return 0.0;
        else
    return (alcohol_volume / current_volume) * 100.0;
}


double Barrel::getCurrentVolume() const {
    return current_volume;
}

void Barrel::pourFrom(Barrel& other, double amount){
    
    if (amount <= 0.0) return;
    

    double actual_amount = std::min(amount, other.getCurrentVolume());


    if (actual_amount <= 0.0) return;


    double alcohol_transferred = 0.0;
    if (other.current_volume > 0.0)
        alcohol_transferred = other.alcohol_volume * (actual_amount / other.current_volume);


    current_volume += actual_amount;
    alcohol_volume += alcohol_transferred;

    other.current_volume -= actual_amount;
    other.alcohol_volume -= alcohol_transferred;
}