#pragma once
#include <vector>


using namespace std;

class CNodeStatic
{
public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	void vEraseNode();
	
	void vFixParent(CNodeStatic* node);

	vector<CNodeStatic>* get_v_children();
	CNodeStatic* get_pc_parent_node();

private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};

class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
	void vPrintTree();
private:
	CNodeStatic c_root;
};