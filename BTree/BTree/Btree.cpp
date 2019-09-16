#include "Btree.h"
using std::cout;
using std::cin;
using std::endl;

void CreateBTreeByArray(BTree *& bTree, DataType elems[], int num)
{
	BTree **tempNodeArray = new BTree*[num + 1];
	for (int i = 0; i <= num; i++)
	{
		tempNodeArray[i] = nullptr;
	}

	for (int i = 1; i <= num; i++)
	{
		if (elems[i] != "#")
		{
			tempNodeArray[i] = new BTree;
			tempNodeArray[i]->data = elems[i];
			tempNodeArray[i]->lChild = nullptr;
			tempNodeArray[i]->rChild = nullptr;
		}
	}

	for (int i = 1; i <= num / 2; i++)
	{
		tempNodeArray[i]->lChild = tempNodeArray[2 * i];
		if (2 * i + 1 <= num)
		{
			tempNodeArray[i]->rChild = tempNodeArray[2 * i + 1];
		}
	}
	bTree = tempNodeArray[1];
	delete[] tempNodeArray;
}

void PreOrder_DiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	if (bTree == nullptr)
	{
		return;
	}
	else
	{
		Visit(bTree);
		PreOrder_DiGui(bTree->lChild, Visit);
		PreOrder_DiGui(bTree->rChild, Visit);
	}
}

void InOrder_DiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	if (bTree != nullptr)
	{
		InOrder_DiGui(bTree->lChild, Visit);
		Visit(bTree);
		InOrder_DiGui(bTree->rChild, Visit);
	}
}

void PostOrder_DiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	if (bTree != nullptr)
	{
		PostOrder_DiGui(bTree->lChild, Visit);
		PostOrder_DiGui(bTree->rChild, Visit);
		Visit(bTree);
	}

}

void PreOrder_NoDiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	BTree* curNode = bTree;

	const int maxStackNum = 100;
	BTree* stack[maxStackNum];
	int top = -1;

	stack[++top] = curNode;

	while (top > -1)
	{
		Visit(stack[top]);
		curNode = stack[top--];
		if (curNode->rChild != nullptr)
			stack[++top] = curNode->rChild;
		if (curNode->lChild != nullptr)
			stack[++top] = curNode->lChild;
	}
}

void PrintParentOfXNode(BTree *bTree, DataType X)
{
	const int maxSize = 50;
	BTree *(stack[maxSize]);
	BTree *curNode = bTree;
	BTree *tempNode = nullptr;
	int top = -1;
	int visitOfrChild[maxSize] = { 0 };

	stack[++top] = curNode;				// 根节点进栈
	curNode = curNode->lChild;

	while (top > -1)					// 栈不空循环
	{
		while (curNode != nullptr)		// 左孩子全部进栈
		{
			stack[++top] = curNode;
			curNode = curNode->lChild;
			visitOfrChild[top] = 0;
		}

		if (stack[top]->data == X)
		{
			for (int i = 0; i < top; i++)
			{
				cout << stack[i]->data << " ";
			}
		}
		//		cout << stack[top]->data << " ";// 访问栈首节点
		top--;

		if (visitOfrChild[top] == 0)
		{
			curNode = stack[top]->rChild;
			visitOfrChild[top] = 1;
		}

	}
}

void InOrder_NoDiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	BTree*		curNode = bTree;

	const int	maxStackNum = 100;
	BTree*		stack[maxStackNum];
	int			top = -1;

	while (curNode != nullptr || top > -1)
	{
		if (curNode != nullptr)
		{
			stack[++top] = curNode;
			curNode = curNode->lChild;
		}
		else
		{
			curNode = stack[top]->rChild;
			Visit(stack[top--]);
		}
	}
}

void PostOrder_NoDiGui(BTree * bTree, bool(*Visit)(BTree* Node))
{
	BTree*		curNode = bTree;
	BTree*		preNode = nullptr;

	const int	maxStackNum = 100;
	BTree*		stack[maxStackNum];
	int			top = -1;

	do {
		while (curNode != nullptr)
		{
			stack[++top] = curNode;
			curNode = curNode->lChild;
		}

		Visit(stack[top]);				// 访问节点数据
		preNode = stack[top--];

		if (top > -1 && preNode == stack[top]->lChild)		// 若从左孩子退回，则右孩子进栈
		{
			curNode = stack[top]->rChild;
		}
		else
		{
			curNode = nullptr;
		}
	} while (top > -1);
}

BTree* CreateBTree_PreOrderAndInOrder(string Pre[], string In[], int num)
{
	return CreateBTree_PreOrderInOrder(Pre, 0, num - 1, In, 0, num - 1);
}

BTree* CreateBTree_PreOrderInOrder(string Pre[], int preL, int preR, string In[], int InL, int InR)
{
	if (InL <= InR)
	{
		BTree* root = new BTree;
		root->data = Pre[preL];

		int indexOfInOrder, i;
		for (i = InL; i <= InR; i++)		// 寻找中序节点，把树分开
		{
			if (In[i] == Pre[preL])
			{
				indexOfInOrder = i;
				break;
			}
		}
		root->lChild = CreateBTree_PreOrderInOrder(Pre, preL + 1, preL + indexOfInOrder - InL, In, InL, indexOfInOrder - 1);	// 递归创建左子树
		root->rChild = CreateBTree_PreOrderInOrder(Pre, preL + indexOfInOrder - InL + 1, preR, In, indexOfInOrder + 1, InR);	// 递归创建右子树
		return root;
	}
	return nullptr;
}

void DestoryBTree(BTree *& bTree)
{
	if (bTree != nullptr)
	{
		DestoryBTree(bTree->lChild);
		DestoryBTree(bTree->rChild);
		delete bTree;
		bTree = nullptr;
	}
}

