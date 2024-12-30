/*7. Escriba un programa que solicite una edad (un entero) e indique en la
salida estandar si La edad introducida esta en el rango [18-25].*/

#include<iostream>

using namespace std;

int main (){
	int edad;
	
	cout<<"Digite su edad: ";
	cin>>edad;
	//18-19-20-21-22-23-24-25
	if((edad>=18)&&(edad<=25)){
		cout<<"Su edad esta en el rango de [18-25]";
	}
	else{
		cout<<"Su edad no esta en dicho rango";
	}
	
	return 0;
}
