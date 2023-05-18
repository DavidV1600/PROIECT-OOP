#pragma once
#include "Turneu.h"
#include <cstring>
class Turneu_Tenis : public Turneu
{
private:
	static int nr_Turnee_Tenis;
	char data_Inceperii[20];
	char data_Terminarii[20];
	char nume_Organizator[30];
	char email_Organizator[30];
	char telefon_Organizator[11];
	char locatie[30];
	int varsta_Maxima;
	int clasament_Maxim;
	int clasament_Minim;
public:

	void set_data_Inceperii(const char t[]) { strcpy(data_Inceperii, t); }
	void set_data_Terminarii(const char t[]) { strcpy(data_Terminarii, t); }
	void set_nume_Organizator(const char t[]) { strcpy(nume_Organizator, t); }
	void set_email_Organizator(const char t[]) { strcpy(email_Organizator, t); }
	void set_telefon_Organizator(const char t[]) { strcpy(telefon_Organizator, t); }
	void set_Locatie(const char t[]) { strcpy(locatie, t); }
	void set_varsta_Maxima(const int t) { varsta_Maxima = t; }
	void set_clasament_Maxim(const int t) { clasament_Maxim = t; }
	void set_clasament_Minim(const int t) { clasament_Minim = t; }
	void static set_nr_Turnee_Tenis(const int nr) { nr_Turnee_Tenis = nr; }

	const char* get_data_Inceperii() const
	{
		return data_Inceperii;
	}
	const char* get_data_Terminarii()const
	{
		return data_Terminarii;
	}
	const char* get_nume_Organizator()const
	{
		return nume_Organizator;
	}
	const char* get_email_Organizator()const
	{
		return email_Organizator;
	}
	const char* get_telefon_Organizator()const
	{
		return telefon_Organizator;
	}
	const char* get_Locatie()const
	{
		return locatie;
	}
	const int get_varsta_Maxima()const
	{
		return varsta_Maxima;
	}
	const int get_clasament_Maxim()const
	{
		return clasament_Maxim;
	}
	const int get_clasament_Minim()const
	{
		return clasament_Minim;
	}
	static int get_nr_Turnee_Tenis()
	{
		return nr_Turnee_Tenis;
	}

	Turneu_Tenis(const char data_start[] = "Unknown", const char data_finish[] = "Unknown",
		const char nume_O[] = "Unknown", const char email_O[] = "Unknown",
		const char telefon_O[] = "Unknown", const char loc[] = "Unknown",const int varsta_Max = 200,const int clasament_Max = 9999,const int clasament_Min = 0);
	Turneu_Tenis(const Turneu_Tenis&);
	Turneu_Tenis& operator=(const Turneu_Tenis&);

	void Incepe_Turneu();
	void Sortare_Echipe_Inaintea_Rundei();
	void Editare_Turneu();
	void Citire_Turneu(istream&);
	friend void Alegere_Turneu_Tenis(std::vector<std::shared_ptr<Turneu>>);
};

