#pragma once
#include <map>
#include <string>
#include <mutex>

// Declaración de las variables globales
extern std::map<std::string,int> expected_threads;
extern std::map<std::string,int> created_threads;
extern std::mutex               registry_mtx;

// Función para registrar/verificar cada hilo que arranca
void register_thread(const std::string& name);
