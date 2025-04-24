// #ifndef SINGLETON_H
// #define SINGLETON_H

// #endif

#pragma once

#include <string>
#include <iostream>
#include <mutex>

class Logger {
    public:
        static Logger& getInstance() {
            static Logger _instance; // Instancia única de Logger
            return _instance;
        }

        void log(const std::string& message) {
            std::lock_guard<std::mutex> lock(_mtx); // Bloquea el mutex
            // UART, SPI, I2C, o cualquier otro buffer de hardware
            escribirMensaje(message); // Llama a la función para escribir el mensaje
            // std::cout << message << std::endl; // Output a consola (standard output)
        }

    private:
        Logger() {
            initHardware();
        } // Constructor privado

        ~Logger() = default; // Destructor por defecto
        Logger(const Logger&) = delete; // Elimina el constructor de copia
        Logger(Logger&&) = delete; // Elimina el constructor de movimiento
        Logger& operator=(const Logger&) = delete; // Elimina el operador de asignación
        Logger& operator=(Logger&&) = delete; // Elimina el operador de movimiento

        void initHardware() {
            // Inicializa el hardware del logger
            std::cout << "Inicializando hardware del logger..." << std::endl;
        }

        void escribirMensaje(const std::string& message) {
            // Aquí iría la lógica para escribir el mensaje en el hardware
            std::cout << "Escribiendo mensaje: " << message << std::endl;
        }

        std::mutex _mtx; // Mutex para proteger el acceso a la instancia
};


// Constructor de instanciacion
// Logger miLogger();

// Constructor de copia
// Logger miLogger2 = miLogger; // Error: no se puede copiar

// Constructor de transferencia
// 