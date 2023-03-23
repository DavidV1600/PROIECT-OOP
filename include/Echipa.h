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
    int puncte;
    Jucator *Membri;
public:
    void set_Nume(char text[])
    {
        strcpy(nume,text);
    }
    void set_Numar_Membri(int nr)
    {
        numar_membri=nr;
    }
    void set_Elo_Echipa(int elo)
    {
        elo_echipa=elo;   ///SETTERI
    }
    void set_Puncte(const int x)
    {
        puncte=x;
    }

    void Calculeaza_Medie(); ///calculez media jucatorilor
    void Add_Membru(const Jucator &); ///bag membru
    void Sterge_Jucator(const Jucator& jucatorDeSters);
    void Citire_Nume_Echipa()
    {
        cout<<"Introdu Numele Echipei: ";
        cin.getline(nume,20);
    }

    const char* get_Nume()const
    {
        return nume;
    }
    const int get_Numar_Membri()const
    {
        return numar_membri;
    }
    const int get_Elo_Echipa()const
    {
        return elo_echipa;   ///GETTERI
    }
    const Jucator * get_Membri()const
    {
        return Membri;
    }
    const int get_Puncte()const
    {
        return puncte;
    }

    Echipa(const char nume_1[]="",int nr_membri=0,int echipa_elo=0,Jucator *Membru=nullptr,int puncte1=0); ///CONSTRUCTOR
    Echipa(Echipa &); ///Constructor de copiere
    ~Echipa(); ///Destructor

    Echipa& operator=(const Echipa &); ///Operatorul =
    friend ostream& operator<<(ostream &, Echipa &); ///Afisare
    friend istream& operator>>(istream &, Echipa &); ///Citire
};

#endif // ECHIPA_H
