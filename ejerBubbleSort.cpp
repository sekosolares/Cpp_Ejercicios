#include <iostream>
#include <iomanip>

using namespace std;

//			Prototipos de funciones:
void orden( int *, const int );
void swap( int * const, int * const );

int main(){
   int nSize; //Variable para cantidad de datos del vector dinamico.
   int *a=NULL; //Puntero que contendra la direccion en memoria de los datos.
   
   cout << "############################# ORDENAMIENTO BURBUJA #############################" << endl;
   
   cout << "Ingrese la cantidad de numeros a ordenar:" << endl;
   cout << "\n-->_ ";
   cin >> nSize;
   
   a = new int[ nSize ];
   
   system("cls");
   
   cout << "############################# ORDENAMIENTO BURBUJA #############################" << endl;
   for(int i = 0; i < nSize; i++){
   		cout << "Ingrese el dato #" << i+1 << ":" << endl;
   		cout << "\n-->_ ";
   		cin >> a[i];
   }
   
   cout << "\nElementos a ordenar\n";
   for ( int j = 0; j < nSize; j++ ){
      cout << setw( 5 ) << a[ j ];
	}
   orden( a, nSize );  // ordena el arreglo
   cout << "\nElementos ordenados\n";

   for ( int j = 0; j < nSize; j++ ){
      cout << setw( 5 ) << a[ j ];
	}
	cout << endl;

	system("pause");

	delete [] a;
	a = NULL;

   return 0;  // indica terminación exitosa
}

void orden( int *matriz, const int nSize ){
   for ( int pasada = 0; pasada < nSize - 1; pasada++ )
   {
      for ( int k = 0; k < nSize - 1; k++ )
      {
         if ( matriz[ k ] > matriz[ k + 1 ] )
         {
            swap( &matriz[ k ], &matriz[ k + 1 ] );
         }
      }
   }
} 

void swap( int * const ptrElemento1, int * const ptrElemento2 ){
   int mantiene = *ptrElemento1;
   *ptrElemento1 = *ptrElemento2;
   *ptrElemento2 = mantiene;
}

