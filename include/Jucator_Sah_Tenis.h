#pragma once
#include "Jucator_Sah.h"
#include "Jucator_Tenis.h"
#include <iostream>
class Jucator_Sah_Tenis :public Jucator_Sah,public Jucator_Tenis
{


	friend ostream& operator <<(ostream&, Jucator_Sah_Tenis&);
	friend istream& operator >>(istream&, Jucator_Sah_Tenis&);
	void Citire_Jucator(istream&);
};

