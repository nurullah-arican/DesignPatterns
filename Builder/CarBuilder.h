#ifndef CARBUILDER_H
#define CARBUILDER_H

#include <iostream>
#include <memory>
#include <string>

// Product - Araba
class Car {
public:
    void SetEngine(const std::string& engine) { engine_ = engine; }
    void SetSeats(int seats) { seats_ = seats; }
    void SetGPS(bool hasGPS) { hasGPS_ = hasGPS; }

    void ShowSpecifications() const {
        std::cout << "Motor: " << engine_ << "\n"
            << "Koltuk Sayısı: " << seats_ << "\n"
            << "GPS: " << (hasGPS_ ? "Var" : "Yok") << "\n";
    }

private:
    std::string engine_;
    int seats_;
    bool hasGPS_;
};

// Abstract Builder - CarBuilder
class CarBuilder {
public:
    virtual ~CarBuilder() = default;
    virtual void BuildEngine() = 0;
    virtual void BuildSeats() = 0;
    virtual void BuildGPS() = 0;

    std::unique_ptr<Car> GetCar() {
        return std::move(car_);
    }

protected:
    std::unique_ptr<Car> car_ = std::make_unique<Car>();
};

// Concrete Builder - SportsCarBuilder
class SportsCarBuilder : public CarBuilder {
public:
    void BuildEngine() override {
        car_->SetEngine("V8 Motor");
    }

    void BuildSeats() override {
        car_->SetSeats(2);
    }

    void BuildGPS() override {
        car_->SetGPS(true);
    }
};

// Concrete Builder - SUVCarBuilder
class SUVCarBuilder : public CarBuilder {
public:
    void BuildEngine() override {
        car_->SetEngine("Dizel Motor");
    }

    void BuildSeats() override {
        car_->SetSeats(7);
    }

    void BuildGPS() override {
        car_->SetGPS(false);
    }
};

// Director - CarDirector
class CarDirector {
public:
    void SetBuilder(CarBuilder* builder) {
        builder_ = builder;
    }

    std::unique_ptr<Car> Construct() {
        builder_->BuildEngine();
        builder_->BuildSeats();
        builder_->BuildGPS();
        return builder_->GetCar();
    }

private:
    CarBuilder* builder_;
};


#endif // CARBUILDER_H


