#include <iostream>
#include "Fun_Alloc_Dealloc_2_Dim.h"
#include "CTable.h"
#include "GlobalConst.h"
#include "Fun_Alloc_Tab_Add_5.h"
#include "Fun_Set_Size_CTable.h"
using namespace std;

void testModyfikacji()
{
	CTable C_ORIGI;
	C_ORIGI.ToString();
	CTable C_COPY(C_ORIGI);
	C_COPY.ToString();
}


int main()
{
	int** tab;
	/*
	v_alloc_table_add_5(I_DEF_TAB_LEN);
	cout << b_alloc_table_2_dim(&tab, I_DEF_TAB_X_LEN, I_DEF_TAB_Y_LEN);
	cout << b_dealloc_table_2_dim(&tab, I_DEF_TAB_X_LEN, I_DEF_TAB_Y_LEN);

	cout << endl;

	
	CTable* t1 = new CTable();
	v_mod_tab1(t1, 22);
	t1->ToString();
	delete t1;
	CTable t2;
	v_mod_tab2(t2, 101);
	t2.ToString();
	*/

	testModyfikacji();

	CTable* CTest = new CTable("Dynamiczna",22,1);
	CTable CTest_copy(*CTest);
	CTest_copy.ToString();

	delete CTest;

	return 0;
}

