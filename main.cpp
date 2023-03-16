#include <iostream>
#include "Jucator.h"
#include "Echipa.h"
using namespace std;

int main()
{
    Jucator j("Mita","Bita","Ghita",10,false,2058);
    Jucator a=j;
    Jucator b;
    //a.afis_cnp();
    //cin>>b;
    //cout<<a;
    //cout<<b;
cout<<"CE ARE BA"<<'\n';
    Echipa sper;
    Echipa kl("SUOER",12,34);
    cout<<sper<<'\n';
    cout<<kl;
    //cin>>b;
    //cout<<b;
    cin>>sper;
    cout<<sper;
    return 0;
}
