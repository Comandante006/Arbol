#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

//prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *,int);

Nodo *arbol=NULL;

int main(){
	 menu();

	getch();
	return 0;
}

//menu
void menu(){
	int dato,opcion,contador=0;
	do{
		cout<<" M E N U "<<endl;
		cout<<"1.- Insertar nodo"<<endl;
		cout<<"2.- Mostrar Arbol"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<" "<<endl;
		cout<<"OPCION---> "<<endl;
		cin>>opcion;

		switch(opcion){
			case 1: cout<<"\n Digite un numero--> ";
					cin>>dato;
					insertarNodo(arbol,dato);//insertar un arbol
					cout<<"\n";
					system("pause");
			break;
			case 2: cout<<"Mostrar Arbol completo"<<endl;
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
			break;
		}
		system("cls");
	}while(opcion !=2);
}

//creacion de nodos
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo=new Nodo;

	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;

	return nuevo_nodo;
}

//insertar nodos
void insertarNodo(Nodo *&, int n){
	if (arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{
		int valorRaiz=arbol->dato;//valor de la raiz
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
}

//mostrar arbol
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for (int i=0; i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}
