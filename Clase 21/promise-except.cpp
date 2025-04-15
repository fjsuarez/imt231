#include <future>
#include <iostream>
#include <chrono>
#include <thread>

void tareaConError(std::promise<int>& promesa) {
    try {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        throw std::runtime_error("Error en la tarea");
        promesa.set_value(42); // Simulando un resultado. Esta línea no se ejecutará.
    } catch (...) {
        promesa.set_exception(std::current_exception());

    }
}

int main() {
    std::promise<int> promesa;
    std::future<int> futuro = promesa.get_future();

    std::thread hilo(tareaConError, std::ref(promesa));

    std::cout << "Esperando el resultado..." << std::endl;
    try {
        int resultado = futuro.get();
        std::cout << "Resultado: " << resultado << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    hilo.join();
    std::cout << "Hilo terminado." << std::endl;
    std::cout << "Haciendo otras tareas..." << std::endl;
    return 0;
}