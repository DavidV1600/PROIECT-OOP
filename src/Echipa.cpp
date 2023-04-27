#include <iostream>
#include <fstream>
#include "Echipa.h"
#include "Jucator_Sah.h"
#include "Jucator_Tenis.h"
#include <memory>
using namespace std;




Echipa::Echipa(const char nume_1[], int nr_membri, int echipa_elo, Jucator* Membru, int puncte1,int tip_Echipa1) ///Constructorul
{
    strcpy(nume, nume_1);
    numar_membri = nr_membri;
    elo_echipa = echipa_elo;
    puncte = puncte1;
    Membri = Membru;
    tip_Echipa = tip_Echipa1;
}

Echipa::Echipa(int tip)
{
    strcpy(nume, "");
    numar_membri = 0;
    elo_echipa = 0;
    puncte = 0;
    Membri = nullptr;
    tip_Echipa = tip;
}

void Echipa::Calculeaza_Medie() ///Calculez Media
{
    int suma = 0;
    if (numar_membri != 0)
    {
        for (int i = 0; i < numar_membri; ++i)
            suma += Membri[i].get_Elo();///SA MODIFIC MEMBRII cu 2 i
        try {
            elo_echipa = suma / numar_membri;
        }
        catch (exception& e)
        {
            throw("Nu poti Imparti la 0!\n");
        }
    }
}

void Echipa::Add_Membru(const Jucator& Gicu) ///Adaug Membru
{
    try {
        numar_membri++;
        Jucator* temp;
        temp = new Jucator[numar_membri];
        for (int i = 0; i < numar_membri - 1; ++i)
            temp[i] = Membri[i];
        temp[numar_membri - 1] = Gicu;            ///Salvez in variabla temporara ca nus sa dau realoc
        delete[]Membri;
        Membri = temp;
    }
    catch (bad_alloc& e)
    {
        cerr << "Alocare de memorie invalida:" << e.what() << '\n';
    }
    std::shared_ptr<Jucator> p = std::make_shared<Jucator>(Membri[numar_membri - 1]);
    Membrii.push_back(p);
    Calculeaza_Medie();
}

void Echipa::Sterge_Jucator(const Jucator& jucatorDeSters)
{

    const char* prim = jucatorDeSters.get_Cnp();
    int pozitieDeSters = -1;
    for (int i = 0; i < numar_membri; i++)
    {
        const char* prim2 = Membri[i].get_Cnp();

        if (strcmp(prim, prim2) == 0)
        {
            pozitieDeSters = i;
            break;
        }
    }
    if (pozitieDeSters == -1)
    {
        cout << "Nu s-a gasit jucatorul de sters\n";
        return;
    }

    Jucator* MembriNoi = new Jucator[numar_membri - 1];

    // Copiem jucatorii in vectorul nou, fara jucatorul de sters
    int k = 0;
    for (int i = 0; i < numar_membri; i++)
    {
        if (i != pozitieDeSters)
        {
            MembriNoi[k] = Membri[i];
            k++;
        }
    }

    numar_membri--;
    delete[] Membri;
    Membri = MembriNoi;
    Calculeaza_Medie();
}



Echipa::Echipa(Echipa& Gicu) ///Constructor de copiere
{

    strcpy(nume, Gicu.nume);///de ce la construcorul de copiere nu imi recomanda scriptul???
    numar_membri = Gicu.numar_membri;
    puncte = Gicu.puncte;
    elo_echipa = Gicu.elo_echipa;
    try {
        Membri = new Jucator[numar_membri];
    }
    catch (bad_alloc& e)
    {
        cerr << "Alocare de memorie invalida: " << e.what() << '\n';
    }
    for (int i = 0; i < numar_membri; ++i)
        Membri[i] = Gicu.Membri[i];
    for (int i = 0; i < Gicu.Membrii.size(); ++i)
    {
        Membrii[i] = Gicu.Membrii[i];
    }
}

Echipa::~Echipa()
{
    delete[]Membri;
}

Echipa& Echipa::operator=(const Echipa& Gicu) ///Operatorul de =
{
    if (this != &Gicu)
    {
        delete[] Membri; // sterg valoarea veche
        numar_membri = Gicu.numar_membri;
        elo_echipa = Gicu.elo_echipa;
        puncte = Gicu.puncte;
        strcpy(nume, Gicu.nume);
        try {
            Membri = new Jucator[numar_membri];
        }
        catch (bad_alloc& e)
        {
            cerr << "Alocare de memorie invalida: " << e.what()<<'\n';
        }
        for (int i = 0; i < numar_membri; ++i)
            Membri[i] = Gicu.Membri[i];
    }
    return *this;
}

ostream& operator<<(ostream& out, Echipa& Gicu)///Afisare
{
    Gicu.Calculeaza_Medie();
    out << "Nume Echipa: " << Gicu.nume << '\n' << "Puncte: " << Gicu.get_Puncte() << '\n' << "Elo Echipa: " << Gicu.elo_echipa << '\n' << "Numar Membri: " << Gicu.numar_membri << '\n' << "Membri: ";
    int i;
    for (i = 0; i < Gicu.numar_membri - 1; ++i)
        out << Gicu.Membri[i].get_Nume() << ", ";
    out << Gicu.Membri[i].get_Nume();
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
    try {
        Gicu.Membri = new Jucator[Gicu.numar_membri];
    }
    catch (bad_alloc& e)
    {
        cerr << "Alocare de memorie invalida: " << e.what() << '\n';
    }
    for (int i = 0; i < Gicu.numar_membri; ++i)
    {
        cout << '\n' << "Membrul " << i + 1 << ":\n";
        if(Gicu.tip_Echipa==0){
            in >> Gicu.Membri[i];
        }
        else if (Gicu.tip_Echipa == 1)
        {
            Jucator_Sah Juc;
            in >> Juc;
            std::shared_ptr<Jucator>Juc2 = std::make_shared<Jucator>(Juc);
            Gicu.Membrii.push_back(Juc2);
            Gicu.Membri[i].set_Elo(Juc.get_Elo());
        }
        else if (Gicu.tip_Echipa == 2)
        {
            Jucator_Tenis Juc;
            in >> Juc;
            std::shared_ptr<Jucator>Juc2 = std::make_shared<Jucator>(Juc);
            Gicu.Membrii.push_back(Juc2);
            Gicu.Membri[i].set_Elo(Juc.get_Elo());
        }
    }
    Gicu.Calculeaza_Medie();
    cout << '\n';
    return in;
}

