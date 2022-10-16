#include<iostream>
#include<string.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//macrodefinitii: #define nume(param1, param2, …, pn) text_de_substituit
#define impartire /

using namespace std;

/***Varianta recursiva pentru oglindirea unui numar ***/
int oglindit(int n, int o) // o va fi zero in int main();
{
	if (n == 0)
		return o;
	else
		return oglindit(n / 10, o * 10 + n % 10);
}


//Transferul parametrilor prin valoare(nr)
int oglindit1(int nr) {
	int nrOglindit = 0;
	while (nr) {
		nrOglindit = nrOglindit * 10 + nr % 10;
		nr /= 10;
	}
	return nrOglindit;
}

//Transferul parametrilor prin valoare(nr) si adresa/referinta(nrOglindit)
void oglindit2(int nr, int* nrOglindit) {
	while (nr) {
		(*nrOglindit) = (*nrOglindit) * 10 + nr % 10;
		nr /= 10;
	}
}

//Transferul parametrilor prin valoare(nr) si adresa/referinta(nrOglindit)
void oglindit3(int nr, int& nrOglindit) {
	while (nr) {
		nrOglindit = nrOglindit * 10 + nr % 10;
		nr /= 10;
	}
}

//de adaugat cuv
char* adauga_cuvant(char* fraza, const char* cuvant) {
	int dimCuvant = sizeof(cuvant) / sizeof(char);

	if (fraza != nullptr && strlen(fraza) > 0) {
		char* aux = new char[strlen(fraza) + dimCuvant + 1];
		for (int i = 0; i < strlen(fraza); i++) {
			aux[i] = fraza[i];
		}
		for (int i = 0; i <= dimCuvant; i++) {
			aux[strlen(fraza) + i] = cuvant[i];
		}
		delete[] fraza;
		fraza = nullptr;
		return aux;
	}
	return nullptr;
}

int main() {
	int n = 1234;
	//Obs:
	int rezOglinditRecursiv = oglindit(n, 0);
	cout << "\nRecursiv: nrOglindit= " << rezOglinditRecursiv;
	//Ex1:
	int nrOglindit1 = oglindit1(n);
	cout << "\nEx1: nrOglindit= " << nrOglindit1;
	//Ex2:

	int nrOglindit2 = 0;
	oglindit2(n, &nrOglindit2);
	cout << "\nEx2: nrOglindit= " << nrOglindit2;
	//Ex3:

	int nrOglindit3 = 0;
	oglindit3(n, nrOglindit3);
	cout << "\nEx3: nrOglindit= " << nrOglindit3;

	/// Alocare dinamica in memoria Heap
	//CRT library for Memory Leaks:
	/*https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022*/

	//NEW vs MALLOC
	int* vect = new int[4];
	//vect=[3,2,14,5]
	delete[] vect; //check with CRT library
	vect = nullptr;


	int* vect2 = (int*)malloc(4 * sizeof(int));
	free(vect2); //check with CRT library
	vect2 = nullptr;


	cout << endl << endl << n impartire 10;

	//Exercitiu: de adaugat un cuvant intr-o fraza 
	// ->concatenare a doua siruri: https://www.geeksforgeeks.org/strcat-vs-strncat-c/
	// ->si returnarea rezultatului in sirul initial

	char* fraza = new char[5];
	fraza[0] = 'm';
	fraza[1] = 'e';
	fraza[2] = 'r';
	fraza[3] = 'e';
	fraza[4] = '\0';//terminator de sir (NULL)

	cout << endl << "Fraza1= ";
	for (int i = 0; i < 4; i++) {
		cout << fraza[i];
	}
	cout << endl << "->Adaugare cuvant: ";

	char cuvant[] = ",pere";
	char* copieFraza = new char[5]; //fac o copie la fraza initiala
	strcpy(copieFraza, fraza);

	delete[]fraza;//sterg fraza initiala
	fraza = nullptr;

	//strlen vs sizeof pentru siruri de caractere
	//cout << endl << endl << "sizeof=" << sizeof(copieFraza);
	//cout << endl << endl << "strlen=" << strlen(copieFraza);


	//realoc memorie care sa cuprinda atat fraza initiala, cat si cuvantul nou:
	fraza = new char[strlen(copieFraza) + strlen(cuvant) + 1]; 
	for (int i = 0; i < strlen(copieFraza); i++) {
		fraza[i] = copieFraza[i];//adaug fraza initiala
	}
	
	for (int i = 0; i < strlen(cuvant); i++) {
		fraza[strlen(copieFraza) + i] = cuvant[i];//adaug cuvantul dupa fraza initiala
	}

	cout << endl << "Fraza2= ";
	for (int i = 0; i < 9; i++) {
		cout << fraza[i];
	}
	delete[]fraza;//sterg fraza 
	fraza = nullptr;

	delete[]copieFraza;//sterg copia fraza 
	copieFraza = nullptr;

	//variabila "cuvant" nu trebuie stearsa!

	/*------------------------------------------------------------------------------------*/
	/*Rezolvati memory leaks [REZOLVAT]*/

	cout << endl << endl << "Exercitiu:";
	fraza = new char[5];
	fraza[0] = 'm';
	fraza[1] = 'e';
	fraza[2] = 'r';
	fraza[3] = 'e';
	fraza[4] = '\0';//terminator de sir (NULL)

	cout << endl << "Fraza1= ";
	for (int i = 0; i < 4; i++) {
		cout << fraza[i];
	}
	cout << endl << "->Adaugare cuvant: ";

	/*char cuvant[] = ",pere";*/
	fraza = adauga_cuvant(fraza, cuvant);
	cout << endl << "Fraza2= ";
	for (int i = 0; i < 9; i++) {
		cout << fraza[i];
	}
	delete[]fraza;//sterg fraza 
	fraza = nullptr;
	
	_CrtDumpMemoryLeaks(); //Verif memory leaks
	return 0;

}