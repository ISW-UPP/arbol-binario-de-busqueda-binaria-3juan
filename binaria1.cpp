#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct Nodo
{
char dato;
Nodo* der;
Nodo* izq;
Nodo* padre;
};
//Prototipos
void menu();

Nodo *crearNodo(int, Nodo*);
void insertarNodo(Nodo*&, int, Nodo *);
void mostrarArbol(Nodo*, int);
void preOrden(Nodo *arbol);
void PostOrden(Nodo* arbol);
void Intorden(Nodo* arbol);
Nodo* minimo(Nodo*);

Nodo* arbol = NULL;//Inicializa el arbol en NULL, al igual que listas/pilas/colas

int main()
{
//menu();
int inf, sup, mm, mitad;//los datos que se utilizan para la busqueda
char band;//Si el numero existe o no en el arreglo
char datos;
int i, to, m = 0, kk = 0;
char dat;
char dato;
int opcion, contador = 0,dd;
cout << "\nAgregue el tamano para el arbol: ";
cin >> dd;
char a [dd];//se utiliza para acomodar el arreglo
char k[dd], g[dd], temp; //donde se guardan los datos para el arreglo

for(int i = 0; i < dd;i++){
	cout <<"\nAgregue un numero para el arbol en la posicion "<< i+1<<":";	
	cin >> dato;
	insertarNodo(arbol, dato, NULL); //Insertamos un nuevo nodo
	k[i] = dato;
	g[i] = dato;
	cout << "\n";
}
for (int l=0;l<dd;l++){
		for(int j=l+1;j<dd;j++){
			if (k[j] < k[l]){
				temp = k[l];
				k[l]  = k[j];
				k[j] = temp;
			}
		}
	}
	/*for(int l = 0; l < dd; l++){
		cout << k[l]<<endl;
	}
	system("pause");*/
	system("cls");
do
{
	
	
cout << "\t\t .:MENU:." << endl;
cout << "1.- Mostrar arbol completo" << endl;
cout << "2.- Buscar elemento arbol" << endl;
cout << "3.- PreOrden " << endl;
cout << "4.- postOrden " << endl;
cout << "5.- inOrden " << endl;
cout << "6.- SALIR"<<endl;
cout << "Elige una opcion: "<<endl;

cin >> opcion;

switch (opcion)
{
case 1: 
char f;
f = g[0];
cout << f;
cout << "Posiciones de los caracteres: "<<endl;
for(int l = 0; l < dd; l++){
		if(g[l+1] < f){
			cout << g[l]<<" posicion "<<l<<" , ";
		}else{
			cout << g[l]<<" posicion "<<l<<" , ";
		}
	}
cout << "\nMostrando el arbol completo\n\n";
mostrarArbol(arbol, contador); //Funcion para mostrar arbol
cout << "\n";
system("pause");
break;

case 2:
	band = 'F';
	cout << "Ingrese el dato a buscar: "<<endl;
	cin >> datos;
	sup = dd;
	inf = 0;
	mm = 0;
	while ((inf <= sup) && (mm< dd))
	{
		mitad = (inf + sup) / 2;// mitad

		if (k[mitad] == datos)
		{
			band = 'V';
			
			break; //Se encontro el elemento buscado, para no perder tiempo
		}
		if (k[mitad] > datos)
		{
			sup = mitad;
			mitad = (inf + sup) / 2; //Refrescar la mitad con un nuevo valor del lado superior
		}
		if (k[mitad] < datos)
		{
			inf = mitad;
			mitad = (inf + sup) / 2; //Refrescar la mitad con un nuevo valor del lado inferior
		}
		mm++;
	}
	if (band == 'V')
	{
		cout << "El numero se encontro en la posicion: " << mitad << endl; // mitad guarda las posiciones
	}
	else
	{
		cout << "El numero no se encontro "<<endl;
	}
	/*cout << "Ingrese el dato a buscar: ";
	cin >> dat;
	
	i = 0;
	while ((bandera == 'F') && (i < to))
	{
		if (k[i] == dat)
		{
			bandera = 'V';
		}
		i++;
	}
	if (bandera == 'F') //Nunca entro a la condicion de while
	{
		cout << "El nunero no existe en el arreglo " << endl;

	}
	else if (bandera == 'V') //Se encontro el numero
	{ 
	cout << "El numero a sido encontrado en la posicion: " << i << endl;
	}
	cout << "\n";*/
	system("pause");
break;
case 3:
cout << "\n Mostrando en preorden\n\n";
preOrden(arbol);
cout <<"\n";
system ("pause");
break;
case 4:
cout << "\n Mostrando en postorden\n\n";
PostOrden(arbol);
cout <<"\n";
system ("pause");
break;
case 5:
cout << "\n Mostrando en Intorden\n\n";
Intorden(arbol);
cout <<"\n";
system ("pause");
break;
}
system("cls");
} while (opcion != 6);


return 0;
}

//Funcion del menu
void menu()
{

}

//Funcion crear NODOS
Nodo *crearNodo(int n, Nodo * padre)
{
Nodo *nuevo_nodo = new Nodo();

nuevo_nodo->dato = n;
nuevo_nodo->der = NULL;
nuevo_nodo->izq = NULL;
nuevo_nodo->padre = padre;

return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo*& arbol, int n, Nodo * padre)
{
if (arbol == NULL)//Si el arbol esta vacio
{
Nodo* nuevo_nodo = crearNodo(n, padre);
arbol = nuevo_nodo;
}
else
{//Si el arbol tiene un nodo o mas
int valorRaiz = arbol->dato;//Obtenemos el valor de la raiz
if (n < valorRaiz)
{ //Si el elemento es menor a la raiz, se inserta en la izquierda

insertarNodo(arbol->izq, n, arbol);
}
else
{//Si el elemento es mayor a la raiz, se inserta a la derecha
insertarNodo(arbol->der, n, arbol);
}
}
}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo* arbol, int cont)
{
//int contador = 0;
//int s = 0, ss = 0;
if (arbol == NULL) //Si el arbol esta vacio
{
return;
}
else
{
mostrarArbol(arbol->der, cont + 1);
for (int i = 0; i < cont; i++)
{
cout << " ";
//s++;//se pone para ver la cantidad de hojas
}
cout << arbol->dato << endl;
//contador = contador +1;
mostrarArbol(arbol->izq, cont + 1);

//s++;
//cout << s;
}
//cout<<contador;
}

void preOrden(Nodo* arbol)
{
if(arbol!=NULL)
{
cout << arbol->dato <<" ";
for(int l = 0; l < 5; l++){
		cout << arbol->dato <<" posicion "<<l<<" , ";;
	}
preOrden(arbol->izq);
preOrden(arbol->der);
}
}

void PostOrden(Nodo* arbol)
{
if(arbol!=NULL)
{
PostOrden(arbol->izq);
PostOrden(arbol->der);
cout << arbol->dato <<" ";
}
}

void Intorden(Nodo* arbol)
{
	if(arbol!=NULL)
	{
		
		Intorden(arbol->izq);
		 cout<< arbol->dato<<" ";
		Intorden(arbol->der);
	}
}

Nodo* minimo(Nodo* arbol)
{
if (arbol==NULL)
{
return NULL;
}
if (arbol->izq) //Si tiene hijo izq
{

return minimo(arbol->izq);
}
else //Si no tiene hijo izq
{
return arbol; //Retornamos su mismo valor

}

}
