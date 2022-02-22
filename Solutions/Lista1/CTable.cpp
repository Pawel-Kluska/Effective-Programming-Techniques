#include <iostream>
#include "CTable.h"
#include "GlobalConst.h"

using namespace std;

CTable::CTable()
{
	s_name = S_DEF_TAB_NAME;
	pi_table = new int[I_DEF_TAB_LEN];
	iTable_Len = I_DEF_TAB_LEN;
	pi_Val = new int;
	*pi_Val = I_DEF_FIFTY_FIVE;
	cout << "Konstruktor bez parametrow: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLength, int iVal)
{
	s_name = sName;
	iTable_Len = iTableLength;
	pi_table = new int[iTableLength];
	pi_Val = new int;
	*pi_Val = iVal;
	cout << "Konstruktor z parametrami: " << s_name << endl;
}

CTable::CTable(CTable& pcOther) 
{
	s_name = (pcOther.s_name + "_copy");
	iTable_Len = pcOther.iTable_Len;
	pi_table = new int[iTable_Len];
	pi_Val = new int;
	*pi_Val = *(pcOther.pi_Val);

	for (int ii = 0; ii < iTable_Len; ii++) 
	{
		pi_table[ii] = pcOther.pi_table[ii];
	}

	cout << "Konstruktor kopiujacy " << s_name << endl;

}

CTable::~CTable()
{
	delete[] pi_table;
	delete pi_Val;
	cout << "Destruktor uzyty dla " + s_name<<endl;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLength)
{
	
	if (iTableLength > 0)
	{
		int* pi_table_new = new int[iTableLength];

		for (int i = 0; i < iTable_Len && i < iTableLength; i++) {
			pi_table_new[i] = pi_table[i];
		}

		delete[] pi_table;
		iTable_Len = iTableLength;
		pi_table = pi_table_new;
		return true;
	}
	return false;
}
	

CTable* CTable::pcClone()
{
	CTable* clone;
	clone = new CTable(*this);
	return clone;
}

void CTable::ToString()
{
	cout << "Nazwa: " << s_name << endl;
	cout << "Dlugosc: " << iTable_Len << endl;
	cout << "Val " << *pi_Val << endl;
	
}


void CTable::movPr(CTable&& pcOther)
{

}