#include<iostream>
using namespace std;

class Student {

private:
const int id;
char* nume;
int varsta;
bool lucreaza;

public:
static int nrStudenti;
//constructor fara parametrii
Student() :id(0) {
this->nume = new char[strlen("Anonim") + 1];
strcpy(this->nume, "Anonim");
this->varsta = 18;
this->lucreaza = false;
nrStudenti++;
}
//constructor cu toti parametrii (sau partial)
Student(const char* nume, int varsta = 18, bool lucreaza = false) :id(nrStudenti) {
if (varsta <= 0 || nume == NULL || strlen(nume) == 0) {
throw "params incorecti";
}
else {
this->nume = new char[strlen(nume) + 1];
strcpy(this->nume, nume);
this->varsta = varsta;
this->lucreaza = lucreaza;
nrStudenti++;
}

}
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
void setLucreaza(bool luc) {
this->lucreaza = luc;
}
//constructor de copiere
Student(const Student& s) :id(nrStudenti) {
this->nume = new char[strlen(s.nume) + 1];
strcpy(this->nume, s.nume);
this->varsta = s.varsta;
this->lucreaza = s.lucreaza;
nrStudenti++;

}
//SUPRAINCARCARE OPERATORI:
//opr =
Student& operator=(const Student& s) {
if (this->nume != NULL) {
delete[] this->nume;
this->nume = nullptr;
}
this->nume = new char[strlen(s.nume) + 1];
strcpy(this->nume, s.nume);
this->varsta = s.varsta;
this->lucreaza = s.lucreaza;
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

//---Seminar8---

//++

//post incre
//s7=s1++;
const Student operator++(int i) {
Student copie = *this;
//modif apelat functi
this->varsta++;
//salariu++
return copie;
}

//const Student operator++() {
// this->varsta++;
// return *this;

//}
friend const Student operator++(Student& s);

Student operator!() {
Student copie = *this;
copie.lucreaza = !copie.lucreaza;
return copie;
}

bool operator!=(const Student& s) {
if (strcmp(this->nume, s.nume) == 0 && this->varsta == s.varsta && this->lucreaza == s.lucreaza) {
return false;
}
else {
return true;
}
}

//cast
operator int() {
return this->varsta;
}
};

int Student::nrStudenti = 0;

const Student operator++(Student & s) {
s.varsta++;
return s;

}

ostream& operator<<(ostream& out, Student& s) {
out << "\nStudentul:" << s.getNameShallowCopy() << " are varsta: " << s.getVarsta();
if (s.lucreaza == true) {
out << " si lucreaza";
}
else {
out << " si NU lucreaza";
}
return out;
}
istream& operator>>(istream& in, Student& s) {
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
cout << "\nIntrodu 1 daca lucreaza, 0 daca nu: ";
in >> s.lucreaza;
return in;
}



/*Seminar 8*/

int main() {

try {
Student s1("Mada", 25);
Student s2("Alex");

Student s3(s2);
Student s4;
s4 = s2;//s4.operator=(s2)

cout << s4;
int a = 2;
int b = 2;
a++;//3
++b;//3
cout << "\na=" << a;
cout << "\nB=" << b;


int c = a++;//c=3, | a=4
int d = ++b;//d=4 | b=4
cout << "\na=" << a;
cout << "\nB=" << b;
cout << "\nc=" << c;
cout << "\nd=" << d;

cout << s1;
Student s5 = s1++; //post

cout << s5;
cout << s1;
s1 = s2 = s3;
int i = 0;
//++ ++i;
//i++ ++;
//s1++ ++; //obiectul e const => evitam apelarea in cascada

cout << endl << endl;
cout << s2;
Student s6 = ++s2;
cout << s2;
cout << s6;

//bool suntViu = true;
//!suntViu;
////bool nuStViu=!suntViu;
//cout << endl << suntViu; //<< nuStViu;
cout << endl << endl;
Student s8 = !s6;
cout << s8;
cout << s6;

//!=
int x = 1, y = 2;
Student copie = s8;
if (copie != s8) {
cout << "\n studenti diferiti";
}
else {
cout << "\n studenti identici";
}

//cast
float m = 10.5;
int n = 10;
float o =(float) n + m;
cout << "\n"<<o;
cout << s1;

int j =  2+s1;
cout << endl << endl << j;
}
catch (const char* err) {
cout << "\nError: " << err;
}

return 0;
}