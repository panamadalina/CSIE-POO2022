#include<iostream>

/* https://www.mygreatlearning.com/blog/polymorphism-in-cpp/ 

https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm
*/
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

	//opr =
	Student& operator=(const Student& s) {
		//id
		//(const) nu mai modif id
		//nume
		//this->nume = s.nume;
		if (this->nume != NULL) {
			delete[] this->nume;
			this->nume = nullptr;
		}
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		//varsta
		this->varsta = s.varsta;
		//this->nrStud=s.nrStud//NU
		return *this;

	}
	//[]
	char operator[](int i) {
		if (i < 0 || i >= strlen(this->nume)) {
			throw "index invalid";
		}
		else {
			return this->nume[i];
		}
	}

	//destructor
	~Student() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
	}

	friend ostream& operator<<(ostream& out, Student& s);
	friend istream& operator>>(istream& in, Student& s);
};

int Student::nrStudenti = 0;

ostream& operator<<(ostream& out, Student& s) {
	//pasii dde exec
	out << "\nStudentul:" << s.getNameShallowCopy() << " are varsta: " << s.getVarsta();
	return out;
}
istream& operator>>(istream& in, Student& s) {
	//Student newS;
	// cin >> newS.varsta;

	cout << "\nIntrodu nume: ";
	char buffer[255];
	in >> buffer;
	if (buffer != NULL) {
		if (s.nume != NULL) {
			delete[]s.nume;
		}
		s.nume = new char[strlen(buffer) + 1];
		strcpy(s.nume, buffer);
	}

	cout << "\nIntrodu varsta: ";
	in >> s.varsta;
	//s = newS;
	return in;
}

int suma(int a, int b) {
	return a + b;

}

float suma(float a, float b) {
	return a + b;
}

int main() {
	int a = 10, b = 20;
	cout << suma(a, b);
	float x = 3.2;
	float y = 2.3;
	cout << suma(x, y);



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

		s2 = s1;//s2.operator=(s1)
		cout << endl << endl << s2.getNameShallowCopy();

		//FUNCTII FRIEND

		cout << endl << endl << s1[0];//char <- s1.operator[](int)
		//fct friend = meth care nu tin 100% de clasa
		cout << s1.getVarsta();// cout.opertaor<<(int)
		cout << s1;//cout.operator<<(cout,Student)

		int a = 0;
		//cout << "\nIntrodu nr tastatura: "; cin >> a;
		cout << "\nIntrodu Student: "; cin >> s1;//cin.operator>>(Student)
		cout << s1;
	}
	catch (const char* err) {
		cout << "\nError: " << err;
	}

	return 0;
}