#ifndef JUCATOR_SAH_H
#define JUCATOR_SAH_H

#include <Jucator.h>
using namespace std;

class Jucator_Sah : public Jucator
{
private:
    int elo_National;
    int elo_International;
    int elo_Online;
    char titlu[5];
public:
    void set_elo_National(const int elo){elo_National=elo;}
    void set_elo_International(const int elo){elo_International=elo;}
    void set_elo_Online(const int elo){elo_Online=elo;}
    void set_Titlu(const char t[]){strcpy(titlu,t);}

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
    Jucator_Sah(const int elo1=0,const int elo2=0,const int elo3=0,const char titlu1[]="Unknown");
    Jucator_Sah(const Jucator_Sah&);
    Jucator_Sah& operator=(const Jucator_Sah &);

    friend istream& operator >>(istream &in,Jucator_Sah &);
    friend ostream& operator <<(ostream &out,Jucator_Sah &);
};

#endif // JUCATOR_SAH_H
