// Dependency inversion principle (DIP) - Principio de inversión de dependencias
#include <iostream>
using namespace std;

// class Interruptor {
//     public:
//         void encender(Foco foco) {
//             foco.encender();
//         }
// };

// class Foco {
//     public:
//         void encender() {
//             cout << "Foco encendido" << endl;
//         }
// };

class DispositivoElectrico {
    public:
        virtual void encender() = 0;
};

class Foco : public DispositivoElectrico {
    public:
        void encender() override {
            cout << "Foco encendido" << endl;
        }
};

class Interruptor {
    public:
        void encender(DispositivoElectrico& dispositivo) {
            dispositivo.encender();
        }
};


class Arma {
    public:
        virtual void atacar() = 0;
};

class Espada : public Arma {
    public:
        void atacar() override {
            cout << "Atacando con espada" << endl;
        }
};

class Arco : public Arma {
    public:
        void atacar() override {
            cout << "Atacando con arco" << endl;
        }
};

class Personaje {
    public:
        void atacar() {
            cout << "Atacando" << endl;
            arma->atacar();
        }
    private:
        Arma* arma;
};