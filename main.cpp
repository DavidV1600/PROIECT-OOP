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
    Jucator j("07434983","Bita","Ghita",10,false,2058);
    Jucator a("293849843","Ionescu","Ghita",10,true,1895);
    Echipa sper,fier;
    sper.Add_Membru(j);
    fier.Add_Membru(a);
    fier.Add_Membru(j);
    cout<<sper;
    sper.Add_Membru(a);
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
    cout<<r1;

    return 0;
}
