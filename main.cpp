#include <iostream>
#include <fstream>
#include "Jucator.h"
#include "Echipa.h"
#include "Turneu.h"
#include "Meci.h"
#include "Runda.h"
using namespace std;
ifstream fin("poo.in");

int main()
{
    Turneu T;
    T.Citire_Nume_Turneu();
    int nr_Echipe;
    int nr_Jucatori;
    cout<<"Introdu Numar Echipe: ";
    cin>>nr_Echipe;
    cin.get();
    for(int i=1;i<=nr_Echipe;++i)
    {
        Echipa e;
        e.Citire_Nume_Echipa();
        cout<<"Introdu Numar Jucatori Echipa "<<e.get_Nume()<<": ";
        cin>>nr_Jucatori;
        for(int j=1;j<=nr_Jucatori;++j)
        {
            cout<<"Introdu datele jucatorului "<<j<<" din echipa "<<e.get_Nume()<<":\n";
            Jucator a;
            cin.get();
            cin>>a;
            e.Add_Membru(a);
        }
        cin.get();

        T.add_Echipa(e);

    }
    cout<<T;

    /*Jucator a("07434983","Bita","Ghita",10,false,2058);
    Jucator b("38749993","Ionescu","Lucian",13,true,1895);
    Jucator c("293849843","Kopacu","Mihai",15,true,3895);
    Echipa sper,fier;
    sper.Add_Membru(a);
    fier.Add_Membru(b);
    fier.Add_Membru(c);
    cout<<sper;
    sper.Add_Membru(b);
    sper.set_Nume("EchipaBomba");
    fier.set_Nume("SusraGalactica");
    cout<<sper;
    Turneu t1;
    t1.add_Echipa(sper);
    t1.add_Echipa(fier);
    cout<<t1;
    t1.sterge_Echipa(fier);
    cout<<t1;
    Meci m(sper,fier);
    cout<<m;
    Runda r1;
    r1.add_Meci(m);
    cout<<r1;*/


    return 0;
}
