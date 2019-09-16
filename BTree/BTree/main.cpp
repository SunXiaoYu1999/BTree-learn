//-------------------------------------------------------------------------------------
//                                                                                   //
//                                       ÀÔ                                          //                      
//                                     /    \                                        //
//                                  ”Ó        –°                                     //
//                                 /  \      /  \                                    //
//                               ∫√    —Ó  ≤∑    ”„                                  //
//                              /  \                                                 //
//                             »À   ∞°                                               //
//                                                                                   //
//-------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Btree.h"

using namespace std;
bool Print(BTree *node)
{
	cout << endl;
	cout << "node->data   = " << node->data << endl;
	cout << "node->height = " << node->height << endl;
	cout << "node->weight = " << node->weight << endl;
	cout << "node->flagL  = " << node->flagL << endl;
	cout << "node->flagR  = " << node->flagR << endl;
	cout << endl;

	return true;
}
int main()
{
	const int elemNum = 9;
	BTree *bTree;
	DataType elem[elemNum + 1] = { "#", "ÀÔ","”Ó" ,"–°" ,"∫√" ,"—Ó" ,"≤∑" ,"”„" ,"»À" ,"∞°" };
	CreateBTreeByArray(bTree, elem, elemNum);

	double w[elemNum] = { 10.0,10.0,10.0,10.0,10.0,10.0,10.0,10.0,10.0 };
	SetWeight(bTree, w, elemNum);


	double p = CalSumOfLeaf(bTree);
	InOrder_DiGui(bTree, Print);
	cout << p << endl;

	return 0;
}