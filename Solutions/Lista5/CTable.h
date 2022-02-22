#pragma once


using namespace std;

class CTable
{
private:
	string s_name;
	int iTable_Len;
	int* pi_table;
	void v_move(CTable& pcOther);
	void v_copy(const CTable& pcOther);

public:
	CTable();
	CTable(string sName, int iTableLength);
	CTable(const CTable& pcOther);
	CTable(CTable&& pcOther) noexcept;

	~CTable();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLength);
	CTable* pcClone();
	void ToString();
	void operator=(CTable&& cOther) noexcept;

	void operator=(const CTable& pcOther);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	CTable operator+(CTable& pcOther);
	CTable operator-(int value);
};