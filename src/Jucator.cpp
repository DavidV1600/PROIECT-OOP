#pragma once
#include <iostream>
#include <fstream>
#include <exception>
#include "Exceptie_Custom.h"
#include "Jucator.h"
#include <cstring>
#include "Jucator_Sah.h"///SA AM GRIJA CA LE AM DOAR PENTRU DYNAMIC CAST
#include "Jucator_Tenis.h"///SA AM ....
using namespace std;

void Jucator::set_Cnp(const char text[]) ///definire Setter Cnp
{
    strcpy(cnp, text);
}
void Jucator::set_Nume(const char text[]) ///definire setter nume
{
    int lg = strlen(text);
    nume = new char[lg];
    strcpy(nume, text);
}
void Jucator::set_Prenume(const char text[]) ///definire setter prenume
{
    int lg = strlen(text);
    prenume = new char[lg];
    strcpy(prenume, text);
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
void Jucator::set_Email(const char text[])
{
    int lg = strlen(text);
    try {
        email = new char[lg];
    }
    catch (bad_alloc& e)
    {
        std::cerr << "Ai alocat prost veric\n";
    }
    strcpy(email, text);  ///SA N_AM EROARE CA AM INLOCUIT FORUL CU STRCPY
}
void Jucator::set_NrTelefon(const char text[])
{
    strcpy(nr_Telefon, text);
}

Jucator::Jucator(const char cnp_1[], const char nume_1[], const char prenume_1[], int varsta_1, int sex_1, int elo_1, const char email1[], const char nr_Telefon1[]) ///definire constructor
{
    int lg_nume = strlen(nume_1);
    int lg_prenume = strlen(prenume_1);
    int lg_email = strlen(email1);
    strcpy(cnp, cnp_1);
    strcpy(nr_Telefon, nr_Telefon1);
    try {
        nume = new char[lg_nume + 1];
        prenume = new char[lg_prenume + 1];
        email = new char[lg_email + 1];
    }
    catch (bad_alloc& e)
    {
        std::cerr << "Prea muta memorie folosita!\n";
    }
    strcpy(nume, nume_1);
    strcpy(prenume, prenume_1);
    strcpy(email, email1);
    varsta = varsta_1;
    sex = sex_1;
    elo = elo_1;

}

Jucator::Jucator(const Jucator& Gicu) ///definire contructor de copiere
{
    int lg_nume = strlen(Gicu.nume);
    int lg_prenume = strlen(Gicu.prenume);
    int lg_email = strlen(Gicu.email);
    strcpy(cnp, Gicu.cnp);
    strcpy(nr_Telefon, Gicu.nr_Telefon);
    nume = new char[lg_nume + 1];
    prenume = new char[lg_prenume + 1];
    email = new char[lg_email + 1];
    strcpy(nume, Gicu.nume);
    strcpy(prenume, Gicu.prenume);
    strcpy(email, Gicu.email);
    varsta = Gicu.varsta;
    sex = Gicu.sex;
    elo = Gicu.elo;
}

Jucator::~Jucator() ///definire destructor
{
    delete[]nume;
    delete[]prenume;
    delete[]email;
}

Jucator& Jucator::operator=(const Jucator& Gicu) ///redefinire operator =
{
    if (this != &Gicu)
    {
        delete[]nume;
        delete[]prenume;
        delete[]email;
        int lg_email = strlen(Gicu.email);
        int lg_nume = strlen(Gicu.nume);
        int lg_prenume = strlen(Gicu.prenume);
        strcpy(cnp, Gicu.cnp);
        strcpy(nr_Telefon, Gicu.nr_Telefon);
        nume = new char[lg_nume + 1];
        prenume = new char[lg_prenume + 1];
        email = new char[lg_email + 1];
        strcpy(nume, Gicu.nume);
        strcpy(prenume, Gicu.prenume);
        strcpy(email, Gicu.email);
        varsta = Gicu.varsta;
        sex = Gicu.sex;
        elo = Gicu.elo;
    }
    return *this;
}

bool Jucator::validare_Nr_telefon(const char t[])
{
    if (t[0] != '0')
        return 0;
    int lg = strlen(t);
    for (int i = 0; i < 10; ++i)
    {
        if (t[i] > '9' || t[i] < '0')
            return 0;
    }
    if (strlen(t) > 10)
        return 0;

    return 1;
}

bool Jucator::validare_Cnp(const char t[])
{
    int lg = strlen(t);
    for (int i = 0; i < lg; ++i)
    {
        if (t[i] > '9' || t[i] < '0')
            return 0;
    }
    if (lg!=13)
        return 0;

    return 1;
}

bool Jucator::validare_Email(const char t[])
{
    bool amAron = 0;
    bool amPunct = 0;
    int lg = strlen(t);
    for (int i = 0; i < lg; ++i)
    {
        if (t[i] == '@')
            amAron = 1;
        else if (t[i] == '.')
            amPunct = 1;
    }
    if (amAron && amPunct)
        return 1;
    return 0;
}

bool Jucator::validare_Prenume(const char t[])
{
    int lg = strlen(t);
    for(int i=0;i<lg;++i)
        if(!(t[i]<='Z' && t[i]>='A') && !(t[i]>='a' && t[i]<='z'))
            return 0;
    return 1;
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

void Jucator::Citire_Jucator(istream& in)
{
    int lg;
    char text[100];
    do {
        cout << "Introdu CNP-ul: ";
        in.getline(text, 100);
        strcpy(this->cnp, text);
        if (Jucator::validare_Cnp(text) == 0)
            cout << "Incercare invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu Nume: ";
        in.getline(text, 100);
        lg = strlen(text);
        this->nume = new char[lg + 1];
        strcpy(this->nume, text);
        if (Jucator::validare_Prenume(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    {

    }
    do {
        cout << "Introdu Prenume: ";
        in.getline(text, 100);
        lg = strlen(text);
        this->prenume = new char[lg + 1];
        strcpy(this->prenume, text);
        if (Jucator::validare_Prenume(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    {

    }
    do {
        cout << "Introdu Email: ";
        in.getline(text, 100);
        lg = strlen(text);
        this->email = new char[lg + 1];
        strcpy(this->email, text);
        if (Jucator::validare_Email(text) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);

    do {
        cout << "Introdu Numar Telefon: ";
        in.getline(text, 100);
        strcpy(this->nr_Telefon, text);
        if (Jucator::validare_Nr_telefon(text) == 0)
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
