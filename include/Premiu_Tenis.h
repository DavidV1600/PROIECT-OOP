#pragma once
#include "Premiu.h"
#include <vector>
class Premiu_Tenis :
    public Premiu
{
private:
    std::vector<int>Premii;
    int nr_Premii;
    int nr_Premianti;
public:

	void set_nr_Premianti(const int nr) override { nr_Premianti = nr; }
	void set_nr_Premi(const int nr) override { nr_Premii = nr; }
	const int get_nr_Premianti()const override { return nr_Premianti; }
	const int get_nr_Premii() const override { return nr_Premii; };
	void seteaza_Suma_per_Premiu(const int suma_Totala);
	void seteaza_Procentaj_per_Premiu(const int suma_Totala);

	Premiu_Tenis(int nr_Premii1 = 0, int nr_Premianti1 = 0);
	Premiu_Tenis(const Premiu_Tenis&);
	~Premiu_Tenis();
};

