#include "CNodeDynamic.h"
#include <iostream>


CNodeDynamic::CNodeDynamic() 
{ 
	i_val = 0; pc_parent_node = NULL; 
}

CNodeDynamic::~CNodeDynamic()
{
	
	if (pc_parent_node != NULL)
	{
		for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		{
			if ((pc_parent_node->v_children[i]) == this)
			{
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
			}
		}
	}

	int size = v_children.size();

	for (int i = 0; i < size; i++)
	{
		delete v_children[0];
	}

	
}


void CNodeDynamic::vSetValue(int iNewVal) 
{
	i_val = iNewVal; 
}

int CNodeDynamic::iGetChildrenNumber() 
{
	return v_children.size();
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* node = new CNodeDynamic;
	node->pc_parent_node = this;
	v_children.push_back(node);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
		return v_children[iChildOffset];
	else return NULL;
}

void CNodeDynamic::vPrint()
{ 
	cout << " " << i_val; 
}

void CNodeDynamic::vPrintAllBelow()
{
	this->vPrint();

	for (int i = 0; i < v_children.size(); i++)
	{
		if(v_children[i] != NULL)
		v_children[i]->vPrintAllBelow();
	}
	
}

int CNodeDynamic::get_i_val()
{
	return i_val;
}


void CNodeDynamic::set_pc_parent_node(CNodeDynamic* pc_parent)
{
	pc_parent_node = pc_parent;
}

vector<CNodeDynamic*>* CNodeDynamic::get_v_children()
{
	return (&v_children);
}


CNodeDynamic* CNodeDynamic::get_pc_parent_node()
{
	return pc_parent_node;
}


CNodeDynamic* CNodeDynamic::mul(CNodeDynamic* node1, CNodeDynamic* node2)
{
	CNodeDynamic* parent = new CNodeDynamic;
	parent->i_val = (node1->i_val) * (node2->i_val);

	for (int i = 0; (i < node1->v_children.size()) && (i < node2->v_children.size()); i++)
	{
		CNodeDynamic* temp = mul(node1->v_children[i], node2->v_children[i]);
		temp->pc_parent_node = parent;
		parent->v_children.push_back(temp);
	}

	return parent;
}


CTreeDynamic::CTreeDynamic()
{
	CNodeDynamic* root = new CNodeDynamic;
	pc_root = root;
}

CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
}

CNodeDynamic* CTreeDynamic::pcGetRoot() 
{
	return(pc_root);
}

void CTreeDynamic::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}


bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		pcParentNode->get_v_children()->push_back(pcNewChildNode);

		if (pcNewChildNode->get_pc_parent_node() != NULL)
		{
			for (int i = 0; i < pcNewChildNode->get_pc_parent_node()->iGetChildrenNumber(); i++)
			{
				if ((pcNewChildNode->get_pc_parent_node()->get_v_children()->operator[](i)) == pcNewChildNode)
				{
					pcNewChildNode->get_pc_parent_node()->get_v_children()->erase(pcNewChildNode->get_pc_parent_node()->get_v_children()->begin() + i);
				}
			}
		}

		pcNewChildNode->set_pc_parent_node(pcParentNode);
		return true;
	}
	return false;
}


