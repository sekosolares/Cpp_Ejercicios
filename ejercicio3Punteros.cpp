#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;

int main(){
	int cols = 2;
	string** libros;
	int tamanio;
	
	cout << "Cuantos libros desea ingresar?" << endl;
	cout << "\t>";
	string entrada;
	getline(cin, entrada);
	tamanio = atoi(entrada.c_str());
	libros = new string*[tamanio];
	
	cout << "Por favor, ingrese la siguiente informacion de los Libros:" << endl;
	string titulo, autor;
	for(int i = 0; i < tamanio; i++){
		libros[i] = new string[cols];
		cout << "\n******* Libro " << i + 1 << " *******:" << endl;
		cout << "Titulo: ";
		getline(cin, titulo);
		
		cout << "Autor: ";
		getline(cin, autor);
		
		libros[i][0] = titulo;
		libros[i][1] = autor;
	}
	
	//Para liberar la memoria debemos recorrer fila por fila primero.
	for(int i = 0; i < tamanio; i++){
		delete [] libros[i];
	}
	
	delete [] libros;
	
	system("pause");
	
	return 0;
}
