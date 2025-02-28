// Liskov substitution principle (LSP) - Principio de sustitución de Liskov
#include <iostream>

using namespace std;

class Ave {
    public:
        virtual void volar() = 0;
};

class Aguila : public Ave {
    public:
        void volar() override {
            cout << "Volando como un águila" << endl;
        }
};

class Gorrion : public Ave {
    public:
        void volar() override {
            cout << "Volando como un gorrión" << endl;
        }
};

class Pinguino : public Ave {
    public:
        void volar() override {
            throw "Los pingüinos no vuelan";
        }
};