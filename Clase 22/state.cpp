#include <iostream>
#include <memory>
#include <string>

//=== Forward declarations ===
class MaquinaBebidas;

//=== State interface ===
class IEstado {
public:
    virtual ~IEstado() = default;
    virtual void insertarMoneda(MaquinaBebidas& mb) = 0;
    virtual void seleccionarBebida(MaquinaBebidas& mb) = 0;
    virtual void dispensarBebida(MaquinaBebidas& mb) = 0;
    virtual void devolverMoneda(MaquinaBebidas& mb) = 0;
};

//=== Context ===
class MaquinaBebidas {
    std::unique_ptr<IEstado> _estado;
    int _credito = 0;

public:
    MaquinaBebidas(std::unique_ptr<IEstado> estadoInicial)
      : _estado(std::move(estadoInicial)) {}

    void setEstado(std::unique_ptr<IEstado> nuevoEstado) {
        _estado = std::move(nuevoEstado);
    }
    void agregarCredito(int cantidad) {
        _credito += cantidad;
        std::cout << "Credito actual: " << _credito << "\n";
    }
    void borrarCredito() {
        _credito = 0;
        std::cout << "Credito borrado.\n";
    }
    int getCredito() const { return _credito; }

    // Delegate to the current state
    void insertarMoneda()    { _estado->insertarMoneda(*this); }
    void seleccionarBebida() { _estado->seleccionarBebida(*this); }
    void dispensarBebida()   { _estado->dispensarBebida(*this); }
    void devolverMoneda()    { _estado->devolverMoneda(*this); }
};

//=== Declaraciones de estado ===
// (sólo firmas de métodos, no implementaciones)
// hacemos esto para que las clases de estado puedan referirse entre sí
class EstadoSinMoneda : public IEstado {
public:
    void insertarMoneda(MaquinaBebidas& mb) override;
    void seleccionarBebida(MaquinaBebidas& mb) override;
    void dispensarBebida(MaquinaBebidas& mb) override;
    void devolverMoneda(MaquinaBebidas& mb) override;
};

class EstadoConMoneda : public IEstado {
public:
    void insertarMoneda(MaquinaBebidas& mb) override;
    void seleccionarBebida(MaquinaBebidas& mb) override;
    void dispensarBebida(MaquinaBebidas& mb) override;
    void devolverMoneda(MaquinaBebidas& mb) override;
};

class EstadoDispensando : public IEstado {
public:
    void insertarMoneda(MaquinaBebidas& mb) override;
    void seleccionarBebida(MaquinaBebidas& mb) override;
    void dispensarBebida(MaquinaBebidas& mb) override;
    void devolverMoneda(MaquinaBebidas& mb) override;
};

//=== Definiciones de estados ===

void EstadoSinMoneda::insertarMoneda(MaquinaBebidas& mb) {
    mb.agregarCredito(1);
    mb.setEstado(std::make_unique<EstadoConMoneda>());
    std::cout << "Moneda insertada correctamente.\n";
}
void EstadoSinMoneda::seleccionarBebida(MaquinaBebidas&) {
    std::cout << "Por favor, inserte una moneda primero.\n";
}
void EstadoSinMoneda::dispensarBebida(MaquinaBebidas&) {
    std::cout << "No se puede dispensar bebida. Inserte una moneda.\n";
}
void EstadoSinMoneda::devolverMoneda(MaquinaBebidas&) {
    std::cout << "No hay moneda para devolver.\n";
}


void EstadoConMoneda::insertarMoneda(MaquinaBebidas& mb) {
    std::cout << "Ya hay una moneda insertada.\n";
}
void EstadoConMoneda::seleccionarBebida(MaquinaBebidas& mb) {
    if (mb.getCredito() > 0) {
        std::cout << "Bebida seleccionada. Preparando para dispensar...\n";
        mb.setEstado(std::make_unique<EstadoDispensando>());
    } else {
        std::cout << "No hay suficiente crédito.\n";
    }
}
void EstadoConMoneda::dispensarBebida(MaquinaBebidas&) {
    std::cout << "Seleccione una bebida primero.\n";
}
void EstadoConMoneda::devolverMoneda(MaquinaBebidas& mb) {
    std::cout << "Devolviendo moneda...\n";
    mb.borrarCredito();
    mb.setEstado(std::make_unique<EstadoSinMoneda>());
}


void EstadoDispensando::insertarMoneda(MaquinaBebidas&) {
    std::cout << "No se puede insertar moneda. Bebida en dispensación.\n";
}
void EstadoDispensando::seleccionarBebida(MaquinaBebidas&) {
    std::cout << "Bebida en dispensación. Espere.\n";
}
void EstadoDispensando::dispensarBebida(MaquinaBebidas& mb) {
    std::cout << "Dispensando bebida...\n";
    mb.borrarCredito();
    mb.setEstado(std::make_unique<EstadoSinMoneda>());
}
void EstadoDispensando::devolverMoneda(MaquinaBebidas&) {
    std::cout << "No se puede devolver moneda. Bebida en dispensación.\n";
}


int main() {
    MaquinaBebidas maquina{ std::make_unique<EstadoSinMoneda>() };

    std::cout << "\n--- Ciclo 1: Operación normal ---\n";
    maquina.insertarMoneda();
    maquina.seleccionarBebida();
    maquina.dispensarBebida();

    std::cout << "\n--- Ciclo 2: Devolución de moneda ---\n";
    maquina.insertarMoneda();
    maquina.devolverMoneda();

    std::cout << "\n--- Ciclo 3: Operaciones inválidas ---\n";
    maquina.dispensarBebida();
    maquina.seleccionarBebida();
    maquina.devolverMoneda();

    return 0;
}
