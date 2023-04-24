#include "Istoric_Jucator_Sah.h"
#include <iostream>
void Istoric_Jucator_Sah::Afiseaza_Adversarii()
{
	for (int i = 0; i < Adversari.size(); ++i)
	{
		std::cout << Adversari[i]->get_Nume()<<'\n';
	}
}

void Istoric_Jucator_Sah::Afiseaza_Progres()
{
	for (int i = 0; i < Progresul_Jucatorului.size(); ++i)
	{
		std::cout << Progresul_Jucatorului[i]<<'\n';
	}
}

Istoric_Jucator_Sah::Istoric_Jucator_Sah(const Istoric_Jucator_Sah& Gicu)
{
	for (int i = 0; i < Gicu.Adversari.size(); ++i)
	{
		Adversari.push_back(Gicu.Adversari[i]);
	}
	for (int i = 0; i < Gicu.Progresul_Jucatorului.size(); ++i)
	{
		Progresul_Jucatorului.push_back(Gicu.Progresul_Jucatorului[i]);
	}
}
