#include <iostream>
#include <memory>

class Singleton {
public:
    // Static method to access the Singleton instance
    static Singleton& GetInstance() {
        static Singleton instance;  // Static Singleton instance
        return instance;
    }

    // An example method
    void ShowMessage() const {
        std::cout << "Singleton instance is working!" << std::endl;
    }

    // Disable copy and assignment operators
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton created." << std::endl;
    }

    // Private destructor to prevent deletion of instance
    ~Singleton() {
        std::cout << "Singleton destroyed." << std::endl;
    }
};