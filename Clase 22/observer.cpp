#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// tambien llamado pub/sub
// el sujeto es el que publica los datos y los observadores son los que se suscriben a esos datos

class IObservador {
    public:
        virtual ~IObservador() = default;
        virtual void actualizar(int estado) = 0; // Método virtual puro
};

class Sujeto { // topic
    public:
        void agregarObservador(std::shared_ptr<IObservador> observador) { // subscribe
            observadores.push_back(std::move(observador));
        }

        void quitarObservador(std::shared_ptr<IObservador> observador) {
            observadores.erase(
                std::remove(observadores.begin(), observadores.end(), observador),
                observadores.end()
            );
        }

    protected:
        void notificarObservadores(int valor) {
            for (const auto& observador : observadores) {
                observador->actualizar(valor);
            }
        }

    private:
        std::vector<std::shared_ptr<IObservador>> observadores;
};

class TemperaturaSensor : public Sujeto {
    public:
        void establecerTemperatura(int temperatura) { // publish
            this->temperatura_ = temperatura;
            notificarObservadores(temperatura);
        }
        int getTemperatura() {
            std::cout << "Temperatura actual: " << temperatura_ << std::endl;
            return temperatura_;
        }

    private:
        int temperatura_{0};
};

class DisplayTemperatura : public IObservador {
    public:
        void actualizar(int estado) override {
            std::cout << "Display de temperatura actualizado: " << estado << std::endl;
        }
};

class PanelControl : public IObservador {
    public:
        void actualizar(int estado) override {
            std::cout << "Panel de control actualizado: " << estado << std::endl;
        }
};

int main() {
    auto sensor = std::make_shared<TemperaturaSensor>();
    auto display = std::make_shared<DisplayTemperatura>();
    auto panel = std::make_shared<PanelControl>();

    sensor->agregarObservador(display);
    sensor->agregarObservador(panel);

    sensor->establecerTemperatura(25);
    sensor->establecerTemperatura(30);

    sensor->quitarObservador(display);
    sensor->establecerTemperatura(35);

    return 0;
}