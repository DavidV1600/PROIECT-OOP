#include "Meci_Sah.h"

void Meci_Sah::schimba_Diferenta_Elo_International(Meci &M, Jucator_Sah & A,Jucator_Sah& B)
{
	int diferenta = A.get_elo_International() - B.get_elo_International();
	if (diferenta > 0)
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA + diferenta / 10 + 15);
			B.set_elo_International(elo_anteriorB - diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA - diferenta / 10 - 15);
			B.set_elo_International(elo_anteriorB + diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA - diferenta / 20);
			B.set_elo_International(elo_anteriorB + diferenta / 20);
		}
	}
	else
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA - diferenta / 10 + 15);
			B.set_elo_International(elo_anteriorB + diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA + diferenta / 10 - 15);
			B.set_elo_International(elo_anteriorB - diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_International();
			int elo_anteriorB = B.get_elo_International();
			A.set_elo_International(elo_anteriorA + diferenta / 20);
			B.set_elo_International(elo_anteriorB - diferenta / 20);
		}
	}
}

void Meci_Sah::schimba_Diferenta_Elo_National(Meci& M, Jucator_Sah& A, Jucator_Sah& B)
{
	int diferenta = A.get_elo_National() - B.get_elo_National();
	if (diferenta > 0)
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA + diferenta / 10 + 15);
			B.set_elo_National(elo_anteriorB - diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA - diferenta / 10 - 15);
			B.set_elo_National(elo_anteriorB + diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA - diferenta / 20);
			B.set_elo_National(elo_anteriorB + diferenta / 20);
		}
	}
	else
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA - diferenta / 10 + 15);
			B.set_elo_National(elo_anteriorB + diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA + diferenta / 10 - 15);
			B.set_elo_National(elo_anteriorB - diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_National();
			int elo_anteriorB = B.get_elo_National();
			A.set_elo_National(elo_anteriorA + diferenta / 20);
			B.set_elo_National(elo_anteriorB - diferenta / 20);
		}
	}
}

void Meci_Sah::schimba_Diferenta_Elo_Online(Meci& M, Jucator_Sah& A, Jucator_Sah& B)
{
	int diferenta = A.get_elo_Online() - B.get_elo_Online();
	if (diferenta > 0)
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA + diferenta / 10 + 15);
			B.set_elo_Online(elo_anteriorB - diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA - diferenta / 10 - 15);
			B.set_elo_Online(elo_anteriorB + diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA - diferenta / 20);
			B.set_elo_Online(elo_anteriorB + diferenta / 20);
		}
	}
	else
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA - diferenta / 10 + 15);
			B.set_elo_Online(elo_anteriorB + diferenta / 10 - 15);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA + diferenta / 10 - 15);
			B.set_elo_Online(elo_anteriorB - diferenta / 10 + 15);
		}
		else
		{
			int elo_anteriorA = A.get_elo_Online();
			int elo_anteriorB = B.get_elo_Online();
			A.set_elo_Online(elo_anteriorA + diferenta / 20);
			B.set_elo_Online(elo_anteriorB - diferenta / 20);
		}
	}
}
