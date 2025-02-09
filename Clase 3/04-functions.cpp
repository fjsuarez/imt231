#include <iostream>

// Function prototype (declaration)
int add(int a, int b);                      // Declares a function named 'add' that takes two ints and returns an int
void modifyByValue(int x);                 // Pass by value
void modifyByReference(int& y);             // Pass by reference
void modifyByPointer(int* z);               // Pass by pointer
int* createAndReturnPointer(int value);       // Returns a pointer


int main() {
    int num1 = 5;
    int num2 = 10;

    // Call the add function
    int sum = add(num1, num2);
    std::cout << "Sum: " << sum << std::endl;

    int val = 20;
    std::cout << "\nBefore modifyByValue: " << val << std::endl;
    modifyByValue(val);
    std::cout << "After modifyByValue: " << val << std::endl; // Value unchanged


    int ref = 30;
    std::cout << "\nBefore modifyByReference: " << ref << std::endl;
    modifyByReference(ref);
    std::cout << "After modifyByReference: " << ref << std::endl; // Value changed


    int ptr = 40;
    std::cout << "\nBefore modifyByPointer: " << ptr << std::endl;
    modifyByPointer(&ptr); // Pass the address of ptr
    std::cout << "After modifyByPointer: " << ptr << std::endl; // Value changed


    //Demonstrating returning a pointer:
    int* dynamicPtr = createAndReturnPointer(55);
    std::cout << "\nValue pointed to by dynamicPtr: " << *dynamicPtr << std::endl;
    delete dynamicPtr; // Important to avoid memory leaks!

    return 0;
}

// Function definition (implementation)
int add(int a, int b) {
    return a + b;
}

void modifyByValue(int x) {
    x = x * 2; // Modifies a copy, not the original variable
    std::cout << "Inside modifyByValue: " << x << std::endl;
}

void modifyByReference(int& y) {
    y = y * 2; // Modifies the original variable through the reference
    std::cout << "Inside modifyByReference: " << y << std::endl;
}

void modifyByPointer(int* z) {
    *z = *z * 2; // Modifies the original variable by dereferencing the pointer
    std::cout << "Inside modifyByPointer: " << *z << std::endl;
}

int* createAndReturnPointer(int value) {
    int* newPtr = new int; // Allocate memory dynamically
    *newPtr = value;
    return newPtr; // Return the address of the newly created memory
}