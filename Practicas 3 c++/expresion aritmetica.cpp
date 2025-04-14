#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Para funciones de manejo de caracteres como isdigit

using namespace std;

// Función para realizar una operación básica
int realizarOperacion(int a, int b, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: 
            cout << "Operador inválido: " << operador << endl;
            return 0; // Devuelve 0 como valor por defecto
    }
}

// Función para evaluar una expresión aritmética
int evaluarExpresion(const string &expresion) {
    stack<int> valores;         // Pila para valores
    stack<char> operadores;     // Pila para operadores
    
    for (size_t i = 0; i < expresion.length(); ++i) {
        if (isdigit(expresion[i])) {  // Si es un número
            int numero = 0;
            while (i < expresion.length() && isdigit(expresion[i])) {
                numero = numero * 10 + (expresion[i] - '0'); // Conversión manual
                ++i;
            }
            --i;  // Regresar el índice una posición
            valores.push(numero);
        } else if (expresion[i] == '(') {  // Si es un paréntesis abierto
            operadores.push(expresion[i]);
        } else if (expresion[i] == ')') {  // Si es un paréntesis cerrado
            while (!operadores.empty() && operadores.top() != '(') {
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                char operador = operadores.top(); operadores.pop();
                valores.push(realizarOperacion(a, b, operador));
            }
            operadores.pop();  // Remover '('
        } else if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/') { // Si es un operador
            while (!operadores.empty() && operadores.top() != '(') {
                int b = valores.top(); valores.pop();
                int a = valores.top(); valores.pop();
                char operador = operadores.top(); operadores.pop();
                valores.push(realizarOperacion(a, b, operador));
            }
            operadores.push(expresion[i]);
        }
    }
    
    while (!operadores.empty()) {  // Procesar operadores restantes
        int b = valores.top(); valores.pop();
        int a = valores.top(); valores.pop();
        char operador = operadores.top(); operadores.pop();
        valores.push(realizarOperacion(a, b, operador));
    }
    
    return valores.top();  // Resultado final
}

int main() {
    string expresion;
    cout << "Ingresa la expresión aritmética: ";
    getline(cin, expresion);
    
    int resultado;
    try {
        resultado = evaluarExpresion(expresion);
        cout << "Resultado: " << resultado << endl;
    } catch (...) { // Captura cualquier excepción
        cerr << "Ha ocurrido un error al evaluar la expresión." << endl;
    }
    
    return 0;
}
