#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Turneu_Tenis.h"
using namespace std;

Turneu_Tenis::Turneu_Tenis(const char data_start[], const char data_finish[],
	const char nume_O[], const char email_O[],
	const char telefon_O[], const char loc[], int varsta_Max, int clasament_Max, int clasament_Min) :Turneu(), varsta_Maxima(varsta_Max), clasament_Maxim(clasament_Max), clasament_Minim(clasament_Min)
{
	strcpy(locatie, loc);
	strcpy(data_Inceperii, data_start);
	strcpy(data_Terminarii, data_finish);
	strcpy(nume_Organizator, nume_O);
	strcpy(email_Organizator, email_O);
	strcpy(telefon_Organizator, telefon_O);

}

Turneu_Tenis::Turneu_Tenis(const Turneu_Tenis& Gicu) : Turneu(Gicu)
{
	clasament_Maxim = Gicu.clasament_Maxim;
	clasament_Minim = Gicu.clasament_Minim;
	varsta_Maxima = Gicu.varsta_Maxima;
	strcpy(locatie, Gicu.locatie);
	strcpy(data_Inceperii, Gicu.data_Inceperii);
	strcpy(data_Terminarii, Gicu.data_Terminarii);
	strcpy(nume_Organizator, Gicu.nume_Organizator);
	strcpy(email_Organizator, Gicu.email_Organizator);
	strcpy(telefon_Organizator, Gicu.email_Organizator);
}


Turneu_Tenis& Turneu_Tenis::operator=(const Turneu_Tenis& Gicu)
{
	if (this != &Gicu) {
		clasament_Maxim = Gicu.clasament_Maxim;
		clasament_Minim = Gicu.clasament_Minim;
		varsta_Maxima = Gicu.varsta_Maxima;
		strcpy(locatie, Gicu.locatie);
		strcpy(data_Inceperii, Gicu.data_Inceperii);
		strcpy(data_Terminarii, Gicu.data_Terminarii);
		strcpy(nume_Organizator, Gicu.nume_Organizator);
		strcpy(email_Organizator, Gicu.email_Organizator);
		strcpy(telefon_Organizator, Gicu.email_Organizator);
	}
	return *this;
}

void Turneu_Tenis::Incepe_Turneu()
{
	///Urmeaza sa implementez
	std::cout << "Sunt in clasa Tenis cand urmeaza sa implementez turneul de tenis\n";
}

void Turneu_Tenis::Sortare_Echipe_Inaintea_Rundei()
{
	for (int i = 0; i < nr_Echipe_actual - 1; ++i)
		for (int j = i + 1; j < nr_Echipe_actual; ++j)
		{
			if (Echipe[i].get_Puncte() < Echipe[j].get_Puncte())
			{
				Echipa temp = Echipe[i];
				Echipe[i] = Echipe[j];
				Echipe[j] = temp;
			}
			else if (Echipe[i].get_Puncte() == Echipe[j].get_Puncte() && Echipe[i].get_Elo_Echipa() < Echipe[j].get_Elo_Echipa()) {
				Echipa temp = Echipe[i];
				Echipe[i] = Echipe[j];
				Echipe[j] = temp;
			}

		}
}

void Turneu_Tenis::Editare_Turneu()
{
    int tasta;
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce \n";
    std::cout << "Apasa [1] pentru a adauga echipa\n";
    std::cout << "Apasa [2] pentru a sterge echipa\n";
    std::cout << "Apasa [3] schimba numele turneului\n";
    std::cout << "Apasa [4] schimba taxa de participare\n";
    std::cout << "Apasa [5] pentru a schimba premiul total\n";
    std::cout << "Apasa [6] pentru a schimba numarul de echipe admis\n";
    std::cout << "Apasa [7] pentru a schimba numarul de runde\n";
    std::cout << "Apasa [8] pentru a incepe turneul\n";  ///Aci tre sa vad ce fct bag
    std::cout << "---------------------------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();

    switch (tasta)
    {
    case 0:
        break;
    case 1: {
        Echipa b;
        std::cin >> b;
        this->add_Echipa(b);
        this->Editare_Turneu();
        break;
    }
    case 2: {
        this->Stergere_Echipa();///Aci trebe functie
        this->Editare_Turneu();
        break;
    }
          break;
    case 3: {
        char nume_nou[30];
        std::cout << "Introdu numele nou: ";
        std::cin >> nume_nou;
        this->set_nume_Turneu(nume_nou);
        this->Editare_Turneu();
        break; }
    case 4:
        std::cout << "Introdu taxa de participare noua: ";

        std::cin >> tasta;
        std::cin.get();
        this->set_taxa_Participare(tasta);
        this->Editare_Turneu();
        break;
    case 5:
        std::cout << "Introdu noul premiu total: ";

        std::cin >> tasta;
        std::cin.get();
        this->set_premiu_Total(tasta);
        this->Editare_Turneu();
        break;
    case 6:
        std::cout << "Introdu noul nr maxim de echipe admis: ";

        std::cin >> tasta;
        std::cin.get();
        this->set_nr_Maxim_Echipe(tasta);
        this->Editare_Turneu();
        break;
    case 7:
        std::cout << "Introdu noul nr de runde: ";

        std::cin >> tasta;
        std::cin.get();
        this->set_nr_Runde(tasta);
        this->Editare_Turneu();
        break;
    case 8:
        this->Sortare_Echipe_Inaintea_Rundei();
        this->Incepe_Turneu();
        this->Editare_Turneu();
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        this->Editare_Turneu();
        break;
    }
}

void Alegere_Turneu_Tenis(std::vector<std::shared_ptr<Turneu>>Lista_Turnee_Tenis)
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Tenis.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Tenis[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Tenis.size())
    {
        Lista_Turnee_Tenis[tasta - 1]->Editare_Turneu();
    }
    else if (tasta == 0)
        return;
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu(Lista_Turnee_Tenis);
    }
}

void Turneu_Tenis::Citire_Turneu(istream& in)
{
    this->Turneu::Citire_Turneu(in);
    in.get();
    cout << "Introdu data inceperii (zi-luna-an):";
    in.getline(data_Inceperii, 20);
    cout << "Introdu data finalizarii (zi-luna-an):";
    in.getline(data_Terminarii, 20);
    cout << "Introdu numele Organizator: ";
    in.getline(nume_Organizator, 30);
    cout << "Introdu email Organizator: ";
    in.getline(email_Organizator, 30);
    cout << "Introdu telefon organizator: ";
    in.getline(telefon_Organizator, 11);
    cout << "Introdu locatia turneului: ";
    in.getline(locatie, 30);
    in.get();
    cout << "Introdu varsta maxima admisa: ";
    in >> varsta_Maxima;
    cout << "Introdu clasamentul ATP maxim admis: ";
    in >> clasament_Maxim;
    cout << "Introdu clasamentul ATP minim admis: ";
    in >> clasament_Minim;
    in.get();
    nr_Echipe_actual = 0;
}
