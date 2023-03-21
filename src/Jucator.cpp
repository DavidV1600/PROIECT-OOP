#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Jucator.h"
#include <cstring>
using namespace std;

void Jucator::set_Cnp(const char text[]) ///definire Setter Cnp
{
    strcpy(cnp,text);
}
void Jucator::set_Nume(const char text[]) ///definire setter nume
{
    int lg=strlen(text);
    nume=new char[lg];
    strcpy(nume,text);
}
void Jucator::set_Prenume(const char text[]) ///definire setter prenume
{
    int lg=strlen(text);
    prenume=new char[lg];
    strcpy(prenume,text);
}
void Jucator::set_Varsta(const int a) ///definire setter Varsta
{
    varsta=a;
}
void Jucator::set_Elo(const int a) ///definire setter Elo
{
    elo=a;
}
void Jucator::set_Sex(const bool a) ///definire setter Sex
{
    sex=a;
}
void Jucator::set_Email(const char text[])
{
    int lg=strlen(text);
    email=new char[lg];
    strcpy(email,text);  ///SA N_AM EROARE CA AM INLOCUIT FORUL CU STRCPY
}
void Jucator::set_NrTelefon(const char text[])
{
    strcpy(nr_Telefon,text);
}

Jucator::Jucator(char cnp_1[], char nume_1[], char prenume_1[], int varsta_1, bool sex_1, int elo_1,char email1[],char nr_Telefon1[]) ///definire constructor
{
    int lg_nume=strlen(nume_1);
    int lg_prenume=strlen(prenume_1);
    int lg_email=strlen(email1);
    strcpy(cnp,cnp_1);
    strcpy(nr_Telefon,nr_Telefon1);
    nume=new char[lg_nume+1];
    prenume=new char[lg_prenume+1];
    email=new char[lg_email+1];
    strcpy(nume,nume_1);
    strcpy(prenume,prenume_1);
    strcpy(email,email1);
    varsta=varsta_1;
    sex=sex_1;
    elo=elo_1;

}

Jucator::Jucator(const Jucator& Gicu) ///definire contructor de copiere
{

    int lg_nume=strlen(Gicu.nume);
    int lg_prenume=strlen(Gicu.prenume);
    int lg_email=strlen(Gicu.email);
    strcpy(cnp,Gicu.cnp);
    strcpy(nr_Telefon,Gicu.nr_Telefon);
    nume=new char[lg_nume+1];
    prenume=new char[lg_prenume+1];
    email=new char[lg_email+1];
    strcpy(nume,Gicu.nume);
    strcpy(prenume,Gicu.prenume);
    strcpy(email,Gicu.email);
    varsta=Gicu.varsta;
    sex=Gicu.sex;
    elo=Gicu.elo;
}

Jucator::~Jucator() ///definire destructor
{
    delete []nume;
    delete []prenume;
    delete []email;
}

Jucator& Jucator::operator=(const Jucator & Gicu) ///redefinire operator =
{
    if(this != &Gicu)
    {
        delete[]nume;
        delete[]prenume;
        delete[]email;
        int lg_email=strlen(Gicu.email);
        int lg_nume=strlen(Gicu.nume);
        int lg_prenume=strlen(Gicu.prenume);
        strcpy(cnp,Gicu.cnp);
        strcpy(nr_Telefon,Gicu.nr_Telefon);
        nume=new char[lg_nume+1];
        prenume=new char[lg_prenume+1];
        email=new char[lg_email+1];
        strcpy(nume,Gicu.nume);
        strcpy(prenume,Gicu.prenume);
        strcpy(email,Gicu.email);
        varsta=Gicu.varsta;
        sex=Gicu.sex;
        elo=Gicu.elo;
    }
    return *this;
}

ostream & operator <<(ostream &out,const Jucator & Gicu1)///redefinire operatorul << (Afisare Jucator)
{
    out<<"Cnp: "<<Gicu1.cnp<<'\n'<<"Nume si Prenume: "<<Gicu1.nume<<" "<<Gicu1.prenume<<'\n'<<"Varsta: "<<Gicu1.varsta<<'\n'<<"Sex: ";
    if(Gicu1.sex==false)
        out<<"Feminin"<<'\n';
    else
        out<<"Masculin"<<'\n';
    out<<"Elo: "<<Gicu1.elo<<'\n';
    out<<"Email: "<<Gicu1.email<<'\n';
    out<<"Nr Telefon: "<<Gicu1.nr_Telefon<<'\n';
    return out;
}

istream & operator >>(istream & in, Jucator & Gicu)///redefinire operator >> (Citire Jucator)
{
    int lg;
    char text[100];
    cout<<"Introdu CNP-ul: ";
    in.getline(text,100);
    strcpy(Gicu.cnp,text);

    cout<<"Introdu Nume: ";
    in.getline(text,100);
    lg=strlen(text);
    Gicu.nume=new char[lg+1];
    strcpy(Gicu.nume,text);

    cout<<"Introdu Prenume: ";
    in.getline(text,100);
    lg=strlen(text);
    Gicu.prenume=new char[lg+1];
    strcpy(Gicu.prenume,text);

    cout<<"Introdu Email: ";
    in.getline(text,100);
    lg=strlen(text);
    Gicu.email=new char[lg+1];
    strcpy(Gicu.email,text);

    cout<<"Introdu Numar Telefon: ";
    in.getline(text,100);
    strcpy(Gicu.nr_Telefon,text);

    cout<<"Introdu Varsta: ";
    in>>Gicu.varsta;
    cout<<"Introdu Sex (0=F, 1=M): ";
    in>>Gicu.sex;
    cout<<"Introdu Elo: ";
    in>>Gicu.elo;
    cout<<'\n';
    return in;
}
