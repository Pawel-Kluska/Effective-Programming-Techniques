#pragma once

#define DEF_TAB_SIZE 10 

class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(const CTab& cOther);
	CTab(CTab&& cOther) noexcept;
	void operator=(const CTab& cOther);
	~CTab();
	bool bSetSize(int iNewSize);
	int iGetSize() { return(i_size); }
	void operator=(CTab&& cOther) noexcept;
	void v_move(CTab& pcOther);
	CTab cCreateTab();
private:
	void v_copy(const CTab& cOther);
	int* pi_tab;
	int i_size;
};//class CTab