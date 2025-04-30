// tienda_tickets.h

#pragma once

#include <vector>
#include <string>

struct Cliente {
    std::string nombre;
    int         numeroTickets;
    double      tiempoEnTienda;
    double      retrasoIngreso;
    bool        VIP;
};

/**
 * Simula la tienda de entradas con hilos (uno por cliente).
 *
 * @param clientes    Vector de clientes a procesar.
 * @param precio_ticket Precio unitario de cada entrada.
 * @param capacidad_maxima Número máximo de personas simultáneas en la tienda.
 * @param n_vips       Número total de clientes VIP (para priorizar la entrada).
 * @return             La recaudación total obtenida.
 */
double simular_tienda(const std::vector<Cliente>& clientes,
                      double precio_ticket,
                      int capacidad_maxima,
                      int n_vips);
