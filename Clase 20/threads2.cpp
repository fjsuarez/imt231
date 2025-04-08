#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>
#include <random>

using namespace std;

const int MAX_CONEXIONES = 5;
const int NUM_HILOS_TRABAJADORES = 15;

atomic<int> conexiones_activas{0};
atomic<bool> limite_alcanzado{false};

// int1 = int2 + int3;
// cargar int2 al ALU
// cargar int3 al ALU
// sumar int2 + int3
// guardar resultado en int1

void simular_trabajo_bd(int id_hilo) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(100, 500);
    cout << "Hilo " << id_hilo << ": Intentando iniciar conexión a la base de datos..." << endl;
    conexiones_activas++;
    int conteo_actual = conexiones_activas.load();
    if (conteo_actual > MAX_CONEXIONES) {
        cerr << "Hilo " << id_hilo << ": Límite de conexiones alcanzado: " << conteo_actual << " El limite es " << MAX_CONEXIONES << endl;
        limite_alcanzado = true;
    } else {
        cout << "Hilo " << id_hilo << ": Conexión establecida. Conexiones activas: " << conteo_actual << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(distribucion(gen)));
    cout << "Hilo " << id_hilo << ": Conexión cerrada. Conexiones activas: " << conteo_actual << endl;
    conexiones_activas--;
}

int main() {
    vector<thread> hilos;

    for (int i=0; i < NUM_HILOS_TRABAJADORES; i++) {
        hilos.emplace_back(simular_trabajo_bd, i+1);  // Se va a generar un "race condition"
    }
    for (auto& hilo : hilos) {
        hilo.join();
    }
    if (limite_alcanzado) {
        cout << "Se alcanzó el límite de conexiones activas." << endl;
    } else {
        cout << "Limite parece OK (o tal vez tuvimos suerte)" << endl;
    }

    return 0;
}