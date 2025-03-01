#include "json.hpp"  // Incluir archivo header JSON  
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int main() {
    // Leer bootstrap-static.json
    std::ifstream bootstrapFile("bootstrap-static.json");
    if (!bootstrapFile.is_open()){
        std::cerr << "Error: No se puede abrir bootstrap-static.json" << std::endl;
        return 1;
    }
    json bootstrap;
    bootstrapFile >> bootstrap;
    bootstrapFile.close();

    // Read fixtures.json
    std::ifstream fixturesFile("fixtures.json");
    if (!fixturesFile.is_open()){
        std::cerr << "Error: No se puede abrir fixtures.json" << std::endl;
        return 1;
    }
    json fixtures;
    fixturesFile >> fixtures;
    fixturesFile.close();

    // Process or display the JSON data as needed
    std::cout << "bootstrap-static.json:" << std::endl;
    std::cout << bootstrap.dump(4) << std::endl;
    // std::cout << bootstrap["elements"].size() << std::endl;

    std::cout << "fixtures.json:" << std::endl;
    std::cout << fixtures.dump(4) << std::endl;

    return 0;
}