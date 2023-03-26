#ifndef MECI_H
#define MECI_H
#include "Echipa.h"
#include <cstring>
using namespace std;

class Meci
{
private:
    Echipa *Echipa_1;
    Echipa *Echipa_2;
    int scor_1;
    int scor_2;
    bool rezultat_final;

public:
    void set_Echipa1(Echipa *Echipa1){Echipa_1=Echipa1;}
    void set_Echipa2(Echipa *Echipa2){Echipa_2=Echipa2;}
    void set_scor_1(const int scor){scor_1=scor;}          ///Setteri
    void set_scor_2(const int scor){scor_2=scor;}///Cand castiga: 1-primul, 0-al doilea
    void set_rezultat_final(const bool rez){rezultat_final=rez;}

    const Echipa& get_Echipa1 ()const {return *Echipa_1;}
    const Echipa& get_Echipa2 ()const{return *Echipa_2;}
    Echipa& get_Echipa1 (){return *Echipa_1;}
    Echipa& get_Echipa2 (){return *Echipa_2;}
    const int get_scor_1 ()const{return scor_1;}///Getteri
    const int get_scor_2 ()const{return scor_2;}
    const bool get_rezultat ()const{return rezultat_final;}

    Meci(Echipa *Echipa1=nullptr,Echipa *Echipa2=nullptr,int scor1=0,int scor2=0,bool rezultat_final=1);
    Meci(Meci &);
    Meci & operator=(const Meci &);
    friend ostream & operator<<(ostream &,const Meci &);

};

#endif // MECI_H
