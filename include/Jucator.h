#ifndef JUCATOR_H
#define JUCATOR_H
#include <exception>
#include <iostream>
using namespace std;

class Jucator
{
private:

    char cnp[14];
    char nr_Telefon[11];
    char* nume;   ///Astea cre ca nu ae rost sa le las dinamic
    char* prenume;
    char* email;
    int varsta;
    int sex;
    int elo;


public:
    const char* get_Cnp()const
    {
        return cnp;
    }
    const char* get_Nume()const
    {
        return nume;
    }
    const char* get_Prenume()const
    {
        return prenume;                                       ///Getteri
    }
    const int  get_Varsta()const
    {
        return varsta;
    }
    const int get_Sex()const
    {
        return sex;
    }
    const int  get_Elo()const
    {
        return elo;
    }
    const char* get_Email()const
    {
        return email;
    }
    const char* get_NrTelefon()const
    {
        return nr_Telefon;
    }

    void set_Cnp(const char text[]);
    void set_Nume(const char text[]);
    void set_Prenume(const char text[]);   ///Setteri
    void set_Varsta(const int);
    void set_Sex(const int);
    void set_Elo(const int);
    void set_Email(const char text[]);
    void set_NrTelefon(const char text[]);

    ///SA PUN CONST UNDE TREBE
    Jucator(const char* cnp_1 = "Unknown", const char nume_1[] = "Unknown", const char prenume_1[] = "Unknown", int varsta_1 = 0, int sex_1 = 0, int elo_1 = 0, const char email1[] = "Unknown", const char nr_Telefon1[] = "Unknown");///Constructor
    Jucator(const Jucator& Gicu); ///Constructor de copiere
    ~Jucator(); ///Destructor

    Jucator& operator=(const Jucator& Gicu); ///Operatorul =      Daca e mai bine sa-i declar friend sau normal
    friend ostream& operator <<(ostream& out, const Jucator& Gicu); ///Operatorul <<
    friend istream& operator >>(istream& in, Jucator& Gicu);
    static bool validare_Nr_telefon(const char text[]);
    static bool validare_Email(const char text[]);
    static bool validare_Prenume(const char text[]);
    static bool validare_Cnp(const char text[]);
    virtual void Citire_Jucator(istream&);
    void ce_Jucator_E();
};

#endif // JUCATOR_H

