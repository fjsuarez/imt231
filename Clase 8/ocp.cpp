// Open-Closed Principle

class Figura { // clase base abstracta (ABC)
    public:
        virtual double area() const = 0;
};

class Rectangulo : public Figura {
    public:
        Rectangulo(double base, double altura) : base(base), altura(altura) {}
        double area() const override {
            return base * altura;
        }
    private:
        double base;
        double altura;
};

class Circulo : public Figura {
    public:
        Circulo(double radio) : radio(radio) {}
        double area() const override {
            return 3.1416 * radio * radio;
        }
        double circunferencia() const {
            return 2 * 3.1416 * radio;
        }
    private:
        double radio;
};