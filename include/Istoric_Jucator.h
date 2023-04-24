#pragma once
#include <vector>
#include "Jucator.h"
class Istoric_Jucator
{
protected:
	vector<int>Progresul_Jucatorului;
	vector<Jucator*>Adversari;
public:
	virtual void Afiseaza_Adversarii() = 0;
	virtual void Afiseaza_Progres() = 0;
	~Istoric_Jucator();
};

