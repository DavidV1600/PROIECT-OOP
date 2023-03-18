#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Runda.h"
#include "Meci.h"
using namespace std;

void Runda::set_Meciuri(const Meci * Gicu)
{
    nr_Meciuri = sizeof(Gicu) / sizeof(Gicu[0]);
    Meciuri= new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri;++i)
        Meciuri[i]=Gicu[i];
}

Runda::Runda(Meci * Meciuri1,int runda1,int nr_Meciuri1)
{
    Meciuri=Meciuri1;
    nr_Runda=runda1;
    nr_Meciuri=nr_Meciuri1;
}

Runda::Runda(Runda & Gicu)
{
    nr_Meciuri=Gicu.nr_Meciuri;
    nr_Runda=Gicu.nr_Runda;
    Meciuri=new Meci[nr_Meciuri];
    for(int i=0;i<nr_Meciuri;++i)
        Meciuri[i]=Gicu.Meciuri[i];
}

Runda & Runda::operator=(const Runda & Gicu)
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

ostream & operator<<(ostream & out,const Runda & Gicu)
{
    for(int i=0;i<Gicu.nr_Meciuri;++i)
        out<<"Meciul "<<i+1<<": "<<Gicu.Meciuri[i]<<'\n';
}

Runda::~Runda()
{
    delete[]Meciuri;
}

void Runda::add_Meci(const Meci & Gicu)
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
