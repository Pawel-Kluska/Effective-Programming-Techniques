#include <iostream>
#include "GlobalConst.h"
#include "Fun_Alloc_Tab_Add_5.h"

using namespace std;


bool v_alloc_table_add_5(int iSize)
{
	if (iSize > 0)
	{
		int* tablica;
		tablica = new int[iSize];
		int* pom = tablica;

		for (int i = 0; i < iSize; i++)
		{
			*pom = i + I_DEF_FIVE;
			pom++;
		}

		for (int i = 0; i < iSize; i++)
		{
			cout << tablica[i] << " ";

		}

		cout << endl;
		delete[] tablica;

		return true;
	}
	return false;
}