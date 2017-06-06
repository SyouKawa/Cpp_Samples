#include <stdio.h>

#define dim(x) sizeof(x) / sizeof(x[0])

struct NODE
{
	char iData;
	NODE *pLChild;
	NODE *pRChild;
};

void tree_init(NODE **a_tree, char*data);


void PreOrder(NODE *node)
{
	if (node == NULL) return;
	printf("%c ", node->iData);
	PreOrder(node->pLChild);
	PreOrder(node->pRChild);
}


void InOrder(NODE *node)
{
	if (node == NULL) return;

	InOrder(node->pLChild);

	printf("%c ", node->iData);

	InOrder(node->pRChild);
}

void LastOrder(NODE *node)
{
	if (node == NULL) return;

	LastOrder(node->pLChild);
	LastOrder(node->pRChild);

	printf("%c ", node->iData);
}

//the number of node
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

//Height
//1. tree empty, h=0
//2. tree not empty,h=max(LEFT,RIGHT)+1 
int GetNodeDepth(NODE *node)
{
	if (node == NULL) return 0;

	int iLDepth = GetNodeDepth(node->pLChild); 
	int iRDepth = GetNodeDepth(node->pRChild);

	int iDepth = iLDepth > iRDepth ? iLDepth : iRDepth;

	return (iDepth + 1);  //add root
}

void tree_init(NODE **a_tree, const char*data) {
	for (int i(0); i < dim(a_tree); i++) {//dim(x)  means sizeof(array_or_sth_like_array)/sizeof(element) 
		a_tree[i] = new NODE();
		a_tree[i]->iData = data[i];
		a_tree[i]->pLChild = NULL;
		a_tree[i]->pRChild = NULL;
	}
}

void main() {
	//1.generate a tree
	char data[] = { 'A','B','C','D','E','F','G','H','I','J' };
	char pid[] = { NULL,'A','A','B','B','C','C','D','D','E' };
	NODE *root = NULL;
	NODE *tree[10];

	//1.1 generate 10 node first(init no child)
	// put them into tree array.
	//tree_init(tree,data);

	int i, j;
	for (i = 0; i < dim(data); i++)
	{
		tree[i] = new NODE();
		tree[i]->iData = data[i];
		tree[i]->pLChild = NULL;
		tree[i]->pRChild = NULL;
	}

	//1.2 link
	for (int i(0); i < dim(data); i++) {
		if (pid[i] == NULL) {
			root = tree[i];
			continue;
		}
		for (int j(0); j < dim(data); j++) {
			if (pid[i] == tree[j]->iData) {
				if (tree[j]->pLChild == NULL) { tree[j]->pLChild = tree[i]; break; }
				if (tree[j]->pRChild == NULL) { tree[j]->pRChild = tree[i]; break; }
			}
		}
	}
}
