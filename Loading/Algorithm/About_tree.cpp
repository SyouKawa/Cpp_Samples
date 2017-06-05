#include <stdio.h>

#define dim(x) sizeof(x) / sizeof(x[0])

struct NODE
{
	char iData;
	NODE *pLChild;
	NODE *pRChild;
};

//前序遍历: 根左右(先访问根, 然后从左至右访问所有子树)
void PreOrder(NODE *node)
{
	if (node == NULL) return;
	printf("%c ", node->iData);
	PreOrder(node->pLChild);
	PreOrder(node->pRChild);
}

//中序遍历: 左根右(先左边第一个子树, 然后访问根, 再从左至右访问剩下的其他子树)
void InOrder(NODE *node)
{
	if (node == NULL) return;

	InOrder(node->pLChild);

	printf("%c ", node->iData);

	InOrder(node->pRChild);
}

//后序遍历: 左右根(先从左至右访问所有子树, 然后访问根)
void LastOrder(NODE *node)
{
	if (node == NULL) return;

	LastOrder(node->pLChild);
	LastOrder(node->pRChild);

	printf("%c ", node->iData);
}

//求树的节点数量
int GetNodeNum(NODE *node)
{
	int nCount = 0;
	if (node != NULL)
	{
		nCount++;
		nCount += GetNodeNum(node->pLChild);
		nCount += GetNodeNum(node->pRChild);
	}
	return nCount;
}

//求二叉树的深度(高度)
//1. 若二叉树为空, 则高度为0
//2. 若二叉树不为空, 则高度应为其左右子树高度的最大值加1
int GetNodeDepth(NODE *node)
{
	if (node == NULL) return 0;

	int iLDepth = GetNodeDepth(node->pLChild);  //遍历左边
	int iRDepth = GetNodeDepth(node->pRChild);  //遍历右边

	int iDepth = iLDepth > iRDepth ? iLDepth : iRDepth;

	return (iDepth + 1);  //加1表示根节点
}

