
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//Bloc de apartamente-abstractizare: strada, numãr scãri, numãr apartamente etc.
//Cãuta?i minim 5 caracteristici.
//Realiza?i o structura în care vã declara?i atribute pentru toate aceste caracteristici ale blocului.
//Realizati un program in C++ care sa creeze un vector cu 10 blocuri.
//Programul trebui sã citeascã de la tastaturã valori pentru toate aceste caracteristici ale tuturor blocurilor din vector.
//Realizati o functie de citire a valorilor, astfel incat sa o puteti apela de 10 ori(cele 10 blocuri).
//Implementati o functie care sa afi?eze într - o propozi?ie toate valorile retinute de un bloc.Exemplu: “Blocul de pe strada Maresal Averescu, are 4 scari si un numar total de 54 de apartamente.”.Trebuie sa realizati o propozitie cu toate cele 5 caracteristici.
//Apelati aceasta functie pentru toate blocurile din vector.

class Bloc {
public:
	string adresa;
	int nrScari;
	int nrApt;
	int etajMax;
	//un atribut const dureaza de la terminarea construrii obiectului pana la distrugerea lui
	//valoarea sa odata stabilita, nu se modifica
	const int anConstructie;

	//Constructorul implicit
	Bloc() :anConstructie(2000), nrScari(8), etajMax(4) {
		this->adresa = "Nespecificat";
		//this->nrScari = 0;
		this->nrApt = 0;
		//this->etajMax;
	}

	//Constructorul cu parametri
	Bloc(string adresa, int nrScari, int nrApt, int etajMax, int an) :anConstructie(an) {

		//this->adresa = new char[strlen(adresa) + 1];
		this->adresa = adresa;
		this->nrScari = nrScari;
		this->nrApt = nrApt;
		this->etajMax = etajMax;

	}

	//Destructor
	//daca declaram adresa de tip char*
	/*
	~Bloc() {
		delete[] adresa;
	}
	*/

	//Functie de citire
	void citire() {
		//tot pt adresa char*
		/*
		char buffer[100];//buffer temporar pt a citi intreaga adresa de la tastatura(pana la 100 de caractere
		cout << "Introduceti adresa apartamentului: ";
		cin.getline(buffer, 100);//getline pt a citi o linie intreaga
		adresa = new char[strlen(buffer) + 1];
		strcpy_s(adresa, strlen(buffer) + 1, buffer);*/
		
		cout << "Introduceti adresa:";
		cin.ignore();
		getline(cin,this->adresa);

		cout << "Introduceti numarul de scari:";
		cin >> this->nrScari;
		
		cout << "Introduceti numarul de apartamente:";
		cin >> this->nrApt;

		cout << "Introduceti numarul de etaje al blocului:";
		cin >> this->etajMax;
	}

	//Functie de afisare
	void afisare() {
		cout << "Adresa blocului este: " << this->adresa<<" si are un numar de: "<< this->nrScari << " scari, " << this->nrApt << " apartamente, iar etajul maxim este: "<< this->etajMax<< endl;
	}
};
int main() {
	//Creez vectorul de blocuri
	int nrBl = 2;
	Bloc* blocuri = new Bloc[nrBl];

	//Functia de citire 
	for (int i = 0; i < nrBl; i++) {
		cout << "Introduceti informatiile necesare pentru blocul " << i + 1 << " : " << endl;
		blocuri[i].citire();
	}
	//Functia de afisare
	for (int i = 0; i < nrBl; i++) {
		blocuri[i].afisare();
	}
	//Eliberam memoria alocata dinamic pt vectorul de blocuri
	delete[] blocuri;

	return 0;
} 
