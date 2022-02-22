#include <iostream>
#include "CTable.h"
#include "GlobalConst.h"

using namespace std;

CTable::CTable()
{
	s_name = S_DEF_TAB_NAME;
	pi_table = new int[I_DEF_TAB_LEN];
	i_tab_len = I_DEF_TAB_LEN;
	pi_Val = new int;
	*pi_Val = I_DEF_VALUE;
	cout << "Konstruktor bez parametrow: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLength, int iVal)
{
	s_name = sName;
	i_tab_len = iTableLength;
	pi_table = new int[iTableLength];
	pi_Val = new int;
	*pi_Val = iVal;
	cout << "Konstruktor z parametrami: " << s_name << endl;
}

CTable::CTable(CTable& pcOther) 
{
	s_name = (pcOther.s_name + "_copy");
	i_tab_len = pcOther.i_tab_len;
	pi_table = new int[i_tab_len];
	pi_Val = new int;
	*pi_Val = *(pcOther.pi_Val);

	for (int ii = 0; ii < i_tab_len; ii++) 
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
	if (iTableLength >= 0)
	{
		int* pi_table_new = new int[iTableLength];

		for (int ii = 0; ii < i_tab_len && ii < iTableLength; ii++) {
			pi_table_new[ii] = pi_table[ii];
		}

		delete[] pi_table;
		i_tab_len = iTableLength;
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
	cout << "Dlugosc: " << i_tab_len << endl;
	cout << "Val " << *pi_Val << endl;
	
}

/*
void CTable::operator=(const CTable& pcOther)
{
	pi_table = pcOther.pi_table;
	i_tab_len = pcOther.i_tab_len;
	s_name = pcOther.s_name;
}

*/

void CTable::operator=(const CTable& pcOther)
{
	delete[] pi_table;
	delete pi_Val;
	i_tab_len = pcOther.i_tab_len;
	s_name = pcOther.s_name;
	pi_Val = new int;
	*pi_Val = *(pcOther.pi_Val);
	pi_table = new int[i_tab_len];

	for (int ii = 0; ii < i_tab_len; ii++)
	{
		pi_table[ii] = pcOther.pi_table[ii];
	}
}



void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset >= 0 && iOffset < i_tab_len)
	{
		pi_table[iOffset] = iNewVal;
	}
	else
		cout << "Bledna wartosc\n";
}

void CTable::vPrint()
{
	cout << endl;
	for (int i = 0; i < i_tab_len; i++)
	{
		cout << pi_table[i] << " ";
	}
	cout << endl;
}

CTable CTable::operator+(CTable& pcOther)
{
	CTable new_pi_tab(*this);
	new_pi_tab.bSetNewSize(i_tab_len + pcOther.i_tab_len);

	for (int i = 0; i < pcOther.i_tab_len; i++)
	{
		new_pi_tab.pi_table[i+i_tab_len] = pcOther.pi_table[i];
	}
	return new_pi_tab;
}
	
CTable CTable::operator-(int value)
{
	CTable new_pi_tab(*this);

	if (value > 0) {
		if (i_tab_len - value > 0) 
		{
			new_pi_tab.bSetNewSize(i_tab_len - value);

		}
		else
			new_pi_tab.bSetNewSize(0);
	}
	return new_pi_tab;
}
