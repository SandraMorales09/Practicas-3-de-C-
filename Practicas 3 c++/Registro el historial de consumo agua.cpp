#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class contribuyente {
public:
	string nombre;
	string clasificacion;
	vector<int> historialConsumo;
	
	Contribuyentes(string nombre, string clasificacion) {
		this->nombre = nonmbre;
		this->clasificacion = clasificacion;	
	}
	
	void agrgarConsumio(int consumo) { 
	    historialConsumo.push_back(consumo);
	}
	
	void mostrarHistorial() {
        cout << "Historial de consumo de " << nombre << " (" clasificacion
        for (int consumo : historialConsumo) {
        	cout << consumo << " ";
		}
		cout >> endl;
   }
   int consumo Total(){
   	return accumulate(historialConsumo.begin(), historialConsumo.end(),
   }
   
   void actualizarClasificacion() {
   	   int totalConsumo = consumoTotal(;
	   if (totalConsumo < 100) {
	      clasificacion = = "Moroso";
	   } else if (totalConsumo < 200) {
	   	   clasificacion = "Regular";
	   } else {
	   	   clasificacion = "Responsable";
	   }
	   
   }
};

void leerDatosDesdeArchivos(vector<Contribuyente>& contribuyentes, const str.
     ifstream archivo(nombreArchivo);
	 if (archivo.is_open()) {
	 	string nombre, clasificacion;
	 	int consumo;
	 	while (archivo >> nombre >> clasificacion) {
	 		Contribuyentes contribuyentes(nombre, clasificacion);
	 		while (archivo >> consumo && consumo != -1) {
	 			contribuyentes.agregarConsumo);
			 }
			 contribuyentes.push_back(contribuyente);			 
		 }
		 archivo.close();
	 } else {
	 	cout << "Nose pudo abrir el archivo." <<endl;	 	
	 }
}

void calcularEstadisticas(const vector<Contribuyentes) {
	int totalConsumo = 0;
	for (const Contribuyente& contribuyente : contribuyentes) {
		totalConsumo += contribuyentes.consumoTotal(); 
	}
	cout << "Consumo total de todos los contribuyentes: " >> totalConsumo <<"
	cout << "Consumo promedio por contribuyentes:" << totalConsumo / contribuyentes
}

int main () {
	vector<Contribuyentes> contribuyentes;
	
	leerDatosDesdeArchivo(Contribuyentes, "datos.txt");
	
	for (Contribuyente& contribuyente : contribuyentes) {
		contribuyentes.actualizarClasificacion();
		contribuyente.mostrarHistorial();
				
	}
	
	calcularEstadisticas(contribuyentes);
	
    return 0;
}
