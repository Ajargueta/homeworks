#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
using namespace std;

void conhrmnsg(){
	int seg, mn, hr;
	cout << "\n\n\t -- Horas, minutos y segundos --\n";
	cout << "Podra ingresar una cantidad de segundos y esos se convetiran en el\n";
	cout << "equivalente en horas, minutos y segundos restantes de la conversion.\n\n";
	do {
		cout << "\nIngrese la cantidad de segundos: "; cin >> seg;
		if (seg < 1){
			cout << "Ingrese un numero mayor a 0.";
		}
	}while(seg < 1);
	if ((seg % 60) != 0){
		if ((seg % 60) == 1){
			cout << 1 << " segundo.\n";
		}else{
			cout << (seg % 60) << " segundos.\n";
		}
	}
	mn = (seg - (seg % 60))/60;
	if ((mn % 60) != 0){
		if ((mn % 60) == 1){
			cout << 1 << " minuto.\n";
		}else{
			cout << (mn % 60) << " minutos.\n";
		}
	}
	hr = (mn - (mn % 60))/60;
	if (hr >= 1){
		if(hr == 1){
			cout << hr <<" hora.";
		}else{
			cout << hr << " horas.";
		}
	}
}

void numinvert(){
	int n;
	cout << "\n\n\t -- Numero Invertido --\n";
	cout << "Se le pedira un numero mayor a 9 y se reordenara\n";
	cout << "poniendo el ultimo numero en primera posicion y asi consecutivamente.\n\n";
	do{
		cout << "Ingrese su numero: "; cin >> n;
		if ( n <= 9){
			cout << "Recuerde que tiene que ingresar un numero mayor a 9.\n";
		}
	}while(n <= 9);
    ostringstream str1;
    str1 << n;
    string txt = str1.str();
    string ness = "";
    for (int i = 0; i <=(txt.length()-1); i ++){
    	ness = txt[i] + ness;
	}
	cout << "El nuevo numero es: " << ness;
}

void piramide(){
	cout << "\n\n\t -- Piramide --\n";
	for(int i = 9 ; i >= 1; i --){
		for (int j = 1; j <= i; j++){
			cout << j;
		}
		cout << "\n";
	}
}

void vectornprim(){
	int n, k, hp = 0, pr;
	srand (time(NULL));
	cout << "\n\n\t -- Vectores y sus primos --\n";
	cout << "Se creara un vector del tamaño que indique y se llenara\n";
	cout << "con valores aleatoreos con valores de 1 hasta el numero que indique,\n";
	cout << "luego se indicara cuantos de esos valores son primos.\n\n";
	do{
		cout << "Indique el tamaño del vector: "; cin >> n;
		if (n < 1){
			cout << "Tiene que ingresar un numero mayor a 0.\n";
		}
	}while(n < 1);
	do{
		cout << "Entre 1 y que numero se debe llenar el vector? "; cin >> k;
		if (k < 1){
			cout << "Tiene que ingresar un numero mayor a 0.\n";
		}
	}while(k < 1);
	int vector[n];
	cout << "\nEstos son los valores que tiene el vector:\n";
	for (int i = 0; i < n; i++){
		vector[i] = (rand() % k) + 1;
		cout << vector [i] << " .";
		pr = 1;
		for (int j = 2; j <= ceil(sqrt(vector[i])); j ++){
			if ((vector[i] % j) == 0){
				pr = 0;
			}
		}
		hp = hp + pr;
	}
	if (hp == 1){
		cout << "\n\nHay " << hp << " numero primo en el vector.";
	}else{
		cout << "\n\nHay " << hp << " numeros primos en el vector.";
	}
}

void celnfaren(){
	float cel, fare, n;
	cout << "\n\n\t -- Celcius y Farenheit --\n";
	cout << "Podra hacer la conversion de grados Celcius a Farenheit ";
	cout << "o de grados Farenheit a Celcius.\n\n";
	cout << "1.- Celcius a Farenheit\n";
	cout << "2.- Farenheit a Celcius\n";
	cout << "Elija su opcion: "; cin >> n;
	if (n == 1){
		cout << "\n\t***Conversion de Celsius(°C) a Fahrenheit(°F)***\n";
		cout << "Ingrese la temperature en Celsius: "; cin >> cel;
		fare = (( (cel * 9) / 5) + 32);
		cout << "La temperatura es " << fare << " °F.\n\n";	
	}else if(n == 2){
		cout << "\n\t***Conversion de Fahrenheit(°F) a Celsius(°C)***\n";
		cout << "Ingrese la temperature en Fahrenheit: "; cin >> fare;
		cel = (((fare - 32) *5) / 9);
		cout << "La temperatura es " << cel << " °C.\n\n";
	}else{
		cout <<  "Esa no fue una opcion valida.\n";
	}
}

void parimpar(){
	int n;
	cout << "\n\n\t -- Par o impar --\n";
	cout << "Ingrese el numero a probar: "; cin >> n;
	if ((n % 2) == 0){
		cout << "El numero es par.";
	}else{
		cout << "El numero es impar.";
	}
}

void promedio(){
	int n;
	double tmp, pro = 0;
	cout << "\n\n\t -- Promedio de n numeros -- \n";
	do{
		cout << "Cuantos numeros desea ingresar? "; cin >> n;
		if (n < 1){
			cout << "Tiene que ingresar un numero mayor a 0.\n";
		}
	}while(n < 1);
	for (int i = 1; i <= n; i++){
		cout << "Ingrese #" << i << ": "; cin >> tmp;
		pro = pro + tmp;
	}
	cout << "El promedio de los " << n << " numeros que ingreso es: " << (pro / n);
}

void maxmin(){
	int mn, mx, tmp, n;
	cout << "\n\n\t -- Mayor y Menor --\n";
	do{
		cout << "Cuantos numeros desea comparar? "; cin >> n;
		if (n < 2){
			cout << "Tiene que ingresar al menos 2 numeros.\n";
		}
	}while(n < 2);
	cout << "Ingrese #1: "; cin >> tmp;
	mx = mn = tmp;
	for (int i = 2; i <= n; i++){
		cout << "Ingrese #" << i << ": "; cin >> tmp;
		mx = max (mx, tmp);
		mn = min (mn, tmp);
	}
	cout << "El numero menor es: " << mn;
	cout << "\nEl numero mayor es: " << mx;
}

int main(){
	int opt = 1;
	while (opt != 0){
		cout << "\t ** Opciones **\n";
		cout << "1 . - Horas, minutos y segundos\n";
		cout << "2 . - Numero Invertido\n";
		cout << "3 . - Vector y sus elementos primos\n";
		cout << "4 . - Celcius y Farenheit\n";
		cout << "5 . - Piramide\n";
		cout << "6 . - Par e Impar\n";
		cout << "7 . - Promedio\n";
		cout << "8 . - Mayor y Menor\n";
		cout << "0 . - SALIR\n";
		cout << "Ingrese la opcion a ejecutar: "; cin >> opt;
		switch (opt){
			case 1:
				conhrmnsg(); break;
			case 2:
				numinvert(); break;
			case 3:
				vectornprim(); break;
			case 4:
				celnfaren(); break;
			case 5:
				piramide(); break;
			case 6:
				parimpar(); break;
			case 7:
				promedio(); break;
			case 8:
				maxmin(); break;
			case 0:
				break;
			default:
				cout << "Esa no es una opcion valida.";
		}
		cout << "\n\n";
	}
	return 0;
}
