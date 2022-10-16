#include<iostream>
#include<string.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;


struct Student {
	char* nume;
	int varsta;
};

//constructor
Student initializareStudent(const char* n, int v) {
	Student stud;
	stud.nume = new char[5];
	strcpy(stud.nume, "Mada");
	stud.varsta = 25;
	//delete[]mada.nume;//access violation
	return stud;

}

int main() {

	/*Exemplu 1*/
	//enumeratie - tip de data ce rastrange numarul de valori posibile
	//la cele de mai jos:

	enum tipuriClienti { clientPremium = 30, clientStandard = 20, nonClient = 5 };
	tipuriClienti client = tipuriClienti::clientPremium;
	cout << client;
	client = (tipuriClienti)20;
	cout << client;
	/*------------------------------------------------------------*/

	/*Exemplu 2*/

	//Operatiile aritmetice permise asupra pointerilor sunt:
	//a) adunarea / scaderea unei constante, 
	//b) incrementarea / decrementarea si 
	//c) scaderea a doi pointeri de acelasi tip.
	//d) OBS: adunarea a doi pointeri -> INTERZIS 

	int x = 10;
	int* p = &x;
	cout << endl << p;

	//a) p salveaza o adresa mai mare cu 4 * sizeof(int) 
	p = p + 4;//salvez adresa la 3 int-uri mai departe
	cout << endl << p;
	p = p - 2;
	cout << endl << p;

	//b)  creste adresa salvata in pointer cu sizeof(int)
	p++;//postijncrementare //p=p+1;
	++p;//preincrementare p=1+p;

	int* q = p + 4;
	cout << endl << q;

	//c)diferenta a doi pointeri este un intreg
	//si reprezinta cate variabile de tip int, in acest caz particular
	//incap intre cele doua adrese de memorie
	cout << endl << q - p;
	cout << endl << q - p;

	//d) Adunare 2 pointeri -> INTERZIS
	//cout << p + q;//Nu merge!!

	/*------------------------------------------------------------*/

	/*Exemplu 3*/


	//Student madalina;
	//madalina.nume = new char[5];
	//strcpy(madalina.nume , "Mada");
	//madalina.varsta = 25;

	Student mada = initializareStudent("Madalina", 25);
	cout << endl << mada.nume;

	Student* ps = &mada;
	delete[]mada.nume;
	_CrtDumpMemoryLeaks(); //Verif memory leaks
	return 0;

	//o matrice este:
	// -> o adresa la adresa la un element
	// -> o adresa unui vector de elemente
	// ->vector de adrese;
	
	//TEMA: realizati o matrice care sa contina notele voastre de la mai multe materii.
	//      puteti folosi si structuri (care sa contina elemente alocate dinamic), pentru a ingreuna exemplul.
	//      Obiectivul temei este de a realiza corespunzator dezalocarea matricei (verificati folosind debugger + CRT library)
}