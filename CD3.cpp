#include <iostream>

// Define a macro expression
#define PI 3.14159

int main() {
    double radius = 5.0;
    double circumference = 2 * PI * radius;

    std::cout << "The circumference of a circle with radius "
              << radius << " is " << circumference << std::endl;


    #undef PI
    #define PI 3.14

    circumference = 2 * PI * radius;

    std::cout << "The circumference of a circle with radius "
              << radius << " is " << circumference << std::endl;

    return 0;
}