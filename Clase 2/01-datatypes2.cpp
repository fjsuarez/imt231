#include <iostream>
#include <iomanip> // For setprecision

int main() {
    float floatVar = 3.14;       // Potential warning: implicit conversion from double to float
    float floatVarCorrect = 3.14f; // Correct: explicit float literal

    double doubleVar = 3.14;

    std::cout << std::setprecision(10); // Show more decimal places

    std::cout << "floatVar: " << floatVar << std::endl;
    std::cout << "floatVarCorrect: " << floatVarCorrect << std::endl;
    std::cout << "doubleVar: " << doubleVar << std::endl;

    return 0;
}