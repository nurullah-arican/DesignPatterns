#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>

// Component
class Beverage {
public:
	virtual ~Beverage() = default;
	virtual std::string getDescription() = 0;
	virtual double getCost() = 0;
};

// Concrete Component
class Coffee : public Beverage {
public:
	std::string getDescription() override {
		return "Coffee";
	}

	double getCost() override {
		return 5.0;
	}
};

// Base decorator
class BeverageDecorator : public Beverage {
protected:
	Beverage* beverage;

public:
	BeverageDecorator(Beverage* beverage) : beverage(beverage) {}
};

// Concrete Decorator
class Milk : public BeverageDecorator {
public:
	Milk(Beverage* beverage) : BeverageDecorator(beverage) {}

	std::string getDescription() override {
		return beverage->getDescription() + " + Milk ";
	}

	double getCost() override {
		return beverage->getCost() + 1.5;
	}
};

// Concrete Decorator
class Sugar : public BeverageDecorator {
public:
	Sugar(Beverage* beverage) : BeverageDecorator(beverage) {}

	std::string getDescription() override {
		return beverage->getDescription() + " + Sugar ";
	}

	double getCost() override {
		return beverage->getCost() + 0.5;
	}
};


#endif // DECORATOR_H