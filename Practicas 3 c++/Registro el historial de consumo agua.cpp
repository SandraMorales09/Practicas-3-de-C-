#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <numeric> // Para std::accumulate

using namespace std;

// Clase Contribuyente
class Contribuyente {
public:
    string nombre;
    string clasificacion;
    vector<int> historialConsumo;

    // Constructor
    Contribuyente(string nombre, string clasificacion) {
        this->nombre = nombre;
        this->clasificacion = clasificacion;
    }

    // M�todo para agregar consumo
    void agregarConsumo(int consumo) {
        historialConsumo.push_back(consumo);
    }

    // M�todo para mostrar historial de consumo
    void mostrarHistorial() const {
        cout << "Historial de consumo de " << nombre << " (" << clasificacion << "): ";
        for (int consumo : historialConsumo) {
            cout << consumo << " ";
        }
        cout << endl;
    }

    // M�todo para calcular el consumo total
    int consumoTotal() const {
        return accumulate(historialConsumo.begin(), historialConsumo.end(), 0);
    }

    // M�todo para actualizar la clasificaci�n
    void actualizarClasificacion() {
        int totalConsumo = consumoTotal();
        if (totalConsumo < 100) {
            clasificacion = "Moroso";
        } else if (totalConsumo < 200) {
            clasificacion = "Regular";
        } else {
            clasificacion = "Responsable";
        }
    }
};

// Funci�n para leer datos desde un archivo
void leerDatosDesdeArchivo(vector<Contribuyente>& contribuyentes, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string nombre, clasificacion;
        int consumo;
        while (archivo >> nombre >> clasificacion) {
            Contribuyente contribuyente(nombre, clasificacion);
            while (archivo >> consumo && consumo != -1) {
                contribuyente.agregarConsumo(consumo);
            }
            contribuyentes.push_back(contribuyente);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Funci�n para calcular estad�sticas
void calcularEstadisticas(const vector<Contribuyente>& contribuyentes) {
    int totalConsumo = 0;
    for (const Contribuyente& contribuyente : contribuyentes) {
        totalConsumo += contribuyente.consumoTotal();
    }
    cout << "Consumo total de todos los contribuyentes: " << totalConsumo << endl;
    if (!contribuyentes.empty()) {
        cout << "Consumo promedio por contribuyente: " << totalConsumo / contribuyentes.size() << endl;
    } else {
        cout << "No hay contribuyentes para calcular estad�sticas." << endl;
    }
}

int main() {
    vector<Contribuyente> contribuyentes;

    // Leer datos desde el archivo
    leerDatosDesdeArchivo(contribuyentes, "datos.txt");

    // Actualizar clasificaci�n y mostrar historial
    for (Contribuyente& contribuyente : contribuyentes) {
        contribuyente.actualizarClasificacion();
        contribuyente.mostrarHistorial();
    }

    // Calcular estad�sticas
    calcularEstadisticas(contribuyentes);

    return 0;
}

