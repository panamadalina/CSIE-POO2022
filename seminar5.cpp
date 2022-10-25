#include<iostream>
#include<crtdbg.h>
using namespace std;

class Student {
private:
	const int idStudent;

	char* nume;
	char prenume[10];
	int varsta;


public:
	static int nrStudenti;//-> la nivelul intregii clase

	Student() :idStudent(nrStudenti) {

		cout << "\n+Apelare constructor fara param";
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		strcpy(this->prenume, "Panonim");
		this->varsta = 0;
		nrStudenti++;
	}

	//constructor cu toti parametrii
	Student(int idStudent, const char* numeStud, const char prenumeStud[], int varstaStud) :idStudent(idStudent) {
		cout << "\n+Apelare constructor toti params";
		//this->idStudent = idStudent;
		nume = new char[strlen(numeStud) + 1];
		strcpy(nume, numeStud);

		if (strlen(prenumeStud) > 10) {
			throw "prea mare prenumele";
		}
		else {
			strcpy(prenume, prenumeStud);
		}
		varsta = varstaStud;
		nrStudenti++;
	}
	Student(const char* numeStud, const char prenumeStud[], int varstaStud) :idStudent(nrStudenti) {
		cout << "\n+Apelare constructor cu cativa params";
		//this->idStudent = idStudent;
		nume = new char[strlen(numeStud) + 1];
		strcpy(nume, numeStud);

		if (strlen(prenumeStud) > 10) {
			throw "prea mare prenumele";
		}
		else {
			strcpy(prenume, prenumeStud);
		}
		this->varsta = varstaStud;
		nrStudenti++;
	}
	//constructor cu cativa parametrii
	Student(int idStud, const char* numeStud, int varstaStud) :idStudent(idStud) {
		/*idStudent = idStud;*/
		nume = new char[strlen(numeStud) + 1];
		strcpy(nume, numeStud);

		strcpy(prenume, "nedefinit");
		varsta = varstaStud;
		nrStudenti++;
	}
	int getVartsa() {
		return this->varsta;
	}
	//destructor=oglinditul constructorului
	~Student() {
		if (nume != NULL) {
			delete[] this->nume;
		}
	}

	static void faCevaLaNivelDeClasa();
};

//initializare varianbila statica:
int Student::nrStudenti = 0;//op de rezolutie;

void Student::faCevaLaNivelDeClasa() {
	cout << "\n-do smth class level-";

}


int main() {
	/*
	-Recap: ce este o clasa?
			Tip de data definit de user
	-Ce contine o clasa?
			Atribute si metode
	-Cate tipuri de accesari avem?
			Public, private, protected
	-Ce este un constructor?
			Metoda prin care initializam (optional: alocam spatiu de memorie in heap daca avem pointeri) un obiect al unei clase
	-Cate tipuri de constructori exista?
			Constructor fara param, constructor cu params, constructor de copiere
	*/

	/*constructor fara param + constructor cu params*/

	Student s1(1, "Pana", "Madalina", 25);
	cout << "\ns1.nrStud=" << s1.nrStudenti;
	Student s2;//constr fara param

/*-----------------------------------------------------------------------------------------------------*/
	/*
	POINTERUL THIS:
		- Utilizat, în special în metode, pentru a accesa obiectul curent (cel prelucrat de
			acea metodă), evitarea AMBIGUITATII
		- El salvează adresa acestui obiect
		- Este necesară utilizarea acestuia atunci când metoda are un parametru cu
			aceeași denumire ca un atribut al clasei deoarece variabilele locale (în acest caz
			parametrul) au prioritate în fața variabilelor globale (în acest caz atributul) cu
			aceeași denumire
	*/

/*-----------------------------------------------------------------------------------------------------*/
	//atribute constante (initializarea lor speciala in constructori)
	//atribute statice sunt la nivelul clasei
	//atribute non-statice sunt la nivel de obiect

	cout << "\ns2.nrStud=" << s1.nrStudenti;
	Student s3(2, "Popescu", "Ion", 25);
	//cout<<"Varsta= "<<s2.getVartsa();

	Student::faCevaLaNivelDeClasa();//metoda statica
	s1.faCevaLaNivelDeClasa();

	cout << "\ns3.nrStud=" << s3.nrStudenti;
	cout << "\nvarsta s1" << s1.getVartsa();

/*-----------------------------------------------------------------------------------------------------*/
	/*Exemplu2: Destructor*/
	//_CrtDumpMemoryLeaks();
	//False positives:
	/* https://learn.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022#false-positives */

/*-----------------------------------------------------------------------------------------------------*/
	/*desi s1,s2,s3 nu st pointeri, fiecare contine alocat un pointer de char
		Folosim DESTRUCTOR:
		- Utilizat la distrugerea obiectelor (dezalocarea memoriei alocate în constructor)
		- Dacă nu există destructor într-o anumită clasă, atunci automat se crează unul gol*/

	
/*-----------------------------------------------------------------------------------------------------*/


	/*
	REGULA!
	Orice clasa care are membrii pointeri, treb sa contina:
	- constructori
	- destructor
	- constructor de copiere
	- supraincarcarea op =
	*/

	return 0;
}