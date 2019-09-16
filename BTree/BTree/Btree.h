#pragma once
#include <iostream>
#include <string>

using std::string;


typedef string DataType;

typedef struct Node
{
	DataType		data;		// ����
	struct Node*	lChild;		// ����
	struct Node*	rChild;		// �Һ���

	int				height;		// ���ڵ�ĸ߶�
	double			weight;		// Ȩ��
	int				flagL;		// ����	0����һ���ڵ㣬1������
	int				flagR;		// �ұ��	0����һ���ڵ㣬1���Һ���
}BTree;

//--------------------------------- ������ -----------------------------------------------------------------------
// ����˵��		��Ӧ��һ������elems[n]������һ�ö�������elems[1]���������Ľڵ����ݣ�elems[2*i]Ϊelems[i]����
//				  ���ӽڵ����ݣ�elems[2*i+1]Ϊelems[i]d���Һ��ӽڵ����ݡ�elems[k] = "#"����Ϊ�սڵ㡣
// @param elems :����Ԫ��
// @param num	:����Ԫ�ظ���
// ע�⣡����	������Ԫ���±���1��ʼ�����������±�0��
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CreateBTreeByArray(BTree *&bTree, DataType elems[], int num);

//--------------------------------- �ȸ������ݹ鷽�� ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ���÷�����
//				  <1> �ȶ���һ����ӡ���� Print,���£�
//					bool Print(DataType data)
//					{
//						cout << " " << data << " ";
//						return true;
//					}
//				  <2> �����·�ʽ���ã�
//					PreOrder_DiGui(bTree, Print);
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PreOrder_DiGui(BTree *bTree, bool(*Visit)(BTree* Node));

//--------------------------------- ��������ݹ鷽�� ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ	  
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void InOrder_DiGui(BTree *bTree, bool(*Visit)(BTree* Node));


//--------------------------------- ��������ݹ鷽�� ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ	  
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PostOrder_DiGui(BTree *bTree, bool(*Visit)(BTree* Node));

//--------------------------------- ��������ǵݹ鷨 ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ	  
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PreOrder_NoDiGui(BTree *bTree, bool(*Visit)(BTree* Node));

//--------------------------------- ��������ǵݹ鷨 ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ	  
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void InOrder_NoDiGui(BTree *bTree, bool(*Visit)(BTree* Node));

//--------------------------------- ��������ǵݹ鷨 ------------------------------------------------------------
// ����˵��		���������һ���������������ڵ�bTree, PrintΪһ������ָ�룬���ⲿ���룬������ӡ�ڵ�ֵ	  
// @param bTree �������ڵ�
// @param Visit	�����ʺ���ָ�룬������ʽڵ�ֵ
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PostOrder_NoDiGui(BTree *bTree, bool(*Visit)(BTree* Node));

//--------------------------------- ��ӡ�ڵ�X���������Ƚڵ� ------------------------------------------------------------
// ����˵��		����ӡ�ڵ�ֵΪX���������Ƚڵ�	  
// @param bTree �������ڵ�
// @param X		����ֵX
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void PrintParentOfXNode(BTree *bTree, DataType X);

//--------------------------------- ���������� --------------------------------------------------------------------
// ����˵��		������������������д���һ�������� 
// @param Pre[] ����������
// @param In[]	����������
// @param num	���ڵ����
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BTree* CreateBTree_PreOrderAndInOrder(string Pre[], string In[], int num);
/*���溯���������Ҫ����*/
BTree* CreateBTree_PreOrderInOrder(string Pre[], int preL, int preR, string In[], int InL, int InR);

//--------------------------------- ����һ�������� --------------------------------------------------------------------
// ����˵��		������һ��������
// @param bTree	�������ڵ�
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void DestoryBTree(BTree *& bTree);


/******************************************************************************************************************/
/*********************************************** ��������������Ŀ *************************************************/
/******************************************************************************************************************/

// 10�������������K���ڵ������
DataType ValueOfKInOrder(BTree *bTree, int k);
void Solution_10(BTree *bTree, int k, int &curCount, int &find, DataType &findData);

// 11��ɾ��Ԫ��ֵΪx�Ľڵ�
void DeleteXNode(BTree *& bTree, DataType X);

// 15���������������������������������
void PreOrderGuessPostOrder(DataType A[], int num);
void Solution_15(DataType A[], int AL, int AR);

// 16��������Ҷ�ӽڵ����ӳɵ�����
BTree* LinkLeafToList(BTree *bTree);
void Solution_16(BTree *bTree, BTree *&preNode);

// 17��������������	
/*********************************** ��ͷ�ڵ�������������� ***************************************/
// ˵�� : '_' ��ͷ�ĺ���Ϊ������������Ӧ��ֱ�ӵ��á�����ʱ��Ҫ���ò��� '_' �ĺ���
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//---------------------------------- ������һ�������� ---------------------------------------------
// @param	root�������������Ķ�����
// ����˵��		���ú���������һ�Ŷ��������������������ͷ�ڵ�
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
BTree* TreadBTree(BTree *root);
void _Inorder_TreadBTree(BTree *&curNode, BTree *&preNode);
// Ѱ�ҵ�ǰ�ڵ������������Һ�̵ĵ�һ���ڵ�
BTree* TreadFindFirstR(BTree *root);
// Ѱ�ҵ�ǰ�ڵ�������������ǰ���ĵ�һ���ڵ�
BTree* TreadFindFirstL(BTree *root);
// Ѱ�ҵ�ǰ�ڵ�ĺ�̽ڵ�
BTree* TreadFindNext(BTree *root);
// Ѱ�ҵ�ǰ�ڵ��ǰ���ڵ�
BTree* TreadFindPrior(BTree *root);

// 18����������Ĵ�ȨҶ��·����WPL
double CalSumOfLeaf(BTree *root);
void _Solution_18(BTree *root, double &sum, double preWeight, int height);
void SetWeight(BTree *root, double w[], int wLen);