#include "Animal.h"

// Function that accepts any Animal and calls its move function
void makeAnimalMove(const Animal& animal) {
    animal.move();
}

// Function that accepts any CanMakeSound object and calls its makeSound function
void makeAnimalSound(const CanMakeSound& soundMaker) {
    soundMaker.makeSound();
}

int main() {
    std::unique_ptr<Animal> dog = std::make_unique<Dog>();
    std::unique_ptr<Animal> sparrow = std::make_unique<Sparrow>();
    std::unique_ptr<Animal> silentBird = std::make_unique<SilentBird>();

    // All animals can move
    makeAnimalMove(*dog);         // Outputs: "Dog is running."
    makeAnimalMove(*sparrow);     // Outputs: "Sparrow is flying."
    makeAnimalMove(*silentBird);  // Outputs: "Silent bird is flying."

    // Only objects that implement CanMakeSound can make sounds
    makeAnimalSound(dynamic_cast<CanMakeSound&>(*dog));      // Outputs: "Woof woof!"
    makeAnimalSound(dynamic_cast<CanMakeSound&>(*sparrow));  // Outputs: "Chirp chirp!"

    // SilentBird does not implement CanMakeSound, so it cannot make a sound
    // makeAnimalSound(dynamic_cast<CanMakeSound&>(*silentBird)); // This line would cause a compilation error

    return 0;
}
