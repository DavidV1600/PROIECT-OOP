#include "Jucator_Sah_Tenis.h"
using namespace std;


void Jucator_Sah_Tenis::Citire_Jucator(istream &in)
{
	std::cout << "Citire jucator de ambele sporturi:\n";
	this->Jucator::Citire_Jucator(in);
    do {
        cout << "Introdu elo-International: ";///nus daca sa pun si aci:
        in >> this->elo_International;
        if (this->elo_International < 0 || this->elo_International>3200)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu elo-National: ";
        in >> this->elo_National;
        if (this->elo_National < 0 || this->elo_National>3200)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu elo-Online: ";
        in >> this->elo_Online;
        if (this->elo_Online < 0 || this->elo_Online>4000)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    do {
        cout << "Introdu Titlu: ";
        in >> this->titlu;
        if (Jucator_Sah::validare_Titlu(this->titlu) == 0)
            cout << "Introducere invalida!\n";
        else break;
    } while (true);
    cout << "Introdu Club Sportiv de sah la care activeaza jucatorul: ";
    in >> this->club_Sportiv_Tenis;
    cout << "Introdu Username Online: ";
    in >> this->nume_Online;
    cout << "Introdu mana dominanta 0-Dreapta, 1-Stanga: ";

    in >> this->mana_Dominanta;
    cout << "Introdu inaltimea jucatorului (cm): ";

    in >> this->inaltime;
    cout << "Introdu clubul sportiv de tenis la care activeaza jucatorul: ";

    in >> this->club_Sportiv_Tenis;
    in.get();
    cout << '\n';
}

istream& operator>>(istream& in, Jucator_Sah_Tenis& Gicu)
{
	in >> static_cast<Jucator&>(Gicu);
	return in;
}

ostream& operator<<(ostream& out, Jucator_Sah_Tenis& Gicu)
{
    out << static_cast<Jucator&>(Gicu);
    cout << "Elo-International: " << Gicu.get_elo_International();
    cout << "\nElo-National: " << Gicu.get_elo_National();
    cout << "\nElo-Online: " << Gicu.get_elo_Online();
    cout << "\nTitlu: " << Gicu.get_Titlu();
    cout << "\nClub Sportiv: " << Gicu.get_club_Sportiv_Sah();
    cout << '\n';
    out << "Mana Dominanta: ";
    if (Gicu.mana_Dominanta == 0)
        out << "Dreapta\n";
    else out << "Stanga\n";
    out << "Inaltimea Jucatorului (cm): " << Gicu.inaltime << '\n';
    out << "Clasamentul ATP: " << Gicu.clasament_ATP << '\n';
    out << "Clubul Sportiv: " << Gicu.club_Sportiv_Tenis << '\n';
    return out;
}
