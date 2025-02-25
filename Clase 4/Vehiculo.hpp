#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <string>
#include <iostream>
using namespace std;

class Vehiculo {
    public:
        Vehiculo(); // constructor por defecto
        Vehiculo(string nombre); // constructor delegador
        Vehiculo(string nombre, string marca);
        Vehiculo(string nombre, int cilindrada);
        Vehiculo(const string& modelo, float tanque);
        Vehiculo(const Vehiculo& otroVehiculo); // constructor de copia
        string obtenerMarca();
        int obtenerCilindrada();
        string obtenerNombre();
        void establecerNombre(string nombre);
        void acelerar();
        void encenderRadio();
        float obtenerGasolina();
        void cargarGasolina(float litros);
        void establecerModelo(const string& modelo);
        string obtenerModelo();
    private:
        string nombre;
        string marca;
        int cilindrada;
        int ruedas;
        bool esElectrico;
        bool tieneAireAcondicionado;
        bool tieneCajaAutomatica;
        float tanque;
        string* modelo;
        void activarAirbags();
};

#endif