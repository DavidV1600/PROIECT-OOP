#ifndef ECHIPA_H
#define ECHIPA_H
#include "Jucator.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;
class Echipa
{
private:
    char nume[20];
    int numar_membri;
    int elo_echipa;
    int puncte;
    int tip_Echipa;
    vector<std::shared_ptr<Jucator>>Membrii;

public:
    void set_Nume(const char text[])
    {
        strcpy_s(nume, text);
    }
    void set_Numar_Membri(int nr)
    {
        numar_membri = nr;
    }
    void set_Elo_Echipa(int elo)
    {
        elo_echipa = elo;   ///SETTERI
    }
    void set_Puncte(const int x)
    {
        puncte = x;
    }

    void Calculeaza_Medie(); ///calculez media jucatorilor
    void Add_Membru(const Jucator&); ///bag membru
    void Sterge_Jucator(const Jucator& jucatorDeSters);
    void Citire_Nume_Echipa()///cre ca o so scot
    {
        cout << "Introdu Numele Urmatoarei Echipei: ";
        cin.getline(nume, 20);
    }

    const char* get_Nume()const
    {
        return nume;
    }
    const int get_Numar_Membri()const
    {
        return numar_membri;
    }
    const int get_Elo_Echipa()const
    {
        return elo_echipa;   ///GETTERI
    }
    const vector<std::shared_ptr<Jucator>> get_Membrii()const
    {
        return Membrii;
    }
    const int get_Puncte()const
    {
        return puncte;
    }

    Echipa(const char nume_1[] = "", int nr_membri = 0, int echipa_elo = 0, int puncte1 = 0,int tip_Echipa1=0); ///CONSTRUCTOR
    Echipa(int tip);
    Echipa(const Echipa&); ///Constructor de copiere
    ~Echipa(); ///Destructor
    void Sortare_Echipa();

    bool operator < (const Echipa&);
    bool operator ==(const Echipa&)const;
    Echipa& operator=(const Echipa&); ///Operatorul =
    friend ostream& operator<<(ostream&, Echipa&); ///Afisare
    friend istream& operator>>(istream&, Echipa&); ///Citire
    void Gaseste_Pozitia_In_Echipa(const Jucator&);
    void Inverseaza_Ordinea_Jucatorilor();///Pentru Vizualizare de la cel mai bun la cel mai slab si invers
};

#endif // ECHIPA_H

