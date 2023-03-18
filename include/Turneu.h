#ifndef TURNEU_H
#define TURNEU_H
#include "Echipa.h"
#include <cstring>

using namespace std;

class Turneu
{
private:
    static int nr_Echipe_actual;
    char nume_Turneu[30];
    int taxa_Participare;
    ///Aici bag clasa premii poate
    int premiu_Total;
    int nr_Maxim_Echipe;
    Echipa *Echipe;

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
        taxa_Participare=taxa;   ///SETTERI
    }
    void set_premiu_Total(const int premiu)
    {
        premiu_Total=premiu;
    }
    void set_nr_Maxim_Echipe(const int maxim_echipe)
    {
        nr_Maxim_Echipe=maxim_echipe;
    }
    void set_Echipe(const Echipa*);

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
        return nr_Maxim_Echipe;   ///GETTERI
    }
    const char* get_nume_Turneu()const
    {
        return nume_Turneu;
    }
    const Echipa* get_Echipe()const
    {
        return Echipe;
    }

    //Turneu()

};

#endif // TURNEU_H
