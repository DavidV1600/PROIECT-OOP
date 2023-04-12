#include <iostream>
#include <fstream>
#include "Jucator_Sah.h"
using namespace std;

Jucator_Sah::Jucator_Sah(const int elo1, const int elo2, const int elo3, const char titlu1[], const char club[], const char nume_Online1[]) :Jucator(), elo_National(elo1), elo_International(elo2), elo_Online(elo3)
{
    strcpy(titlu, titlu1);
    strcpy(club_Sportiv, club);
    strcpy(nume_Online, nume_Online1);
}

Jucator_Sah::Jucator_Sah(const Jucator_Sah& Gicu) : Jucator(Gicu)
{
    elo_International = Gicu.elo_International;
    elo_National = Gicu.elo_National;
    elo_Online = Gicu.elo_Online;
    strcpy(titlu, Gicu.titlu);
    strcpy(club_Sportiv, Gicu.club_Sportiv);
    strcpy(nume_Online, Gicu.nume_Online);
}

Jucator_Sah& Jucator_Sah::operator=(const Jucator_Sah& Gicu)
{
    if (this != &Gicu)
    {
        Jucator::operator=(Gicu);
        elo_International = Gicu.elo_International;
        elo_National = Gicu.elo_National;
        elo_Online = Gicu.elo_Online;
        strcpy(titlu, Gicu.titlu);
        strcpy(club_Sportiv, Gicu.club_Sportiv);
        strcpy(nume_Online, Gicu.nume_Online);
    }
    return *this;
}

istream& operator >>(istream& in, Jucator_Sah& Gicu)
{
    in >> static_cast<Jucator&>(Gicu);
    cout << "Introdu elo-International: ";
    in >> Gicu.elo_International;
    cout << "Introdu elo-National: ";
    in >> Gicu.elo_National;
    cout << "Introdu elo-Online: ";
    in >> Gicu.elo_Online;
    cout << "Introdu Titlu: ";
    in >> Gicu.titlu;
    cout << "Introdu Club Sportiv: ";
    in >> Gicu.club_Sportiv;
    cout << "Introdu Username Online: ";
    in >> Gicu.nume_Online;
    in.get();
    cout << '\n';
    return in;
}

ostream& operator <<(ostream& out, Jucator_Sah& Gicu)
{
    out << static_cast<Jucator&>(Gicu);
    cout << "\nElo-International: " << Gicu.get_elo_International();
    cout << "\nElo-National: " << Gicu.get_elo_National();
    cout << "\nElo-Online: " << Gicu.get_elo_Online();
    cout << "\nTitlu: " << Gicu.get_Titlu();
    cout << "\nClub Sportiv: " << Gicu.get_club_Sportiv();
    cout << '\n';
    return out;
}
