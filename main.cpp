#include <iostream>
#include <cstdlib>

using namespace std;

int menu();
void ejercicio1();
void ejercicio2();
int** creatematrix(int**,int);
void printmatrix();

int main(){
	char resp1='y';

	while(resp1=='y' || resp1=='Y'){
		int seleccion = menu();
		switch(seleccion){
			case 1:
        			ejercicio1();
      			break;
      			case 2:
        			ejercicio2();
      			break;
      			case 3:
        			cout<<"Que tengas un buen dia!"<<endl;
      			break;
    		}//fin switch de seleccion
    		cout<<"Desea reinciar el programa?y/n"<<endl;
    		cin>>resp1;
    		while(resp1 != 'y' && resp1 != 'Y' && resp1 != 'N' && resp1 != 'n'){
      			cout<<"Error, valor no valido. Reiniciar?y/n"<<endl;
      			cin>>resp1;
    		}//fin while verificar respuesta
  	}//fin while repetir programa

	return 0;
}


//funcion que imprime el menu
int menu(){
  int opcion1=1;

  cout<<"***LABORATORIO TRES***"<<endl<<"1) Ejercicio 1"<<endl<<"2) Ejercicio 2"<<endl<<"3) Ejercicio 3"
      <<endl<<"4) Salir"<<endl<<"Ingrese una opcion:"<<endl;
	cin>>opcion1;
	while(opcion1<1 || opcion1>3){
		cout<<"Error valor no valido. Ingrese opcion:"<<endl;
		cin>>opcion1;
	}//fin while verificar rango
	return opcion1;
}

void ejercicio1(){
	int size;
	cout<<"Ingrese entero positivo:"<<endl;
	cin>>size;
	int** matrix = creatematrix(matrix, size);
	
}

int** creatematrix(int** matrix,int size){
	int** matrix
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matrix[i][j] = rand()%6+1;
		}
	}
	return matrix
}

//imprimir matriz
void printMatrix(int size, int** matrix){
	for(int i=0;i<size;i++){
    		for(int j=0;j<size;j++){
      			cout<<" "<<matrix[i][j];

    		}
    		cout<<endl;
  	}
}

void ejercicio2(){

}
