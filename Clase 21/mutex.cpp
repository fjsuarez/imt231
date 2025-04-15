#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx;
int contador = 0;

void incrementar(int id_hilo) {
    // for (int i = 0; i < 10000; ++i) {
    //     mtx.lock(); // Bloquea el mutex
    //     ++contador;
    //     mtx.unlock(); // Desbloquea el mutex
    // }

    std::lock_guard<std::mutex> bloqueo(mtx); // Bloquea el mutex automáticamente

    for (int i = 0; i < 10000; ++i) {
        ++contador;
    }

    // El mutex se desbloquea automáticamente al salir del bloque, porque el destructor de lock_guard se llama
    // al salir del alcance.
}

int main() {
    std::thread hilos[10];

    for (int i = 0; i < 10; ++i) {
        hilos[i] = std::thread(incrementar, i);
    }

    for (int i = 0; i < 10; ++i) {
        hilos[i].join();
    }

    std::cout << "Valor final del contador: " << contador << std::endl;

    return 0;
}