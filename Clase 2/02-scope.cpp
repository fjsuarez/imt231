#include <iostream>

// Global variable (scope: entire file, lifetime: program duration)
int globalVar = 10;

// Function declaration (demonstrates scope)
void myFunction();

int main() {
    // Local variable (scope: within main function, lifetime: within main function)
    int localVar = 20;

    // Static local variable (scope: within main function, lifetime: program duration)
    static int staticLocalVar = 30;  // Initialized only once

    // const variable (scope: within main, cannot be modified after initialization)
    const int constVar = 40;

    // constexpr variable (scope: within main, value known at compile time)
    constexpr int constexprVar = 50;

    std::cout << "Inside main:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "localVar: " << localVar << std::endl;
    std::cout << "staticLocalVar: " << staticLocalVar << std::endl;
    std::cout << "constVar: " << constVar << std::endl;
    std::cout << "constexprVar: " << constexprVar << std::endl;

    myFunction(); // Call the function

    std::cout << "\nBack in main:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "localVar (still): " << localVar << std::endl; //localVar still exists
    std::cout << "staticLocalVar (incremented in myFunction): " << staticLocalVar << std::endl;
    std::cout << "constVar: " << constVar << std::endl;
    std::cout << "constexprVar: " << constexprVar << std::endl;

    myFunction(); // Call the function again
    myFunction(); // Call the function again

    return 0;
}

void myFunction() {
    // Local variable (scope: within myFunction, lifetime: within myFunction)
    int localVar = 60; // This is a DIFFERENT localVar than in main()

    // Modify the global variable
    globalVar = 70;

    // Modify the static local variable
    static int staticLocalVar = 31; // This is the SAME staticLocalVar as in main, but this is an initialization that is executed only once, the first time the execution reaches this line. After that, this line is skipped.
    staticLocalVar++;

    std::cout << "\nInside myFunction:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "localVar: " << localVar << std::endl;
    std::cout << "staticLocalVar: " << staticLocalVar << std::endl;

    // constVar = 80;  // Error: Cannot modify a const variable
    // constexprVar = 90; // Error: Cannot modify a constexpr variable
}