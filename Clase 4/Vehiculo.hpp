#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <string>
#include <iostream>
using namespace std;

class Vehiculo {
    public:
    string obtenerMarca();
    int obtenerCilindrada();
    string obtenerNombre();
    void establecerNombre(string nombre);
    void acelerar();
    void encenderRadio();
    float obtenerGasolina();
    void cargarGasolina(float litros);
    private:
    string nombre;
    string marca;
    int cilindrada;
    int ruedas;
    bool esElectrico;
    bool tieneAireAcondicionado;
    bool tieneCajaAutomatica;
    float tanque;
    void activarAirbags();
};

#endif