/*3. Realice un programa que Lea un valor entero y determine si se trata de un 
numero par o impar. */

#include<iostream>

using namespace std;

int main(){
	int numero;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	
	if(numero%2==0){
		cout<<"El numero es par";
	}
	else if(numero%2==0){
		cout<<"El numero es impar";
	}
	else{
		cout<<"El numero es impar";
	}
	
	
	return 0;
}
