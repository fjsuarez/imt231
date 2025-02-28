// Interface segregation principle (ISP) - Principio de segregación de interfaces
#include <iostream>
using namespace std;

// class Impresora {
//     public:
//         virtual void imprimir() = 0;
//         virtual void escanear() = 0;
//         virtual void faxear() = 0;
// };

// class ImpresoraEpson : public Impresora {
//     public:
//         void imprimir() override {
//             cout << "Imprimiendo con Epson" << endl;
//         }
//         void escanear() override {
//             cout << "Escaneando con Epson" << endl;
//         }
//         void faxear() override {
//             throw "Epson no puede faxear";
//         }
// };

class Impresora {
    public:
        virtual void imprimir() = 0;
};

class Escaner {
    public:
        virtual void escanear() = 0;
};

class Fax {
    public:
        virtual void faxear() = 0;
};

class ImpresoraEpson : public Impresora, public Escaner {
    public:
        void imprimir() override {
            cout << "Imprimiendo con Epson" << endl;
        }
        void escanear() override {
            cout << "Escaneando con Epson" << endl;
        }
};