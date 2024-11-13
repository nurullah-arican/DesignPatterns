#include "CarBuilder.h"

// Usage
int main() {
    CarDirector director;

    // Construction of a sports car
    SportsCarBuilder sportsCarBuilder;
    director.SetBuilder(&sportsCarBuilder);
    std::unique_ptr<Car> sportsCar = director.Construct();
    std::cout << "Sports Car Specifications:\n";
    sportsCar->ShowSpecifications();

    // Construction of a SUV car
    SUVCarBuilder suvCarBuilder;
    director.SetBuilder(&suvCarBuilder);
    std::unique_ptr<Car> suvCar = director.Construct();
    std::cout << "\nSUV Car Specifications:\n";
    suvCar->ShowSpecifications();

    return 0;
}