#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>

// Complex Subsystem I
class Lights {
public:
	void turnOn() {
		std::cout << "Lights are turned ON." << std::endl;
	}

	void turnOff() {
		std::cout << "Lights are turned OFF." << std::endl;
	}
};

// Complex Subsystem II
class TV {
public:
	void turnOn() {
		std::cout << "TV is turned ON." << std::endl;
	}

	void turnOff() {
		std::cout << "TV is turned OFF." << std::endl;
	}

	void setChannel(int channel) {
		std::cout << "TV channel is set to " << channel << std::endl;
	}
};

// Complex Subsystem II
class AirConditioner {
public:
	void turnOn() {
		std::cout << "Air Conditioner is turned ON." << std::endl;
	}

	void turnOff() {
		std::cout << "Air Conditioner is turned OFF." << std::endl;
	}

	void setTemperature(int temperature) {
		std::cout << "Temperature is set to " << temperature << std::endl;
	}
};

// Facade 
class HomeAutomationFacade {
private:
	Lights lights;
	TV tv;
	AirConditioner airConditioner;
public:
	void movieMode() {
		std::cout << "--- Movie Mode Activated ---" << std::endl;
		lights.turnOff();
		airConditioner.turnOn();
		airConditioner.setTemperature(25);
		tv.turnOn();
		tv.setChannel(5);
	}

	void arriveHomeMode() {
		std::cout << "--- Arrive Home Mode Activated ---" << std::endl;
		lights.turnOn();
		airConditioner.turnOn();
		airConditioner.setTemperature(25);
	}

	void leaveHomeMode() {
		std::cout << "--- Leave Home Mode Activated ---" << std::endl;
		lights.turnOn();
		airConditioner.turnOff();
		tv.turnOff();
	}
};


#endif // FACADE_H