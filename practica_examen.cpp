#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
int vector[10];

void creandovector(){
	int hp;
	float sum = 0;
	cout << "Estos son los valores que tiene el vector: ";
	for (int i = 0; i < 10; i++){
		vector[i] = (rand() % 100) + 1;
		sum += vector[i];
		cout << vector[i] << " .";
	}
	cout << "\n\nEstos son los valores ya ordenados: ";
	for (int i = 0; i < 10; i++){
		for (int j = (i + 1); j < 10; j++){
			if(vector [j] < vector[i]){
				hp = vector[j];
				vector[j] = vector[i];
				vector[i] = hp;
			}
		}
		cout << vector[i] << " .";
	}
	cout << "\nEl numero menor es: " << vector[0];
	cout << "\nEl numero mayor es: " << vector[9];
	cout << "\nEl promedio de los 10 numeros es: " << sum / 10;
}

int main(){
	char otro = 's';
	srand(time(NULL));
	do{
		cout << "\n -- Se genero un arreglo de 10 espacios con numeros aleatorios de 1 a 100\n";
		creandovector();
		cout << "\nDesea generar otro numero? (s/n) "; cin >> otro;
		if (otro == 'S'){
			otro = 's';
		}
	}while(otro == 's');
}
