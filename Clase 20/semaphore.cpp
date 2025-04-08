#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <semaphore>
#include <random>

using namespace std;

const int MAX_CONEXIONES = 5;
const int NUM_HILOS_TRABAJADORES = 15;

counting_semaphore semaforo(MAX_CONEXIONES);

atomic<int> conexiones_activas{0};

void simluar_trabajo_bd(int id_hilo) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(100, 500);
    cout << "Hilo " << id_hilo << ": Intentando iniciar conexión a la base de datos..." << endl;
    semaforo.acquire(); // Espera hasta que haya un recurso disponible
    conexiones_activas++;
    cout << "Hilo " << id_hilo << ": Conexión establecida. Conexiones activas: " << conexiones_activas.load() << endl;
    this_thread::sleep_for(chrono::milliseconds(distribucion(gen)));
    cout << "Hilo " << id_hilo << ": Conexión cerrada. Conexiones activas: " << conexiones_activas.load() << endl;
    conexiones_activas--;
    semaforo.release(); // Libera el recurso
}

int main() {
    cout << "Iniciando simulacion con SEMAFORO" << endl;
    vector<thread> hilos;
    for (int i = 0; i < NUM_HILOS_TRABAJADORES; i++) {
        hilos.emplace_back(simluar_trabajo_bd, i + 1);
    }
    for (auto& hilo : hilos) {
        hilo.join();
    }
    cout << "Simulacion terminada." << endl;
    cout << "Conexiones activas finales: " << conexiones_activas.load() << endl;

    return 0;
}