#include "CTab.h"
#include <iostream>


CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab::CTab(CTab&& cOther) noexcept
{
	v_move(cOther);
	std::cout << "MOVE ";
}

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}

void CTab::operator=(const CTab& cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);

}

void CTab::operator=(CTab&& cOther) noexcept
{
	if (pi_tab != NULL) delete pi_tab;
	v_move(cOther);

}

void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}


bool CTab::bSetSize(int iNewSize)
{
	if (iNewSize > 0)
	{
		int* pi_table_new = new int[iNewSize];

		for (int i = 0; i < i_size && i < iNewSize; i++) {
			pi_table_new[i] = pi_tab[i];
		}

		delete[] pi_tab;
		i_size = iNewSize;
		pi_tab = pi_table_new;
		return true;
	}
	return false;
}



void CTab::v_move(CTab& pcOther)
{
	pi_tab = pcOther.pi_tab;
	i_size = pcOther.i_size;
	pcOther.pi_tab = NULL;
	pcOther.i_size = 0;

}

CTab CTab::cCreateTab()
{
	CTab c_result;
	c_result.bSetSize(5);
	return(std::move(c_result));
}
