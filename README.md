# Báscula Digital con Celda de Carga y HX711

Firmware desarrollado para un sistema de pesaje digital con capacidad de calibración en dos puntos y conversión de unidades en tiempo real. El proyecto abarca la adquisición de señales de celda de carga a través de un acondicionador ADC de 24 bits, procesamiento en microcontrolador y despliegue en pantalla LCD.

## Información del Desarrollo
- Fecha de desarrollo: 09/10/2022

## Hardware Utilizado
- Microcontrolador: Microchip PIC16F877 / PIC16F877A
- Oscilador: Cristal de cuarzo de 4 MHz
- Acondicionador de señal: Módulo ADC de 24 bits HX711 (Ganancia de 128)
- Sensor: Celda de carga (Galgas extensiométricas)
- Interfaz de usuario: Pantalla LCD 16x2
- Entradas: 3 botones de pulsación (Puerto B con resistencias pull-up internas)

## Descripción de Funcionamiento

El firmware ejecuta una secuencia modular para garantizar la precisión de la lectura frente a variaciones de temperatura y desviaciones de cero:

1. Establecimiento de Cero (zeroin):
Al iniciar el sistema, se solicita al usuario despejar la plataforma de medición. El sistema toma un promedio de 50 muestras consecutivas mediante el sensor HX711 para registrar el valor base de offset (tara inicial).

2. Calibración Inicial (calibracion):
Se emplea una masa patrón de referencia fija de 3700 gramos. El microcontrolador lee el valor del ADC correspondiente y calcula la constante de pendiente (relación de proporcionalidad) necesaria para convertir las lecturas analógicas a unidades de masa.

3. Muestreo y Conversión Dinámica:
En el ciclo principal, el sistema lee el peso en intervalos continuos, resta la masa base guardada y aplica el factor de conversión correspondiente según la unidad seleccionada:
- Gramos (Unidad base)
- Onzas (Factor de conversión: / 28.35)
- Libras (Factor de conversión: * 0.00220462)

4. Menú de Tarado y Control de Interfaz:
Mediante combinaciones de pulsadores en el Puerto B (pines B5, B6 y B7), el usuario puede alternar la unidad de medida en pantalla o activar la rutina de re-tarado para compensar contenedores adicionales.

## Estructura de Archivos
- main.c: Código fuente principal que contiene la lógica de calibración, lectura y menú.
- hx711.c: Librería de comunicación serie para la lectura del integrado HX711.
- lcd_c.c: Controlador para la pantalla LCD de 16x2.