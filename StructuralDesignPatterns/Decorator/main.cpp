#include "Decorator.h"

int main()
{
	Beverage* beverage = new Coffee();
	std::cout << beverage->getDescription() << " costs $" << beverage->getCost() << std::endl;

	beverage = new Milk(beverage);
	std::cout << beverage->getDescription() << " costs $" << beverage->getCost() << std::endl;
	
	beverage = new Sugar(beverage);
	std::cout << beverage->getDescription() << " costs $" << beverage->getCost() << std::endl;
}