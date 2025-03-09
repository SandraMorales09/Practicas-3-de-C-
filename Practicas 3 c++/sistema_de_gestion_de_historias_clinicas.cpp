#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Estructura para paciente
struct Paciente {
    string nombre;
    string apellido;
    int edad;
    string direccion;
    string contraseña; //Cambiado
};

// Estructura para historia clínica
struct HistoriaClinica {
    string paciente;
    string fecha;
    string descripcion;
};

// Vector para almacenar pacientes
vector<Paciente> pacientes;

// Vector para almacenar historias clínicas
vector<HistoriaClinica> historiasClinicas;

// Función para registrar paciente
void registrarPaciente() {
    Paciente paciente;
    cout << "Ingrese nombre: ";
    cin >> paciente.nombre;
    cout << "Ingrese apellido: ";
    cin >> paciente.apellido;
    cout << "Ingrese edad: ";
    cin >> paciente.edad;
    cout << "Ingrese direccion: ";
    cin >> paciente.direccion;
    cout << "Ingrese contraseña: ";
    cin >> paciente.contraseña;

    // Validación de edad
    if (paciente.edad < 0 || paciente.edad > 120) {
        cout << "Edad inválida. Por favor, ingrese una edad entre 0 y 120." << endl;
        return;
    }

    // Validación de contraseña
    if (paciente.contraseña.length() < 8) {
        cout << "Contraseña demasiado corta. Por favor, ingrese una contraseña de al menos 8 caracteres." << endl;
        return;
    }

    pacientes.push_back(paciente);
}

// Función para crear historia clínica
void crearHistoriaClinica() {
    HistoriaClinica historiaClinica;
    cout << "Ingrese paciente: ";
    cin >> historiaClinica.paciente;
    cout << "Ingrese fecha: ";
    cin >> historiaClinica.fecha;
    cout << "Ingrese descripcion: ";
    cin >> historiaClinica.descripcion;

    // Validación de fecha
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int año = 1900 + ltm->tm_year;
    int mes = 1 + ltm->tm_mon;
    int dia = ltm->tm_mday;

    int añoHC = stoi(historiaClinica.fecha.substr(0, 4));
    int mesHC = stoi(historiaClinica.fecha.substr(5, 2));
    int diaHC = stoi(historiaClinica.fecha.substr(8, 2));

    if (añoHC < 1900 || añoHC > año || mesHC < 1 || mesHC > 12 || diaHC < 1 || diaHC > 31) {
        cout << "Fecha inválida." << endl;
        return;
    }

    historiasClinicas.push_back(historiaClinica);
}

// Función para consultar historia clínica
void consultarHistoriaClinica() {
    string paciente;
    cout << "Ingrese paciente: ";
    cin >> paciente;

    // Validación de paciente
    bool pacienteExiste = false;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].nombre == paciente) {
            pacienteExiste = true;
            break;
        }
    }

    if (!pacienteExiste) {
        cout << "Paciente no existe." << endl;
        return;
    }

    for (int i = 0; i < historiasClinicas.size(); i++) {
        if (historiasClinicas[i].paciente == paciente) {
            cout << "Fecha: " << historiasClinicas[i].fecha << endl;
            cout << "Descripcion: " << historiasClinicas[i].descripcion << endl;
        }
    }
}

// Función para iniciar sesión
void iniciarSesion() {
    string nombre;
    string contraseña;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese contraseña: ";
    cin >> contraseña;

    // Validación de inicio de sesión
    bool inicioSesionCorrecto = false;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].nombre == nombre && pacientes[i].contraseña == contraseña) {
            inicioSesionCorrecto = true;
            break;
        }
    }

    if (!inicioSesionCorrecto) {
        cout << "Nombre o contraseña incorrectos." << endl;
    } else {
        cout << "Inicio de sesión correcto." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "1. Registrar paciente" << endl;
        cout << "2. Crear
