#include <iostream>
#include <string>

// Function overloading: different versions of the same function name
// 1. Function to add two integers
int add(int a, int b) {
    std::cout << "Adding two integers" << std::endl;
    return a + b;
}

// 2. Function to add three integers
int add(int a, int b, int c) {
    std::cout << "Adding three integers" << std::endl;
    return a + b + c;
}

// 3. Function to concatenate two strings
std::string add(const std::string& str1, const std::string& str2) {
    std::cout << "Concatenating two strings" << std::endl;
    return str1 + str2;
}

// 4. Function to add an integer and a double
double add(int a, double b) {
    std::cout << "Adding an integer and a double" << std::endl;
    return a + b;
}


int main() {
    int sum1 = add(5, 10);        // Calls the first version of add
    std::cout << "Sum1: " << sum1 << std::endl;

    int sum2 = add(5, 10, 15);    // Calls the second version of add
    std::cout << "Sum2: " << sum2 << std::endl;

    std::string strSum = add("Hello, ", "C++!"); // Calls the third version of add
    std::cout << "String Sum: " << strSum << std::endl;

    double sum3 = add(5, 3.14);  // Calls the fourth version of add
    std::cout << "Sum3: " << sum3 << std::endl;

    return 0;
}