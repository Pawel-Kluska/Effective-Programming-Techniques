#include <iostream>
#include "CNodeStatic.h"
#include "CNodeDynamic.h"
#include <vector> 
using namespace std;




void v_tree_test()
{
	CTreeDynamic* c_tree = new CTreeDynamic;
	CNodeDynamic* c_root = c_tree->pcGetRoot();
	c_root->vAddNewChild();
	c_root->vAddNewChild();
	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	CTreeDynamic* c_tree2 = new CTreeDynamic;
	CNodeDynamic* c_root2 = c_tree2->pcGetRoot();
	c_root2->vAddNewChild();
	c_root2->vAddNewChild();
	c_root2->pcGetChild(0)->vSetValue(3);
	c_root2->pcGetChild(1)->vSetValue(4);
	c_root2->pcGetChild(0)->vAddNewChild();
	c_root2->pcGetChild(0)->vAddNewChild();
	c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(31);
	c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(32);


	CTreeDynamic* c_tree3 = new CTreeDynamic;
	CNodeDynamic* c_root3 = c_tree3->pcGetRoot();
	c_root3->vAddNewChild();
	c_root3->vAddNewChild();
	c_root3->pcGetChild(0)->vSetValue(5);
	c_root3->pcGetChild(1)->vSetValue(6);
	c_root3->pcGetChild(0)->vAddNewChild();
	c_root3->pcGetChild(0)->vAddNewChild();
	c_root3->pcGetChild(0)->pcGetChild(0)->vSetValue(51);
	c_root3->pcGetChild(0)->pcGetChild(1)->vSetValue(52);
	c_root3->pcGetChild(1)->vAddNewChild();
	c_root3->pcGetChild(1)->vAddNewChild();
	c_root3->pcGetChild(1)->pcGetChild(0)->vSetValue(61);
	c_root3->pcGetChild(1)->pcGetChild(1)->vSetValue(62);
	

	//c_root2->vPrintAllBelow();
	//cout << endl;
	//delete c_root3->pcGetChild(0);
//	cout << endl;;
	//c_root2->pcGetChild(0)->vPrint();
	//c_root3->vPrintAllBelow();

	//cout << endl;
	
	
	//c_tree2->bMoveSubtree(c_root2, c_root3->pcGetChild(0));
	
	c_root->vPrintAllBelow();
	cout << endl;

	c_root2->vPrintAllBelow();
	cout << endl;
	CNodeDynamic* sub = c_root->mul(c_root, c_root2);

	sub->vPrintAllBelow();
	cout << endl;
	

	


}//void v_tree_test()

void v_tree_test2()
{
	CTreeStatic c_tree;
	CNodeStatic* c_root = c_tree.pcGetRoot();
	c_root->vAddNewChild();
	c_root->vAddNewChild();
	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_root->vPrintAllBelow();
	cout << endl;

	CTreeStatic c_tree2;
	CNodeStatic* c_root2 = c_tree2.pcGetRoot();
	c_root2->vAddNewChild();
	c_root2->vAddNewChild();
	c_root2->pcGetChild(0)->vSetValue(3);
	c_root2->pcGetChild(1)->vSetValue(4);
	c_root2->pcGetChild(0)->vAddNewChild();
	c_root2->pcGetChild(0)->vAddNewChild();
	c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(31);
	c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(32);
	c_root2->pcGetChild(1)->vAddNewChild();
	c_root2->pcGetChild(1)->vAddNewChild();
	c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue(41);
	c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue(42);

	c_root2->vPrintAllBelow();
	cout << endl;

	c_tree2.bMoveSubtree(c_root2, c_root->pcGetChild(0));

	c_root2->vPrintAllBelow();
	cout << endl;
	c_root->vPrintAllBelow();
	cout << endl;
	c_root2->pcGetChild(1)->pcGetChild(0)->vPrintUp();


	

}//void v_tree_test()

int main()
{
	v_tree_test();
	return 0;
}