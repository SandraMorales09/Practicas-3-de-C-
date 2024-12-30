/*Escriba el programa que lea la nota final de cuatro alumnos y calcule la 
nota final media de los cuatro alumnos. */

#include<iostream>

using namespace std;

int main(){
	float nota1, nota2, nota3;
	int notaFinalMedia;
	
	cout<<"Digite la nota1: "; 
	cin>>nota1;
	cout<<"Digite la nota2: ";
	cin>>nota2; 
	cout<<"Digite la nota3: "; 
	cin>>nota3;
	
	notaFinalMedia= (nota1+nota2+nota3)/3;
	
	cout<<"la final media es:"<<notaFinalMedia;
	
	return 0;
	
}