#include <iostream>
#include "Saludo.hpp"
using namespace std;

int main() {
    string nombre = "Batman";
    string saludo = generarSaludo(nombre);
    cout << saludo << endl;
    cout << "El saludo tiene " << saludo.size() << " caracteres." << endl;
    return 0;
}