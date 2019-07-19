#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void menu();//funcion que muestra un menu en pantalla
void trabajar_matriz(int**,int,int);
void mostrar_matriz(int**,int,int);
void leer_matriz(int**,int,int);
int main(){
	int opcion;
	//el programa continua mientras el usuario no ingrese la opcion de salir
	do{
		menu();
		cin>>opcion;
		
		switch(opcion){
			case 1:
				{
					
					int filas=5;
					int columnas=5;
					//matriz 5*5
					int matriz[filas][columnas];
					leer_matriz(matriz,filas,columnas);
					trabajar_matriz(matriz,filas,columnas);
				}
				
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
void trabajar_matriz(int**matriz,int filas,int columnas){
	//1.muestra la matriz mediante una funcion
	mostrar_matriz(matriz,filas,columnas);	
}

void mostrar_matriz(int**matriz,int filas,int columnas){
	cout<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<endl;
}

void leer_matriz(int**matriz,int filas,int columnas){
	srand(time(0));
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			matriz[i][j]=1+rand()%30;
		}
	}
}

