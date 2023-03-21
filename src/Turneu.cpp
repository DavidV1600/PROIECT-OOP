#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Echipa.h"
#include "Turneu.h"
using namespace std;

void Turneu::set_Echipe(const Echipa * Echipe1)///Setter pentru Echipe
{
    nr_Echipe_actual = sizeof(Echipe1) / sizeof(Echipe1[0]);
    Echipe=new Echipa[nr_Echipe_actual];
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Echipe1[i];
}

void Turneu::set_Runde(const Runda * Runde1)
{
    nr_Runde=sizeof(Runde1)/ sizeof(Runde1[0]);
    Runde=new Runda[nr_Runde];
    for(int i=0;i<nr_Runde;++i)
        Runde[i]=Runde1[i];
}

Turneu::Turneu(int nr_Echipe_actual1,int nr_Maxim_Echipe1,int premiu_Total1,int taxa_Participare1,int nr_Runde1,char nume_Turneu1[30],Echipa * Echipe1,Runda * Runde1)///constructor cu parametri impliciti
{
    nr_Echipe_actual=nr_Echipe_actual1;
    nr_Maxim_Echipe=nr_Maxim_Echipe1;
    premiu_Total=premiu_Total1;
    taxa_Participare=taxa_Participare1;
    nr_Runde=nr_Runde1;
    strcpy(nume_Turneu,nume_Turneu1);
    Echipe=Echipe1;
    Runde=Runde1;
}

Turneu::Turneu(Turneu & Gicu)///Constructor de copiere
{
    nr_Echipe_actual=Gicu.nr_Echipe_actual;
    Echipe=new Echipa[nr_Echipe_actual];
    nr_Runde=Gicu.nr_Runde;
    Runde=new Runda[nr_Runde];
    nr_Maxim_Echipe=Gicu.nr_Maxim_Echipe;
    premiu_Total=Gicu.premiu_Total;
    taxa_Participare=Gicu.taxa_Participare;
    nr_Runde=Gicu.nr_Runde;
    strcpy(nume_Turneu,Gicu.nume_Turneu);
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Gicu.Echipe[i];
    for(int i=0;i<nr_Runde;++i)
        Runde[i]=Gicu.Runde[i];
}

void Turneu::add_Echipa(const Echipa & Gicu)///Functie de adaugare Echipe
{
    nr_Echipe_actual++;
    Echipa * temp;
    temp=new Echipa[nr_Echipe_actual];
    for(int i=0;i<nr_Echipe_actual-1;++i)
        temp[i]=Echipe[i];
    temp[nr_Echipe_actual-1]=Gicu;
    delete[]Echipe;
    Echipe=temp;
}

void Turneu::add_Runda(const Runda & Gicu)///Functie de adaugare Runda
{
    nr_Runde++;
    Runda * temp;
    temp=new Runda[nr_Runde];
    for(int i=0;i<nr_Runde-1;++i)
        temp[i]=Runde[i];
    temp[nr_Echipe_actual-1]=Gicu;
    delete[]Runde;
    Runde=temp;
}

void Turneu::sterge_Echipa(const Echipa & Gicu)///Functie de stergere Echipe
{
    nr_Echipe_actual--;
    Echipa * temp;
    temp = new Echipa[nr_Echipe_actual];
    int k=0;
    for(int i=0;i<=nr_Echipe_actual;++i)
        if(strcmp(Echipe[i].get_Nume(),Gicu.get_Nume())!=0)
    {
        temp[k]=Echipe[i];
        k++;
    }
    delete[]Echipe;
    Echipe=temp;
}

void Turneu::sterge_Runda(const Runda & Gicu)///functie de stergere runda
{
    nr_Runde--;
    Runda * temp;
    temp = new Runda[nr_Runde];
    int k=0;
    for(int i=0;i<=nr_Runde;++i)
        if(Runde[i].get_nr_Runda()!=Gicu.get_nr_Runda())
    {
        temp[k]=Runde[i];
        k++;
    }
    delete[]Runde;
    Runde=temp;
}

void Turneu::Sortare_Dupa_Elo()///functie sortare crescatoare dupa elo
{
  for(int i=0;i<nr_Echipe_actual-1;++i)
  for(int j=i+1;j<nr_Echipe_actual;++j)
    if(Echipe[i].get_Elo_Echipa()<Echipe[j].get_Elo_Echipa())
  {
      Echipa temp=Echipe[i];
      Echipe[i]=Echipe[j];
      Echipe[j]=temp;
  }
}

Turneu::~Turneu()///Destructor
{
    delete[]Echipe;
    delete[]Runde;
}

Turneu & Turneu::operator=(const Turneu & Gicu)///redefinire operatorul =
{
    if(this!=&Gicu){
    delete[]Echipe;
    delete[]Runde;
    Echipe=new Echipa[Gicu.nr_Echipe_actual];
    Runde=new Runda[Gicu.nr_Runde];
    nr_Echipe_actual=Gicu.nr_Echipe_actual;
    nr_Maxim_Echipe=Gicu.nr_Maxim_Echipe;
    premiu_Total=Gicu.premiu_Total;
    taxa_Participare=Gicu.taxa_Participare;
    nr_Runde=Gicu.nr_Runde;
    strcpy(nume_Turneu,Gicu.nume_Turneu);
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Gicu.Echipe[i];
    for(int i=0;i<nr_Runde;++i)
        Runde[i]=Gicu.Runde[i];

    }
    return *this;
}

ostream & operator<<(ostream & out,Turneu & Gicu)///redefinire operator << (Afisare Turneu)
{
    Gicu.Sortare_Dupa_Elo();
    out<<"Nume Turneu: "<<Gicu.nume_Turneu<<'\n';
    out<<"Lista de start:\n";
    int i;
    for(i=0;i<Gicu.nr_Echipe_actual;++i)
        out<<i+1<<".) "<<Gicu.Echipe[i].get_Nume()<<"  Elo: "<<Gicu.Echipe[i].get_Elo_Echipa()<<'\n';
    return out;
}

