#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Echipa.h"
#include "Jucator.h"
using namespace std;


void Echipa::set_Membri(const Jucator * Lista_Jucatori)
{
    numar_membri = sizeof(Lista_Jucatori) / sizeof(Lista_Jucatori[0]);  ///Gasesc marimea listei de jucatori
    Membri=new Jucator[numar_membri];
    for(int i=0;i<numar_membri;++i)
        Membri[i]=Lista_Jucatori[i];

}

Echipa::Echipa(char nume_1[],int nr_membri,int echipa_elo,Jucator *Membru) ///Constructorul
{
    strcpy(nume,nume_1);
    numar_membri=nr_membri;
    elo_echipa=echipa_elo;
    Membri=Membru;
}

void Echipa::Calculeaza_Medie() ///Calculez Media
{
    int suma=0;
    if (numar_membri!=0){
    for(int i=0;i<numar_membri;++i)
        suma+=Membri[i].get_Elo();
    elo_echipa=suma/numar_membri;
    }
}

void Echipa::Add_Membru(const Jucator & Gicu) ///Adaug Membru
{
    numar_membri++;
    Jucator * temp;
    temp=new Jucator[numar_membri];
    for(int i=0;i<numar_membri-1;++i)
        temp[i]=Membri[i];
    temp[numar_membri-1]=Gicu;            ///Salvez in variabla temporara ca nus sa dau realoc
    delete[]Membri;
    Membri =new Jucator[numar_membri];
    for(int i=0;i<numar_membri;++i)
        Membri[i]=temp[i];
    delete[]temp;

}

Echipa::Echipa(Echipa& Gicu) ///Constructor de copiere
{

    strcpy(nume,Gicu.nume);
    numar_membri=Gicu.numar_membri;
    elo_echipa=Gicu.elo_echipa;
    Membri=new Jucator[numar_membri];
    for(int i=0;numar_membri;++i)
        Membri[i]=Gicu.Membri[i];
}

Echipa::~Echipa()
{
    strcpy(nume,"");///NUS daca trebe
    delete []Membri;
}

Echipa& Echipa::operator=(const Echipa& Gicu) ///Operatorul de =
{
    if (this != &Gicu) {
        delete[] Membri; // sterg valoarea veche
        numar_membri = Gicu.numar_membri;
        elo_echipa = Gicu.elo_echipa;
        Membri = new Jucator[numar_membri];
        for (int i = 0; i < numar_membri; ++i)
            Membri[i] = Gicu.Membri[i];
    }
    return *this;
}

ostream & operator<<(ostream & out,Echipa & Gicu)///Afisare
{
    //Gicu.Calculeaza_Medie();
    out<<"Nume Echipa: "<<Gicu.nume<<'\n'<<"Elo Echipa: "<<Gicu.elo_echipa<<'\n'<<"Numar Membri: "<<Gicu.numar_membri<<'\n'<<"Membri: "<<Gicu.Membri<<'\n';
    return out;
}

istream & operator>>(istream & in, Echipa & Gicu)///Citire
{
    cout<<"Introdu Nume Echipa: ";
    in>>Gicu.nume;
    cout<<"Introdu Numarul de Membri: ";
    in>>Gicu.numar_membri;
    in.get();

    Gicu.Membri=new Jucator[Gicu.numar_membri];
    for(int i=0;i<Gicu.numar_membri;++i){
            cout<<'\n'<<"Membrul "<<i+1<<":\n";
        in>>Gicu.Membri[i];
    }
    return in;
}
