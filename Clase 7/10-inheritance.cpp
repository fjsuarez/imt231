#include <iostream>
#include <string>
using namespace std;

// class Animal {
//     public:
//         string nombre;
//         Animal(string nombre, int edad) : nombre(nombre), edad(edad) {};
//         void comer() {
//             cout << nombre << " está comiendo..." << endl;
//         }
//         int obtenerEdad() {
//             return edad;
//         }
//     protected:
//         void establecerEdad(int edad) {
//             this->edad = edad;
//         }
//     private: 
//         int edad;
// };

// class Perro : public Animal {
//     public:
//         Perro(string nombre, int edad) : Animal(nombre, edad) {};
//         void ladrar() {
//             cout << nombre << " está ladrando..." << endl;
//         }
// };

// class Pato : public Animal {
//     public:
//         Pato(string nombre, int edad) : Animal(nombre, edad) {};
//         void graznar() {
//             cout << nombre << " está graznando..." << endl;
//         }
// };

class Animal {
    public:
        Animal() { cout << "Constructor de Animal" << endl; }
        ~Animal() { cout << "Destructor de Animal" << endl; }
};

class Perro: public Animal {
    public:
        Perro() { cout << "Constructor de Perro" << endl; }
        ~Perro() { cout << "Destructor de Perro" << endl; }
};


int main() {
    // Animal animal("Perro", 7);
    // animal.comer();
    // Perro perro("Firulais", 12);
    // cout << perro.nombre << endl;
    // cout << perro.obtenerEdad() << endl;
    // perro.comer();
    // perro.ladrar();
    // Pato pato("Lucas", 2);
    // pato.comer();
    // pato.graznar();

    Perro miPerro;

    return 0;   
}