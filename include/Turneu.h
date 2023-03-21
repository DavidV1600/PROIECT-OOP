#ifndef TURNEU_H
#define TURNEU_H
#include "Echipa.h"
#include "Runda.h"
#include <cstring>

using namespace std;

class Turneu
{
private:
    int nr_Echipe_actual;
    char nume_Turneu[30];
    int taxa_Participare;
    ///Aici bag clasa premii poate
    int premiu_Total;
    int nr_Maxim_Echipe;
    int nr_Runde;
    Echipa *Echipe;
    Runda *Runde;

public:
    void set_nr_Echipe_actual(const int nr)
    {
        nr_Echipe_actual=nr;
    }
    void set_nume_Turneu(const char text[])
    {
        strcpy(nume_Turneu,text);
    }
    void set_taxa_Participare(const int taxa)
    {
        taxa_Participare=taxa;                                             ///SETTERI
    }
    void set_premiu_Total(const int premiu)
    {
        premiu_Total=premiu;
    }
    void set_nr_Maxim_Echipe(const int maxim_echipe)
    {
        nr_Maxim_Echipe=maxim_echipe;
    }
    void set_nr_Runde(const int runde)
    {
        nr_Runde=runde;
    }
    void set_Echipe(const Echipa*);
    void set_Runde(const Runda*);

    const int get_nr_Echipe_actual()const
    {
        return nr_Echipe_actual;
    }
    const int get_taxa_Participare()const
    {
        return taxa_Participare;
    }
    const int get_premiu_Total()const
    {
        return premiu_Total;
    }
    const int get_nr_Maxim_Echipe()const
    {
        return nr_Maxim_Echipe;                                               ///GETTERI
    }
    const char* get_nume_Turneu()const
    {
        return nume_Turneu;
    }
    const Echipa* get_Echipe()const
    {
        return Echipe;
    }
    const Runda* get_Runde()const
    {
        return Runde;
    }
    const int get_nr_Runde()const
    {
        return nr_Runde;
    }

    void add_Echipa(const Echipa &);
    void sterge_Echipa(const Echipa &);
    void add_Runda(const Runda &);
    void sterge_Runda(const Runda &);
    void Sortare_Echipe_Inaintea_Rundei();

    Turneu(int nr_Echipe_actual1=0,int nr_Maxim_Echipe1=0,int premiu_Total1=0,int taxa_Participare1=0,int nr_Runde1=0,char nume_Turneu1[30]="",Echipa * Echipe1=nullptr,Runda *Runde1=nullptr);
    Turneu(Turneu &);
    ~Turneu();

    Turneu & operator=(const Turneu &);
    friend ostream & operator<<(ostream &,Turneu &);
    friend istream & operator>>(istream &,Turneu &);
};

#endif // TURNEU_H
