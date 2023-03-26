#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Runda.h"
using namespace std;


Runda::Runda(Meci * Meciuri1,int runda1,int nr_Meciuri1)///Constructor cu parametri impliciti
{
    Meciuri=Meciuri1;
    nr_Runda=runda1;
    nr_Meciuri=nr_Meciuri1;
}

Runda::Runda(Runda & Gicu)///Constructor de copiere
{
    nr_Meciuri=Gicu.nr_Meciuri;
    nr_Runda=Gicu.nr_Runda;
    Meciuri=new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri;++i)
        Meciuri[i]=Gicu.Meciuri[i];
}

Runda & Runda::operator=(const Runda & Gicu)///redefinire operatorul =
{
    if(this!=&Gicu){
    delete[]Meciuri;
    nr_Meciuri=Gicu.nr_Meciuri;
    nr_Runda=Gicu.nr_Runda;
    Meciuri=new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri;++i)
        Meciuri[i]=Gicu.Meciuri[i];
    }
    return *this;
}

ostream & operator<<(ostream & out,const Runda & Gicu)///redefinire operator << (Afisare Runda)
{
    for(int i=0;i<Gicu.nr_Meciuri;++i)
        out<<"Meciul "<<i+1<<": "<<Gicu.Meciuri[i]<<'\n';
    return out;
}

Runda::~Runda()///Destructor
{
    delete[]Meciuri;
}

void Runda::pregateste_Runda(Echipa *& Echipe1,int nr_Echipe)
{

    nr_Meciuri = (nr_Echipe/2);
    ///Aci poate tre sa dau si delete inainte
    delete[]Meciuri;
    Meciuri=new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri;++i)
    {
        Meciuri[i].set_Echipa1(&Echipe1[2*i]);
        Meciuri[i].set_scor_1(0);
        Meciuri[i].set_Echipa2(&Echipe1[2*i+1]);
        Meciuri[i].set_scor_2(0);
    }

    for(int i=0;i<nr_Meciuri;++i)
    {
        cout<<Meciuri[i].get_Echipa1().get_Nume()<<" - "<<Meciuri[i].get_Echipa2().get_Nume()<<"  Intordu scorul: ";
        int scor_echipa1,scor_echipa2;
        cin>>scor_echipa1>>scor_echipa2;
        Meciuri[i].set_scor_1(scor_echipa1);
        Meciuri[i].set_scor_2(scor_echipa2);
        if(scor_echipa1>scor_echipa2)
            Meciuri[i].get_Echipa1().set_Puncte(Meciuri[i].get_Echipa1().get_Puncte()+1);
        else
            Meciuri[i].get_Echipa2().set_Puncte(Meciuri[i].get_Echipa2().get_Puncte()+1);
    }
    cout<<'\n';
}

void Runda::add_Meci(const Meci & Gicu)///Functie de Adaugare Meci
{
    nr_Meciuri++;
    Meci * temp;
    temp=new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri-1;++i)
        temp[i]=Meciuri[i];
    temp[nr_Meciuri-1]=Gicu;
    delete[]Meciuri;
    Meciuri=temp;
}
