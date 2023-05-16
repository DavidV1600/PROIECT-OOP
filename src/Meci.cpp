#include <iostream>
#include <fstream>
#include "Meci.h" ///Mai tre sa o includ intrebare de pus
using namespace std;

Meci::Meci(Echipa* Echipa1, Echipa* Echipa2, int scor1, int scor2, bool rezultat_final)///constructor implicit
{
    Echipa_1.reset(Echipa1);
    Echipa_2.reset(Echipa2);
    scor_1 = scor1;
    scor_2 = scor2;
    rezultat_final = rezultat_final;
}
Meci::Meci(Meci& Gicu)///constructor de copiere
{
    Echipa_1 = std::move(Gicu.Echipa_1);
    Echipa_2 = std::move(Gicu.Echipa_2);
    scor_1 = Gicu.scor_1;
    scor_2 = Gicu.scor_2;
    rezultat_final = Gicu.rezultat_final;
}

Meci& Meci::operator=(const Meci& Gicu)///redefinire operator =
{
    if (this != &Gicu) {
        //Echipa_1.reset(Gicu.Echipa_1.release());//CUM FAC ASTA SA MEARGA desi cre ca nu imi mai trebe
        //Echipa_2.reset(Gicu.Echipa_2.release());//CUM FAC ASTA SA MEARGA desi cre ca nu imi mai trebe
        scor_1 = Gicu.scor_1;
        scor_2 = Gicu.scor_2;
        rezultat_final = Gicu.rezultat_final;
    }
    return *this;
}

Meci& Meci::operator=(Meci& Gicu)///redefinire operator =
{
    if (this != &Gicu) {
        Echipa_1.reset(Gicu.Echipa_1.release());
        Echipa_2.reset(Gicu.Echipa_2.release());
        scor_1 = Gicu.scor_1;
        scor_2 = Gicu.scor_2;
        rezultat_final = Gicu.rezultat_final;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Meci& Gicu)///redefinire operator << (Afisare Meci)
{
    out << Gicu.Echipa_1->get_Nume() << " " << Gicu.scor_1 << "-" << Gicu.scor_2 << " " << Gicu.Echipa_2->get_Nume() << '\n';
    return out;
}

