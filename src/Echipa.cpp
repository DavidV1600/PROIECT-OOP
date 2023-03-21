#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Echipa.h"
using namespace std;


void Echipa::set_Membri(const Jucator * Lista_Jucatori)
{
    numar_membri = sizeof(Lista_Jucatori) / sizeof(Lista_Jucatori[0]);  ///Gasesc marimea listei de jucatori
    Membri=new Jucator[numar_membri];
    for(int i=0; i<numar_membri; ++i)
        Membri[i]=Lista_Jucatori[i];
    Calculeaza_Medie();

}

Echipa::Echipa(char nume_1[],int nr_membri,int echipa_elo,Jucator *Membru,int puncte1) ///Constructorul
{
    strcpy(nume,nume_1);
    numar_membri=nr_membri;
    elo_echipa=echipa_elo;
    puncte=puncte1;
    Membri=Membru;
}

void Echipa::Calculeaza_Medie() ///Calculez Media
{
    int suma=0;
    if (numar_membri!=0)
    {
        for(int i=0; i<numar_membri; ++i)
            suma+=Membri[i].get_Elo();
        elo_echipa=suma/numar_membri;
    }
}

void Echipa::Add_Membru(const Jucator & Gicu) ///Adaug Membru
{
    numar_membri++;
    Jucator * temp;
    temp=new Jucator[numar_membri];
    for(int i=0; i<numar_membri-1; ++i)
        temp[i]=Membri[i];
    temp[numar_membri-1]=Gicu;            ///Salvez in variabla temporara ca nus sa dau realoc
    delete[]Membri;
    Membri =temp;
    Calculeaza_Medie();
}

void Echipa::Sterge_Jucator(const Jucator& jucatorDeSters)
{

    const char *prim=jucatorDeSters.get_Cnp();
    int pozitieDeSters = -1;
    for (int i = 0; i < numar_membri; i++)
    {
        const char *prim2=Membri[i].get_Cnp();

        if(strcmp(prim,prim2)==0)
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

    strcpy(nume,Gicu.nume);///de ce la construcorul de copiere nu imi recomanda scriptul???
    numar_membri=Gicu.numar_membri;
    puncte=Gicu.puncte;
    elo_echipa=Gicu.elo_echipa;
    Membri=new Jucator[numar_membri];
    for(int i=0; i<numar_membri; ++i)
        Membri[i]=Gicu.Membri[i];
}

Echipa::~Echipa()
{
    delete []Membri;
}

Echipa& Echipa::operator=(const Echipa& Gicu) ///Operatorul de =
{
    if (this != &Gicu)
    {
        delete[] Membri; // sterg valoarea veche
        numar_membri = Gicu.numar_membri;
        elo_echipa = Gicu.elo_echipa;
        puncte=Gicu.puncte;
        strcpy(nume,Gicu.nume);
        Membri = new Jucator[numar_membri];
        for (int i = 0; i < numar_membri; ++i)
            Membri[i] = Gicu.Membri[i];
    }
    return *this;
}

ostream & operator<<(ostream & out,Echipa & Gicu)///Afisare
{
    Gicu.Calculeaza_Medie();
    out<<"Nume Echipa: "<<Gicu.nume<<'\n'<<"Elo Echipa: "<<Gicu.elo_echipa<<'\n'<<"Numar Membri: "<<Gicu.numar_membri<<'\n'<<"Membri: ";
    int i;
    for(i=0; i<Gicu.numar_membri-1; ++i)
        out<<Gicu.Membri[i].get_Nume()<<", ";
    out<<Gicu.Membri[i].get_Nume();
    out<<'\n'<<'\n';
    return out;
}

istream & operator>>(istream & in,Echipa & Gicu)///Citire
{
    cout<<"Introdu Nume Echipa: ";
    in>>Gicu.nume;
    cout<<"Introdu Numarul de Membri: ";
    in>>Gicu.numar_membri;
    in.get();

    Gicu.Membri=new Jucator[Gicu.numar_membri];
    for(int i=0; i<Gicu.numar_membri; ++i)
    {
        cout<<'\n'<<"Membrul "<<i+1<<":\n";
        in>>Gicu.Membri[i];
    }
    cout<<'\n';
    return in;
}
