#include <iostream>
#include <memory>

class IComm {
    public:
        virtual ~IComm() = default; // Destructor virtual
        virtual void enviar(const std::string& data, size_t len) = 0; // Método virtual puro
        virtual void recibir(std::string& data, size_t len) = 0; // Método virtual puro
};

class UART : public IComm {
    public:
        void enviar(const std::string& data, size_t len) override {
            // Implementación específica para UART
            std::cout << "Enviando por UART: " << data.substr(0, len) << std::endl;
        }
        
        void recibir(std::string& data, size_t len) override {
            // Implementación específica para UART
            data = "Datos recibidos por UART";
            std::cout << "Recibiendo por UART: " << data.substr(0, len) << std::endl;
        }
};
class SPI : public IComm {
    public:
        void enviar(const std::string& data, size_t len) override {
            // Implementación específica para SPI
            std::cout << "Enviando por SPI: " << data.substr(0, len) << std::endl;
        }
        
        void recibir(std::string& data, size_t len) override {
            // Implementación específica para SPI
            data = "Datos recibidos por SPI";
            std::cout << "Recibiendo por SPI: " << data.substr(0, len) << std::endl;
        }
};
class I2C : public IComm {
    public:
        void enviar(const std::string& data, size_t len) override {
            // Implementación específica para I2C
            std::cout << "Enviando por I2C: " << data.substr(0, len) << std::endl;
        }
        
        void recibir(std::string& data, size_t len) override {
            // Implementación específica para I2C
            data = "Datos recibidos por I2C";
            std::cout << "Recibiendo por I2C: " << data.substr(0, len) << std::endl;
        }
};

enum class CommType {
    UART,
    SPI,
    I2C
};

class CommFactory {
    public:
        static std::unique_ptr<IComm> crearComunicacion(CommType tipo) {
            switch (tipo) {
                case CommType::UART:
                    return std::make_unique<UART>();
                case CommType::SPI:
                    return std::make_unique<SPI>();
                case CommType::I2C:
                    return std::make_unique<I2C>();
                default:
                    throw std::invalid_argument("Tipo de comunicación no soportado");
            }
        }
};

// #include <factory.h>

// int main() {
//     // Crear un objeto de comunicación UART
//     auto uart = CommFactory::crearComunicacion(CommType::UART);
//     std::string data = "Hola UART";
//     uart->enviar(data, data.size());
//     uart->recibir(data, data.size());

//     // Crear un objeto de comunicación SPI
//     auto spi = CommFactory::crearComunicacion(CommType::SPI);
//     data = "Hola SPI";
//     spi->enviar(data, data.size());
//     spi->recibir(data, data.size());

//     // Crear un objeto de comunicación I2C
//     auto i2c = CommFactory::crearComunicacion(CommType::I2C);
//     data = "Hola I2C";
//     i2c->enviar(data, data.size());
//     i2c->recibir(data, data.size());

//     return 0;
// }