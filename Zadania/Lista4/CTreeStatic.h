#pragma once
#include <vector>
#include <iostream>


using namespace std;

template <typename T>
class CNodeStatic
{
public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(T iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic<T>* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	void vEraseNode();
	
	void vFixParent(CNodeStatic<T>* node);

	vector<CNodeStatic<T>>* get_v_children();
	CNodeStatic<T>* get_pc_parent_node();

private:
	vector<CNodeStatic<T>> v_children;
	CNodeStatic<T>* pc_parent_node;
	T i_val;
};

template <typename T>
class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic<T>* pcGetRoot();
	bool bMoveSubtree(CNodeStatic<T>* pcParentNode, CNodeStatic<T>* pcNewChildNode);
	void vPrintTree();
private:
	CNodeStatic<T> c_root;
};


template <typename T>
CNodeStatic<T>::CNodeStatic()
{
	i_val = {};
	pc_parent_node = NULL;
}


template <typename T>
void CNodeStatic<T>::vSetValue(T iNewVal)
{
	i_val = iNewVal;
}

template <typename T>
int CNodeStatic<T>::iGetChildrenNumber()
{
	return(v_children.size());
}

template <typename T>
void CNodeStatic<T>::vPrint()
{
	cout << " " << i_val;
}

template <typename T>
void CNodeStatic<T>::vAddNewChild()
{
	CNodeStatic<T> a;
	a.pc_parent_node = this;
	v_children.push_back(a);
}

template <typename T>
CNodeStatic<T>::~CNodeStatic()
{

}

template <typename T>
void CNodeStatic<T>::vEraseNode()
{
	for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		if (&(pc_parent_node->v_children[i]) == this)
		{
			pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
		}
}



template <typename T>
void CNodeStatic<T>::vFixParent(CNodeStatic<T>* node)
{
	for (int i = 0; i < node->iGetChildrenNumber(); i++)
	{
		node->v_children[i].pc_parent_node = node;
		vFixParent(&node->v_children[i]);
	}
}

template <typename T>
CNodeStatic<T>* CNodeStatic<T>::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size() && iChildOffset >= 0)
		return &v_children[iChildOffset];
	else return NULL;
}

template <typename T>
void CNodeStatic<T>::vPrintAllBelow()
{
	this->vPrint();

	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i].vPrintAllBelow();
	}
}


template <typename T>
void CNodeStatic<T>::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
		pc_parent_node->vPrintUp();
}

template <typename T>
vector<CNodeStatic<T>>* CNodeStatic<T>::get_v_children()
{
	return &v_children;
}

template <typename T>
CNodeStatic<T>* CNodeStatic<T>::get_pc_parent_node()
{
	return pc_parent_node;
}


template <typename T>
CTreeStatic<T>::CTreeStatic()
{
	CNodeStatic<T> root;
	c_root = root;
}

template <typename T>
CNodeStatic<T>* CTreeStatic<T>::pcGetRoot()
{
	return(&c_root);
}

template <typename T>
void CTreeStatic<T>::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}

template <typename T>
bool CTreeStatic<T>::bMoveSubtree(CNodeStatic<T>* pcParentNode, CNodeStatic<T>* pcNewChildNode)
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

template <typename T>

CTreeStatic<T>::~CTreeStatic()
{

}


