#include "Singleton.h"

int main()
{
    // Access the Singleton instance and call the ShowMessage method
    Singleton::GetInstance().ShowMessage();

    // Access the Singleton instance again
    Singleton::GetInstance().ShowMessage();

    return 0;
}