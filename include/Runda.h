#ifndef RUNDA_H
#define RUNDA_H
#include "Meci.h"
using namespace std;
class Runda
{
private:
    Meci* Meciuri;
    int nr_Runda;
    int nr_Meciuri;

public:
    void set_nr_Meciuri(const int nr_meci) { nr_Meciuri = nr_meci; }
    void set_nr_Runda(const int nr_rud) { nr_Runda = nr_rud; }

    const int get_nr_Meciuri()const { return nr_Meciuri; }
    const int get_nr_Runda()const { return nr_Runda; }
    const Meci* get_Meciuri()const { return Meciuri; }

    Runda(Meci* Meciuri1 = nullptr,const int runda1 = 0,const int nr_Meciuri1 = 0);
    Runda(const Runda&);
    ~Runda();

    Runda& operator=(const Runda&);
    friend ostream& operator<<(ostream&, const Runda&);
    void add_Meci(const Meci&);
    void pregateste_Runda(vector<Echipa>&,const int);
};

#endif // RUNDA_H

