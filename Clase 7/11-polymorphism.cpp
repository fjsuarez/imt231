#include <iostream>
using namespace std;

class Figura { // clase base abstracta (ABC)
    public:
        virtual double area() = 0; // método virtual puro
        virtual ~Figura() {};
};

class Rectangulo : public Figura {
    public:
        Rectangulo(double base, double altura) : base(base), altura(altura) {}
        double area() override {
            return base * altura;
        }
    private:
        double base;
        double altura;
};

class Circulo : public Figura {
    public:
        Circulo(double radio) : radio(radio) {}
        double area() override {
            return 3.1416 * radio * radio;
        }
    private:
        double radio;
};


int main() {
    Figura* figuras[] = {new Rectangulo(10, 5), new Circulo(5)};
    // for (int i = 0; i < 2; i++) { // for loop
    //     cout << "Área de la figura " << i + 1 << ": " << figuras[i]->area() << endl;
    //     delete figuras[i];
    // }
    for (Figura* figura : figuras) { // for each loop
        cout << "Área de la figura: " << figura->area() << endl;
        delete figura;
    }
    return 0;
}