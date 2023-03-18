#include <iostream>
#include <fstream>
#include "Jucator.h"
#include "Echipa.h"
using namespace std;
ifstream fin("poo.in");

int main()
{
    Jucator j("Mita","Bita","Ghita",10,false,2058);
    Jucator a=j;
    Jucator b;
    cout<<j.get_Nume()<<'\n';
    //a.afis_cnp();
    //cin>>b;
    //cout<<a;
    //cout<<b;
    cout<<"CE ARE BA"<<'\n';
    Echipa sper;
    Echipa k("SUOER",12,34);
    //cin>>b;
    //cout<<b;
    cin>>sper;
    cout<<sper;
    sper.Add_Membru(j);
    cout<<sper;
    sper.Sterge_Jucator(j);///NU MERE NUS DE CE CEVA DE MEMORIE DINAMICA
    cout<<sper.get_Numar_Membri();
    cout<<sper;
    return 0;
}
