#ifndef BARREL_HPP
#define BARREL_HPP

class Barrel{
    private:
    double capacity;     
    double current_volume;     
    double alcohol_volume;
    public:

    Barrel(double capacity, double initial_volume, double initial_alcohol_volume);


    double getConcentrationAl() const;

    double getCurrentVolume() const;


    void pourFrom(Barrel& other, double amount = 1.0);

};
#endif //BARREL_HPP