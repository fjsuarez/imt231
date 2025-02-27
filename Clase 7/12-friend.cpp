#include <iostream>
using namespace std;

class Privada {
    private:
        int datoPrivado;
    public:
        Privada(int valor) : datoPrivado(valor) {}
        friend class Amiga;
};

class Amiga {
    public:
        void mostrarDato(const Privada& privada) {
            cout << "Dato privado: " << privada.datoPrivado << endl;
        }

        void modificarDato(Privada& privada, int nuevoValor) {
            privada.datoPrivado = nuevoValor;
        }
};

int main() {
    Privada instanciaPrivada(10);
    Amiga instanciaAmiga;

    instanciaAmiga.mostrarDato(instanciaPrivada);
    instanciaAmiga.modificarDato(instanciaPrivada, 20);
    instanciaAmiga.mostrarDato(instanciaPrivada);
    
    return 0;
}