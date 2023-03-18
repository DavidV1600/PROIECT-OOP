#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Meci.h"
#include "Echipa.h" ///Mai tre sa o includ intrebare de pus
using namespace std;

Meci::Meci(Echipa Echipa1,Echipa Echipa2,int scor1,int scor2,bool rezultat_final)
{
    Echipa_1=Echipa1;
    Echipa_2=Echipa2;
    scor_1=scor1;
    scor_2=scor2;
    rezultat_final=rezultat_final;
}
Meci::Meci(Meci & Gicu)
{
    Echipa_1=Gicu.Echipa_1;
    Echipa_2=Gicu.Echipa_2;
    scor_1=Gicu.scor_1;
    scor_2=Gicu.scor_2;
    rezultat_final=Gicu.rezultat_final;
}

Meci & Meci::operator=(const Meci & Gicu)
{
    if(this!=&Gicu){
    Echipa_1=Gicu.Echipa_1;
    Echipa_2=Gicu.Echipa_2;
    scor_1=Gicu.scor_1;
    scor_2=Gicu.scor_2;
    rezultat_final=Gicu.rezultat_final;
    }
    return *this;
}

ostream & operator<<(ostream & out,const Meci & Gicu)
{
    out<<Gicu.Echipa_1.get_Nume()<<" "<<Gicu.scor_1<<"-"<<Gicu.scor_2<<" "<<Gicu.Echipa_2.get_Nume()<<'\n';
return out;
}
