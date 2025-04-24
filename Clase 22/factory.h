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