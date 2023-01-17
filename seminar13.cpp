#include<iostream>
using namespace std;

//Parfum

//tipParfum - enum
//brand - char*
//pret float
//esteImpachetat -> bool
//costImpachetare - float static

class IOnline {
public:
virtual float getPretFinal() = 0;//meth virt pura
};
enum ETipParfum {
Barbat=1,
Femeie=2,
Copil=3
};

 class Parfum:public IOnline {
ETipParfum tipParfum;
char* brand;
float pret;
bool esteImpachetat;
 public:
static float costImpachetare;

Parfum() {
this->brand = new char[strlen("N/A") + 1];
strcpy(this->brand, "N/A");
this->pret = 100;
this->esteImpachetat = false;
this->tipParfum = ETipParfum::Femeie;


}
Parfum(const char* brand, float pret, bool esteImpachetat, ETipParfum tip) {
this->brand = new char[strlen(brand) + 1];
strcpy(this->brand, brand);
this->pret = pret;
this->esteImpachetat = esteImpachetat;
this->tipParfum = tip;


}
Parfum(const Parfum& p) {
this->brand = new char[strlen(p.brand) + 1];
strcpy(this->brand, p.brand);
this->pret = p.pret;
this->esteImpachetat = p.esteImpachetat;
this->tipParfum = p.tipParfum;
}

Parfum& operator=(const Parfum& p) {
if (this->brand != NULL) {
delete[] this->brand;
this->brand = nullptr;
}
this->brand = new char[strlen(p.brand) + 1];
strcpy(this->brand, p.brand);
this->pret = p.pret;
this->esteImpachetat = p.esteImpachetat;
this->tipParfum = p.tipParfum;
return *this;
}
~Parfum() {
if (this->brand != NULL) {
delete[] this->brand;
this->brand = nullptr;
}
}

friend ostream& operator<<(ostream& out, Parfum& p);

//@Override
float getPretFinal() {
if (this->esteImpachetat) {
return this->pret + this->costImpachetare;
}
else {
return this->pret;
}


}

};
 float Parfum::costImpachetare = 500;

 ostream& operator<<(ostream& out, Parfum& p) {

out << "\nParfumul " << p.brand << " are pret: " << p.pret << " de tip: ";// << p.tipParfum;
switch (p.tipParfum) {
case 1:
out << "  barbat";
break;
case 2:
out << "  femeie";
break;
case 3:
out << "  copil";
break;
default:
out << " barbat";
break;
}
return out;
 }
 template<class T>
 class Colectie {
//listaParfumuri;
//nrParfumuri

T* listaParfumuri;
int nrParfumuri;
 public:
Colectie(T* listaParfumuri, int nrParfumuri) {
this->nrParfumuri = nrParfumuri;
this->listaParfumuri = new T[nrParfumuri];
for (int i = 0; i < nrParfumuri; i++) {
this->listaParfumuri[i] = listaParfumuri[i];
}
}
friend ostream& operator<<(ostream& out, Colectie<T> p);
 };
 
 template<class T>
 ostream& operator<<(ostream& out, Colectie<T> c) {
out << "\nAvem colectia de parfumuri: ";
for (int i = 0; i < c.nrParfumuri; i++) {
out <<"\n"<< c.listaParfumuri[i];
}
return out;
 }

 //Template -> polimorfim
 //overloading
 //int suma(int a, int b) {
// return a + b;
 //}
 //float suma(float a, float b) {
// return a + b;
 //}
 template<class T>
T suma(T a, T b) {
return a + b;
 }

int main() {
suma(2.4, 1.6);
suma(2, 3);

Parfum p1;
Parfum p2("Dior", 2500, true, ETipParfum::Barbat);
Parfum p3("Chanel", 1500, true, ETipParfum::Femeie);
Parfum p4("Zara", 500, true, ETipParfum::Barbat);

//cout << p2;
Parfum* lista = new Parfum[3];
lista[0] = p2;
lista[1] = p3;
lista[2] = p4;

Colectie<Parfum> c(lista,3);
cout << c;
return 0;
}