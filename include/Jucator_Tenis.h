#pragma once
#include "Jucator.h"
#include "Sortari.h"
#include <memory>
using namespace std;
class Istoric_Jucator_Tenis;
class Jucator_Tenis : virtual public Jucator
{
protected:
	bool mana_Dominanta;
	int inaltime;
	int clasament_ATP;
	char club_Sportiv_Tenis[30];
	std::unique_ptr<Istoric_Jucator_Tenis>Istoric;
public:
	void set_mana_Dominanta(const bool mana) { mana_Dominanta = mana; }
	void set_Inaltime(const int inalt) { inaltime = inalt; }
	void set_clasament_ATP(const int clasament) { clasament_ATP = clasament; }
	void set_club_Sportiv_Tenis(const char text[]) { strcpy(club_Sportiv_Tenis, text); }

	const bool get_mana_Dominanta()const  { return mana_Dominanta; }
	const int get_Inaltime()const  { return inaltime; }
	const int get_Clasament_ATP() const { return clasament_ATP; }
	const char* get_club_Sportiv_Tenis()const  { return club_Sportiv_Tenis; }

	Jucator_Tenis(const bool mana = 0, const int inalt = 0,const int clasament=999, const char text[] = "Unknown");
	Jucator_Tenis(Jucator_Tenis&);
	Jucator_Tenis& operator=(const Jucator_Tenis&);
	~Jucator_Tenis();
	bool operator<(const Jucator_Tenis&);

	friend istream& operator>>(istream&, Jucator_Tenis&);
	friend ostream& operator<<(ostream&, Jucator_Tenis&);
	void Citire_Jucator(istream&);

};
