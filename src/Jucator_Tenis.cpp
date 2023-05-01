#include <iostream>
#include <fstream>
#include "Jucator_Tenis.h"
using namespace std;

Jucator_Tenis::Jucator_Tenis(const bool mana, const int inalt,const int clasament, const char text[]):Jucator(),mana_Dominanta(mana),inaltime(inalt),clasament_ATP(clasament)
{
	strcpy(club_Sportiv_Tenis, text);
}

Jucator_Tenis::Jucator_Tenis(Jucator_Tenis& Gicu): Jucator(Gicu)
{
	mana_Dominanta = Gicu.mana_Dominanta;
	inaltime = Gicu.inaltime;
	clasament_ATP = Gicu.clasament_ATP;
	strcpy(club_Sportiv_Tenis,Gicu.club_Sportiv_Tenis);
}

Jucator_Tenis& Jucator_Tenis::operator=(const Jucator_Tenis& Gicu)
{
	if (this != &Gicu)
	{
		Jucator::operator=(Gicu);
		mana_Dominanta = Gicu.mana_Dominanta;
		inaltime = Gicu.inaltime;
		clasament_ATP = Gicu.clasament_ATP;
		strcpy(club_Sportiv_Tenis, Gicu.club_Sportiv_Tenis);
	}
	return *this;
}

istream& operator>>(istream& in, Jucator_Tenis& Gicu)
{
	in >> static_cast<Jucator&>(Gicu);
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
	out << "Clubul Sportiv: " << Gicu.club_Sportiv_Tenis<<'\n';
	return out;
}

void Jucator_Tenis::Citire_Jucator(istream& in)
{
	cout << "Sunt la jucator tenis\n";
	this->Jucator::Citire_Jucator(in);///ACI E DUBIOS AR TREBUI SA PUN CITIREA DE LA TENIS
	cout << "Introdu mana dominanta 0-Dreapta, 1-Stanga: ";

	in >> this->mana_Dominanta;
	cout << "Introdu inaltimea jucatorului (cm): ";

	in >> this->inaltime;
	cout << "Introdu clubul sportiv la care activeaza jucatorul: ";

	in >> this->club_Sportiv_Tenis;
	in.get();
	cout << '\n';
}
