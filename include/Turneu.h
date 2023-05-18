#ifndef TURNEU_H
#define TURNEU_H
#include "Echipa.h"
#include "Runda.h"
#include "Premiu.h"
#include <cstring>
#include <vector>

using namespace std;

class Turneu
{
protected:
    static int nr_Turnee_Create;
    int nr_Echipe_actual;
    char nume_Turneu[30];
    int taxa_Participare;
    ///Aici bag clasa premii poate
    int premiu_Total;
    int nr_Maxim_Echipe;
    int nr_Runde;
    vector<Echipa>Echipee;
    vector<Runda>Rundee;

public:
    void static set_nr_Turnee_Create(const int nr)
    {
        nr_Turnee_Create = nr;
    }
    void set_nr_Echipe_actual(const int nr)
    {
        nr_Echipe_actual = nr;
    }
    void set_nume_Turneu(const char text[])
    {
        strcpy_s(nume_Turneu, text);
    }
    void set_taxa_Participare(const int taxa)
    {
        taxa_Participare = taxa;                                             ///SETTERI
    }
    void set_premiu_Total(const int premiu)
    {
        premiu_Total = premiu;
    }
    void set_nr_Maxim_Echipe(const int maxim_echipe)
    {
        nr_Maxim_Echipe = maxim_echipe;
    }
    void set_nr_Runde(const int runde)
    {
        nr_Runde = runde;
    }
    static int get_nr_Turnee_Create()
    {
        return nr_Turnee_Create;
    }
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
    const vector<Echipa> get_Echipe()const
    {
        return Echipee;
    }
    const vector<Runda> get_Runde()const
    {
        return Rundee;
    }
    const int get_nr_Runde()const
    {
        return nr_Runde;
    }

    void add_Echipa(const Echipa&);
    void sterge_Echipa(const Echipa&);
    void add_Runda();
    void sterge_Runda();
    virtual void Sortare_Echipe_Inaintea_Rundei();///la fel tot pura
    virtual void Incepe_Turneu();///cre ca o fac pura
    virtual void Editare_Turneu();///ca pot sa o fac pura
    virtual void Citire_Turneu(istream&);
    void Stergere_Echipa();
    void Gasire_Echipa(const Echipa&);
    void Intoarce_Clasamentul();
    Turneu(const int nr_Echipe_actual1 = 0,const int nr_Maxim_Echipe1 = 0,const int premiu_Total1 = 0,const int taxa_Participare1 = 0,const int nr_Runde1 = 0, const char nume_Turneu1[30] = "");
    Turneu(const Turneu&);
    ~Turneu();

    Turneu& operator=(const Turneu&);
    friend ostream& operator<<(ostream&, Turneu&);
    friend istream& operator>>(istream&, Turneu&);
    friend void Alegere_Turneu(const std::vector<std::shared_ptr<Turneu>>);

};

#endif // TURNEU_H