DataType ValueOfKInOrder(BTree * bTree, int k)
{
	int find = 0, count = 0;
	DataType data;
	Solution_10(bTree, k, count, find, data);
	return data;
}

void Solution_10(BTree *bTree, int k, int &curCount, int &find, DataType & findData)
{
	if (bTree != nullptr && find == 0)
	{
		Solution_10(bTree->lChild, k, curCount, find, findData);

		curCount++;
		if (curCount == k)
		{
			find = 1;
			findData = bTree->data;
		}

		Solution_10(bTree->rChild, k, curCount, find, findData);
	}
}

void DeleteXNode(BTree *& bTree, DataType X)
{
	if (bTree != nullptr)
	{
		if (bTree->lChild != nullptr &&bTree->lChild->data == X)
			DestoryBTree(bTree->lChild);
		if (bTree->rChild != nullptr &&bTree->rChild->data == X)
			DestoryBTree(bTree->rChild);
		if (bTree->data == X)				// 若根节点为X 
		{
			delete bTree;
			bTree = nullptr;
			return;
		}
		DeleteXNode(bTree->lChild, X);
		DeleteXNode(bTree->rChild, X);
	}
}

void PreOrderGuessPostOrder(DataType A[], int num)
{
	Solution_15(A, 0, num - 1);
}

void Solution_15(DataType A[], int AL, int AR)
{
	if (AL < AR)
	{
		int index = (AR - AL) / 2 + AL;

		Solution_15(A, AL + 1, index);
		Solution_15(A, index + 1, AR);

		DataType temp = A[AL];
		for (int i = AL; i <= AR - 1; i++)
		{
			A[i] = A[i + 1];
		}
		A[AR] = temp;
	}
}

BTree * LinkLeafToList(BTree * bTree)
{
	BTree *head = new BTree;
	BTree *preNode = head;
	Solution_16(bTree, preNode);
	preNode->rChild = nullptr;
	return head;
}

void Solution_16(BTree * bTree, BTree *& preNode)
{
	if (bTree != nullptr)
	{
		if (bTree->lChild == nullptr && bTree->rChild == nullptr)
		{
			preNode->rChild = bTree;
			preNode = preNode->rChild;
		}
		Solution_16(bTree->lChild, preNode);
		Solution_16(bTree->rChild, preNode);
	}
}

BTree *TreadBTree(BTree * root)
{
	BTree *head = new BTree;
	head->lChild = nullptr;		// head 初始化
	head->rChild = nullptr;

	BTree *curNode = root;
	BTree *preNode = head;
	_Inorder_TreadBTree(curNode, preNode);

	preNode->rChild = head;
	preNode->flagR = 0;

	head->lChild = preNode;
	head->flagL = 0;

	return head;
}

void _Inorder_TreadBTree(BTree *&curNode, BTree *&preNode)
{
	if (curNode != nullptr)
	{
		_Inorder_TreadBTree(curNode->lChild, preNode);	// 递归线索化左子树

		if (curNode->lChild == nullptr) {				// 处理当前节点的左孩子
			curNode->lChild = preNode;	// 当前节点左孩子为空，更新为指向后继节点
			curNode->flagL = 0;
		}
		else
		{
			curNode->flagL = 1;			// 当前节点左孩子不为空
		}

		if (preNode->rChild == nullptr) {					// 处理上一节点的右孩子
			preNode->rChild = curNode;	// 上一节点右孩子为空，更新为指向后继节点
			preNode->flagR = 0;
		}
		else {
			preNode->flagR = 1;			// 上一节点右孩子不为空
		}

		preNode = curNode;				// 更新上一个节点

		_Inorder_TreadBTree(curNode->rChild, preNode);	// 递归线索化右子树
	}
}

BTree* TreadFindFirstR(BTree *root)
{
	while (root->flagL != 0)
		root = root->lChild;
	return root;
}

BTree* TreadFindFirstL(BTree * root)
{
	while (root->flagR != 0)
		root = root->rChild;
	return root;
}

BTree* TreadFindNext(BTree * root)
{
	if (root->flagR == 0)
		return root->rChild;
	return TreadFindFirstR(root->rChild);
}

BTree* TreadFindPrior(BTree * root)
{
	if (root->flagL == 0)
		return root->lChild;
	return TreadFindFirstL(root->lChild);
}

double CalSumOfLeaf(BTree * root)
{
	double sum = 0.0;
	int height = 0;
	_Solution_18(root, sum, 0.0, height);
	return sum;
}

void _Solution_18(BTree * root, double &sum, double preWeight, int height)
{
	if (root != nullptr)
	{
		root->height = height + 1;
		preWeight += root->height * root->weight;
		if (root->lChild == nullptr && root->rChild == nullptr)
		{
			sum += preWeight;
		}

		_Solution_18(root->lChild, sum, preWeight, root->height);
		_Solution_18(root->rChild, sum, preWeight, root->height);
	}
}

void SetWeight(BTree *root, double w[], int wLen)
{
	BTree **syArray = new BTree*[wLen + 2];

	syArray[1] = root;
	for (int i = 1; i <= wLen / 2; i++)
	{
		if (syArray[i] != nullptr) {
			syArray[2 * i] = syArray[i]->lChild;
			syArray[2 * i + 1] = syArray[i]->rChild;
		}
		else {
			syArray[2 * i] = nullptr;
			syArray[2 * i + 1] = nullptr;
		}
	}

	for (int i = 0; i < wLen; i++)
	{
		if (w[i] > 0.0)
		{
			syArray[i + 1]->weight = w[i];
		}
	}

	delete[]syArray;
}


