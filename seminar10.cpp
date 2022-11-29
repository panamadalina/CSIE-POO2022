#include<iostream>
using namespace std;

class Persoana {

private:
	char* nume;
	int varsta;
public:

	//constructor fara parametrii
	Persoana()
	{
		cout << "\n~Apel constructor fara param->Persoana: Anonim";
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = 0;
	}
	//constructor cu parametrii
	Persoana(const char* nume, int varsta) : varsta(varsta)
	{
		cout << "\n~Apel constructor cu param->Persoana: " << nume;
		if (nume != NULL)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
			this->nume = NULL;
	}

	//constructor de copiere
	Persoana(const Persoana& p)
	{
		cout << "\n~Apel constructor de copiere->Persoana: " << p.nume;
		if (p.nume != NULL)
		{
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
		}
		else
			this->nume = NULL;
		this->varsta = p.varsta;

	}

	//Operatorul egal

	Persoana& operator=(const Persoana& p)
	{
		cout << "\n~Apel operator = ->Persoana: " << p.nume;
		if (this->nume != NULL)
		{
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
		}
		else
			this->nume = NULL;
		this->varsta = p.varsta;
		return *this;
	}

	//destructori

	~Persoana()
	{
		cout << "\n~Apel destructor->Persoana: " << this->nume;
		if (this->nume != NULL)
			delete[]this->nume;
	}

	char* getNume()
	{
		return this->nume;
	}

	int getVarsta()
	{
		return this->varsta;
	}
	friend ostream& operator<<(ostream& out, Persoana p);
};

ostream& operator<<(ostream& out, Persoana p)
{
	out << "\n";
	out << "-->Persoana: " << p.nume << " are " << p.varsta << " ani ";
	return out;
}

int main() {

	Persoana p;
	return 0;
}