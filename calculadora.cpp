#include<iostream>
#include<fstream>

using namespace std;

float raizQ(float number);
float pot2(float number);
long double pot(float number, int exponente);
long double coseno(long double number);
long double seno(long double number);
long double fact(long double n);

int main(int argc, char** argv) {
	int opc;
	float num;
	char resp = 'S';
	
	ofstream Resultados("Resultados.txt", ios::out|ios::app);
	
	if(!Resultados){
		cout << "No se puede crear el log de la calculadora." << endl;
	}else{
		Resultados << "[Inicio]: Entrada." << endl;
		while(resp == 'S'||resp == 's'){
			system("cls");
			cout << "1. Raiz cuadrada" << endl;
			cout << "2. Potencia Cuadrada" << endl;
			cout << "3. Potencia (n)" << endl;
			cout << "4. cos(n)" << endl;
			cout << "5. sen(n)" << endl;
			cout << "6. Salir" << endl;
			
			cout << "Seleccione la opcion que desea:" << endl;
			cin >> opc;
			
			switch(opc){
				case 1:
					system("cls");
					cout << "#################### Raiz Cuadrada ####################\n" << endl;
					cout << "Ingrese el numero :: ";
					cin >> num;
					Resultados << "[opcion 1-raiz cuadrada]: Raiz cuadrada de " << num << " = " << raizQ(num) << endl;
					cout << "\nResultado :: " << raizQ(num) << endl;
					break;
				case 2:
					system("cls");
					cout << "#################### Potencia Cuadrada ####################\n" << endl;
					cout << "Ingrese el numero a elevar al cuadrado :: ";
					cin >> num;
					Resultados << "[opcion 2-potencia cuadrada]: Potencia cuadrada de " << num << " = " << pot2(num) << endl;
					cout << "\nResultado :: " << pot2(num) << endl;
					break;
				case 3:
					int exp;
					system("cls");
					cout << "#################### Potencia n ####################\n" << endl;
					cout << "Ingrese la base :: ";
					cin >> num;
					cout << "\nIngrese el exponente :: ";
					cin >> exp;
					Resultados << "[opcion 3-potencia n]: Potencia " << exp << " de " << num << " = " << pot(num, exp) << endl;
					cout << "\nResultado :: " << pot(num, exp) << endl;
					break;
				case 4:
					system("cls");
					cout << "#################### Cos(n) ####################\n" << endl;
					cout << "Ingrese el numero :: ";
					cin >> num;
					Resultados << "[opcion 4-coseno]: coseno de " << num << " = " << coseno(num) << endl;
					cout << "\nResultado :: " << coseno(num) << endl;
					break;
				case 5:
					system("cls");
					cout << "#################### Sen(n) ####################\n" << endl;
					cout << "Ingrese el numero :: ";
					cin >> num;
					Resultados << "[opcion 5-seno]: seno de " << num << " = " << seno(num) << endl;
					cout << "\nResultado :: " << seno(num) << endl;
					break;
				case 6:
					Resultados << "[opcion 6-salida]: Salida.\n";
					Resultados.close();
					exit(0);
					break;
				default:
					Resultados << "[invalida]: Opcion no valida ingresada!" << endl;
					cout << "Seleccione una opcion valida!" << endl;
					break;
			}
			
			cout << "\nDesea usar otra opcion?(s/n)" << endl;
			cin >> resp;
			
			while(resp != 'n' && resp != 'N' && resp != 's' && resp != 'S'){
				system("cls");
				cout << "Por favor, ingrese una respuesta valida." << endl;
				cout << "\nDesea usar otra opcion?(s/n)" << endl;
				cout << "\t'S' para 'Si' ... 'N' para 'No'" << endl;
				cin >> resp;
			}
		}
	}
	Resultados << "[Salida]: Salida.\n";
	Resultados.close();
		
	return 0;
}

float raizQ(float number){
	float i, raiz=0;
	i=raiz*raiz;
	while(i < number){
		raiz += 0.00001;
		i = raiz*raiz;
	}
	
	return raiz;
}

float pot2(float number){
	float cuadrado;
	cuadrado = number*number;
	
	return cuadrado;
}

long double pot(float number, int exponente){
	long double potencia = number;
	if(exponente == 0){
		return 1;
	}else{
		for(int i=1; i<exponente; i++){
			potencia *= number;
		}
		return potencia;
	}
}

long double coseno(long double number){
	long double res=0, cont;
	int no_es_cero = 1;
	for(int j=90;j<=18090;j+=180){
		if(number == j){
			no_es_cero = 0;
			break;
		}
	}
	if(no_es_cero == 1){
		number = (number*3.14159265358979323846)/180;
		for(int i=0;i<=1750;i++){
			cont = ((pot((-1),i))/(fact((2*i))))*(pot(number, (2*i)));
			res += cont;
		}
	}
	return res;
}

long double seno(long double number){
	long double res=0, cont;
	int no_es_cero = 1;
	for(int j=180;j<=18180;j+=180){
		if(number == j){
			no_es_cero = 0;
			break;
		}
	}
	if(no_es_cero == 1){
		number = (number*3.14159265358979323846)/180;
		for(int i=0;i<=1750;i++){
			cont = ((pot((-1),i))/(fact((2*i)+1)))*(pot(number, (2*i)+1));
			res += cont;
		}
	}
	return res;
}

long double fact(long double n){
	if(n == 0){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

