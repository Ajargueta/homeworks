#include <iostream>
#include <string.h>
using namespace std;
string hexa = "0123456789ABCDEF", bina = "01";

string conversion(string simb, int* n, int x){
	string cad = "";
	int spa = 0, tmp = 0;
	while (*n > 0){
		tmp = *n % x;
		cad = simb.substr(tmp , 1) + cad;
		*n = (*n - tmp) / x;
		spa ++;
		if (spa == 4){
			cad = " " + cad;
			spa = 0;
		} 
	}
	for (int i = spa; i < 4; i++){
		cad = "0" + cad;
	}
	return cad;
}

int main(){
	int num, opt;
	do{
		cout << "1 .- Convertir decimal a binario\n";
		cout << "2 .- Convertir decimal a hexadecimal\n";
		cout << "0 .- SALIR\n";
		cout << "Ingrese su opcion: "; cin >> opt;
		switch (opt){
			case 1:
				cout << "\n\t -- Decimal a Binario --\n";
				cout << "Numero a convertir: "; cin >> num;
				cout << "Es igual a: " << conversion(bina, &num, 2);
				break;
			case 2:
				cout << "\n\t -- Decimal a Hexadecimal --\n";
				cout << "Numero a convertir: "; cin >> num;
				cout << "Es igual a: " << conversion(hexa, &num, 16);
				break;
			case 0:
				break;
			default:
				cout << "\nEsa no es una opcion valida\n";
		}
		cout << "\n\n";
	}while(opt != 0);
	return 0;
}
