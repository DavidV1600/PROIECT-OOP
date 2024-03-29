#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Turneu.h"
#include "Sortari.h"
using namespace std;

Turneu::Turneu(const int nr_Echipe_actual1,const int nr_Maxim_Echipe1,const int premiu_Total1,const int taxa_Participare1,const int nr_Runde1, const char nume_Turneu1[30])///constructor cu parametri impliciti
{
    nr_Echipe_actual = nr_Echipe_actual1;
    nr_Maxim_Echipe = nr_Maxim_Echipe1;
    premiu_Total = premiu_Total1;
    taxa_Participare = taxa_Participare1;
    nr_Runde = nr_Runde1;
    strcpy(nume_Turneu, nume_Turneu1);

}

Turneu::Turneu(const Turneu& Gicu)///Constructor de copiere
{

    for (int i = 0; i < Gicu.Echipee.size(); ++i)
    {
        Echipee.push_back(Gicu.Echipee[i]);
    }
    for (int i = 0; i < Gicu.Rundee.size(); ++i)
    {
        Rundee.push_back(Gicu.Rundee[i]);
    }
    nr_Maxim_Echipe = Gicu.nr_Maxim_Echipe;
    premiu_Total = Gicu.premiu_Total;
    taxa_Participare = Gicu.taxa_Participare;
    nr_Runde = Gicu.nr_Runde;
    strcpy(nume_Turneu, Gicu.nume_Turneu);
}

void Turneu::add_Echipa(const Echipa& Gicu)///Functie de adaugare Echipe
{
    try {
        nr_Echipe_actual++;
        if (nr_Echipe_actual > nr_Maxim_Echipe)
        {
            throw("Ati depasit numarul maxim de echipe admise!\n");///ASA trebe????
        }
    }catch (exception& e)
    {
        std::cout << e.what();
    }
    Echipee.push_back(Gicu);

}

void Turneu::add_Runda()///Functie de adaugare Runda
{
    nr_Runde++;
}

void Turneu::sterge_Echipa(const Echipa& Gicu)///Functie de stergere Echipe
{
    nr_Echipe_actual--;
    int sa_gasit = 0;

    for (int i = 0; i < Echipee.size(); ++i)
    {
        if (Echipee[i] == Gicu)
        {
            sa_gasit = 1;
            Echipee.erase(Echipee.begin() + i);
            break;
        }
    }
    if (sa_gasit == 0)
        std::cout << "Nu s-a gasit echipa!\n";
}

void Turneu::sterge_Runda()///functie de stergere runda
{
    nr_Runde--;
}

void Turneu::Gasire_Echipa(const Echipa& E)//inca nu merge prea bine
{
    auto it = std::find(Echipee.begin(), Echipee.end(), E);
    if (it != Echipee.end())
        std::cout << "Echipa e pe pozitia " << std::distance(Echipee.begin(), it)+1 << '\n';
    else std::cout << "Echipa nu este in turneu!\n";

}

void Turneu::Intoarce_Clasamentul()
{
    std::reverse(Echipee.begin(), Echipee.end());
}

Turneu::~Turneu()///Destructor
{
    Echipee.clear();
    Rundee.clear();
}

Turneu& Turneu::operator=(const Turneu& Gicu)///redefinire operatorul =
{
    if (this != &Gicu)
    {
        Echipee.clear();
        Rundee.clear();
        nr_Echipe_actual = Gicu.nr_Echipe_actual;
        nr_Maxim_Echipe = Gicu.nr_Maxim_Echipe;
        premiu_Total = Gicu.premiu_Total;
        taxa_Participare = Gicu.taxa_Participare;
        nr_Runde = Gicu.nr_Runde;
        strcpy(nume_Turneu, Gicu.nume_Turneu);
        for (int i = 0; i < Gicu.Echipee.size(); ++i)
        {
            Echipee.push_back(Gicu.Echipee[i]);
        }
        for (int i = 0; i < Gicu.Rundee.size(); ++i)
        {
            Rundee.push_back(Gicu.Rundee[i]);
        }

    }
    return *this;
}

ostream& operator<<(ostream& out, Turneu& Gicu)///redefinire operator << (Afisare Turneu)
{
    Sortare(Gicu.Echipee, Gicu.nr_Echipe_actual);///le sortez aici deaia nu e const
    out << "Clasament:\n";
    for (int i = 0; i < Gicu.nr_Echipe_actual; ++i) {
        out << i + 1 << ".) " << Gicu.Echipee[i].get_Nume() << "  Puncte: " << Gicu.Echipee[i].get_Puncte() << " Elo: " << Gicu.Echipee[i].get_Elo_Echipa() << '\n';
    }
    return out;
}

istream& operator>>(istream& in, Turneu& Gicu)
{

    Gicu.Citire_Turneu(in);
    return in;
}

void Turneu::Citire_Turneu(istream& in)
{
    cout << "Introdu Numele Turneului: ";
    in.getline(nume_Turneu, 30);
    cout << "Cate runde va avea turneul: ";
    in >> nr_Runde;
    cout << "Numarul Maxim de Echipe Admis: ";
    in >> nr_Maxim_Echipe;
    nr_Echipe_actual = 0;
}

void Turneu::Incepe_Turneu()
{
    Rundee.resize(nr_Runde);
    for (int i = 0; i < nr_Echipe_actual; ++i)
    {
        Echipee[i].Calculeaza_Medie();
    }
    cout << *this;
    for (int i = 0; i < nr_Runde; ++i)
    {
        cout << "Rezultate Runda " << i + 1 << '\n';
        Rundee[i].pregateste_Runda(Echipee, nr_Echipe_actual);
        cout << *this;
    }
}

void Turneu::Editare_Turneu()
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
        Sortare(this->Echipee, this->nr_Echipe_actual);
        this->Incepe_Turneu();
        this->Editare_Turneu();
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        this->Editare_Turneu();
        break;
    }
}

void Turneu::Stergere_Echipa()
{
    int tasta;
    std::cout << "-----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < this->get_nr_Echipe_actual(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a sterge echipa: " << this->get_Echipe()[i].get_Nume() << '\n';

    }
    std::cout << "---------------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        this->Editare_Turneu();
    else if (tasta > 0 && tasta <= this->get_nr_Echipe_actual())
        this->sterge_Echipa(this->get_Echipe()[tasta - 1]);
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        this->Stergere_Echipa();
    }

}
void Alegere_Turneu(const std::vector<std::shared_ptr<Turneu>>Lista_Turnee_Create)
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Create.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Create[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Create.size())
    {
        Lista_Turnee_Create[tasta - 1]->Editare_Turneu();
    }
    else if (tasta == 0)
        return;
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu(Lista_Turnee_Create);
    }
}

void Turneu::Sortare_Echipe_Inaintea_Rundei()
{
    Sortare(Echipee, nr_Echipe_actual);///sa nu mai modific getterul sa nu fie const
}

