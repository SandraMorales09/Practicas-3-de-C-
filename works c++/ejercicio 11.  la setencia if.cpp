/* La setencia if

    if(condicion){
          Instrucciones 1;
	}
	else{
	      Instrucciones 2;
	}
*/

#include<iostream>

using namespace std;

int main(){
	int numero, dato = 5;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	
	if(numero == dato){
		cout<<"El numero es menor a 5";
	}
	else{
		cout<<"El numero es mayor a 5 ";
	}
	
	
	
	return 0;
}
