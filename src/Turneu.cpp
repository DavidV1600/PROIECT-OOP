#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Echipa.h"
#include "Turneu.h"
using namespace std;

void Turneu::set_Echipe(const Echipa * Echipe1)
{
    nr_Echipe_actual = sizeof(Echipe1) / sizeof(Echipe1[0]);
    Echipe=new Echipa[nr_Echipe_actual];
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Echipe1[i];
}

Turneu::Turneu(int nr_Echipe_actual1,int nr_Maxim_Echipe1,int premiu_Total1,int taxa_Participare1,int nr_Runde1,char nume_Turneu1[30],Echipa * Echipe1)
{
    nr_Echipe_actual=nr_Echipe_actual1;
    nr_Maxim_Echipe=nr_Maxim_Echipe1;
    premiu_Total=premiu_Total1;
    taxa_Participare=taxa_Participare1;
    nr_Runde=nr_Runde1;
    strcpy(nume_Turneu,nume_Turneu1);
    Echipe=Echipe1;
}

Turneu::Turneu(Turneu & Gicu)
{
    nr_Echipe_actual=Gicu.nr_Echipe_actual;
    Echipe=new Echipa[nr_Echipe_actual];
    nr_Maxim_Echipe=Gicu.nr_Maxim_Echipe;
    premiu_Total=Gicu.premiu_Total;
    taxa_Participare=Gicu.taxa_Participare;
    nr_Runde=Gicu.nr_Runde;
    strcpy(nume_Turneu,Gicu.nume_Turneu);
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Gicu.Echipe[i];
}

void Turneu::add_Echipa(const Echipa & Gicu)
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

void Turneu::sterge_Echipa(const Echipa & Gicu)
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

Turneu::~Turneu()
{
    delete[]Echipe;
}

Turneu & Turneu::operator=(const Turneu & Gicu)
{
    if(this!=&Gicu){
    delete[]Echipe;
    nr_Echipe_actual=Gicu.nr_Echipe_actual;
    nr_Maxim_Echipe=Gicu.nr_Maxim_Echipe;
    premiu_Total=Gicu.premiu_Total;
    taxa_Participare=Gicu.taxa_Participare;
    nr_Runde=Gicu.nr_Runde;
    strcpy(nume_Turneu,Gicu.nume_Turneu);
    for(int i=0;i<nr_Echipe_actual;++i)
        Echipe[i]=Gicu.Echipe[i];
    }
    return *this;
}

ostream & operator<<(ostream & out,const Turneu & Gicu)
{
    out<<"Nume Turneu: "<<Gicu.nume_Turneu<<'\n';
    out<<"Echipele Participante: ";
    int i;
    for(i=0;i<Gicu.nr_Echipe_actual-1;++i)
        out<<Gicu.Echipe[i].get_Nume()<<", ";
    out<<Gicu.Echipe[i].get_Nume()<<'\n';
    return out;
}

