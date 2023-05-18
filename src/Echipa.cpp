#include <iostream>
#include <fstream>
#include "Echipa.h"
#include "Jucator_Sah.h"
#include "Jucator_Tenis.h"
#include "Sortari.h"
#include <memory>
#include <algorithm>
using namespace std;




Echipa::Echipa(const char nume_1[], int nr_membri, int echipa_elo, int puncte1,int tip_Echipa1) ///Constructorul
{
    strcpy(nume, nume_1);
    numar_membri = nr_membri;
    elo_echipa = echipa_elo;
    puncte = puncte1;
    tip_Echipa = tip_Echipa1;
}

Echipa::Echipa(int tip)
{
    strcpy(nume, "");
    numar_membri = 0;
    elo_echipa = 0;
    puncte = 0;
    tip_Echipa = tip;
}

void Echipa::Calculeaza_Medie() ///Calculez Media
{
    int suma = 0;

    for (int i = 0; i < numar_membri; ++i)
       suma += Membrii[i]->get_Elo();///SA MODIFIC MEMBRII cu 2 i
     try{
         if (!numar_membri)
             throw runtime_error("Can't divide by 0");
        elo_echipa = suma / numar_membri;
     }
     catch (exception& e)
     {
        throw("Nu poti avea 0 membri!\n");
     }
}

void Echipa::Add_Membru(const Jucator& Gicu) ///Adaug Membru
{
    try {
        numar_membri++;
        Membrii.push_back(std::make_shared<Jucator>(Gicu));
    }
    catch (bad_alloc& e)
    {
        cerr << "Alocare de memorie invalida:" << e.what() << '\n';
    }
    Calculeaza_Medie();
    this->Sortare_Echipa();
}

void Echipa::Sterge_Jucator(const Jucator& jucatorDeSters)
{
    int sa_gasit = 0;
    const char* prim = jucatorDeSters.get_Cnp();
    for (int i = 0; i < numar_membri; i++)
    {
        const char* prim2 = Membrii[i]->get_Cnp();

        if (strcmp(prim, prim2) == 0)
        {
            sa_gasit = 1;
            Membrii.erase(Membrii.begin() + i);
            break;
        }
    }
    if ( sa_gasit == 0)
    {
        cout << "Nu s-a gasit jucatorul de sters\n";
        return;
    }
    Calculeaza_Medie();
}



Echipa::Echipa(const Echipa& Gicu) ///Constructor de copiere
{
    strcpy(nume, Gicu.nume);///de ce la construcorul de copiere nu imi recomanda scriptul???
    numar_membri = Gicu.numar_membri;
    puncte = Gicu.puncte;
    elo_echipa = Gicu.elo_echipa;
    for (int i = 0; i < Gicu.Membrii.size(); ++i)
    {
        Membrii.push_back(Gicu.Membrii[i]);
    }
}

Echipa::~Echipa()
{
    Membrii.clear();
}

bool Echipa::operator<(const Echipa& A)
{
    if (this->get_Puncte() < A.get_Puncte())
        return true;
    else if (this->get_Puncte() == A.get_Puncte() && this->get_Elo_Echipa() < A.get_Elo_Echipa())
        return true;
    return false;
}

Echipa& Echipa::operator=(const Echipa& Gicu) ///Operatorul de =
{
    if (this != &Gicu)
    {
        Membrii.clear();
        numar_membri = Gicu.numar_membri;
        elo_echipa = Gicu.elo_echipa;
        puncte = Gicu.puncte;
        strcpy(nume, Gicu.nume);
        for (int i = 0; i < numar_membri; ++i)
            Membrii.push_back(Gicu.Membrii[i]);
    }
    return *this;
}

void Echipa::Gaseste_Pozitia_In_Echipa(const Jucator& J)
{
    //sa fac cu find_if ceva compara cu *it<>*it2
        auto it = std::find_if(Membrii.begin(), Membrii.end(),
            [&J](const std::shared_ptr<Jucator>& ptr) {
                return *ptr == J;
            }
        );
        if (it != Membrii.end()) {
            std::cout << "E pe pozitia " << std::distance(Membrii.begin(), it)+1 << '\n';
        }
        else std::cout << "Nu e in echipa\n";

}

void Echipa::Inverseaza_Ordinea_Jucatorilor()
{
    std::reverse(Membrii.begin(), Membrii.end());
}

ostream& operator<<(ostream& out, Echipa& Gicu)///Afisare
{
    Gicu.Calculeaza_Medie();///calculez medie deaia nu e const
    out << "Nume Echipa: " << Gicu.nume << '\n' << "Puncte: " << Gicu.get_Puncte() << '\n' << "Elo Echipa: " << Gicu.elo_echipa << '\n' << "Numar Membri: " << Gicu.numar_membri << '\n' << "Membri: ";
    int i;
    for (i = 0; i < Gicu.numar_membri - 1; ++i)
        out << Gicu.Membrii[i]->get_Nume() << ", ";
    out << Gicu.Membrii[i]->get_Nume();
    out << '\n' << '\n';
    return out;
}

istream& operator>>(istream& in, Echipa& Gicu)///Citire
{
    cout << "Introdu Nume Echipa: ";
    in >> Gicu.nume;
    cout << "Introdu Numarul de Membri: ";
    in >> Gicu.numar_membri;
    in.get();
    for (int i = 0; i < Gicu.numar_membri; ++i)
    {
        cout << '\n' << "Membrul " << i + 1 << ":\n";
        if(Gicu.tip_Echipa==0){
            in >> *Gicu.Membrii[i];
        }
        else if (Gicu.tip_Echipa == 1)
        {
            Jucator_Sah Juc;
            in >> Juc;
            std::shared_ptr<Jucator>Juc2 = std::make_shared<Jucator>(Juc);
            Gicu.Membrii.push_back(Juc2);
        }
        else if (Gicu.tip_Echipa == 2)
        {
            Jucator_Tenis Juc;
            in >> Juc;
            std::shared_ptr<Jucator>Juc2 = std::make_shared<Jucator>(Juc);
            Gicu.Membrii.push_back(Juc2);
        }
    }
    Gicu.Calculeaza_Medie();
    cout << '\n';
    return in;
}

void Echipa::Sortare_Echipa()
{
    Sortare(Membrii, numar_membri);///sa nu mai sterg getterul sa fie const
}

bool Echipa::operator==(const Echipa& E2)const
{
    if (strcmp(this->get_Nume(), E2.get_Nume()) == 0)
        return true;
    return false;
}
