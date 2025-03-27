#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mascota {
    string nombre;
    string tipo;
    int edad;
    string dueno;
};

vector<Mascota> mascotas;

void agregarMascota() {
    Mascota nuevaMascota;
    cin.ignore(); // Ignorar el salto de línea previo
    cout << "Ingrese el nombre de la mascota: ";
    getline(cin, nuevaMascota.nombre);
    cout << "Ingrese el tipo de mascota (perro, gato, etc.): ";
    getline(cin, nuevaMascota.tipo);
    cout << "Ingrese la edad de la mascota: ";
    cin >> nuevaMascota.edad;
    cin.ignore(); // Ignorar el salto de línea
    cout << "Ingrese el nombre del dueño: ";
    getline(cin, nuevaMascota.dueno);
    mascotas.push_back(nuevaMascota);
    cout << "Mascota agregada exitosamente.\n";
}

void mostrarMascotas() {
    if (mascotas.empty()) {
        cout << "No hay mascotas registradas.\n";
        return;
    }
    cout << "Mascotas registradas:" << endl;
    for (size_t i = 0; i < mascotas.size(); ++i) {
        cout << "Mascota " << (i + 1) << ":\n";
        cout << "Nombre: " << mascotas[i].nombre << endl;
        cout << "Tipo: " << mascotas[i].tipo << endl;
        cout << "Edad: " << mascotas[i].edad << endl;
        cout << "Dueño: " << mascotas[i].dueno << endl;
        cout << endl;
    }
}

void buscarMascota() {
    cin.ignore(); // Ignorar el salto de línea previo
    string nombreBuscar;
    cout << "Ingrese el nombre de la mascota a buscar: ";
    getline(cin, nombreBuscar);

    bool encontrada = false;
    for (size_t i = 0; i < mascotas.size(); ++i) {
        if (mascotas[i].nombre == nombreBuscar) {
            cout << "Mascota encontrada:\n";
            cout << "Nombre: " << mascotas[i].nombre << endl;
            cout << "Tipo: " << mascotas[i].tipo << endl;
            cout << "Edad: " << mascotas[i].edad << endl;
            cout << "Dueño: " << mascotas[i].dueno << endl;
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "Mascota no encontrada.\n";
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- Veterinaria ---\n";
        cout << "1. Agregar mascota\n";
        cout << "2. Mostrar mascotas\n";
        cout << "3. Buscar mascota\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMascota();
                break;
            case 2:
                mostrarMascotas();
                break;
            case 3:
                buscarMascota();
                break;
            case 4:
                cout << "¡Adiós!\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
