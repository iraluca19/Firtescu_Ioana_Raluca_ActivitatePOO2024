/*
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

//Alegeți trei obiecte din realitate.Cele trei obiecte trebuie să fie din același domeniu.
//Pentru cele trei obiecte realizați trei clase care să conțină atribute specifice fiecărui obiect în parte.
//În cele trei clase trebuie să aveți atribute normale, atribute statice și atribute constante.Atributele le definiți în zona publică a clasei.În fiecare clasă trebuie să aveți cel puțin un pointer pentru care veți aloca spațiu in HEAP.
//Realizați pentru fiecare clasă cel puțin 3 constructori cu număr diferit de parametri(în total vor fi 9 constructori).În cadrul constructorilor inițializați toate atributele claselor.Aveți grija la inițializarea atributelor constante și a atributelor statice.
//În fiecare clasă realizați câte o funcție statică pentru orice tip de procesare sau calcul.
//În funcția main creați, inițializați și afișați câte trei obiecte de tipul fiecărei clase, astfel încât să apelați toți constructorii.
//Realizati toate clasele in acelasi fisier CPP, una sub cealalta, iar in partea de final a fisierului cu cod sursa implementati functia main in cadrul careia testati toti constructorii implementati pentru clasele implementate.

//Obiecte: IPod, Casti, CDPlayer
class IPod {
public:
	//atribute normale
	string culoare;
	int capacitateMem;
	float versiuneSoft;
	int oreIncarcare;//

	//atribute constante
	const int anFabricatie;

	//atribute statice
	static int nrIPoduri;

	//atribut dinamic
	int* baterie;

	//Constructorul implicit
	IPod() :anFabricatie(2015) {
		this->culoare = "nespecificat";
		this->capacitateMem = 32;
		this->versiuneSoft = 1.0;
		this->oreIncarcare = 3;
		this->baterie = NULL;
		nrIPoduri++;

	}

	//Constructorul cu parametri
	IPod(string culoare, int capacitateMem, float versiuneSoft, int oreIncarcare, int an) : anFabricatie(an) {
		this->culoare = culoare;
		this->capacitateMem = capacitateMem;
		this->versiuneSoft = versiuneSoft;
		this->oreIncarcare = oreIncarcare;
		this->baterie = new int[oreIncarcare];
		for (int i = 0; i < oreIncarcare; i++)
		{
			this->baterie[i] = 5 + i;
		}
		nrIPoduri++;
	}
	//Constructorul de copiere-idem cu constructorul cu parametri-SE PUNE REFERINTA.ATRIBUT dupa egal
	IPod(const IPod& p) : anFabricatie(p.anFabricatie) {
		this->culoare = p.culoare;
		this->capacitateMem = p.capacitateMem;
		this->versiuneSoft = p.versiuneSoft;
		this->oreIncarcare = p.oreIncarcare;
		this->baterie = new int[p.oreIncarcare];
		for (int i = 0; i < p.oreIncarcare; i++)
		{
			this->baterie[i] = p.baterie[i];
		}
		nrIPoduri++;
	}

	//Functie statica pentru afisarea numarului total de IPoduri
	static void afisareIPoduri() {
		cout << "Numarul total de IPoduri create este: " << nrIPoduri << endl;
	}

	//Destructor
	~IPod()
	{
		if (this->baterie != NULL)
		{
			delete[]this->baterie;
		}
	}
};
//Initializare atribut static
int IPod::nrIPoduri = 0;

class Casti {
public:
	//atribute normale
	string tip;//in-ear, over-ear
	string brand;
	bool wireless;
	int capacitate_audio;//

	//atribute constante
	const int anLansare;

	//atribute dinamice
	int* volum;

	//atribute statice
	static int nrCasti;

	//Constructorul implicit
	Casti() :anLansare(2023) {
		this->tip = "in-ear";
		this->brand = "necunoscut";
		this->wireless = true;
		this->volum = NULL;
		nrCasti++;
	}
	//Constructorul cu parametri
	Casti(string tip, string brand, bool wireless, int capacitate_audio, int data) :anLansare(data) {
		this->tip = tip;
		this->brand = brand;
		this->wireless = wireless;
		this->capacitate_audio = capacitate_audio;
		this->volum = new int[capacitate_audio];
		for (int i = 0; i < capacitate_audio; i++)
		{
			this->volum[i] = 10 + i;
		}
		nrCasti++;
	}
	//Constructorul de copiere
	Casti(const Casti& c) :anLansare(c.anLansare) {
		this->tip = c.tip;
		this->brand = c.brand;
		this->wireless = c.wireless;
		this->capacitate_audio = c.capacitate_audio;
		this->volum = new int[c.capacitate_audio];
		for (int i = 0; i < c.capacitate_audio; i++)
		{
			this->volum[i] = c.volum[i];
		}
		nrCasti++;
	}

	// Funcție statică pentru afișarea numărului total de căști
	static void afisareCasti() {
		cout << "Numar total de casti create: " << nrCasti << endl;
	}

	//Destructor
	~Casti() {
		if (this->volum != NULL) {
			delete[]this->volum;
		}
	}

};

//Initializare atribut static
int Casti::nrCasti = 0;

class CDPlayer {
public:
	//atribute normale
	string marca;
	bool portabil;
	int capacitateCD;
	int incarcare;//

	//atribute constante
	const int anProductie;

	//atribute dinamice
	int* nivelBaterie;

	//atribute statice
	static int nrPlayere;

	//Constructorul implicit
	CDPlayer() :anProductie(2024) {
		this->marca = "general";
		this->portabil = false;
		this->capacitateCD = 1;
		this->nivelBaterie = NULL;
		nrPlayere++;
	}

	//Constructorul cu parametri
	CDPlayer(string marca, bool portabil, int capacitateCD, int incarcare, int data_prod) :anProductie(data_prod) {
		this->marca = marca;
		this->portabil = portabil;
		this->capacitateCD = capacitateCD;
		this->incarcare = incarcare;
		this->nivelBaterie = new int[incarcare];
		for (int i = 0; i < incarcare; i++) {
			this->nivelBaterie[i] = 1 + 5 * i;
		}
		nrPlayere++;
	}

	//Constructorul de copiere
	//Constructorul cu parametri
	CDPlayer(const CDPlayer& p) :anProductie(p.anProductie) {
		this->marca = p.marca;
		this->portabil = p.portabil;
		this->capacitateCD = p.capacitateCD;
		this->incarcare = p.incarcare;
		this->nivelBaterie = new int[p.incarcare];
		for (int i = 0; i < p.incarcare; i++) {
			this->nivelBaterie[i] = p.nivelBaterie[i];
		}
		nrPlayere++;
	}
	//// Funcție statică pentru afișarea numărului total de playere
	static void afisareCDPlayere() {
		cout << "Numar total de CDPlayere create: " << nrPlayere << endl;
	}

	//Destructorul
	~CDPlayer() {
		if (this->nivelBaterie != NULL) {
			delete[]this->nivelBaterie;
		}
	}
};

//Initializare atribut static
int CDPlayer::nrPlayere = 0;

int main()
{
	//Testare IPod
	IPod i1; //constructor implicit
	IPod i2("rosu", 64, 2.1, 3, 2021);//constructor cu parametri
	IPod i3(i2);//Constructor de copiere
	cout << "IPod 1: Model=" << i1.culoare << ", Capacitate=" << i1.capacitateMem << "GB, Versiune Software=" << i1.versiuneSoft << endl;
	cout << "IPod 2: Model=" << i2.culoare << ", Capacitate=" << i2.capacitateMem << "GB, Versiune Software=" << i2.versiuneSoft << endl;
	IPod::afisareIPoduri();

	// Testare clasa Casti
	Casti c1;
	Casti c2("in-ear", "Sony", true, 100, 2023);
	Casti c3(c2);

	cout << "Casti 1: Tip=" << c1.tip << ", Brand=" << c1.brand << ", Wireless=" << (c1.wireless ? "Da" : "Nu") << endl;
	cout << "Casti 2: Tip=" << c2.tip << ", Brand=" << c2.brand << ", Wireless=" << (c2.wireless ? "Da" : "Nu") << endl;
	Casti::afisareCasti();

	// Testare clasa CDPlayer
	CDPlayer CD1;
	CDPlayer CD2("Philips", true, 2, 100,2022);
	CDPlayer CD3(CD2);

	cout << "CDPlayer 1: Marca=" << CD1.marca << ", Portabil=" << (CD1.portabil ? "Da" : "Nu") << ", CapacitateCD=" << CD1.capacitateCD << endl;
	cout << "CDPlayer 2: Marca=" << CD2.marca << ", Portabil=" << (CD2.portabil ? "Da" : "Nu") << ", CapacitateCD=" << CD2.capacitateCD << endl;
	CDPlayer::afisareCDPlayere();

	return 0;
}
*/