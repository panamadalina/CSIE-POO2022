#include<iostream>
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

struct Materie {
	int id;
	char* denumire;
	int* note;
	int nrNote;
};

Materie initMaterie(int id, const char* denumire, int* note, int nrNote) {

	Materie m;
	m.id = id;
	m.nrNote = nrNote;
	m.note = new int[nrNote];
	for (int i = 0;i < nrNote;i++) {
		m.note[i] = note[i];
	}
	m.denumire = new char[strlen(denumire)+1];
	strcpy(m.denumire, denumire);

	return m;
}

int main() {


	/*-----------------Exemplu 1: matrice alocata dinamic cu 2 linii si 3 coloane----------------------------------------*/
	cout << endl <<"Matrice:" << endl;	
	int nrLinii = 2;
	int nrColoane = 3;
	int** matrice = new int* [nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		matrice[i] = new int[nrColoane];
	}
	int k = 0;
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			matrice[i][j] = ++k;//preincrementare
		}
	}
	//afisare
	cout << endl;
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}

	//Exercitiu1:dezalocare matrice alocata dinamic:
	//???????


	cout << endl << endl;
	/*---------Exemplu 2: Vector de structuri(fiecare structura avand o lista de note)--------------------------------------*/
	cout << endl <<"Struct:" << endl;
	int note1[3] = { 10,8,9 };
	int note2[2] = { 7,5 };
	int note3[4] = { 6,8,10,8};

	Materie m1=initMaterie(1, "poo", note1,3);
	Materie m2 = initMaterie(2, "bd",note2, 2);
	Materie m3 = initMaterie(3, "cts",note3, 4);
	//afisare:
	cout << "\n materia:" << m1.denumire << ", note: ";
	for (int i = 0;i < m1.nrNote;i++) {
		cout << m1.note[i] << " ";
	}

	/*Lista statica*/
	Materie listaMaterii[3];
	listaMaterii[0] = initMaterie(m1.id, m1.denumire,m1.note,m1.nrNote);//m1;  //deep-copy
	listaMaterii[1] = m2;//shallow copy
	listaMaterii[2] = m3;//shallow copy

	//Exercitiu2:dezalocare listaMaterii:
	//??

	/*------------------------------------------------*/

	/*Lista dinamica*/
	//Declarare:
	Materie** pms = (Materie**)malloc(2 * sizeof(Materie*));
	for (int i = 0; i < 2; i++) {
		pms[i] = (Materie*)malloc(sizeof(Materie));
	}
	//Initializare:
	pms[0]->id = m1.id;
	pms[0]->denumire = new char[strlen(m1.denumire) + 1];
	strcpy(pms[0]->denumire, m1.denumire);
	pms[0]->note = new int[3];
	for (int i = 0;i < 3;i++) {
		pms[0]->note[i] = note1[i];
	}

	cout << endl << endl;
	cout << "\n ~Materia:" << pms[0]->denumire << ", note: ";
	for (int i = 0;i < m1.nrNote;i++) {
		cout << pms[0]->note[i] << " ";
	}

	//Ex3: Dezalocati memoria ramasa:
	

	_CrtDumpMemoryLeaks();

	return 0;
}