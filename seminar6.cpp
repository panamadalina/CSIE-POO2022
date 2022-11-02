#include<iostream>

using namespace std;

class Student {

private:
	const int id;
	char* nume;
	int varsta;

public:
	static int nrStudenti;

	//constructor fara parametrii
	Student() :id(0) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = 18;
		nrStudenti++;
	}
	//constructor cu toti parametrii (sau partial)
	Student(const char* nume, int varsta = 18) :id(nrStudenti) {
		if (varsta <= 0 || nume == NULL || strlen(nume) == 0) {
			throw "params incorecti";
		}
		else {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->varsta = varsta;
			nrStudenti++;
		}

	}
	//constructor cu parametrii (partial)
	/*Student(const char* nume) :id(0) {
	if (varsta <= 0 || nume == NULL || strlen(nume) == 0) {
	throw "params incorecti";
	}
	else {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->varsta = 20;
	}

	}*/

	//getters:
	char* getNameShallowCopy() {
		return this->nume;//SHALLOW COPY: Returnez adresa unde este alocat numele in HEAP
	}
	char* getNameDeepCopy() {
		char* copieNumme = new char[strlen(this->nume) + 1];
		strcpy(copieNumme, this->nume);
		return copieNumme;//DEEP COPY : Creez o noua zona de memorie unde copiez valoarea "nume" si returnez noua adresa 
	}
	int getVarsta() {
		return this->varsta;
	}
	//setter:
	void setNume(const char* nume) {
		if (this->nume != NULL) {
			delete[] this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

	}
	//constructor de copiere
	Student(const Student& s) :id(nrStudenti) { 
	//OBS1:folosim ca parametru de intrare "Student&" ca sa nu se creeze o noua variabila locala s 
		// cand se creeaza variabile locale, se auto-apeleaza constructorul de copiere
		//Astfel, variabila s doar pointeaza catre zona de memorie a variabilei s2 din main()
		
	//OBS2: nu dezaloc nimic din obiectul this
	//OBS3: Doar copiez elementele si aloc zona de memorie noua in HEAP
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->varsta = s.varsta;

	}

	//destructor
	~Student() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}
};

int Student::nrStudenti = 0;

int main() {
	try {
		Student s1("Mada", 25);
		Student s2("Alex");

		cout << "\n->Create s3 based on s2 obj";
		Student s3(s2);


		//verif shallow/deep copy for copy-constructor:
		cout << "\nName s3: " << s3.getNameShallowCopy();
		cout << "\n->Set new value for s3.name";
		s3.setNume("Alex2");
		cout << "\nNume s3: " << s3.getNameShallowCopy();
		cout << "\ns2.name(should be the initial one):" << s2.getNameShallowCopy();
		cout << endl << endl;

		//verif shallow copy for getName() 
		char* numeStudShallowCopy = s2.getNameShallowCopy();
		cout << "\nnumeStudShallowCopy:" << numeStudShallowCopy;
		//numeStud = new char[strlen("Maria") + 1]; //nu realoc memorie
		cout << "\n->Set new value for numeStudShallowCopy";
		strcpy(numeStudShallowCopy, "Mari");
		cout << "\nnumeStudShallowCopy:" << numeStudShallowCopy;
		cout << "\ns2.name(shallow copy):" << s2.getNameShallowCopy();
		cout << endl << endl;
		//daca stergem numeStudShallowCopy se va sterge si s2.nume

		//verif deep copy for getName()

		char* numeStudDeepCopy = s2.getNameDeepCopy();
		cout << "\nnumeStudDeepCopy:" << numeStudDeepCopy;
		cout << "\n->Set new value for numeStudDeepCopy";
		strcpy(numeStudDeepCopy, "Ana");
		cout << "\nnumeStudDeepCopy:" << numeStudDeepCopy;
		cout << "\ns2.name(deep copy):" << s2.getNameShallowCopy();
		delete[] numeStudDeepCopy;
		cout << endl << s2.getNameDeepCopy();//aici pierd adresa de la zona de memorie nou creata si nu mai pot sa o dezaloc la final


		/* REGULA! Orice clasa care are membrii pointeri, trebuie sa contina:
				- constructori
				- destructor
				- constructor de copiere
				- supraincarcarea op =
		*/
	}
	catch (const char* err) {
		cout << "\nError: " << err;
	}
	
	return 0;
}