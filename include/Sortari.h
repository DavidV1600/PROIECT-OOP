#pragma once
#include "Jucator_Tenis.h"
#include <memory>
#include <vector>
template <class T>
	void Compara(T& a, T& b)
	{
		if (a < b) {
			T temp;
			temp = a;
			a = b;
			b = temp;
		}
	}


template <class T>
	void Sortare(T& A, int n)///Tre sa fac cu *A[i] pentru vectorul de shared pointeri
	{
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				Compara(A[i], A[j]);
	}
//template<>
//void Sortare <vector<std::shared_ptr<Jucator_Tenis>>>(vector<std::shared_ptr<Jucator_Tenis>>& A, int n);///sa-l declar in cpp

