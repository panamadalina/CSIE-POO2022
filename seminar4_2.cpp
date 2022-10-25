#include<iostream>
#include<stdio.h>
#include <crtdbg.h>
#include<string>
using namespace std;



struct Pers {
	int varsta;
};

//clasa = user defined datatype (un tip de obiecte)
//Membrii unei clase: atribute & metode 

class Persoana {

	//atribut fara sa specifam tip de accesare este PRIVATE
	int varsta;

protected:
	bool lucreaza;

public:
	int idPersoana;
	char* nume;


	void metoda1() {
		cout << "\nMetoda1";
	}


	~Persoana() {
		if (this->nume != NULL) {
			delete[] this->nume;
			this->nume = nullptr;
		}
		//_CrtDumpMemoryLeaks();//nu merge
	}


	void metoda2();//EX1
};


void Persoana::metoda2() {//EX1. OPERATOR DE REZOLUTIE
	cout << "\nMetoda2";
}

//derivare/specializarea tipurilor de obiecte

class Angajat :Persoana {

	//Persoana p;
	int salariu;
public:

	void method1() {
		this->idPersoana = 0;
		this->lucreaza = true; //protected poate fi accesat
	}

	int getSalariu(int codAcces) {
		if (codAcces == 1234) {//caz ipotetic
			return salariu;
		}
		else {
			return -1;
		}
	}

	void setSalariu(int codAcces, int salariuNou) {
		if (codAcces == 1234) {//caz ipotetic
			salariu = salariuNou;
		}
		else {
			//alerta
			throw "cod acces incorect";//EX2
		}
	}
};

//EX3:

int main() {
	//Ce este o clasa?
	// 	   Ce contine o clasa?


	//	Pers pers;
	Persoana p; //acesta e un obiect -> o instanta a unei clase
	//unde e salvat acest obiect?

	//1. Avem 3 tipuri de accesari:

	/*
	public - members are accessible from outside the class
	private (BY DEFAULT) - members cannot be accessed (or viewed) from outside the class --->> INCAPSULARE!!
	protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.
	*/

	p.idPersoana = 1234;
	p.nume = new char[5];
	strcpy(p.nume, "Mada");
	cout << "\nPersoana: " << p.idPersoana << " are numele: " << p.nume;
	/*EXEMPLU 2: Tipuri de metode -> din clasa, din afara clasei*/

	p.metoda1();
	//++
	p.metoda2();


	//GETTERI
	cout << "\n\nGETTERI:";
	Angajat ang;
	cout << " are salariul: " << ang.getSalariu(1235);//acces interzis-> ALERTA EX2

	//SETTERI
	cout << "\n\nSETTERI:";
	
	try {
		ang.setSalariu(1235, 2000);//acces interzis// AALERTA EX2
	}
	catch (const char* excep) {
		cout << "\nCodul arunca o exceptie:" << excep;
	}

	Persoana* pp1 = &p;
	Persoana* pp2 = new Persoana();
	////pp este un pointer la un obiect de tip Student

	delete pp2;
	pp2 = nullptr;

	//EXEMPLU: destructor
	//_CrtDumpMemoryLeaks();//nu merge
	//False positives:
	/* https://learn.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022#false-positives */


	return 0;
}