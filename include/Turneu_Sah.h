#pragma once
#include "Turneu.h"
#include "Premiu_Sah.h"
#include <cstring>
class Turneu_Sah : public Turneu
{
private:
	static int nr_Turnee_Sah;
	char data_Inceperii[20];
	char data_Terminarii[20];
	char nume_Organizator[30];
	char email_Organizator[30];
	char telefon_Organizator[11];
	char locatie[30];
	int varsta_Maxima;
	int elo_Maxim;
	int elo_Minim;
	Premiu_Sah *P;

public:

	void set_data_Inceperii(const char t[]) { strcpy(data_Inceperii, t); }
	void set_data_Terminarii(const char t[]) { strcpy(data_Terminarii, t); }
	void set_nume_Organizator(const char t[]) { strcpy(nume_Organizator, t); }
	void set_email_Organizator(const char t[]) { strcpy(email_Organizator, t); }
	void set_telefon_Organizator(const char t[]) { strcpy(telefon_Organizator, t); }
	void set_Locatie(const char t[]) { strcpy(locatie, t); }
	void set_varsta_Maxima(const int t) { varsta_Maxima = t; }
	void set_elo_Maxim(const int t) { elo_Maxim = t; }
	void set_elo_Minim(const int t) { elo_Minim = t; }
	void static set_nr_Turnee_Sah(const int nr) { nr_Turnee_Sah = nr; }
	void set_Premiu_Sah(Premiu_Sah* const p1) { P = p1; }

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
	const int get_elo_Maxim()const
	{
		return elo_Maxim;
	}
	const int get_elo_Minim()const
	{
		return elo_Minim;
	}
	static int get_nr_Turnee_Sah()
	{
		return nr_Turnee_Sah;
	}
	Premiu_Sah* get_Premiu_Sah()
	{
		return P;
	}

	Turneu_Sah(const char data_start[] = "Unknown", const char data_finish[] = "Unknown",
		const char nume_O[] = "Unknown", const char email_O[] = "Unknown",
		const char telefon_O[] = "Unknown", const char loc[] = "Unknown", int varsta_Max = 200, int elo_Max = 9999, int elo_Min = 0, Premiu_Sah* p1=nullptr);
	Turneu_Sah(const Turneu_Sah&);
	Turneu_Sah& operator=(const Turneu_Sah&);

	void Incepe_Turneu();
	void Sortare_Echipe_Inaintea_Rundei();
	void Editare_Turneu();
	void Citire_Turneu(istream&);
	friend void Alegere_Turneu_Sah(std::vector<std::shared_ptr<Turneu>>);

};

