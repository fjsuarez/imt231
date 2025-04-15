#include <future>
#include <iostream>
#include <chrono>
#include <thread>

// int sumar(int a, int b) {
//     std::this_thread::sleep_for(std::chrono::seconds(2));
//     return a + b;
// }

int tareaConDelay(int id) {
    std::cout << "Tarea " << id << " iniciada." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Tarea " << id << " completada." << std::endl;
    return id * 10;
}

int main() {
    // politicas de ejecucion
    // std::launch::async: Ejecuta la tarea de forma asíncrona (en un nuevo hilo).
    // std::launch::deferred: La tarea se ejecuta de forma diferida (en el hilo que llama a get() o wait()).

    std::future<int> resultado1 = std::async(tareaConDelay, 1);
    // std::future<int> resultado2 = std::async(std::launch::deferred, sumar, 5, 10);
    std::future<int> resultado2 = std::async(tareaConDelay, 2);
    std::cout << "Iniciando tareas..." << std::endl;
    std::cout << "Haciendo otras tareas..." << std::endl;
    std::cout << resultado1.get() << std::endl;
    std::cout << resultado2.get() << std::endl;
    std::cout << "Tarea 1 y Tarea 2 completadas." << std::endl;

    // std::cout << "Iniciando tareas..." << std::endl;
    // std::cout << tareaConDelay(1) << std::endl;
    // std::cout << tareaConDelay(2) << std::endl;
    // std::cout << "Tarea 1 y Tarea 2 completadas." << std::endl;
    // std::cout << "Haciendo otras tareas..." << std::endl;

    return 0;
}