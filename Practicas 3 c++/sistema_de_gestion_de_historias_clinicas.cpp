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
    string contrase�a; //Cambiado
};

// Estructura para historia cl�nica
struct HistoriaClinica {
    string paciente;
    string fecha;
    string descripcion;
};

// Vector para almacenar pacientes
vector<Paciente> pacientes;

// Vector para almacenar historias cl�nicas
vector<HistoriaClinica> historiasClinicas;

// Funci�n para registrar paciente
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
    cout << "Ingrese contrase�a: ";
    cin >> paciente.contrase�a;

    // Validaci�n de edad
    if (paciente.edad < 0 || paciente.edad > 120) {
        cout << "Edad inv�lida. Por favor, ingrese una edad entre 0 y 120." << endl;
        return;
    }

    // Validaci�n de contrase�a
    if (paciente.contrase�a.length() < 8) {
        cout << "Contrase�a demasiado corta. Por favor, ingrese una contrase�a de al menos 8 caracteres." << endl;
        return;
    }

    pacientes.push_back(paciente);
}

// Funci�n para crear historia cl�nica
void crearHistoriaClinica() {
    HistoriaClinica historiaClinica;
    cout << "Ingrese paciente: ";
    cin >> historiaClinica.paciente;
    cout << "Ingrese fecha: ";
    cin >> historiaClinica.fecha;
    cout << "Ingrese descripcion: ";
    cin >> historiaClinica.descripcion;

    // Validaci�n de fecha
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int a�o = 1900 + ltm->tm_year;
    int mes = 1 + ltm->tm_mon;
    int dia = ltm->tm_mday;

    int a�oHC = stoi(historiaClinica.fecha.substr(0, 4));
    int mesHC = stoi(historiaClinica.fecha.substr(5, 2));
    int diaHC = stoi(historiaClinica.fecha.substr(8, 2));

    if (a�oHC < 1900 || a�oHC > a�o || mesHC < 1 || mesHC > 12 || diaHC < 1 || diaHC > 31) {
        cout << "Fecha inv�lida." << endl;
        return;
    }

    historiasClinicas.push_back(historiaClinica);
}

// Funci�n para consultar historia cl�nica
void consultarHistoriaClinica() {
    string paciente;
    cout << "Ingrese paciente: ";
    cin >> paciente;

    // Validaci�n de paciente
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

// Funci�n para iniciar sesi�n
void iniciarSesion() {
    string nombre;
    string contrase�a;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese contrase�a: ";
    cin >> contrase�a;

    // Validaci�n de inicio de sesi�n
    bool inicioSesionCorrecto = false;
    for (int i = 0; i < pacientes.size(); i++) {
        if (pacientes[i].nombre == nombre && pacientes[i].contrase�a == contrase�a) {
            inicioSesionCorrecto = true;
            break;
        }
    }

    if (!inicioSesionCorrecto) {
        cout << "Nombre o contrase�a incorrectos." << endl;
    } else {
        cout << "Inicio de sesi�n correcto." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "1. Registrar paciente" << endl;
        cout << "2. Crear
