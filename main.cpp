#include <iostream>


using namespace std;

int menu();
void ejercicio1();
void ejercicio2();
int** creatematrix(int);
void printMatrix(int,int**);
int** llenarmatrix(int**,int);
int** fillcofactores(int**,int**,int,int,int);
bool verpar(int);
void freeMatrix(int,int**);
char** char_crearmatrix(int);
char** llenartablero(char**,int);
void freecharmatrix(int,char**);
void printcharmatrix(char**,int);
int determinante(int**);

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

  cout<<"***LABORATORIO TRES***"<<endl<<"1) Ejercicio 1"<<endl<<"2) Ejercicio 2"<<endl<<"3) Salir"<<endl<<"Ingrese una opcion:"<<endl;
	cin>>opcion1;
	while(opcion1<1 || opcion1>3){
		cout<<"Error valor no valido. Ingrese opcion:"<<endl;
		cin>>opcion1;
	}//fin while verificar rango
	return opcion1;
}

void ejercicio1(){
	int size=0,fila=0,col=0;
	int** matrix;
	int** m_cofactor;
	cout<<"Ingrese entero positivo:"<<endl;
	cin>>size;
	while(size<=0){
		cout<<"ERROR.Numero no valido, ingrese entero positivo:"<<endl;
		cin>>size;
	}
	matrix = creatematrix(size);
	m_cofactor = creatematrix(size-1);
	matrix = llenarmatrix(matrix,size);
	m_cofactor = llenarmatrix(m_cofactor,size-1);
	cout<<"MATRIZ;"<<endl;
	printMatrix(size,matrix);	
	cout<<"Ingrese la fila del pivote(empieza en 0): "<<endl;
	cin>>fila;
		
	while(fila<0 || fila>size-1){
		cout<<"ERROR.Numero no valido, ingrese de nuevo:"<<endl;
		cin>>fila;
	}
	cout<<"Ingrese la columna del pivote(empieza en 0): "<<endl;
	cin>>col;
	while(col<0 || col>size-1){
		cout<<"ERROR.Numero no valido, ingrese de nuevo:"<<endl;
		cin>>col;
	}
	
	bool pivote=true;//true es positivo, false es negativo
	if((verpar(fila) && verpar(col))||(!verpar(fila)&&!verpar(col))){
		pivote = true;
	}else{
		pivote = false;
	}
	int numpivote=matrix[fila][col];
	
	if(!pivote){
		numpivote*=-1;	
	}
	
	m_cofactor = fillcofactores(m_cofactor,matrix,size,fila,col);
	cout<<"MATRIZ DE COFACTORES:"<<endl;
	printMatrix(size-1,m_cofactor);
	
	if(pivote){
		cout<<"PIVOTE:"<<endl<<"+"<<numpivote<<endl;
	}else{

		cout<<"PIVOTE:"<<endl<<numpivote<<endl;
	}
	//hacer determinante
	if(size-1==3){
	int resultado = determinante(m_cofactor);
	cout<<"Determinante:"<<resultado<<endl;
	}
	//liberar memoria
	freeMatrix(size,matrix);
	freeMatrix(size-1,m_cofactor);
}
//sacar determinante
int determinante(int** matrix){
	int determinante=0;
	determinante=((matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[1][0]*matrix[2][1]*matrix[0][2])+
			(matrix[2][0]*matrix[0][1]*matrix[1][2])-(matrix[0][2]*matrix[1][1]*matrix[2][0])-
			(matrix[1][2]*matrix[2][1]*matrix[0][0])-(matrix[2][2]*matrix[0][1]*matrix[1][0]));
	return determinante;
}


//llenar matrix on randoms
int** llenarmatrix(int** matrix, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			matrix[i][j]=rand()%6+1;
		}
	}
	return matrix;
}

//crear matrix
int** creatematrix(int n){
  	int** retVal = new int*[n];

  	for(int i=0;i<n;i++)
    		retVal[i]= new int[n];
	
  	return retVal;
}

//llenar cofactores
int** fillcofactores(int** m_cofactor,int** matrix,int size,int fila,int col){
	int nums[(size-1)*(size-1)];
	int cont=0;//mantiene la posicion del arreglo
	//sacar los numeros de la matrix a un arreglo
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==fila){
			//no hace nada
			}else{
					
				if(j==col){
				//no hace nada
				}else{
					nums[cont] = matrix[i][j];
					cont++;
				}
			}
		}
	}
	//meter los numeros del arreglo a la matrix de cofactores
	cont=0;
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1;j++){
			m_cofactor[i][j] = nums[cont];
			cont++;
		}
	}

	return m_cofactor;
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

//par
bool verpar(int resp){
	if(resp%2==0){
		return true;
	}else{
		return false;
  	}
}

//liberar memoria
void freeMatrix(int n, int** matrix){

  for(int i=0;i<n;i++)
    delete[] matrix[i];

  delete [] matrix;
}


void ejercicio2(){
	int turno=0,gane=0; //jugador1 = 0, jugador2 = 1; una vez uno gane, gane = 1
	char** tablero;
	tablero = char_crearmatrix(9);
	tablero = llenartablero(tablero,9);
	int avanzar=0;
	while(gane== 0){
		printcharmatrix(tablero,9);
		cout<<endl;
		switch(turno){
			case 0:
				cout<<"Turno jugador uno"<<endl;
				cout<<"ingrese un numero para continuar"<<endl;					
				cin>>avanzar;
				turno=1;
			break;
			case 1:
				cout<<"Turno jugador dos"<<endl;
				cout<<"ingrese un numero para continuar"<<endl;
				cin>>avanzar;
				turno=0;
			break;

		}
	}
	freecharmatrix(9,tablero);

}

char** char_crearmatrix(int n){
	char** retVal = new char*[n];

  	for(int i=0;i<n;i++)
    		retVal[i]=new char[n];

  	return retVal;

}

char** llenartablero(char** tablero, int size){
	int cont = 0,cont2 = 0;//contadores que marcan las orillas del tablero
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==0&&j!=0){
				tablero[i][j]='0'+cont;
				cont++;
			}
			else if(j==0){
				tablero[i][j]='0' + cont2;
				cont2++;
			}
			else if((i==4 && j==4)||(i==5 && j==5)){
				tablero[i][j]='o';
			}else if((i==4 && j==5)||(i==5 && j==4)){
				tablero[i][j]='x';
			}else{
				tablero[i][j]='.';
			}
		}
	}
	return tablero;
}

void printcharmatrix(char** tablero, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
      		cout<<" "<<tablero[i][j];

    		}
    		cout<<endl;
	}

}

//iberar memoria char
void freecharmatrix(int n, char** matrix){

	for(int i=0;i<n;i++)
		delete[] matrix[i];

	delete [] matrix;
}

