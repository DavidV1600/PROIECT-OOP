#pragma once
#include <vector>
#include "Jucator.h"
template <class T=Jucator>
class Istoric_Jucator
{
protected:
	vector<int>Progresul_Jucatorului;
	vector<T*>Adversari;
public:
	virtual void Afiseaza_Adversarii() = 0;
	virtual void Afiseaza_Progres() = 0;
	~Istoric_Jucator() {///DE CE AVEAM EROARE INAINTE cand era declarat in CPP??
		Progresul_Jucatorului.clear();
		Adversari.clear();
	}
};

