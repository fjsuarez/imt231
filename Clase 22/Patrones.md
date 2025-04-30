# Patrones de diseño

## 1. Patrones creacionales

### Singleton

Es una clase que sólo puede generar una instancia.
Si la instancia no existe, llamar a una función la creará, y las llamadas subsiguientes a esa función retornarán la instancia previamente creada.

### Factory

Este patrón nos permite desacoplar la creación de instancias de su uso. Si necesitamos soportar mútliples implementaciones (UART, SPI, I2C), la "factory" centraliza cuál clase concreta se instanciará.

## 2. Patrones estructurales

### Decorador

Agregar funcionalidad adicional a una clase o función ya existente. Podemos combinar múltiples decoradores.

### Adaptador

### Fachada


## 3. Patrones de comportamiento

