#pragma once

using namespace std;

class CTable
{
private:
	string s_name;
	int iTable_Len;
	int* pi_table;
	int* pi_Val;

public:
	CTable();
	CTable(string sName, int iTableLength, int piVal);
	CTable(CTable& pcOther);
	~CTable();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLength);
	CTable* pcClone();
	void ToString();

};