#include<iostream>
using namespace std;
//Variabila de tip static o stocam in alta zona de memorie a clasei;=> pt a ocupa mai putina memorie 
// Un atribut static e un atribut care tine de clasa
//Variabila const nu se modifica


class Magazin {
	//Abstractizare
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;
//Def Constructor default/de copiere: initializeaza atributele unui obiect 
	//Lista de initializare constructor (pt const) + pot fi declarate si celelalte atribute aici, nefiind nevoie neaparat de alocarile cu this
	Magazin() : anDeschidere(2024), nrAngajati(2) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
	}
	//De preferat atributele isi pastreaza denumirea
	Magazin(string oras, int nrAngajati, float suprafata, int an) : anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
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
};


int Magazin::impozitM2 = 2;

//initializarea unui atribut static
//const se initializeaza fix atunci cand se creeaza ob clasei magazin
//impozitul nu tine de zona de memorie a obicetului de aceea nu-l folosim

	//Metoda afisare 
//void nu mai primeste parametri pentru ca avem this-ul;

int main() {
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

	return 219421;


}
//Cum declaram un vector ale carui elemente vor fi stocate in HEAP?
//Facem functia de calcul a suprafetei totale inafara clasei deoarece depinde de mai multe obiecte, nu de unul singur
//Putem face si functii statice


