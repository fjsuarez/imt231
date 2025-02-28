// SOLID Principles
// Single responsibility principle (SRP) - Principio de responsabilidad única
// Open/Closed principle (OCP) - Principio de abierto/cerrado
// Liskov substitution principle (LSP) - Principio de sustitución de Liskov
// Interface segregation principle (ISP) - Principio de segregación de interfaces
// Dependency inversion principle (DIP) - Principio de inversión de dependencias

#include <iostream>
using namespace std;

class Libro {
    public:
        Libro(string titulo) : titulo(titulo) {}
        string getTitulo() const {
            return titulo;
        }
        void setTitulo(string titulo) {
            this->titulo = titulo;
        }
        // void guardarLibro() {
        //     cout << "Guardando libro: " << titulo << endl;
        //     // logica para guardar libro
        // }
    private:
        string titulo;
};

class LibroRepositorio {
    public:
        void guardarLibro(const Libro& libro) {
            cout << "Guardando libro: " << libro.getTitulo() << endl;
            // logica para guardar libro
        }
};

// class Pedido {
//     public:
//         void agregarProducto(Producto producto) { };
//         void calcularTotal() { };
//         void generarFactura() { };
//         void enviarCorreoConfirmacion() { };
//     private:
//         Producto productos[]; // mala practica
// }

class Pedido {
    public:
        void agregarProducto(Producto producto) { };
        void calcularTotal() { };
    private:
        Producto productos[];
};

class GeneradorFactura {
    public:
        void generarFactura(Pedido& pedido) { };
};

class NotificarPedido {
    public:
        void enviarCorreoConfirmacion(Pedido& pedido) { };
};


int main() {
    
    return 0;
}