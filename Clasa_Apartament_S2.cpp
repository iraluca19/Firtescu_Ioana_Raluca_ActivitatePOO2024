#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Apartament {
	char* adresa; //pointer la char!!
	string proprietar;
	int nrCamere;
	float suprafata;

};

void afisareApartament(Apartament* ap) {

	cout << "Adresa:" << ap->adresa << endl;
	cout << "Proprietar:" << ap->proprietar << endl;
	cout << "Numar camere:" << ap->nrCamere << endl;
	cout << "Suprafata:" << ap->suprafata << endl;

}

Apartament citireApartament() {
	Apartament ap;
	cout << "Adresa :";
	char buffer[100];
	cin >> buffer;
	ap.adresa = new char[strlen(buffer) + 1];
	strcpy_s(ap.adresa, strlen(buffer) + 1, buffer);

	cout << "Proprietar: ";
	cin >> ap.proprietar;
	cout << "Numar camere: ";
	cin >> ap.nrCamere;
	cout << "Suprafata: ";
	cin >> ap.suprafata;

	return ap;
}

int main() {

	Apartament ap; //declar pointer
	ap.nrCamere = 3;//accesare elemente

	Apartament* pointer;
	pointer = &ap; //& extrage adresa unui obiect
	pointer = new Apartament();
	pointer->nrCamere = 5; //accesam atribute camere
	pointer->proprietar = "Gigel";
	pointer->adresa = new char[strlen("Bucuresti") + 1];//strlen= calculeaza nr de caractere dintr un sir de caractere
	strcpy_s(pointer->adresa, strlen("Bucuresti") + 1, "Bucuresti");//strcpy=functie cand avem * si dupa strlen; strcpy_s ii spunem cat si cand sa se opreasca
	pointer->suprafata = 120;

	afisareApartament(pointer);
	delete pointer;

	//Apartament v[100]; //alocare statica - deci e alocata in stack(stiva) 

	int nrApartamente = 2;
	Apartament* apartamente;
	apartamente = new Apartament[nrApartamente];
	for (int i = 0; i < nrApartamente; i++) {
		apartamente[i] = citireApartament();
	}

	for (int i = 0; i < nrApartamente; i++) {
		afisareApartament(&(apartamente[i]));
	}

	for (int i = 0; i < nrApartamente; i++) {
		delete[]apartamente[i].adresa;
	}
	delete[]apartamente;

	//Apartament** pointeri;
	//pointeri = new Apartament * [3];


	return 0;

}

//shallow copy - se copiata adresele si nu informatia
//paranteza rotunda aloc spatiu pt un singur apartamente, parant patrate aloc pt mai multe apartamente