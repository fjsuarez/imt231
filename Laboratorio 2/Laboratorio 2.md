# Laboratorio de Programación Orientada a Objetos con la API de la Premier Fantasy League

## Objetivos del Laboratorio

* **Consumo de datos JSON**:
    * Lectura de datos desde archivos JSON locales.
    * Obtención de datos desde APIs web usando HTTP/HTTPS.
* **Programación Orientada a Objetos (POO)**: Diseñar y crear clases para representar jugadores y equipos de fútbol.
* **Manejo de Datos**: Procesar y organizar datos para simular un juego de Fantasy Football.
* **Lógica de Puntuación**: Implementar reglas para calcular la puntuación de los jugadores en un partido.

## Requisitos

* Computadora con un compilador de C++ (g++ es el usado en clase).
* Editor de código (VS Code es el usado en clsae).
* Biblioteca `nlohmann/json` para el manejo de JSON (incluída en esta carpeta).
* Biblioteca `httplib` para las peticiones http y https (incluída en esta carpeta).
* Archivos JSON locales (también incluidos).

## Instrucciones del Laboratorio

1.  **Obtención de Datos JSON**

    * **Opción 1: Lectura desde Archivos Locales**
        * Proporciona a los estudiantes archivos JSON de ejemplo que simulen las respuestas de las APIs `bootstrap-static` y `fixtures`.
        * Utiliza `std::ifstream` para leer los datos desde estos archivos.
        * Analiza los datos JSON usando la biblioteca `nlohmann/json`.
        * Archivo de ejemplo incluído: `main-fstream.cpp`.

    * **Opción 2: Obtención desde URLs (con `httplib`)**
        * Utiliza la biblioteca `httplib` para realizar solicitudes HTTP/HTTPS a las URLs de la API de la Premier Fantasy League.
        * Analiza las respuestas JSON recibidas.
        * Archivo de ejemplo incluído: `main-httplib.cpp`
        * Para las solicitudes HTTPS, se necesita tener instalada la librería OpenSSL, instalar con `sudo apt install openssl-dev` (desde WSL Ubuntu).
        * Para compilar, es necesario indicarle al compilador "linkear" las librerías necesarias: `g++ main-httplib.cpp -lssl -lcrypto -lpthread -o main-httplib`

    * Inspeccionar la estructura que tienen los datos, ya sea abriendo los archivos JSON incluídos, o visitando las URLs de las APIs y viendo la respuesta en el explorador. Existen extensiones que permiten visualizar las respuestas en formato JSON de manera más organizada (Ej. [JSON Beautifier and Editor](https://chromewebstore.google.com/detail/json-beautifier-and-edito/lpopeocbeepakdnipejhlpcmifheolpl))

    * Escribir un programa (o modificar los archivos de ejemplo) para obtener la información de un jugador (tienen la llave `element`).

    * Tomar una captura de pantalla del resultado, y escribe una breve descripción de los campos que tiene el jugador, y cuáles podrían tener importancia.

2.  **Creación de Clases (Jugador, Equipo, etc.)**

    * Define una clase llamada `Jugador` con atributos como:
        * `id` (identificador del jugador)
        * `nombre`
        * `posicion` (Arquero, Defensa, Mediocampista, Delantero)
        * `equipo_id` (identificador del equipo al que pertenece)
        * `puntos_partido` (inicializado a 0)
        * `precio`
    * Agrega métodos para:
        * Actualizar `puntos_partido` según el rendimiento en el partido.
        * Mostrar información del jugador.
    * Crea clases que hereden de la clase jugador. Por ejemplo Arquero, Defensa, Mediocampista, Delantero.
    * Agregar metodos especificos a cada posición para sumar puntos.
    * Define una clase llamada `Equipo` con atributos como:
        * `nombre_equipo`
        * `jugadores` (una lista de objetos `Jugador`)
        * `puntos_totales` (inicializado a 0)
    * Agrega métodos para:
        * Añadir jugadores al equipo.
        * Calcular `puntos_totales` sumando los `puntos_partido` de cada jugador.
        * Mostrar información del equipo.

    * Escribe una breve descripción de cómo diseñaste las clases, fundamentando las decisiones que tomaste.

3.  **Procesamiento de Datos y Simulación de Puntuación**
    * Utiliza los `id` de los jugadores y equipos para relacionarlos correctamente.
    * Utiliza los datos del primer partido (`fixtures[0]`) de la API de fixtures para simular la puntuación.
    * Implementa las siguientes reglas de puntuación, diferenciando por posición:
        * **Arqueros:**
            * Portería a cero: +4 puntos.
            * Cada 3 atajadas: +1 punto.
            * Penalti atajado: +5 puntos.
            * Goles encajados: -1 punto por cada 2 goles.
            * Gol marcado: +10 puntos.
            * Tarjeta amarilla: -1 punto.
            * Tarjeta roja: -3 puntos.
        * **Defensores:**
            * Portería a cero: +4 puntos.
            * Gol marcado: +6 puntos.
            * Asistencia: +3 puntos.
            * Gol en propia puerta: -2 puntos.
            * Tarjeta amarilla: -1 punto.
            * Tarjeta roja: -3 puntos.
        * **Mediocampistas:**
            * Gol marcado: +5 puntos.
            * Asistencia: +3 puntos.
            * Portería a cero: +1 punto.
            * Tarjeta amarilla: -1 punto.
            * Tarjeta roja: -3 puntos.
        * **Delanteros:**
            * Gol marcado: +4 puntos.
            * Asistencia: +3 puntos.
            * Tarjeta amarilla: -1 punto.
            * Tarjeta roja: -3 puntos.
        * **Puntos Adicionales:**
            * Minutos jugados:
                * 1-59 minutos: +1 punto.
                * 60+ minutos: +2 puntos.
            * Puntos de Bonus: los 3 jugadores que más puntuación obtengan en cada partido obtendran puntos extra. 3 puntos para el de mayor puntuación, 2 para el segundo, y 1 para el tercero.
    * Actualiza el atributo `puntos_partido` de cada jugador según las reglas anteriores.

4.  **Comparación de Equipos**

    * Crea instancias de la clase `Equipo` para cada equipo, poblándolas con objetos `Jugador`.
    * Simula la puntuación del primer partido para todos los equipos.
    * Calcula los `puntos_totales` de cada equipo.
    * Determina y muestra qué equipo tiene la mayor puntuación.
    * Toma una captura de pantalla de tu resultado.

5.  **Creación de Equipos con Reglas de FPL (opcional)**

    * Implementa las reglas de construcción de equipos de Fantasy Premier League:
        * Un presupuesto limitado (Suma total del costo de los jugadores seleccionados no puede exceder 1000).
        * Un número específico de jugadores por posición (1 arquero, al menos 3 defensas, al menos 2 mediocampistas, al menos 1 delantero, con un máximo de 11 jugadores en total).
        * Maximo de 3 jugadores por cada equipo de la premier league real.
