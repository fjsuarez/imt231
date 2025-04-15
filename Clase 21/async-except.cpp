#include <iostream>
#include <future>
#include <stdexcept>

int division(int numerador, int denominador) {
    if (denominador == 0) {
        throw std::runtime_error("Error: División por cero");
    }
    return numerador / denominador;
}

int main() {
    std::future<int> resultado = std::async(std::launch::async, division, 10, 0);
    try {
        int valor = resultado.get(); // Esto lanzará la excepción si hubo un error
        std::cout << "Resultado: " << valor << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }
    std::cout << "Haciendo otras tareas..." << std::endl;
    return 0;
}