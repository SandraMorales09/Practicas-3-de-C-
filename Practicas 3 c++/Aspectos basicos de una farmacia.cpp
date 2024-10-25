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

    Medicamento(std::string nombre, int cantidad, double precio) {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->precio = precio;
    }
};

// Clase Farmacia
class Farmacia {
public:
    std::vector<Medicamento> medicamentos;

    void agregarMedicamento(Medicamento medicamento) {
        medicamentos.push_back(medicamento);
    }

    void mostrarMedicamentos() {
      for (const auto& medicamento : medicamentos) { 
            std::cout << "Nombre: " << medicamento.nombre << std::endl;
            std::cout << "Cantidad: " << medicamento.cantidad << std::endl;
            std::cout << "Precio: " << medicamento.precio << std::endl;
            std::cout << std::endl;
        }
    }

    void venderMedicamento(std::string nombre, int cantidad) {
        for (auto& medicamento : medicamentos) {
            if (medicamento.nombre == nombre) {
                if (medicamento.cantidad >= cantidad) {
                    medicamento.cantidad -= cantidad;
                    std::cout << "Venta exitosa" << std::endl;
                } else {
                    std::cout << "No hay suficiente cantidad en stock" << std::endl;
                }
                return;
            }
        }
        std::cout << "Medicamento no encontrado" << std::endl;
    }
};

int main() {
    Farmacia farmacia;

    // Agregar medicamentos
    farmacia.agregarMedicamento(Medicamento("Aspirina", 100, 5.99));
    farmacia.agregarMedicamento(Medicamento("Ibuprofeno", 50, 7.49));

    // Mostrar medicamentos
    farmacia.mostrarMedicamentos();

    // Vender medicamento
    farmacia.venderMedicamento("Aspirina", 20);

    // Mostrar medicamentos después de la venta
    farmacia.mostrarMedicamentos();

    return 0;
}
