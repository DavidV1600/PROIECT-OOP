#include <iostream>
#include <fstream>
#include "Turneu_Sah.h"
using namespace std;

Turneu_Sah::Turneu_Sah(const char data_start[], const char data_finish[],
	const char nume_O[], const char email_O[],
	const char telefon_O[], const char loc[], int varsta_Max, int elo_Max, int elo_Min) :Turneu(), varsta_Maxima(varsta_Max), elo_Maxim(elo_Max), elo_Minim(elo_Min)
{
	strcpy(locatie, loc);
	strcpy(data_Inceperii, data_start);
	strcpy(data_Terminarii, data_finish);
	strcpy(nume_Organizator, nume_O);
	strcpy(email_Organizator, email_O);
	strcpy(telefon_Organizator, telefon_O);

}

Turneu_Sah::Turneu_Sah(const Turneu_Sah& Gicu) : Turneu(Gicu)
{
    elo_Maxim=Gicu.elo_Maxim;
    elo_Minim=Gicu.elo_Minim;
    varsta_Maxima=Gicu.varsta_Maxima;
	strcpy(locatie, Gicu.locatie);
	strcpy(data_Inceperii, Gicu.data_Inceperii);
	strcpy(data_Terminarii, Gicu.data_Terminarii);
	strcpy(nume_Organizator, Gicu.nume_Organizator);
	strcpy(email_Organizator, Gicu.email_Organizator);
	strcpy(telefon_Organizator, Gicu.email_Organizator);
}


Turneu_Sah& Turneu_Sah::operator=(const Turneu_Sah& Gicu)
{
    if(this!=&Gicu){
    elo_Maxim=Gicu.elo_Maxim;
    elo_Minim=Gicu.elo_Minim;
    varsta_Maxima=Gicu.varsta_Maxima;
	strcpy(locatie, Gicu.locatie);
	strcpy(data_Inceperii, Gicu.data_Inceperii);
	strcpy(data_Terminarii, Gicu.data_Terminarii);
	strcpy(nume_Organizator, Gicu.nume_Organizator);
	strcpy(email_Organizator, Gicu.email_Organizator);
	strcpy(telefon_Organizator, Gicu.email_Organizator);
    }
    return *this;
}
