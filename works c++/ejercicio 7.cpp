/*7. La calificacion final de un estudiante es la media ponderada de tres notas: 
La nota de practicas que cuenta un 30% del total, la nota teorica que cuenta un 
60% y La nota de participacion que cuenta el 10% restante. Escriba un programa
que Leo de La entrada estandar Los tres nortas de un alumno y escriba en La 
salida estandar su nota final. */

#include<iostream>

using namespace std;

int main (){
	float practica, teorica,participacion;
	
	cout<<"Digite la nota de practica: "; cin>>practica;
	cout<<"Digite la nota teorica: "; cin>>teorica;
	cout<<"Digite la nota de participacion: "; cin>>participacion;
	
	practica *= 0.30; //practica = practica * 0.30
	teorica *= 0.60; 
	participacion *= 0.10
	
	nota_final = practica + teorica + participacion;
	
	cout<<"nLa nota final es; "<<nota_final;
	
	return 0;
}
