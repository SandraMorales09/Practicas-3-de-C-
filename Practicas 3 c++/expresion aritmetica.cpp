#include <iostream>
#include <stack>
#include <string>
#include <cctype> // Para funciones de manejo de caracteres como isdigit

using namespace std;

// Funci�n para realizar una operaci�n b�sica
int realizarOperacion(int a, int b, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: 
            cout << "Operador inv�lido: " << operador << endl;
            return 0; // Devuelve 0 como valor por defecto
    }
}

// Funci�n para evaluar una expresi�n aritm�tica
int evaluarExpresion(const string &expresion) {
    stack<int> valores;         // Pila para valores
    stack<char> operadores;     // Pila para operadores
    
    for (size_t i = 0; i < expresion.length(); ++i) {
        if (isdigit(expresion[i])) {  // Si es un n�mero
            int numero = 0;
            while (i < expresion.length() && isdigit(expresion[i])) {
                numero = numero * 10 + (expresion[i] - '0'); // Conversi�n manual
                ++i;
            }
            --i;  // Regresar el �ndice una posici�n
            valores.push(numero);
        } else if (expresion[i] == '(') {  // Si es un par�ntesis abierto
            operadores.push(expresion[i]);
        } else if (expresion[i] == ')') {  // Si es un par�ntesis cerrado
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
    cout << "Ingresa la expresi�n aritm�tica: ";
    getline(cin, expresion);
    
    int resultado;
    try {
        resultado = evaluarExpresion(expresion);
        cout << "Resultado: " << resultado << endl;
    } catch (...) { // Captura cualquier excepci�n
        cerr << "Ha ocurrido un error al evaluar la expresi�n." << endl;
    }
    
    return 0;
}
