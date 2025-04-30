#include <iostream>
#include <string>

class  ReproductorBluRay {
    std::string _pelicula;
    public:
        void encender() {
            std::cout << "Encendiendo el reproductor BluRay." << std::endl;
        }
        void apagar() {
            std::cout << "Apagando el reproductor BluRay." << std::endl;
        }
        void reproducir(const std::string& pelicula) {
            _pelicula = pelicula;
            std::cout << "Reproduciendo la película: " << _pelicula << std::endl;
        }
        void pausar() {
            std::cout << "Pausando la película: " << _pelicula << std::endl;
        }
        void detener() {
            std::cout << "Deteniendo la película: " << _pelicula << std::endl;
        }
        void expulsar() {
            std::cout << "Expulsando el disco." << std::endl;
        }
};

class Amplificador {
    public:
        void encender() {
            std::cout << "Encendiendo el amplificador." << std::endl;
        }
        void apagar() {
            std::cout << "Apagando el amplificador." << std::endl;
        }
        void setVolumen(int nivel) {
            std::cout << "Ajustando el volumen a: " << nivel << std::endl;
        }
};

class Proyector {
    public:
        void encender() {
            std::cout << "Encendiendo el proyector." << std::endl;
        }
        void apagar() {
            std::cout << "Apagando el proyector." << std::endl;
        }
        void modoWidescreen() {
            std::cout << "Configurando el proyector en modo widescreen." << std::endl;
        }
};

class Telon {
    public:
        void abrir() {
            std::cout << "Abriendo el telón." << std::endl;
        }
        void cerrar() {
            std::cout << "Cerrando el telón." << std::endl;
        }
};

class Luces {
    public:
        void encender() {
            std::cout << "Encendiendo las luces." << std::endl;
        }
        void apagar() {
            std::cout << "Apagando las luces." << std::endl;
        }
        void atenuar(int nivel) {
            std::cout << "Atenuando las luces al nivel: " << nivel << std::endl;
        }
};

class SistemaHomeTheaterFacade {
    // instanciacion de los subsistemas

    ReproductorBluRay _reproductor;
    Amplificador _amp;
    Proyector _proy;
    Telon _telon;
    Luces _luces;

    public:
        SistemaHomeTheaterFacade(Amplificador amp,
                Proyector proy,
                ReproductorBluRay rep,
                Telon tel,
                Luces luces) :
        _amp(std::move(amp)),
        _proy(std::move(proy)),
        _reproductor(std::move(rep)),
        _telon(std::move(tel)),
        _luces(std::move(luces)) {}

        void iniciarPelicula(const std::string& pelicula) {
            _telon.abrir();
            _luces.atenuar(50);
            _amp.encender();
            _amp.setVolumen(20);
            _proy.encender();
            _proy.modoWidescreen();
            _reproductor.encender();
            _reproductor.reproducir(pelicula);
        }
        void detenerPelicula() {
            _reproductor.pausar();
            _luces.encender();
            _telon.cerrar();
            _proy.apagar();
            _amp.apagar();
        }
};

int main() {
    Amplificador amplificador;
    Proyector proyector;
    ReproductorBluRay reproductor;
    Telon telon;
    Luces luces;

    SistemaHomeTheaterFacade homeTheater(amplificador, proyector, reproductor, telon, luces);

    homeTheater.iniciarPelicula("Inception");
    std::cout << "Disfrutando de la película..." << std::endl;
    homeTheater.detenerPelicula();
    std::cout << "Película detenida." << std::endl;
    return 0;

}