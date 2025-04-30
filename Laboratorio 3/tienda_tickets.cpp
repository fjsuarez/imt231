// tienda_tickets.cpp

#include "tienda_tickets.h"
#include "globals.h"
#include <iostream>
#include <thread>
#include <semaphore> // puedes usar semaphore (requiere C++20)
#include <mutex> // puedes usar mutex
#include <condition_variable> // en combinacion con condition_variable para esperar hasta que se cumpla una condicion
#include <chrono>
#include <cmath>

// Timestamp inicial (al cargar el módulo)
static const auto TIEMPO_INICIAL = std::chrono::steady_clock::now();

// crea una funcion que se ejecuta en un hilo para cada cliente
static void cliente_hilo(const Cliente& c, double precio_ticket) {
// no olvides usar register_thread(c.nombre) para registrar el hilo
    register_thread(c.nombre);
    // 1) Retraso de ingreso
    // 2) Pedir entrada
    // 3) Esperar a que haya espacio en la tienda
    // 4) Entrar a la tienda
    // 5) Comprar entradas (multiplicando por precio_ticket)
    // 6) Salir de la tienda
}

// Devuelve los segundos transcurridos desde el arranque, redondeados a 1 decimal
double get_segundos_transcurridos() {
    auto ahora = std::chrono::steady_clock::now();
    std::chrono::duration<double> dif = ahora - TIEMPO_INICIAL;
    double segs = dif.count();
    return std::round(segs * 10.0) / 10.0;
}

double simular_tienda(const std::vector<Cliente>& clientes,
                      double precio_ticket,
                      int capacidad_maxima,
                      int n_vips) {
    
    // Devolver la recaudación
    return 0.0;
}
