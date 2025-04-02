#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para realizar b�squedas de datos

using namespace std;

// Estructura para paciente
struct Paciente {
    string nombre;
    string apellido;
    int edad;
    string direccion;
    string contrasena;
};

// Estructura para historia cl�nica
struct HistoriaClinica {
    string paciente;
    string fecha;
    string descripcion;
};

// Vectores para almacenar pacientes e historias cl�nicas
vector<Paciente> pacientes;
vector<HistoriaClinica> historiasClinicas;

// Funci�n para registrar pacientes
void registrarPaciente() {
    Paciente paciente;
    cout << "Ingrese nombre: ";
    cin >> paciente.nombre;
    cout << "Ingrese apellido: ";
    cin >> paciente.apellido;
    cout << "Ingrese edad: ";
    cin >> paciente.edad;
    cout << "Ingrese direccion: ";
    cin.ignore(); // Ignorar salto de l�nea previo
    getline(cin, paciente.direccion);
    cout << "Ingrese contrase�a: ";
    cin >> paciente.contrasena;

    // Validaciones b�sicas
    if (paciente.edad < 0 || paciente.edad > 120) {
        cout << "Edad inv�lida. Debe estar entre 0 y 120.\n";
        return;
    }
    if (paciente.contrasena.length() < 8) {
        cout << "Contrase�a demasiado corta. Debe tener al menos 8 caracteres.\n";
        return;
    }

    pacientes.push_back(paciente);
    cout << "Paciente registrado correctamente.\n";
}

// Funci�n para crear historias cl�nicas
void crearHistoriaClinica() {
    HistoriaClinica historia;
    cout << "Ingrese nombre del paciente: ";
    cin >> historia.paciente;
    cout << "Ingrese fecha (YYYY-MM-DD): ";
    cin >> historia.fecha;
    cout << "Ingrese descripci�n: ";
    cin.ignore(); // Ignorar salto de l�nea previo
    getline(cin, historia.descripcion);

    historiasClinicas.push_back(historia);
    cout << "Historia cl�nica registrada correctamente.\n";
}

// Funci�n para consultar historias cl�nicas
void consultarHistoriaClinica() {
    string paciente;
    cout << "Ingrese nombre del paciente: ";
    cin >> paciente;

    bool encontrado = false;
    for (size_t i = 0; i < historiasClinicas.size(); ++i) {
        if (historiasClinicas[i].paciente == paciente) {
            cout << "Fecha: " << historiasClinicas[i].fecha
                 << "\nDescripci�n: " << historiasClinicas[i].descripcion << "\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron historias cl�nicas para el paciente indicado.\n";
    }
}

// Funci�n para iniciar sesi�n
void iniciarSesion() {
    string nombre, contrasena;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese contrase�a: ";
    cin >> contrasena;

    bool inicioCorrecto = false;
    for (size_t i = 0; i < pacientes.size(); ++i) {
        if (pacientes[i].nombre == nombre && pacientes[i].contrasena == contrasena) {
            inicioCorrecto = true;
            break;
        }
    }
    if (inicioCorrecto) {
        cout << "Inicio de sesi�n exitoso.\n";
    } else {
        cout << "Nombre o contrase�a incorrectos.\n";
    }
}

// Men� principal
void mostrarMenu() {
    cout << "\n--- Sistema de Gesti�n de Historial Cl�nico ---\n";
    cout << "1. Registrar paciente\n";
    cout << "2. Crear historia cl�nica\n";
    cout << "3. Consultar historia cl�nica\n";
    cout << "4. Iniciar sesi�n\n";
    cout << "5. Salir\n";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opci�n: ";
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
                cout << "Opci�n inv�lida. Intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
