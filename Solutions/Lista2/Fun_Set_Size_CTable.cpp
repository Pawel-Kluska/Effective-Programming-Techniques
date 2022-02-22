#include <iostream>
#include "Fun_Set_Size_CTable.h"

using namespace std;

void v_mod_tab1(CTable* pcTab, int iNewSize)
{
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab2(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);
}
