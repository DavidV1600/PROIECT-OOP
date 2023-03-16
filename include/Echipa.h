#ifndef ECHIPA_H
#define ECHIPA_H
#include "Jucator.h"
#include <cstring>
using namespace std;
class Echipa
{
private:
    char nume[20];
    int numar_membri;
    int elo_echipa;
    Jucator *Membri;
public:
    void set_Nume(char text[]){strcpy(nume,text);}
    void set_Numar_Membri(int nr){numar_membri=nr;}
    void set_Elo_Echipa(int elo){elo_echipa=elo;}  ///SETTERI
    void set_Membri(const Jucator *);

    void Calculeaza_Medie(); ///calculez media jucatorilor
    void Add_Membru(const Jucator &); ///bag membru

    const char* get_Nume()const {return nume;}
    const int get_Numar_Membri()const {return numar_membri;}
    const int get_Elo_Echipa()const {return elo_echipa;}  ///GETTERI
    const Jucator * get_Membri()const {return Membri;}

    Echipa(char nume_1[]="",int nr_membri=0,int echipa_elo=0,Jucator *Membru=nullptr); ///CONSTRUCTOR
    Echipa(Echipa &); ///Constructor de copiere
    ~Echipa(); ///Destructor

    Echipa& operator=(const Echipa &); ///Operatorul =
    friend ostream& operator<<(ostream &, Echipa &); ///Afisare
    friend istream& operator>>(istream &, Echipa &); ///Citire
};

#endif // ECHIPA_H
