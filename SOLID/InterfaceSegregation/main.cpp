#include "Animal.h"

int main() {
    Dog dog;
    Fish fish;
    Bird bird;

    dog.swim();         // Output: "Dog is swimming."
    dog.makeSound();    // Output: "Woof woof!"

    fish.swim();        // Output: "Fish is swimming."

    bird.fly();         // Output: "Bird is flying."
    bird.makeSound();   // Output: "Chirp chirp!"

    return 0;
}
