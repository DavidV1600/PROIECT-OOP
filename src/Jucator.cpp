#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include "Exceptie_Custom.h"
#include "Jucator.h"
#include <cstring>
#include "Jucator_Sah.h"///SA AM GRIJA CA LE AM DOAR PENTRU DYNAMIC CAST
#include "Jucator_Tenis.h"///SA AM ....
#include "Validare.h"
#include <regex>

using namespace std;

void Jucator::set_Cnp(const char text[]) ///definire Setter Cnp
{
    strcpy(cnp, text);
}
void Jucator::set_Nume(const string text) ///definire setter nume
{
    nume = text;
}
void Jucator::set_Prenume(const string text) ///definire setter prenume
{
    prenume = text;
}
void Jucator::set_Varsta(const int a) ///definire setter Varsta
{
    try {
        if (a > 100 || a < 3)
            throw 0;
        varsta = a;
    }
    catch (int i)
    {
        std::cerr << "Varsta Setata este invalida\n";
    }
}
void Jucator::set_Elo(const int a) ///definire setter Elo
{
    try {
        if (a < 0 || a>3300)
            throw 'b';
        elo = a;
    }
    catch (char b)
    {
        std::cerr << "Eloul setat este invalid\n";
    }
}
void Jucator::set_Sex(const int a) ///definire setter Sex
{
    try {
        if (a < 0 || a>1)
            throw 1;
        sex = a;
    }
    catch (int e)
    {
        std::cerr << "Sex setat invalid\n";
    }
}
void Jucator::set_Email(const string text)
{
    email = text;
}
void Jucator::set_NrTelefon(const char text[])
{
    strcpy(nr_Telefon, text);
}

Jucator::Jucator(const char cnp_1[], const char nume_1[], const char prenume_1[], int varsta_1, int sex_1, int elo_1, const char email1[], const char nr_Telefon1[]) ///definire constructor
{
    strcpy(cnp, cnp_1);
    strcpy(nr_Telefon, nr_Telefon1);
    nume = nume_1;
    prenume = prenume_1;
    email = email1;
    varsta = varsta_1;
    sex = sex_1;
    elo = elo_1;
}

Jucator::Jucator(const Jucator& Gicu) ///definire contructor de copiere
{
    strcpy(cnp, Gicu.cnp);
    strcpy(nr_Telefon, Gicu.nr_Telefon);
    nume = Gicu.nume;
    prenume = Gicu.prenume;
    email = Gicu.email;
    varsta = Gicu.varsta;
    sex = Gicu.sex;
    elo = Gicu.elo;
}

Jucator::~Jucator() ///definire destructor
{
    nume.clear();
    prenume.clear();
    email.clear();
}

Jucator& Jucator::operator=(const Jucator& Gicu) ///redefinire operator =
{
    if (this != &Gicu)
    {
        strcpy(cnp, Gicu.cnp);
        strcpy(nr_Telefon, Gicu.nr_Telefon);
        nume = Gicu.nume;
        prenume = Gicu.prenume;
        email = Gicu.email;
        varsta = Gicu.varsta;
        sex = Gicu.sex;
        elo = Gicu.elo;
    }
    return *this;
}

ostream& operator <<(ostream& out, const Jucator& Gicu1)///redefinire operatorul << (Afisare Jucator)
{
    out << "Cnp: " << Gicu1.cnp << '\n' << "Nume si Prenume: " << Gicu1.nume << " " << Gicu1.prenume << '\n' << "Varsta: " << Gicu1.varsta << '\n' << "Sex: ";
    if (Gicu1.sex == 0)
        out << "Feminin" << '\n';
    else
        out << "Masculin" << '\n';
    out << "Elo: " << Gicu1.elo << '\n';
    out << "Email: " << Gicu1.email << '\n';
    out << "Nr Telefon: " << Gicu1.nr_Telefon<<'\n';
    return out;
}

istream& operator >>(istream& in, Jucator& Gicu)///redefinire operator >> (Citire Jucator)
{
    Gicu.Citire_Jucator(in);
    return in;
}

bool operator==(const Jucator& j1, const Jucator& j2)
{
    if (strcmp(j1.get_Cnp(), j2.get_Cnp()) == 0)
        return true;
    return false;
}

void Jucator::Citire_Jucator(istream& in)
{
    char text[100];
    do {
        cout << "Introdu CNP-ul: ";
        in.getline(text, 100);
        strcpy(this->cnp, text);
        if (validare_Cnp(text) == 0)
            cout << "Incercare invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu Nume: ";
        in.getline(text, 100);
        this->nume = text;
        if (validare_Prenume(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    {

    }
    do {
        cout << "Introdu Prenume: ";
        in.getline(text, 100);
        this->prenume = text;
        if (validare_Prenume(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    {

    }
    do {
        cout << "Introdu Email: ";
        in.getline(text, 100);
        this->email = text;
        if (validare_Email(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);

    do {
        cout << "Introdu Numar Telefon: ";
        in.getline(text, 100);
        strcpy(this->nr_Telefon, text);
        if (validare_Nr_telefon(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);

    do {
        cout << "Introdu Varsta: ";
        in >> this->varsta;
        if (this->varsta < 0 || this->varsta > 100)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu Sex (0=F, 1=M): ";
        in >> this->sex;
        if (this->sex != 0 && this->sex != 1)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);

    do {
        cout << "Introdu Elo: ";
        in >> this->elo;
        if (this->elo < 0 || this->elo>3200)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
}

void Jucator::ce_Jucator_E()
{
    Jucator_Tenis* jucator_tenis = dynamic_cast<Jucator_Tenis*>(this);///daca le scot sa scot #includeul
    Jucator_Sah* jucator_sah = dynamic_cast<Jucator_Sah*>(this);///daca le scot sa scot #include
    if (jucator_tenis != nullptr) {
        std::cout << "E Jucator de tenis!\n";
    }
    else if(jucator_sah !=nullptr)
    {
        std::cout << "E Jucator de sah!\n";
    }
    else
    {
        std::cout << "Nu are tip";
    }
}

bool Jucator::operator<(const Jucator& A)
{
    if (elo < A.get_Elo())
        return true;
    return false;
}
