#include <iostream>
#include <vector>
#include <string>

struct Libro {
    int id;
    std::string titulo;
    std::string autor;
    bool disponible;
};

struct Usuario {
    int id;
    std::string nombre;
};

class Biblioteca {
private:
    std::vector<Libro> libros;
    std::vector<Usuario> usuarios;
    int siguienteIdLibro;
    int siguienteIdUsuario;

public:
    Biblioteca() : siguienteIdLibro(1), siguienteIdUsuario(1) {}

    void agregarLibro(const std::string& titulo, const std::string& autor) {
        Libro nuevoLibro = {siguienteIdLibro++, titulo, autor, true};
        libros.push_back(nuevoLibro);
        std::cout << "Libro agregado: " << titulo << "\n";
    }

    void listarLibros() {
        if (libros.empty()) {
            std::cout << "No hay libros en la biblioteca actualmente.\n";
            return;
        }
        for (size_t i = 0; i < libros.size(); ++i) {
            const Libro& libro = libros[i];
            std::cout << "ID: " << libro.id 
                      << " | Título: " << libro.titulo 
                      << " | Autor: " << libro.autor 
                      << " | Disponible: " << (libro.disponible ? "Sí" : "No") 
                      << "\n";
        }
    }

    void buscarLibro(const std::string& titulo) {
        bool encontrado = false;
        for (size_t i = 0; i < libros.size(); ++i) {
            const Libro& libro = libros[i];
            if (libro.titulo.find(titulo) != std::string::npos) {
                std::cout << "ID: " << libro.id 
                          << " | Título: " << libro.titulo 
                          << " | Autor: " << libro.autor 
                          << " | Disponible: " << (libro.disponible ? "Sí" : "No") 
                          << "\n";
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontraron libros con ese título.\n";
        }
    }

    void eliminarLibro(int id) {
        for (size_t i = 0; i < libros.size(); ++i) {
            if (libros[i].id == id) {
                std::cout << "Eliminando libro: " << libros[i].titulo << "\n";
                libros.erase(libros.begin() + i);
                return;
            }
        }
        std::cout << "Libro no encontrado.\n";
    }

    void registrarUsuario(const std::string& nombre) {
        Usuario nuevoUsuario = {siguienteIdUsuario++, nombre};
        usuarios.push_back(nuevoUsuario);
        std::cout << "Usuario registrado: " << nombre << "\n";
    }

    void prestarLibro(int libroId, int usuarioId) {
        for (size_t i = 0; i < libros.size(); ++i) {
            if (libros[i].id == libroId) {
                if (libros[i].disponible) {
                    libros[i].disponible = false;
                    std::cout << "Libro prestado: " << libros[i].titulo
                              << " | Usuario ID: " << usuarioId << "\n";
                } else {
                    std::cout << "El libro no está disponible.\n";
                }
                return;
            }
        }
        std::cout << "Libro no encontrado.\n";
    }

    void devolverLibro(int libroId) {
        for (size_t i = 0; i < libros.size(); ++i) {
            if (libros[i].id == libroId) {
                if (!libros[i].disponible) {
                    libros[i].disponible = true;
                    std::cout << "Libro devuelto: " << libros[i].titulo << "\n";
                } else {
                    std::cout << "El libro ya estaba disponible.\n";
                }
                return;
            }
        }
        std::cout << "Libro no encontrado.\n";
    }
};

int main() {
    Biblioteca miBiblioteca;

    miBiblioteca.agregarLibro("Cien años de soledad", "Gabriel García Márquez");
    miBiblioteca.agregarLibro("Don Quijote de la Mancha", "Miguel de Cervantes");
    miBiblioteca.registrarUsuario("Juan Pérez");

    std::cout << "Lista de libros:\n";
    miBiblioteca.listarLibros();

    miBiblioteca.prestarLibro(1, 1);
    miBiblioteca.devolverLibro(1);
    miBiblioteca.eliminarLibro(2);

    return 0;
}
