#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T> 

class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeDynamic<T>* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();

	vector<CNodeDynamic<T>*>* get_v_children();
	CNodeDynamic<T>* get_pc_parent_node();
	T get_i_val();

	void set_pc_parent_node(CNodeDynamic<T>* pc_parent);

private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;
	void vAddChildPrivate();
};//class CNodeDynamic

template <typename T>
class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);

private:
	CNodeDynamic<T>* pc_root;
};//class CTreeDynamic


template <typename T>
CNodeDynamic<T>::CNodeDynamic()
{
	i_val = {};
	pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
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


template <typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal)
{
	i_val = iNewVal;
}

template <typename T>
int CNodeDynamic<T>::iGetChildrenNumber()
{
	return v_children.size();
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	vAddChildPrivate();
}


template <>
void CNodeDynamic<bool>::vAddNewChild()
{
	if (iGetChildrenNumber() < 2)
	{
		vAddChildPrivate();
	}

}

template <typename T>
	void CNodeDynamic<T>::vAddChildPrivate()
{
	CNodeDynamic<T>* node = new CNodeDynamic;
	node->pc_parent_node = this;
	v_children.push_back(node);
}


template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
		return v_children[iChildOffset];
	else return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrint()
{
	cout << " " << i_val;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
	this->vPrint();

	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i]->vPrintAllBelow();
	}

}

template <typename T>
T CNodeDynamic<T>::get_i_val()
{
	return i_val;
}

template <typename T>
void CNodeDynamic<T>::set_pc_parent_node(CNodeDynamic<T>* pc_parent)
{
	pc_parent_node = pc_parent;
}

template <typename T>
vector<CNodeDynamic<T>*>* CNodeDynamic<T>::get_v_children()
{
	return (&v_children);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::get_pc_parent_node()
{
	return pc_parent_node;
}


template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	CNodeDynamic<T>* root = new CNodeDynamic<T>;
	pc_root = root;
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
}

template <typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot()
{
	return(pc_root);
}

template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}


template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
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
