#include <iostream>
using namespace std;

string desicion(int pos, int num){
	string let[7] = {"I", "V", "X", "L", "C", "D", "M"};
	string cadrom = "";
	if (num < 4){
		for(int i = 1; i <= num; i++){
			cadrom = cadrom + let[pos];
		}
	}else if(num < 5){
		cadrom = let [pos] + let [pos + 1];
	}else if(num < 6){
		cadrom = let [pos + 1];
	}else if(num < 9){
		cadrom = let [pos + 1];
		for(int i = 6; i <= num; i++){
			cadrom = cadrom + let [pos];
		}
	}else if (num < 10){
		cadrom = let[pos] + let[pos + 2];
	}
	return cadrom;
}

int main(){
	int n, kt, tmp;
	cout << "Ingrese 0 para salir\n\n";
	do{
		do{
			cout << "Ingrese el numero a convertir: "; cin >> n;
			if (n < 0){
				cout << "Tiene que ingresar un numero positivo.\n";
			}
		}while (n < 0);
		string roman = "";
		kt = n;
		int units = 10;
		for (int i = 0; i <= 4; i += 2){
			tmp = n % units;
			if (tmp > 0){
				tmp = tmp / (units / 10);
				roman = desicion(i, tmp) + roman;
				n = n - (n % units);
			}
			units = units * 10;
		}
		tmp = n / 1000;
		for (int i = 1; i <= tmp; i++){
			roman = "M" + roman;
		}
		cout << "Numero en Romano: " << roman << "\n\n";
	}while(kt != 0);
		
	return 0;
}
