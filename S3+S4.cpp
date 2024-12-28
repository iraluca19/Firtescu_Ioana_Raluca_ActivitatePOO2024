#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//Variabila de tip static o stocam in alta zona de memorie a clasei;=> pt a ocupa mai putina memorie 
// Un atribut static e un atribut care tine de clasa
//Variabila const nu se modifica


class Magazin {
	//Abstractizare
private:
	string oras;
	int nrAngajati;//
	float* salarii;
	float suprafata;//
	const int anDeschidere; 
	static int impozitM2;

public:
	//Def Constructor fara parametri: initializeaza atributele unui obiect 
		//Lista de initializare constructor (pt const) + pot fi declarate si celelalte atribute aici, nefiind nevoie neaparat de alocarile cu this
	Magazin() : anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}
	//Constructor cu parametri
	//De preferat atributele isi pastreaza denumirea
	Magazin(string oras, int nrAngajati, float suprafata, int an) : anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
		{
			this->salarii[i] = 2000 + i;
		}
	}

	//Constructor de copiere 
	// Dupa ":" lista de initializare a constructorului 
	Magazin(const Magazin& m) : anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		//De ce nu dezalocam?-Se reeaza un obiect nou si nu dezalocam ("m")
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++)
		{
			this->salarii[i] = m.salarii[i];
		}
		this->salarii = m.salarii;

	}


	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Numar angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << this->impozitM2 << endl;
	}
	float calculeazaSuprafataMedie()
	{
		if (this->nrAngajati != 0)
		{
			return this->suprafata / this->nrAngajati;
		}
		else return 0;
	}

	static void modificaImpozit(int impozit) {	//impozit variabila a functiei
		if (impozit > 0) //validare a valorii
			Magazin::impozitM2 = impozit;
	}
	//primim vectorul de magazine
	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++)
			suma += vector[i].suprafata;
		return suma;
	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	//Get-erii nu primesc parametri
	int getNrAngajati()
	{
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++)
			{
				this->salarii[i] = salarii[i];
			}
		}
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafataNoua) {
		if (suprafataNoua > 0)
			this->suprafata = suprafataNoua;
	}

	float* getSalarii()
	{
		return this->salarii;
	}
	//!! exceptie pt indexare get primeste parametru
	float getSalariu(int index) {
		if (index >= 0 && this->nrAngajati) {
			return this->salarii[index];
		}
	}


};

int Magazin::impozitM2 = 2;

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

//initializarea unui atribut static
//const se initializeaza fix atunci cand se creeaza ob clasei magazin
//impozitul nu tine de zona de memorie a obicetului de aceea nu-l folosim

	//Metoda afisare 
//void nu mai primeste parametri pentru ca avem this-ul;

int main() {
	Magazin m1;
	cout << m1.getNrAngajati() << endl;
	m1.setNrAngajati(6, new float[6] {2, 5, 4, 8, 6, 3});
	cout << m1.getNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1] << endl;//indexare cu []
	cout << m2.getSalariu(1) << endl;//indexarea a fost facuta in getter 
	m2.setNrAngajati(5, new float[5] {5, 8, 3, 9, 4});//initializare in line

	cout << m2.getSalariu(4) << endl;

	Magazin* vector = new Magazin[100];//Constructorul implicit va fi apelat de 100 de ori
	//
	delete[]vector;
	Magazin m3(m2);
	Magazin m4 = m2;

	return 219421;


}


//!! Cand avem variabile care depind unele de altele facem un sett-er compus 
//Cum declaram un vector ale carui elemente vor fi stocate in HEAP?
//Facem functia de calcul a suprafetei totale inafara clasei deoarece depinde de mai multe obiecte, nu de unul singur
//Putem face si functii statice

//main S3 
/*
Magazin m1;
m1.afisare();
Magazin::modificaImpozit(3);//prin clasa
m1.modificaImpozit(4);//prin obiect

//Recomandat prin interiorul clasei

//Apelare prin constructorul cu parametri
Magazin m2("Iasi", 7, 200, 2019);
m2.afisare();
Magazin* pointer = new Magazin("Timisoara", 4, 120, 2022);// Mi-am alocat spatiu pt un magazin in HEAP
pointer->afisare();
//dereferentiere prin "->" +accesare
//pt a apela prin pointer folosim operatorul de dereferentiere
cout << "Suprafata medie per angajat este de:" << pointer->calculeazaSuprafataMedie();

//initializam o variabila
//imi va executa constructorul cu parametri de 3 ori creand atatea obiecte cate au fost alocate in variabila corespunzatoare asociata
int nrMagazine = 3; //initiaizam nr de obiecte dorit pentru vectorul de obiecte
Magazin* vector = new Magazin[nrMagazine];

//pt afisarea celor 3 magazine
//[ ]=indexarea - face deplasare +dereferentiere
for (int i = 0; i < nrMagazine; i++) {
	//am facut dereferentierea deja, asa ca am ramas doar cu accesarea
		//(*(vector + i)).afisare();//deplasare=dereferentiere+accesare separat
		//(vector + i)->afisare();
	vector[i].afisare();
	cout << "Suprafata totala:" << Magazin::calculeazaSuprafataTotala(vector, nrMagazine) << endl;
	delete[]vector;
	delete pointer;
}

*/

//duarat de viata a unui ob se termina atunci cand se termina blocul se executie (IN CAZUL NOSTRU MAIN UL)