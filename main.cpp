#include <iostream>
#include <fstream>
#include "Turneu.h"
using namespace std;
ifstream fin("poo.in");

int main()
{
 /*   Turneu T;
    cin>>T;
    int nr_Echipe;
    int nr_Jucatori;
    cout<<"Introdu Numar Echipe: ";
    cin>>nr_Echipe;
    nr_Echipe=min(T.get_nr_Maxim_Echipe(),nr_Echipe);
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
    T.Incepe_Turneu();
*/
    Jucator a("07434983","Sper","Ghita",10,false,2058);
    Jucator b("38749993","FierSper","Lucian",13,true,1895);
    Jucator c("293849843","Ler","Mihai",15,true,3895);
    Jucator d("293849843","FierMer","Andrei",15,false,1235);
    Echipa sper,fier,ler,mer;
    sper.Add_Membru(a);
    fier.Add_Membru(b);
    ler.Add_Membru(c);
    mer.Add_Membru(d);
    sper.Add_Membru(b);
    fier.Add_Membru(d);
    sper.set_Nume("Echipa sper");
    fier.set_Nume("Echipa fier");
    ler.set_Nume("Echipa ler");
    mer.set_Nume("Echipa mer");
    Turneu t1;
    t1.add_Echipa(sper);
    t1.add_Echipa(fier);
    t1.add_Echipa(ler);
    t1.add_Echipa(mer);
    t1.set_nr_Runde(2);
    t1.Incepe_Turneu();

    return 0;
}
