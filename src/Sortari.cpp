#include "Sortari.h"
template<>///In codeblocks trebe ???
void Sortare <vector<std::shared_ptr<Jucator_Tenis>>>(vector<std::shared_ptr<Jucator_Tenis>>& A, int n)///sa-l declar in cpp
{
	vector<std::shared_ptr<Jucator_Tenis>> B;
	for (int i = 1; i < 1000; ++i) {
		for (int j = 0; j < n; ++j)
		{
			if (A[j]->get_Clasament_ATP() == i)
				B.push_back(A[j]);
		}
	}
	for (int i = 0; i < n; ++i)
		A[i] = B[i];
	B.clear();
}
