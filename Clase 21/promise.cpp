#include <future>
#include <iostream>
#include <chrono>
#include <thread>

void tarea(std::promise<int>& promesa) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int resultado = 42; // Simulando un resultado
    promesa.set_value(resultado);
}

int main() {
    std::promise<int> promesa;
    std::future<int> futuro = promesa.get_future();

    // std::thread hilo([&promesa]() {
    //     std::this_thread::sleep_for(std::chrono::seconds(2));
    //     promesa.set_value(42);
    // });

    std::thread hilo(tarea, std::ref(promesa));
    
    std::cout << "Esperando el resultado..." << std::endl;
    std::cout << "Realizando otras tareas..." << std::endl;
    int resultado = futuro.get();
    std::cout << "Resultado: " << resultado << std::endl;
    
    hilo.join();
    return 0;
}