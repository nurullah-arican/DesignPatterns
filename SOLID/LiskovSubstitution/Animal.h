// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <memory>

// Abstract class: Animal
class Animal {
public:
    virtual void move() const = 0; // Pure virtual function
    virtual ~Animal() = default;
};

// Interface: CanMakeSound
class CanMakeSound {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~CanMakeSound() = default;
};

// Dog class, implementing both Animal and CanMakeSound interfaces
class Dog : public Animal, public CanMakeSound {
public:
    void move() const override {
        std::cout << "Dog is running." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Woof woof!" << std::endl;
    }
};

// Sparrow class, implementing both Animal and CanMakeSound interfaces
class Sparrow : public Animal, public CanMakeSound {
public:
    void move() const override {
        std::cout << "Sparrow is flying." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Chirp chirp!" << std::endl;
    }
};

// SilentBird class, implementing only the Animal interface
class SilentBird : public Animal {
public:
    void move() const override {
        std::cout << "Silent bird is flying." << std::endl;
    }
};

#endif // ANIMAL_H
