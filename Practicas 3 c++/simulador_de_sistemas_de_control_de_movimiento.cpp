#include <iostream>
#include <cmath>

using namespace std;

// Estructura para representar un sistema de control de movimiento
struct Sistema {
    double ganancia;
    double frecuenciaMuestreo;
    double cargaMotor;
    double kp; // ganancia proporcional
    double ki; // ganancia integral
    double kd; // ganancia derivativa
    double kt; // ganancia de seguimiento
};

// Función para simular el sistema de control de movimiento
void simularSistema(Sistema sistema) {
    // inicializar variables
    double error = 0, salida = 0, integral = 0, derivada = 0, referencia = 10; // valor de referencia

    // simulación en tiempo real
    for (int i = 0; i < 1000; i++) {
        // calcular error
        error = referencia - salida;

        // calcular salida
        salida = sistema.kp * error + sistema.ki * integral + sistema.kd * derivada + sistema.kt;

        // actualizar integral y derivada
        integral += error * sistema.frecuenciaMuestreo;
        derivada = error / sistema.frecuenciaMuestreo;

        // imprimir resultados
        cout << "Tiempo: " << i * sistema.frecuenciaMuestreo << " s" << endl;
        cout << "Salida: " << salida << endl;
        cout << "Error: " << error << endl;
    }
}

// Función para implementar control PID
void controlPID(Sistema sistema) {
    double error = 0, integral = 0, derivada = 0;

    // calcular salida
    double salida = sistema.kp * error + sistema.ki * integral + sistema.kd * derivada;

    // imprimir resultados
    cout << "Salida PID: " << salida << endl;
}

// Función para implementar control de seguimiento
void controlSeguimiento(Sistema sistema) {
    double referencia = 10; // valor de referencia

    // calcular salida
    double salida = sistema.kt * referencia;

    // imprimir resultados
    cout << "Salida de seguimiento: " << salida << endl;
}

// Función para analizar estabilidad y respuesta transitoria
void analizarEstabilidad(Sistema sistema) {
    // calcular parámetros del sistema
    double ganancia = sistema.ganancia / (sistema.ganancia + sistema.kd);
    double fase = atan(sistema.kd / sistema.ganancia);

    // imprimir resultados
    cout << "Ganancia: " << ganancia << endl;
    cout << "Fase: " << fase << endl;
}

int main() {
    Sistema sistema;

    // ingresar parámetros del sistema
    cout << "Ingrese ganancia del controlador: ";
    cin >> sistema.ganancia;
    cout << "Ingrese frecuencia de muestreo: ";
    cin >> sistema.frecuenciaMuestreo;
    cout << "Ingrese carga del motor: ";
    cin >> sistema.cargaMotor;
    cout << "Ingrese ganancia proporcional: ";
    cin >> sistema.kp;
    cout << "Ingrese ganancia integral: ";
    cin >> sistema.ki;
    cout << "Ingrese ganancia derivativa: ";
    cin >> sistema.kd;
    cout << "Ingrese ganancia de seguimiento: ";
    cin >> sistema.kt;

    // simular sistema de control de movimiento
    simularSistema(sistema);

    // implementar control PID
    controlPID(sistema);

    // implementar control de seguimiento
    controlSeguimiento(sistema);

    // analizar estabilidad y respuesta transitoria
    analizarEstabilidad(sistema);

    return 0;
}
