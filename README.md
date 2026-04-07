# ✈️ Sistema de Gestión de Aerolínea

Este proyecto es una aplicación de consola desarrollada en **C++** diseñada para gestionar los vuelos, reservas y pasajeros de una aerolínea llamada "Voling". Permite el registro de nuevos vuelos, la gestión de reservas de asientos (con control de disponibilidad) y la visualización de datos mediante diversos filtros.

## 🚀 Características

El sistema implementa las siguientes funcionalidades principales:

* **Gestión de Vuelos:** Registrar nuevos vuelos con origen, destino, horarios y capacidad de asientos.
* **Gestión de Reservas:** Crear reservas vinculadas a vuelos existentes, validando la disponibilidad de asientos y evitando duplicados.
* **Consultas Avanzadas:**
    * Listado de vuelos por orden de registro.
    * Listado de reservas ordenadas por número de reserva.
    * Listado alfabético de pasajeros de un vuelo específico.
    * Filtrado de reservas por estado (ej. "confirmada", "pendent").
* **Control de Errores:** Validaciones para vuelos inexistentes, límites máximos de la aerolínea y falta de asientos.

## 🛠️ Estructura del Proyecto

El código sigue un diseño modular orientado a objetos:

| Archivo | Descripción |
| :--- | :--- |
| `Aerolinia.hpp/cpp` | Clase principal que orquestra los vuelos y las reservas. |
| `Vol.hpp/cpp` | Representa un vuelo individual y contiene sus reservas asociadas. |
| `Reserva.hpp/cpp` | Gestiona la información del ticket de reserva y el enlace con el pasajero. |
| `Passatger.hpp/cpp` | Almacena los datos personales, estado de reserva y asiento del cliente. |
| `program.cpp` | Punto de entrada (Main) con el bucle de interacción de usuario. |
| `Makefile` | Script de compilación automatizada. |

## 💻 Compilación y Ejecución

Para compilar el proyecto, asegúrate de tener instalado `g++`. Utiliza el `Makefile` incluido:

1.  **Compilar:**
    ```bash
    make
    ```
2.  **Ejecutar:**
    ```bash
    ./program.exe
    ```
3.  **Limpiar archivos temporales:**
    ```bash
    make clean
    ```

## 📋 Guía de Uso (Comandos)

Al iniciar, el programa espera dos enteros: `maxVols` y `maxReserves`. Luego, acepta los siguientes comandos:

* `enregistrarVol`: Lee los datos de un nuevo vuelo desde la entrada estándar.
* `enregistrarReserva`: Crea una nueva reserva para un pasajero.
* `mostrarVols`: Muestra todos los vuelos actuales.
* `mostrarReserves`: Lista todas las reservas ordenadas numéricamente.
* `mostrarPassatgersVol [id_vol]`: Lista los pasajeros de un vuelo en orden alfabético.
* `mostrarReservesEstat [estado]`: Muestra las reservas que coinciden con un estado específico.
* `acabar`: Finaliza la ejecución del programa.

## ⚙️ Requisitos Técnicos

* Estándar **C++11** o superior.
* Compilador `g++`.
* Uso de la **STL** (Standard Template Library) para el manejo de vectores y strings.

---
> **Nota:** Este proyecto fue diseñado como una práctica de programación estructurada y orientada a objetos, enfocándose en la gestión de memoria eficiente y la modularidad del código en la asignatura **PRO1**.
