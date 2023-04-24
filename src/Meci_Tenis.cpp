#include "Meci_Tenis.h"

void Meci_Tenis::schimba_Clasament_ATP(Meci& M, Jucator_Tenis& A, Jucator_Tenis& B)
{
	int diferenta = A.get_Clasament_ATP() - B.get_Clasament_ATP();
	if (diferenta > 0)
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int clasament_antA = A.get_Clasament_ATP();
			int clasament_antB = B.get_Clasament_ATP();
			A.set_clasament_ATP(clasament_antA - diferenta / 10 + 1);
			B.set_clasament_ATP(clasament_antB + diferenta / 10 - 1);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int clasament_antA = A.get_Clasament_ATP();
			int clasament_antB = B.get_Clasament_ATP();
			A.set_clasament_ATP(clasament_antA + diferenta / 10 - 1);
			B.set_clasament_ATP(clasament_antB - diferenta / 10 + 1);
		}
	}
	else
	{
		if (M.get_scor_1() > M.get_scor_2())
		{
			int clasament_antA = A.get_Clasament_ATP();
			int clasament_antB = B.get_Clasament_ATP();
			A.set_clasament_ATP(clasament_antA + diferenta / 10 + 1);
			B.set_clasament_ATP(clasament_antB - diferenta / 10 - 1);
		}
		else if (M.get_scor_1() < M.get_scor_2())
		{
			int clasament_antA = A.get_Clasament_ATP();
			int clasament_antB = B.get_Clasament_ATP();
			A.set_clasament_ATP(clasament_antA - diferenta / 10 - 1);
			B.set_clasament_ATP(clasament_antB + diferenta / 10 + 1);
		}
	}

}
