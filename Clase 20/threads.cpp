#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool g_trabajo_terminado = false;

void funcion_hilo_trabajador() {
    cout << "Hilo trabajador: Comenzando el trabajo..." << endl;
    // Simulando trabajo
    this_thread::sleep_for(chrono::seconds(2));
    g_trabajo_terminado = true;
    cout << "Hilo trabajador: Trabajo terminado." << endl;
}

void funcion_hilo_espera_activa() {
    cout << "Hilo de espera activa: Esperando a que el trabajo termine..." << endl;
    while (!g_trabajo_terminado) {
        // Esperando activamente
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "Hilo de espera activa: Trabajo terminado, continuando..." << endl;
}


int main() {
    cout << "Empezando el hilo trabajador y el hilo de espera activa..." << endl;
    thread trabajador(funcion_hilo_trabajador);
    thread espera_activa(funcion_hilo_espera_activa);

    trabajador.join();
    cout << "Hilo principal: Hilo trabajador ha terminado." << endl;
    espera_activa.join();
    cout << "Hilo principal: Hilo de espera activa ha terminado." << endl;
    cout << "Hilo principal: Fin del programa." << endl;
    // No es necesario llamar a `delete` para los hilos, ya que se limpian automáticamente al salir del alcance.
    return 0;
}