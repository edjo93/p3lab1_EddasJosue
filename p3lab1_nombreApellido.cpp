#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void menu();//funcion que muestra un menu en pantalla
void trabajar_matriz(int**,int);
void mostrar_matriz(int**,int);
void leer_matriz(int**,int);
int**provisionar_matriz(int);
void liberar_matriz(int**,int);
int main(){
	int opcion;
	//el programa continua mientras el usuario no ingrese la opcion de salir
	do{
		menu();
		cin>>opcion;
		
		switch(opcion){
			case 1:
				{
					int size=5;
					int** matriz=provisionar_matriz(size);//generacion de una matriz 5*5
					leer_matriz(matriz,size);//llenamos esa matriz con numeros aleatorios
					trabajar_matriz(matriz,size);
					liberar_matriz(matriz,size);//liberamos la matriz
					
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
void trabajar_matriz(int**matriz,int size){
	//1.muestra la matriz mediante una funcion
	mostrar_matriz(matriz,size);	
}

void mostrar_matriz(int**matriz,int size){
	cout<<endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<endl;
}

void leer_matriz(int**matriz,int size){
	srand(time(0));
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matriz[i][j]=1+rand()%30;
		}
	}
}

int** provisionar_matriz(int size){
	int**matriz=NULL;

	matriz=new int*[size];//reservando memoria lara las filas

	for(int i=0;i<size;i++){
		matriz[i]=new int[size];//reservando memoria para las columnas
	}

	return matriz;
}
void liberar_matriz(int** matriz,int size){
	for(int i=0;i<size;i++){
		if(matriz[i]!=NULL){
			delete[] matriz[i];
			matriz[i]=NULL;

		}
	}	
	


	if(matriz!=NULL){
		delete[] matriz;
		matriz=NULL;
	}
}

