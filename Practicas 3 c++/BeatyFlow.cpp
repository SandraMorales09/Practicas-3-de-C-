#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura para almacenar la información de un producto
struct Producto {
    int id;
    string nombre;
    double precio;
};

// Declaraciones de funciones
void agregarProducto(vector<Producto>& productos);
void verProductos(const vector<Producto>& productos);
void eliminarProducto(vector<Producto>& productos);

int main() {
    vector<Producto> productos;
    int opcion;

    do {
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Ver Productos\n";
        cout << "3. Eliminar Producto\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(productos);
                break;
            case 2:
                verProductos(productos);
                break;
            case 3:
                eliminarProducto(productos);
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

// Definición de funciones
void agregarProducto(vector<Producto>& productos) {
    Producto nuevoProducto;
    cout << "Ingrese el ID del producto: ";
    cin >> nuevoProducto.id;
    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, nuevoProducto.nombre);
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;

    productos.push_back(nuevoProducto);
    cout << "Producto agregado exitosamente.\n";
}

void verProductos(const vector<Producto>& productos) {
    if (productos.empty()) {
        cout << "No hay productos en el inventario.\n";
    } else {
        cout << "\n--- Lista de Productos ---\n";
        for (size_t i = 0; i < productos.size(); ++i) {
            cout << "ID: " << productos[i].id
                 << ", Nombre: " << productos[i].nombre
                 << ", Precio: $" << productos[i].precio << "\n";
        }
    }
}

void eliminarProducto(vector<Producto>& productos) {
    if (productos.empty()) {
        cout << "No hay productos para eliminar.\n";
        return;
    }

    int id;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> id;

    bool eliminado = false;
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].id == id) {
            productos.erase(productos.begin() + i);
            cout << "Producto eliminado exitosamente.\n";
            eliminado = true;
            break;
        }
    }

    if (!eliminado) {
        cout << "Producto con ID " << id << " no encontrado.\n";
    }
}
