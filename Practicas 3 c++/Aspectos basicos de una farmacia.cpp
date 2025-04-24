/*Gestiona los aspectos basicos de una farmacia*/
 
#include <iostream>
#include <string>
#include <vector>

// Clase Medicamento
class Medicamento {
public:
    std::string nombre;
    int cantidad;
    double precio;

    Medicamento(std::string nombre, int cantidad, double precio)
        : nombre(nombre), cantidad(cantidad), precio(precio) {}
};

// Clase Farmacia
class Farmacia {
public:
    std::vector<Medicamento> medicamentos;

    void agregarMedicamento(const Medicamento& medicamento) {
        medicamentos.push_back(medicamento);
    }

    void mostrarMedicamentos() {
        if (medicamentos.empty()) {
            std::cout << "No hay medicamentos en la farmacia.\n";
            return;
        }

        for (size_t i = 0; i < medicamentos.size(); ++i) {
            const Medicamento& medicamento = medicamentos[i];
            std::cout << "Nombre: " << medicamento.nombre << std::endl;
            std::cout << "Cantidad: " << medicamento.cantidad << std::endl;
            std::cout << "Precio: " << medicamento.precio << std::endl;
            std::cout << std::endl;
        }
    }

    void venderMedicamento(const std::string& nombre, int cantidad) {
        for (size_t i = 0; i < medicamentos.size(); ++i) {
            Medicamento& medicamento = medicamentos[i];
            if (medicamento.nombre == nombre) {
                if (medicamento.cantidad >= cantidad) {
                    medicamento.cantidad -= cantidad;
                    std::cout << "Venta exitosa de " << cantidad << " unidades de " << nombre << ".\n";
                } else {
                    std::cout << "No hay suficiente cantidad en stock de " << nombre << ".\n";
                }
                return;
            }
        }
        std::cout << "Medicamento no encontrado: " << nombre << ".\n";
    }
};

int main() {
    Farmacia farmacia;

    // Agregar medicamentos
    farmacia.agregarMedicamento(Medicamento("Aspirina", 100, 5.99));
    farmacia.agregarMedicamento(Medicamento("Ibuprofeno", 50, 7.49));

    // Mostrar medicamentos
    std::cout << "Medicamentos disponibles:\n";
    farmacia.mostrarMedicamentos();

    // Vender medicamento
    farmacia.venderMedicamento("Aspirina", 20);

    // Mostrar medicamentos después de la venta
    std::cout << "\nMedicamentos después de la venta:\n";
    farmacia.mostrarMedicamentos();

    return 0;
}
