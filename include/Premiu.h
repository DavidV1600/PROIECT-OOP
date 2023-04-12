#pragma once
class Premiu
{
protected:
	virtual void set_nr_Premianti(const int nr) = 0;
	virtual void set_nr_Premi(const int nr) = 0;
	virtual const int get_nr_Premianti()const  = 0;
	virtual const int get_nr_Premii()const  = 0;
	virtual void seteaza_Suma_per_Premiu(const int suma_Totala) = 0;
	virtual void seteaza_Procentaj_per_Premiu(const int suma_Totala) = 0;
	virtual ~Premiu() {};
};

