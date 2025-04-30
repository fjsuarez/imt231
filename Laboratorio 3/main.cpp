// main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>      // EXIT_FAILURE, EXIT_SUCCESS
#include <iomanip>      // setprecision
#include "json.hpp"     // https://github.com/nlohmann/json
#include "globals.h"    // expected_threads, created_threads, register_thread()
#include "tienda_tickets.h"  // declara simular_tienda(...)

using json = nlohmann::json;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Debes pasar dos argumentos: precio_ticket y maxima_ocupacion\n";
        return EXIT_FAILURE;
    }

    // 1) Parsear argumentos
    double precio_ticket = stod(argv[1]);
    int capacidad_maxima = stoi(argv[2]);

    // 2) Leer y parsear clientes.json
    ifstream ifs("clientes.json");
    if (!ifs) {
        cerr << "No se pudo abrir clientes.json\n";
        return EXIT_FAILURE;
    }
    json j; 
    ifs >> j;

    vector<Cliente> clientes;
    int numero_vips = 0;

    // 3) Cargar clientes y preparar contadores globales
    for (auto& elemento : j) {
        Cliente c;
        c.nombre         = elemento.at("nombre").get<string>();
        c.numeroTickets  = elemento.at("numeroTickets").get<int>();
        c.tiempoEnTienda = elemento.at("tiempoEnTienda").get<double>();
        c.retrasoIngreso = elemento.at("retrasoIngreso").get<double>();
        c.VIP            = elemento.at("VIP").get<bool>();

        clientes.push_back(c);

        // Actualizar mapas globales para el registro de hilos
        expected_threads[c.nombre]++;   // cuántos hilos esperamos de este cliente
        created_threads[c.nombre] = 0;  // inicialmente ninguno creado

        if (c.VIP) ++numero_vips;
    }

    // 4) Ejecutar la simulación (en tienda_tickets.cpp)
    double ganancias = simular_tienda(
        clientes,
        precio_ticket,
        capacidad_maxima,
        numero_vips
    );

    // 5) Verificar que se han creado exactamente los hilos esperados
    for (auto const& [nombre, esperado] : expected_threads) {
        int creados = created_threads[nombre];
        if (creados != esperado) {
            cerr << "Hilos inesperados para " << nombre
                 << ". Esperado " << esperado
                 << ", encontrado " << creados << ".\n";
            return EXIT_FAILURE;
        }
    }

    // 6) Verificar recaudación total
    double ganancias_esperadas = 0.0;
    for (auto const& c : clientes) {
        ganancias_esperadas += precio_ticket * c.numeroTickets;
    }
    if (fabs(ganancias_esperadas - ganancias) > 1e-2) {
        cerr << fixed << setprecision(2)
             << "Recaudación esperada (" << ganancias_esperadas
             << ") no coincide con la real (" << ganancias << ").\n";
        return EXIT_FAILURE;
    }

    // 7) Todo OK
    cout << "Ganancias totales: " << fixed << setprecision(2)
         << ganancias << "\n";
    return EXIT_SUCCESS;
}
