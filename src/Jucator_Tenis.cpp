#include <iostream>
#include <fstream>
#include "Jucator_Tenis.h"
using namespace std;

Jucator_Tenis::Jucator_Tenis(const bool mana, const int inalt,const int clasament, const char text[]):Jucator(),mana_Dominanta(mana),inaltime(inalt),clasament_ATP(clasament)
{
	strcpy(club_Sportiv, text);
}

Jucator_Tenis::Jucator_Tenis(Jucator_Tenis& Gicu): Jucator(Gicu)
{
	mana_Dominanta = Gicu.mana_Dominanta;
	inaltime = Gicu.inaltime;
	clasament_ATP = Gicu.clasament_ATP;
	strcpy(club_Sportiv,Gicu.club_Sportiv);
}

Jucator_Tenis& Jucator_Tenis::operator=(const Jucator_Tenis& Gicu)
{
	if (this != &Gicu)
	{
		Jucator::operator=(Gicu);
		mana_Dominanta = Gicu.mana_Dominanta;
		inaltime = Gicu.inaltime;
		clasament_ATP = Gicu.clasament_ATP;
		strcpy(club_Sportiv, Gicu.club_Sportiv);
	}
	return *this;
}

istream& operator>>(istream& in, Jucator_Tenis& Gicu)
{
	in >> static_cast<Jucator&>(Gicu);
	cout << "Introdu mana dominanta 0-Dreapta, 1-Stanga: ";

	in >> Gicu.mana_Dominanta;
	cout << "Introdu inaltimea jucatorului (cm): ";

	in >> Gicu.inaltime;
	cout << "Introdu clubul sportiv la care activeaza jucatorul: ";

	in >> Gicu.club_Sportiv;
	in.get();
	cout << '\n';
	return in;
}

ostream& operator<<(ostream& out,Jucator_Tenis& Gicu)
{
	out << static_cast<Jucator&>(Gicu);
	out << "Mana Dominanta: ";
	if (Gicu.mana_Dominanta == 0)
		out << "Dreapta\n";
	else out << "Stanga\n";
	out << "Inaltimea Jucatorului (cm): " << Gicu.inaltime << '\n';
	out << "Clasamentul ATP: " << Gicu.clasament_ATP << '\n';
	out << "Clubul Sportiv: " << Gicu.club_Sportiv<<'\n';
	return out;
}
