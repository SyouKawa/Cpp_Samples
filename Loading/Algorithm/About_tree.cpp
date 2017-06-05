#include <stdio.h>

#define dim(x) sizeof(x) / sizeof(x[0])

struct NODE
{
	char iData;
	NODE *pLChild;
	NODE *pRChild;
};

//ǰ�����: ������(�ȷ��ʸ�, Ȼ��������ҷ�����������)
void PreOrder(NODE *node)
{
	if (node == NULL) return;
	printf("%c ", node->iData);
	PreOrder(node->pLChild);
	PreOrder(node->pRChild);
}

//�������: �����(����ߵ�һ������, Ȼ����ʸ�, �ٴ������ҷ���ʣ�µ���������)
void InOrder(NODE *node)
{
	if (node == NULL) return;

	InOrder(node->pLChild);

	printf("%c ", node->iData);

	InOrder(node->pRChild);
}

//�������: ���Ҹ�(�ȴ������ҷ�����������, Ȼ����ʸ�)
void LastOrder(NODE *node)
{
	if (node == NULL) return;

	LastOrder(node->pLChild);
	LastOrder(node->pRChild);

	printf("%c ", node->iData);
}

//�����Ľڵ�����
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

//������������(�߶�)
//1. ��������Ϊ��, ��߶�Ϊ0
//2. ����������Ϊ��, ��߶�ӦΪ�����������߶ȵ����ֵ��1
int GetNodeDepth(NODE *node)
{
	if (node == NULL) return 0;

	int iLDepth = GetNodeDepth(node->pLChild);  //�������
	int iRDepth = GetNodeDepth(node->pRChild);  //�����ұ�

	int iDepth = iLDepth > iRDepth ? iLDepth : iRDepth;

	return (iDepth + 1);  //��1��ʾ���ڵ�
}

