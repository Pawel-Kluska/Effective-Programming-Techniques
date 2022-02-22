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
	
	CTable c_tab_0("c1", 6, 1), c_tab_1("c2",4,2);
	CTable test;

	/* initialize table */
	for (int i = 0; i < 6; i++)
	{
		c_tab_0.vSetValueAt(i, i);
	}

	for (int i = 0; i < 4; i++)
	{
		c_tab_1.vSetValueAt(i, i+50);
	}

	//c_tab_0 = c_tab_1;
	
	//c_tab_1.vPrint();

	test = c_tab_1 + c_tab_0;
	test.vPrint();
	//c_tab_1.vSetValueAt(2, 123);
	//test.ToString();
	c_tab_0.vPrint();


	test = c_tab_0 - 3;
	test.vPrint();
	
	test = c_tab_0 - 8;
	test.vPrint();

	test = c_tab_0 - (-9);
	test.vPrint();

	return 0;
}

