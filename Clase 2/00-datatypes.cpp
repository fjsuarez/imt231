#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    // Integer Types
    int myInt = 10;
    short myShort = 5;
    long myLong = 100000;
    long long myLongLong = 1000000000;
    unsigned int myUnsignedInt = 20; // Can't store negative values
    // char is technically an integer type, often used for characters
    char myChar = 'A';

    std::cout << "Integer Types:" << std::endl;
    std::cout << "int: " << myInt << std::endl;
    std::cout << "short: " << myShort << std::endl;
    std::cout << "long: " << myLong << std::endl;
    std::cout << "long long: " << myLongLong << std::endl;
    std::cout << "unsigned int: " << myUnsignedInt << std::endl;
    std::cout << "char: " << myChar << std::endl;
    std::cout << std::endl;


    // Floating-Point Types
    float myFloat = 3.14f; // 'f' suffix is important for float literals
    double myDouble = 3.14159;
    long double myLongDouble = 3.141592653589793238L; // 'L' suffix for long double

    std::cout << "Floating-Point Types:" << std::endl;
    std::cout << "float: " << myFloat << std::endl;
    std::cout << "double: " << myDouble << std::endl;
    std::cout << "long double: " << myLongDouble << std::endl;
    std::cout << std::endl;

    // Boolean Type
    bool myBool = true;

    std::cout << "Boolean Type:" << std::endl;
    std::cout << "bool: " << myBool << std::endl;  // Output will be 1 (true) or 0 (false)
    std::cout << std::endl;

    // Character Types (already shown char above, let's show more string)
    char singleChar = 'Z';
    std::string myString = "Hello, C++!"; // std::string for more complex strings

    std::cout << "Character/String Types:" << std::endl;
    std::cout << "char: " << singleChar << std::endl;
    std::cout << "std::string: " << myString << std::endl;
    std::cout << std::endl;

    // void type (used for functions that don't return a value)
    // Example: void myFunction() { /* ... */ }


    // Demonstrating numeric_limits (for min/max values)
    std::cout << "Numeric Limits:" << std::endl;
    std::cout << "Minimum int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Maximum double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::endl;

    return 0;
}