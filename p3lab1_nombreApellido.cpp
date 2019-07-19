#include<iostream>
using namespace std;
void menu();//funcion que muestra un menu en pantalla
int main(){
	int opcion;
	//el programa continua mientras el usuario no ingrese la opcion de salir
	do{
		menu();
		cin>>opcion;
		
		switch(opcion){
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
					cout<<"\nhasta luego"<<endl;
				break;
			
			default:
				cout<<"\nno se ingreso una opcion correcta/intente de nuevo"<<endl;
							
		}
	}while(opcion!=4);
	return 0;
}
void menu(){
	cout<<"\nopciones\n1.puntos de silla\n2.numeros triangulares\n3.permutaciones\n4.salir\n?:"<<endl;	
}
