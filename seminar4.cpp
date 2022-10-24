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

	cout << endl << endl;
	//matrice alocata dinamic cu 2 linii si 3 coloane
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
	cout << endl;
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}

	//dezalocare matrice alocata dinamic
	for (int i = 0; i < nrLinii; i++)
	{
		delete[] matrice[i];
	}
	delete[] matrice;


	/*---------------------------------------------------------*/


	cout << endl <<"Struct:" << endl;
	int note1[3] = { 10,8,9 };
	int note2[2] = { 7,5 };
	int note3[4] = { 6,8,10,8};

	Materie m1;//(1, "poo", 5, "Pana", 10);
	m1 = initMaterie(1, "poo", note1,3);

	cout << "\n materia:" << m1.denumire << ", note: ";
	for (int i = 0;i < m1.nrNote;i++) {
		cout << m1.note[i] << " ";
	}

	Materie m2 = initMaterie(2, "bd",note2, 2);

	Materie m3 = initMaterie(3, "cts",note3, 4);

	/*Lista statica*/
	Materie listaMaterii[3];
	listaMaterii[0] = initMaterie(m1.id, m1.denumire,m1.note,m1.nrNote);//m1;  //deep-copy
	listaMaterii[1] = m2;//shallow copy
	listaMaterii[2] = m3;//shallow copy
	//shallow copy vs deep copy -> exercitiu explicat la tabla. 
	/* https://www.youtube.com/watch?v=C_nLA3hfw8E */
	/* https://dotnettutorials.net/lesson/deep-copy-and-shallow-copy-in-cpp */

	//delete[] listaMaterii;//nu merge
	delete[] listaMaterii[0].denumire;
	delete[] listaMaterii[0].note;

	/*------------------------------------------------*/

	/*Lista dinamica*/

	//Declarare:
	Materie** pms = (Materie**)malloc(2 * sizeof(Materie*));
	for (int i = 0; i < 2; i++) {
		pms[i] = (Materie*)malloc(sizeof(Materie));
	}

	//Initializari
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

	delete[] pms[0]->denumire;
	pms[0]->denumire = nullptr;
	
	delete[] pms[0]->note;
	pms[0]->note = nullptr;

	for (int i = 0; i < 2; i++) {
		free(pms[i]);
	}
	free(pms);

	delete[] m1.denumire;
	delete[] m1.note;
	m1.denumire = nullptr;
	m1.note = nullptr;

	delete[] m2.denumire;
	delete[] m2.note;
	m2.denumire = nullptr;
	m2.note = nullptr;

	delete[] m3.denumire;
	delete[] m3.note;
	m3.denumire = nullptr;
	m3.note = nullptr;

	_CrtDumpMemoryLeaks();

	return 0;
}