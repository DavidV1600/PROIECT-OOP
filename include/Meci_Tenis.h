#pragma once
#include "Meci.h"
#include "Jucator_Tenis.h"
#include <cstring>
class Meci_Tenis :
    private Meci, private Jucator_Tenis
{
private:
    int nr_Seturi;
    string Setul1;
    string Setul2;
    string Setul3;
    string Setul4;
    string Setul5;
public:
    void set_nr_Seturi(const int nr) { nr_Seturi = nr; }
    void set_Setul1(const string text) { Setul1=text; }
    void set_Setul2(const string text) { Setul2=text; }
    void set_Setul3(const string text) { Setul3=text; }
    void set_Setul4(const string text) { Setul4=text; }
    void set_Setul5(const string text) { Setul5=text; }
    const int get_nr_Seturi()const { return nr_Seturi; }
    const string get_Setul1()const { return Setul1; }
    const string get_Setul2()const { return Setul2; }
    const string get_Setul3()const { return Setul3; }
    const string get_Setul4()const { return Setul4; }
    const string get_Setul5()const { return Setul5; }
    void schimba_Clasament_ATP(Meci&, Jucator_Tenis&, Jucator_Tenis&);

};

