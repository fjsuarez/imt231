#include <iostream>
#include <string>

// Template function to find the maximum of two values
template <typename T>  // Template parameter declaration
T findMax(T a, T b) {
    return (a > b)? a: b;
}

// Template function to swap two values
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Using findMax with integers
    int maxInt = findMax(10, 20);
    std::cout << "Max of integers: " << maxInt << std::endl;

    // Using findMax with doubles
    double maxDouble = findMax(3.14, 2.71);
    std::cout << "Max of doubles: " << maxDouble << std::endl;

    // Using findMax with strings
    std::string maxString = findMax(std::string("apple"), std::string("banana"));
    std::cout << "Max of strings: " << maxString << std::endl;

    // Using swapValues with integers
    int x = 5, y = 10;
    std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "After swap: x = " << x << ", y = << y" << std::endl;

    // Using swapValues with doubles
    double a = 2.5, b = 7.8;
    std::cout << "\nBefore swap: a = " << a << ", b = " << b << std::endl;
    swapValues(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}