#include "Premiu_Tenis.h"
#include <iostream>
void Premiu_Tenis::seteaza_Suma_per_Premiu(const int suma_Totala)
{
	for (int i = 0; i < nr_Premii; ++i)
	{
		int suma_Acordata = 0;
		std::cout << "Introdu suma acordata pentru locul " << i + 1 << ": ";
		int cit;

		std::cin >> cit;
		Premii.push_back(cit);

	}
}

void Premiu_Tenis::seteaza_Procentaj_per_Premiu(const int suma_Totala)
{
	for (int i = 0; i < nr_Premii; ++i)
	{
		int suma_Acordata = 0;
		std::cout << "Introdu procentaj din suma totala acordat pentru locul " << i + 1 << ": ";
		int cit;

		std::cin >> cit;
		Premii.push_back(suma_Totala * cit / 100);

	}
	for (int i = 0; i < nr_Premii; ++i)
	{
		std::cout << Premii[i] << '\n';
	}
}

Premiu_Tenis::Premiu_Tenis(const int nr_Premii1,const int nr_Premianti1)
{
	nr_Premianti = nr_Premianti1;
	nr_Premii = nr_Premii1;
}

Premiu_Tenis::Premiu_Tenis(const Premiu_Tenis& Gicu)
{
	nr_Premianti = Gicu.nr_Premianti;
	nr_Premii = Gicu.nr_Premii;
	for (int i = 0; i < Gicu.Premii.size(); ++i)
	{
		Premii.push_back(Gicu.Premii[i]);
	}
}

Premiu_Tenis::~Premiu_Tenis()
{
	Premii.clear();
}
