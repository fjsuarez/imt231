#include <iostream>
#include <fstream>      // For file I/O
#include <iomanip>      // For manipulators like setprecision, fixed
#include <limits>       // For numeric_limits

int main() {
    // Basic Output (cout)
    std::cout << "Hello, C++ World!" << std::endl;

    // Output with Formatting (cout and manipulators)
    double pi = 3.141592653589793;
    std::cout << "Pi (default): " << pi << std::endl;
    std::cout << "Pi (fixed, setprecision(5)): " << std::fixed << std::setprecision(5) << pi << std::endl;
    std::cout << "Pi (scientific, setprecision(3)): " << std::scientific << std::setprecision(3) << pi << std::endl;
    std::cout << "Pi (reset to default): " << std::defaultfloat << pi << std::endl; // Reset to default formatting

    // Error Output (cerr)
    std::cerr << "This is an error message." << std::endl;

    // Logging Output (clog)
    std::clog << "This is a log message." << std::endl;


    // Basic Input (cin)
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Your age is: " << age << std::endl;

    // Clear the input buffer (important after reading numeric input)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input


    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // Read a line of text, including spaces
    std::cout << "Your name is: " << name << std::endl;


    // File Output (ofstream)
    std::ofstream outputFile("output.txt"); // Create and open a file for writing
    if (outputFile.is_open()) {
        outputFile << "This is some text written to a file." << std::endl;
        outputFile << "Your age (from input): " << age << std::endl;
        outputFile << "Pi (formatted): " << std::fixed << std::setprecision(10) << pi << std::endl; //Formatted output to file as well
        outputFile.close(); // Close the file
        std::cout << "Data written to output.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    // File Input (ifstream)
    std::ifstream inputFile("output.txt"); // Open the file for reading
    if (inputFile.is_open()) {
        std::string line;
        std::cout << "\nContents of output.txt:" << std::endl;
        while (std::getline(inputFile, line)) { // Read line by line
            std::cout << line << std::endl;
        }
        inputFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}