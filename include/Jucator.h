#ifndef JUCATOR_H
#define JUCATOR_H
using namespace std;

class Jucator
{
private:

    char cnp[14];
    char nr_Telefon[11];
    char *nume;   ///Astea cre ca nu ae rost sa le las dinamic
    char *prenume;
    char *email;
    int varsta;
    bool sex;
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
    const bool get_Sex()const
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
    void set_Sex(const bool);
    void set_Elo(const int);
    void set_Email(const char text[]);
    void set_NrTelefon(const char text[]);

    void afis_cnp()
    {
        cout<<prenume<<varsta<<sex<<elo;
    }
///SA PUN CONST UNDE TREBE
    Jucator(char cnp_1[]="Unknown", char nume_1[]="Unknown", char prenume_1[]="Unknown", int varsta_1=0, bool sex_1=false, int elo_1=0,char email1[]="Unknown",char nr_Telefon1[]="Unknown");///Constructor
    Jucator(const Jucator &); ///Constructor de copiere
    ~Jucator(); ///Destructor

    Jucator& operator=(const Jucator &); ///Operatorul =      Daca e mai bine sa-i declar friend sau normal
    friend ostream & operator <<(ostream &, const Jucator &); ///Operatorul <<
    friend istream & operator >>(istream &, Jucator &);
};

#endif // JUCATOR_H
