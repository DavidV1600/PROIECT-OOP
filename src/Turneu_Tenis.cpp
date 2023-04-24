#include <iostream>
#include <fstream>
#include "Turneu_Tenis.h"
using namespace std;

Turneu_Tenis::Turneu_Tenis(const char data_start[], const char data_finish[],
	const char nume_O[], const char email_O[],
	const char telefon_O[], const char loc[], int varsta_Max, int clasament_Max, int clasament_Min) :Turneu(), varsta_Maxima(varsta_Max), clasament_Maxim(clasament_Max), clasament_Minim(clasament_Min)
{
	strcpy(locatie, loc);
	strcpy(data_Inceperii, data_start);
	strcpy(data_Terminarii, data_finish);
	strcpy(nume_Organizator, nume_O);
	strcpy(email_Organizator, email_O);
	strcpy(telefon_Organizator, telefon_O);

}

Turneu_Tenis::Turneu_Tenis(const Turneu_Tenis& Gicu) : Turneu(Gicu)
{
	clasament_Maxim = Gicu.clasament_Maxim;
	clasament_Minim = Gicu.clasament_Minim;
	varsta_Maxima = Gicu.varsta_Maxima;
	strcpy(locatie, Gicu.locatie);
	strcpy(data_Inceperii, Gicu.data_Inceperii);
	strcpy(data_Terminarii, Gicu.data_Terminarii);
	strcpy(nume_Organizator, Gicu.nume_Organizator);
	strcpy(email_Organizator, Gicu.email_Organizator);
	strcpy(telefon_Organizator, Gicu.email_Organizator);
}


Turneu_Tenis& Turneu_Tenis::operator=(const Turneu_Tenis& Gicu)
{
	if (this != &Gicu) {
		clasament_Maxim = Gicu.clasament_Maxim;
		clasament_Minim = Gicu.clasament_Minim;
		varsta_Maxima = Gicu.varsta_Maxima;
		strcpy(locatie, Gicu.locatie);
		strcpy(data_Inceperii, Gicu.data_Inceperii);
		strcpy(data_Terminarii, Gicu.data_Terminarii);
		strcpy(nume_Organizator, Gicu.nume_Organizator);
		strcpy(email_Organizator, Gicu.email_Organizator);
		strcpy(telefon_Organizator, Gicu.email_Organizator);
	}
	return *this;
}

void Turneu_Tenis::Incepe_Turneu()
{
	///Urmeaza sa implementez
	std::cout << "Sunt in clasa Tenis cand urmeaza sa implementez turneul de tenis\n";
}
