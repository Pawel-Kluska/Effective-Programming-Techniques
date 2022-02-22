#include <iostream>
#include "Fun_Alloc_Dealloc_2_Dim.h"
using namespace std;



bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX > 0 && iSizeY > 0)
	{
		(*piTable) = new int* [iSizeX];
		for (int i = 0; i < iSizeX; i++)
			(*piTable)[i] = new int[iSizeY];


		return true;
	}
	return false;
}

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if ((*piTable) != NULL)
	{
		for (int i = 0; i < iSizeX; i++)
			delete[](*piTable)[i];

		delete[](*piTable);
		return true;
	}
	return false;
}