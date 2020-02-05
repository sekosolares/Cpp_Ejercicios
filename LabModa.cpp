#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	double numero;
	int cent=1, comparadorAct=0, comparadorAnt=0;
	char resp;
	string nums="", moda="", numero_i="", numero_j="";
	cout << "######################## MODA DE NUMEROS ########################" << endl;
	do{
		cout << "Numeros ingresados : {" << nums << "}" << endl;
		cout << "\n\nIngresar numero : " << endl;
		cout << ">";
		cin >> numero;
		
		std::stringstream sstm;
		sstm << nums << numero;
		nums = sstm.str();
		
		cent++;
		cout << "\nDesea ingresar otro numero?(s/n)" << endl;
		cout << ">";
		cin >> resp;
		while(resp != 's' && resp != 'S' && resp != 'n' && resp != 'N'){
			cout << "\nIngrese una respuesta valida! (s = si, n = no)" << endl;
			cout << ">";
			cin >> resp;
		}
		if(resp != 'n' && resp != 'N')
			nums += ", ";
		if(resp == 'n' || resp == 'N')
			nums += "}";
		system("cls");
		cout << "######################## MODA DE NUMEROS ########################" << endl;
	}while(resp == 'S' || resp == 's');
	
	for(int i = 0; i <= nums.length() - 1 ; i++){
		if(nums[i] != ',' && nums[i] != ' ' && nums[i] != '}'){
			numero_i += nums[i];
		}else if(nums[i] == ',' || nums[i] == '}'){
			for(int j = 0; j <= nums.length() - 1 ; j++){
				if(nums[j] != ',' && nums[j] != ' ' && nums[j] != '}'){
					numero_j += nums[j];
				}else if(nums[j] == ',' || nums[j] == '}'){
					if(numero_i == numero_j){
						comparadorAct++;
					}
					if(comparadorAct > comparadorAnt){
						moda = numero_i;
					}
					numero_j = "";
				}
			}
			comparadorAnt = comparadorAct;
			comparadorAct = 0;
			numero_i = "";
		}
	}
	
	system("cls");
	cout << "######################## MODA DE NUMEROS ########################" << endl;
	cout << "\nNumeros ingresados : {" << nums << endl;
	cout << "\nLa moda de los numeros ingresados es : " << moda << endl;
	system("pause");
	
	return 0;
}
