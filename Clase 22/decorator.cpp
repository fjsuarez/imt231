#include <iostream>
#include <vector>
#include <memory>
#include <ctime>

class IComm {
    public:
        virtual ~IComm() = default; // Destructor virtual
        virtual void enviar(const std::string& data, size_t len) = 0; // Método virtual puro
        virtual void recibir(std::string& data, size_t len) = 0; // Método virtual puro
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

// decorador base

class Decorador : public IComm {
    protected:
        std::unique_ptr<IComm> comm; // Puntero a la interfaz de comunicación // comm tambien es llamado wrappee

    public:
        Decorador(std::unique_ptr<IComm> comm) : comm(std::move(comm)) {}
        virtual ~Decorador() = default;

        void enviar(const std::string& data, size_t len) override {
            comm->enviar(data, len);
        }

        void recibir(std::string& data, size_t len) override {
            comm->recibir(data, len);
        }
};

// decorador checksum

class ChecksumDecorator : public Decorador {
    public:
        ChecksumDecorator(std::unique_ptr<IComm> comm) : Decorador(std::move(comm)) {}

        void enviar(const std::string& data, size_t len) override { // wrapper
            // Calcular checksum
            std::string checksum = calcularChecksum(data);
            std::cout << "Checksum calculado: " << checksum << std::endl;

            // Enviar datos y checksum
            Decorador::enviar(data + checksum, len + checksum.size());
        }

        void recibir(std::string& data, size_t len) override { // wrapper
            // Recibir datos
            Decorador::recibir(data, len);

            // Verificar checksum
            if (verificarChecksum(data)) {
                std::cout << "Checksum verificado correctamente." << std::endl;
            } else {
                std::cout << "Error en la verificación del checksum." << std::endl;
            }
        }

    private:
        std::string calcularChecksum(const std::string& data) {
            // Implementación de cálculo de checksum (ejemplo simple)
            return "CHECKSUM";
        }

        bool verificarChecksum(const std::string& data) {
            // Implementación de verificación de checksum (ejemplo simple)
            return true;
        }
};

// decorador de logging

class LoggingDecorator : public Decorador {
    public:
        LoggingDecorator(std::unique_ptr<IComm> comm) : Decorador(std::move(comm)) {}

        void enviar(const std::string& data, size_t len) override { // wrapper
            // timestamp
            std::cout << "Timestamp: " << std::time(nullptr) << std::endl;
            std::cout << "Enviando datos: " << data.substr(0, len) << std::endl;
            Decorador::enviar(data, len);
        }

        void recibir(std::string& data, size_t len) override { // wrapper
            // timestamp
            std::cout << "Timestamp: " << std::time(nullptr) << std::endl;
            Decorador::recibir(data, len);
            std::cout << "Datos recibidos: " << data.substr(0, len) << std::endl;
        }
};

int main() {
    // Crear un objeto de comunicación SPI
    std::unique_ptr<IComm> spi = std::make_unique<SPI>();

    // Crear un objeto de comunicación UART
    // std::unique_ptr<IComm> uart = std::make_unique<UART>();
    // Decorar el objeto SPI con el decorador de checksum
    std::unique_ptr<IComm> spiConChecksum = std::make_unique<ChecksumDecorator>(std::move(spi));

    // Decorar el objeto SPI con el decorador de logging
    std::unique_ptr<IComm> spiConLoggingYChecksum = std::make_unique<LoggingDecorator>(std::move(spiConChecksum));

    // Enviar y recibir datos
    std::string data = "Hola, mundo!";
    spiConLoggingYChecksum->enviar(data, data.size());

    std::string recibido;
    spiConLoggingYChecksum->recibir(recibido, 20);


    return 0;
}