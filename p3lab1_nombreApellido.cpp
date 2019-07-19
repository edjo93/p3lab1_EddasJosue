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
int menorFila(int**,int,int);
bool comprobar_num_t(int);
bool testMenor(int**,int,int,int);
int menorFila(int**,int,int);
bool testMayor(int**,int,int,int);
int mayorColumna(int**,int,int);
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
					{
				int num;
				cout<<"\ningrese un numero [>=1] para comprobar si es un numero triangular: ";
				cin>>num;
				
				//validacion de num
				while(num<1){
					cout<<"\nerror! ingrese un numero [>=1] para comprobar si es un numero triangular: ";
					cin>>num;
				}
				
				
				if(comprobar_num_t(num)){
					cout<<"\nel numero "<<num<<" es un numero tringular";
				}else{
					cout<<"\nel numero "<<num<<" no es un numero tringular"<<endl;
					
					//encontrando numero triangular previo
					int previo;
					
					for(int i=1;i<num;i++){
						if(comprobar_num_t(i)){
							previo=i;
						}		
					}
					cout<<"\nel numero tringular previo a "<<num<<" es: "<<previo<<endl;
				}
					}
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
	int counter=0;
	//1.muestra la matriz mediante una funcion
	mostrar_matriz(matriz,size);
	//buscamos los numeros silla
	//recorremos la matriz
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(testMenor(matriz,i,j,size)&&testMayor(matriz,i,j,size)){
				cout<<"numero silla en pos["<<i<<"]"<<"["<<j<<"]"<<endl;
				counter++;
			}
		}
	}
	cout<<"\ntotal numeros silla: "<<counter<<endl;
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

	matriz=new int*[size];//reservando memoria para las filas

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

bool testMenor(int**matriz,int i,int j,int size){
	int menor=matriz[i][j];//current number
	//test in row
	return menor==menorFila(matriz,i,size);
}



int menorFila(int**matriz,int fila,int size){//devuelve el menor de la fila
	int menor=matriz[fila][0];
	for(int j=0;j<size-1;j++){
		if(matriz[fila][j+1]<=menor){
			menor=matriz[fila][j+1];
		}
	}
	return menor;
}

bool comprobar_num_t(int t){
	int sum=0;
	// comprobacion segun definicion numero triangular
	for(int i=1;i<=t;i++){
		//salida temprana del ciclo
		sum+=i;
		if(sum>=t){
			break;
		}
	}
	
	//resultado
	
	return sum==t;
	
}
	
bool testMayor(int**matriz,int i,int j,int size){
	int mayor=matriz[i][j];//current number
	//test in row
	return mayor==mayorColumna(matriz,j,size);
}



int mayorColumna(int**matriz,int columna,int size){//devuelve el menor de la fila
	int mayor=matriz[0][columna];
	for(int i=0;i<size-1;i++){
		if(matriz[i+1][columna]>=mayor){
			mayor=matriz[i+1][columna];
		}
	}
	return mayor;
}
