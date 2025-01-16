#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <numeric>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
//#include <>
using namespace std;

	class Librarie {
	public:
		string nume;

	//public:

		Librarie() {
			this->nume = "Mihai Eminescu";
		}
		Librarie(string nume) {
			this->nume = nume;
		}
		// Cand avem cel putin o functie virtuala se initializeaza o tabela de pointeri la functiile virtuale 
		//Virtualizarea permite realizarea asa numitului late-binding 
		virtual string getDenumire() {
			return nume;
		}
	};

	//Mostenire
	class LibrarieOnline : public Librarie {
	public:
		string site;
		LibrarieOnline() :Librarie("Librarie Online"){
			this->site = "www.site.ro";
		}
		LibrarieOnline(string nume, string site): Librarie(nume) {
			this->site = site;
		}
		string getDenumire() {
			return nume + "-" + site;
		}
	};
	int main(){
		LibrarieOnline lo("Libris", "libris.ro");
			cout << lo.getDenumire()<<endl;
			Librarie* lib = new LibrarieOnline("Humanitas", "humanitas.ro");
			cout << lib->getDenumire() << endl;

			vector <float>v;
			v.push_back(1.2);
			v.push_back(4.5);
			v.push_back(3.7);
			v.push_back(5.9);
			float s=0;
			for (int i = 0; i < v.size(); i++) {
				s += v[i];
				cout << s<<endl;
			}
			if (v.size() > 0) {
				cout << "Media este: " << s / v.size() << endl;
			}
			else
			{
				cout << "Media este 0." << endl;
			}
			for (int i = 0; i < v.size(); i++)
				cout << v[i]<<" ";
			float suma = accumulate(v.begin(), v.end(), 0);

			//Lista de librarii
			//se adauga cu push_back sau push_front

			list <Librarie*> lista;
			lista.push_front(new Librarie());
			lista.push_front(new Librarie("Carturesti"));
			lista.push_front(new LibrarieOnline("Bookzone", "bookzone.ro"));
			lista.push_back(new LibrarieOnline());
			//ca sa ne declaram un obiect de tipul clasei imbricate 
			list <Librarie*> ::iterator it = lista.begin();
			while (it != lista.end()) {
				cout<<(*it)->getDenumire() << endl;
				it++;
			}
			//Map si set sunt asociative 
			//Neaparat INSERT pt adaugarea de elemente
			map<int, Librarie> librarii;
			librarii.insert(pair<int, Librarie>(1, Librarie()));
			librarii.insert(pair<int, Librarie>(27, Librarie("Carturesti")));
			librarii.insert(pair<int, Librarie>(3, Librarie("Libris")));
			librarii.insert(pair<int, Librarie>(23, Librarie("Humanitas")));
			librarii.insert(pair<int, Librarie>(3, Librarie("Mihail Sadoveanu")));
			cout << librarii[23].getDenumire() << endl;
			map<int, Librarie>::iterator iterator=librarii.begin();
			cout << "Afisare Map: " << endl;
			while (iterator != librarii.end())
			{
				cout << iterator->first<<" - ";
				cout << iterator->second.getDenumire()<<endl;
				iterator++;
			}
			




	return 2139;
	}