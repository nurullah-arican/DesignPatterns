// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

// Segregated interfaces
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() = default;
};

class Soundable {
public:
    virtual void makeSound() = 0;
    virtual ~Soundable() = default;
};

// Dog class implementing only Swimmable and Soundable interfaces
class Dog : public Swimmable, public Soundable {
public:
    void swim() override {
        std::cout << "Dog is swimming." << std::endl;
    }
    void makeSound() override {
        std::cout << "Woof woof!" << std::endl;
    }
};

// Fish class implementing only Swimmable interface
class Fish : public Swimmable {
public:
    void swim() override {
        std::cout << "Fish is swimming." << std::endl;
    }
};

// Bird class implementing Flyable and Soundable interfaces
class Bird : public Flyable, public Soundable {
public:
    void fly() override {
        std::cout << "Bird is flying." << std::endl;
    }
    void makeSound() override {
        std::cout << "Chirp chirp!" << std::endl;
    }
};

#endif // ANIMAL_H
