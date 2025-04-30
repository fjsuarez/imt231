#include "globals.h"
#include <iostream>
#include <cstdlib>

// Definición de las variables globales
std::map<std::string,int> expected_threads;
std::map<std::string,int> created_threads;
std::mutex               registry_mtx;

void register_thread(const std::string& name) {
    std::lock_guard<std::mutex> lk(registry_mtx);
    // ¿Nombre esperado?
    if (expected_threads.find(name) == expected_threads.end()) {
        std::cerr << "Unexpected customer thread " << name << "\n";
        std::exit(EXIT_FAILURE);
    }
    // ¿No excedemos el máximo?
    if (++created_threads[name] > expected_threads[name]) {
        std::cerr << "Reached maximum threads for "
                  << name << " (" << expected_threads[name] << ").\n";
        std::exit(EXIT_FAILURE);
    }
}
