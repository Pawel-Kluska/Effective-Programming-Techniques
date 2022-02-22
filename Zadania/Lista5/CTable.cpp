#include <iostream>
#include "GlobalConst.h"
#include "CTable.h"

using namespace std;

CTable::CTable()
{
	s_name = S_DEF_TAB_NAME;
	pi_table = new int[I_DEF_TAB_LEN];
	iTable_Len = I_DEF_TAB_LEN;
	cout << "Konstruktor bez parametrow: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLength)
{
	s_name = sName;
	iTable_Len = iTableLength;
	pi_table = new int[iTableLength];

	cout << "Konstruktor z parametrami: " << s_name << endl;
}

CTable::CTable(const CTable& pcOther)
{

	v_copy(pcOther);
	cout << "Konstruktor kopiujacy " << s_name << endl;

}

CTable::~CTable()
{
	delete[] pi_table;
	cout << "Destruktor uzyty dla " + s_name << endl;
}

CTable::CTable(CTable&& pcOther) noexcept
{
	v_move(pcOther);

	cout << "Konstruktor przenoszacy " << s_name << endl;
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

}

void CTable::operator=(const CTable& pcOther)
{
	if (pi_table != NULL) delete pi_table;
	v_copy(pcOther);

}

void CTable::operator=(CTable&& cOther) noexcept
{
	if (pi_table != NULL) delete pi_table;
	v_move(cOther);

}


void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset >= 0 && iOffset < iTable_Len)
	{
		pi_table[iOffset] = iNewVal;
	}
	else
		cout << "Bledna wartosc\n";
}

void CTable::vPrint()
{
	cout << endl;
	for (int i = 0; i < iTable_Len; i++)
	{
		cout << pi_table[i] << " ";
	}
	cout << endl;
}

CTable CTable::operator+(CTable& pcOther)
{
	CTable new_pi_tab = (*this);
	new_pi_tab.bSetNewSize(iTable_Len + pcOther.iTable_Len);

	for (int i = 0; i < pcOther.iTable_Len; i++)
	{
		new_pi_tab.pi_table[i + iTable_Len] = pcOther.pi_table[i];
	}
	return move(new_pi_tab);
}

CTable CTable::operator-(int value)
{
	CTable new_pi_tab = (*this);

	if (value > 0) {
		if (iTable_Len - value > 0)
		{
			new_pi_tab.bSetNewSize(iTable_Len - value);

		}
		else
			new_pi_tab.bSetNewSize(0);
	}
	return move(new_pi_tab);
}



void CTable::v_copy(const CTable& pcOther)
{
	s_name = (pcOther.s_name + "_copy");
	iTable_Len = pcOther.iTable_Len;
	pi_table = new int[iTable_Len];

	for (int ii = 0; ii < iTable_Len; ii++)
	{
		pi_table[ii] = pcOther.pi_table[ii];
	}
}

void CTable::v_move(CTable& pcOther)
{
	s_name = pcOther.s_name + "_mov";
	iTable_Len = pcOther.iTable_Len;
	pi_table = pcOther.pi_table;
	
	pcOther.pi_table = NULL;
	pcOther.s_name = "Empty";

}

