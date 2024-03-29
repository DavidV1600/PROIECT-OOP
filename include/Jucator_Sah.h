#ifndef JUCATOR_SAH_H
#define JUCATOR_SAH_H

#include "Jucator.h"
#include "Sortari.h"
using namespace std;

class Jucator_Sah : virtual public Jucator
{
protected:
    int elo_National;
    int elo_International;
    int elo_Online;
    char titlu[5];
    char club_Sportiv_Sah[30];
    char nume_Online[30];
    //std::unique_ptr<Istoric_Jucator_Sah>Istoric;
public:
    void set_elo_National(const int elo) { elo_National = elo; }
    void set_elo_International(const int elo) { elo_International = elo; }
    void set_elo_Online(const int elo) { elo_Online = elo; }
    void set_Titlu(const char t[]) { strcpy(titlu, t); }
    void set_club_Sportiv_Sah(const char t[]) { strcpy(club_Sportiv_Sah, t); }
    void set_nume_Online(const char t[]) { strcpy(nume_Online, t); }

    const int get_elo_National()const
    {
        return elo_National;
    }
    const int get_elo_International()const
    {
        return elo_International;
    }
    const int get_elo_Online()const
    {
        return elo_Online;
    }
    const char* get_Titlu()const
    {
        return titlu;
    }
    const char* get_club_Sportiv_Sah()const
    {
        return club_Sportiv_Sah;
    }
    const char* get_nume_Online()const
    {
        return nume_Online;
    }

    Jucator_Sah(const int elo1 = 0, const int elo2 = 0, const int elo3 = 0, const char titlu1[] = "Unknown", const char club[]="Unknown", const char nume_Online1[]="Unknown");
    Jucator_Sah(const Jucator_Sah& Gicu);
    Jucator_Sah& operator=(const Jucator_Sah& Gicu);
    bool operator<(const Jucator_Sah&);

    friend istream& operator >>(istream& in, Jucator_Sah& Gicu);
    friend ostream& operator <<(ostream& out,Jucator_Sah& Gicu);
    static bool validare_Titlu(const char text[]);
    void Citire_Jucator(istream&);
};

#endif // JUCATOR_SAH_H
