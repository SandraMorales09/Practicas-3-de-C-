#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para almacenar información del paciente
struct Paciente {
    int id;
    string nombre;
    int edad;
    string estado;
};

// Declaraciones de funciones
void agregarPaciente(vector<Paciente>& pacientes);
void verPacientes(const vector<Paciente>& pacientes);
void actualizarEstado(vector<Paciente>& pacientes);

int main() {
    vector<Paciente> pacientes;
    int opcion;

    do {
        cout << "\n--- Sistema para Enfermeros ---\n";
        cout << "1. Agregar Paciente\n";
        cout << "2. Ver Pacientes\n";
        cout << "3. Actualizar Estado del Paciente\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPaciente(pacientes);
                break;
            case 2:
                verPacientes(pacientes);
                break;
            case 3:
                actualizarEstado(pacientes);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

void agregarPaciente(vector<Paciente>& pacientes) {
    Paciente nuevoPaciente;
    cout << "Ingrese el ID del paciente: ";
    cin >> nuevoPaciente.id;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nuevoPaciente.nombre);
    cout << "Ingrese la edad del paciente: ";
    cin >> nuevoPaciente.edad;
    cout << "Ingrese el estado del paciente (Ejemplo: Estable, Crítico): ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nuevoPaciente.estado);

    pacientes.push_back(nuevoPaciente);
    cout << "Paciente agregado exitosamente.\n";
}

void verPacientes(const vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
    } else {
        cout << "\n--- Lista de Pacientes ---\n";
        for (size_t i = 0; i < pacientes.size(); ++i) { // Uso de índice en lugar de "auto"
            cout << "ID: " << pacientes[i].id
                 << ", Nombre: " << pacientes[i].nombre
                 << ", Edad: " << pacientes[i].edad
                 << ", Estado: " << pacientes[i].estado << "\n";
        }
    }
}

void actualizarEstado(vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados para actualizar.\n";
        return;
    }

    int id;
    cout << "Ingrese el ID del paciente a actualizar: ";
    cin >> id;

    for (size_t i = 0; i < pacientes.size(); ++i) { // Uso de índice en lugar de "auto"
        if (pacientes[i].id == id) {
            cout << "Ingrese el nuevo estado del paciente: ";
            cin.ignore();
            getline(cin, pacientes[i].estado);
            cout << "Estado actualizado exitosamente.\n";
            return;
        }
    }
    cout << "Paciente con ID " << id << " no encontrado.\n";
}


