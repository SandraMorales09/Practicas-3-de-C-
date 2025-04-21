#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para realizar búsquedas de datos

using namespace std;

// Estructura para paciente
struct Paciente {
    string nombre;
    string apellido;
    int edad;
    string direccion;
    string contrasena;
};

// Estructura para historia clínica
struct HistoriaClinica {
    string paciente;
    string fecha;
    string descripcion;
};

// Vectores para almacenar pacientes e historias clínicas
vector<Paciente> pacientes;
vector<HistoriaClinica> historiasClinicas;

// Función para registrar pacientes
void registrarPaciente() {
    Paciente paciente;
    cout << "Ingrese nombre: ";
    cin >> paciente.nombre;
    cout << "Ingrese apellido: ";
    cin >> paciente.apellido;
    cout << "Ingrese edad: ";
    cin >> paciente.edad;
    cout << "Ingrese direccion: ";
    cin.ignore(); // Ignorar salto de línea previo
    getline(cin, paciente.direccion);
    cout << "Ingrese contraseña: ";
    cin >> paciente.contrasena;

    // Validaciones básicas
    if (paciente.edad < 0 || paciente.edad > 120) {
        cout << "Edad inválida. Debe estar entre 0 y 120.\n";
        return;
    }
    if (paciente.contrasena.length() < 8) {
        cout << "Contraseña demasiado corta. Debe tener al menos 8 caracteres.\n";
        return;
    }

    pacientes.push_back(paciente);
    cout << "Paciente registrado correctamente.\n";
}

// Función para crear historias clínicas
void crearHistoriaClinica() {
    HistoriaClinica historia;
    cout << "Ingrese nombre del paciente: ";
    cin >> historia.paciente;
    cout << "Ingrese fecha (YYYY-MM-DD): ";
    cin >> historia.fecha;
    cout << "Ingrese descripción: ";
    cin.ignore(); // Ignorar salto de línea previo
    getline(cin, historia.descripcion);

    historiasClinicas.push_back(historia);
    cout << "Historia clínica registrada correctamente.\n";
}

// Función para consultar historias clínicas
void consultarHistoriaClinica() {
    string paciente;
    cout << "Ingrese nombre del paciente: ";
    cin >> paciente;

    bool encontrado = false;
    for (size_t i = 0; i < historiasClinicas.size(); ++i) {
        if (historiasClinicas[i].paciente == paciente) {
            cout << "Fecha: " << historiasClinicas[i].fecha
                 << "\nDescripción: " << historiasClinicas[i].descripcion << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron historias clínicas para el paciente indicado.\n";
    }
}

// Función para iniciar sesión
void iniciarSesion() {
    string nombre, contrasena;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese contraseña: ";
    cin >> contrasena;

    bool inicioCorrecto = false;
    for (size_t i = 0; i < pacientes.size(); ++i) {
        if (pacientes[i].nombre == nombre && pacientes[i].contrasena == contrasena) {
            inicioCorrecto = true;
            break;
        }
    }
    if (inicioCorrecto) {
        cout << "Inicio de sesión exitoso.\n";
    } else {
        cout << "Nombre o contraseña incorrectos.\n";
    }
}

// Menú principal
void mostrarMenu() {
    cout << "\n--- Sistema de Gestión de Historial Clínico ---\n";
    cout << "1. Registrar paciente\n";
    cout << "2. Crear historia clínica\n";
    cout << "3. Consultar historia clínica\n";
    cout << "4. Iniciar sesión\n";
    cout << "5. Salir\n";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarPaciente();
                break;
            case 2:
                crearHistoriaClinica();
                break;
            case 3:
                consultarHistoriaClinica();
                break;
            case 4:
                iniciarSesion();
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
