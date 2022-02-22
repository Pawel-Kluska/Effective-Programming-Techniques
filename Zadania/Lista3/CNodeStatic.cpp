#include "CNodeStatic.h"
#include <iostream>

using namespace std;

CNodeStatic::CNodeStatic()
{
	i_val = 0; pc_parent_node = NULL; 
}


void CNodeStatic::vSetValue(int iNewVal)
{ 
	i_val = iNewVal; 
}
int CNodeStatic::iGetChildrenNumber() 
{
	return(v_children.size()); 
}

void CNodeStatic::vPrint() 
{
	cout << " " << i_val; 
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic a;
	a.pc_parent_node = this;
	v_children.push_back(a);
}

CNodeStatic::~CNodeStatic()
{
	
}

void CNodeStatic::vEraseNode()
{
	for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		if (&(pc_parent_node->v_children[i]) == this)
		{
			pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
		}
}



void CNodeStatic::vFixParent(CNodeStatic* node)
{
	for (int i = 0; i < node->iGetChildrenNumber(); i++)
	{
		node->v_children[i].pc_parent_node = node;
		vFixParent(&node->v_children[i]);
	}
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
		return &v_children[iChildOffset];
	else return NULL;
}

void CNodeStatic::vPrintAllBelow()
{
	this->vPrint();

	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i].vPrintAllBelow();
	}
}


void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	pc_parent_node->vPrintUp();
}

vector<CNodeStatic>* CNodeStatic::get_v_children()
{
	return &v_children;
}

CNodeStatic* CNodeStatic::get_pc_parent_node()
{
	return pc_parent_node;
}


CTreeStatic::CTreeStatic()
{
	CNodeStatic root;
	c_root = root;
}

CNodeStatic* CTreeStatic::pcGetRoot() 
{ 
	return(&c_root); 
}

void CTreeStatic::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		pcParentNode->get_v_children()->push_back(*pcNewChildNode);
		pcNewChildNode->vEraseNode();
		pcParentNode->vFixParent(pcParentNode);
		return true;
	}
	return false;
}


CTreeStatic::~CTreeStatic()
{
	
}
