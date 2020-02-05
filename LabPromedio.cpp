#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	double numero, promedio, suma=0;
	int cent=1;
	char resp;
	string nums="";
	cout << "######################## PROMEDIO DE NUMEROS ########################" << endl;
	do{
		cout << "Numeros ingresados : {" << nums << "}" << endl;
		cout << "\n\nIngrese el numero " << cent << ": " << endl;
		cin >> numero;
		suma += numero;
		std::stringstream sstm;
		sstm << nums << numero;
		nums = sstm.str();
		
		cent++;
		cout << "\nDesea ingresar otro numero?(s/n)" << endl;
		cin >> resp;
		while(resp != 's' && resp != 'S' && resp != 'n' && resp != 'N'){
			cout << "\nIngrese una respuesta valida! (s = si, n = no)" << endl;
			cin >> resp;
		}
		if(resp != 'n' && resp != 'N')
			nums += ", ";
		system("cls");
		cout << "######################## PROMEDIO DE NUMEROS ########################" << endl;
	}while(resp == 'S' || resp == 's');
	
	promedio = suma / cent;
	system("cls");
	cout << "Numeros ingresados : {" << nums << "}" << endl;
	cout << "\nLa media de los numeros ingresados es : " << promedio << endl;
	system("pause");
	
	return 0;
}
