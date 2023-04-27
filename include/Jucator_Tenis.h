#ifndef Jucator_TENIS_H
#define Jucator_TENIS_H

#include "Jucator.h"
#include <cstring>
using namespace std;

class Jucator_Tenis : public Jucator
{
private:
	bool mana_Dominanta;
	int inaltime;
	int clasament_ATP;
	char club_Sportiv[30];
public:
	void set_mana_Dominanta(const bool mana) { mana_Dominanta = mana; }
	void set_Inaltime(const int inalt) { inaltime = inalt; }
	void set_clasament_ATP(const int clasament) { clasament_ATP = clasament; }
	void set_club_Sportiv(const char text[]) { strcpy(club_Sportiv, text); }

	const bool get_mana_Dominanta()const  { return mana_Dominanta; }
	const int get_Inaltime()const  { return inaltime; }
	const int get_Clasament_ATP() const { return clasament_ATP; }
	const char* get_club_Sportiv()const  { return club_Sportiv; }

	Jucator_Tenis(const bool mana = 0, const int inalt = 0,const int clasament=999, const char text[] = "Unknown");
	Jucator_Tenis(Jucator_Tenis&);
	Jucator_Tenis& operator=(const Jucator_Tenis&);

	friend istream& operator>>(istream&, Jucator_Tenis&);
	friend ostream& operator<<(ostream&, Jucator_Tenis&);
	void Citire_Jucator(istream&);

};
#endif
