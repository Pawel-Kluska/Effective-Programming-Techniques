#pragma once

using namespace std;

class CTable
{
private:
	string s_name;
	int i_tab_len;
	int* pi_table;
	int* pi_Val;

public:
	CTable();
	CTable(string sName, int iTableLength, int iVal);
	CTable(CTable& pcOther);
	~CTable();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLength);
	CTable* pcClone();
	void ToString();
	void operator=(const CTable& pcOther);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	CTable operator+(CTable& pcOther);
	CTable operator-(int value);

};