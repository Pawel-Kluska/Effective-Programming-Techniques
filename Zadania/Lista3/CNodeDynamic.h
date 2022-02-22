#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeDynamic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();

	vector<CNodeDynamic*>* get_v_children();
	CNodeDynamic* get_pc_parent_node();
	int get_i_val();

	void set_pc_parent_node(CNodeDynamic* pc_parent);
	CNodeDynamic* mul(CNodeDynamic* node1, CNodeDynamic* node2);

private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};//class CNodeDynamic


class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
	
private:
	CNodeDynamic* pc_root;
};//class CTreeDynamic
