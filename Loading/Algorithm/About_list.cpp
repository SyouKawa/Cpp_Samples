#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define dim(x) sizeof(x) / sizeof(x[0])

struct tagStack {
	int iData;
	tagStack *pPrev;
};

struct tagNode {
	int iData;
	tagNode *pPrev;
	tagNode *pNext;
};

void main()
{
	/*|||||| down |||||||  init   ||||||||| down ||||||||||*/
	tagStack AA = { 11, NULL };
	tagStack BB = { 22, &AA };
	tagStack CC = { 33, &BB };
	tagStack DD = { 44, &CC };
	tagStack EE = { 55, &DD };

	tagStack *pTop = &EE;

	//	return;

	tagNode A = { 11 };
	tagNode B = { 22 };
	tagNode C = { 33 };
	tagNode D = { 44 };
	tagNode E = { 55 };

	A.pPrev = NULL;
	A.pNext = &B;

	B.pPrev = &A;
	B.pNext = &C;

	C.pPrev = &B;
	C.pNext = &D;

	D.pPrev = &C;
	D.pNext = &E;

	E.pPrev = &D;	//NULL
	E.pNext = NULL;	//&D

	tagNode *pHead = &A;

	tagNode *pCurr = pHead;
	tagNode *pLast = NULL;
	/*||||||| up |||||  init  |||||||| up |||||||*/
	
	//1.1reserve list
	while (pCurr != NULL)
	{
		//A-loop£ºA   B-loop:B  C-loop:C D-loop:D
		pLast = pCurr;/*6w6*/
		
		//   A <-(exchange)-> B
		tagNode *pTemp = pCurr->pNext;
		pCurr->pNext = pCurr->pPrev;
		pCurr->pPrev = pTemp;
		
		//B->A  C->B->A  D->C->B->A
		pCurr = pLast->pPrev;/*6w6*/
	}
	pHead = pLast;//E

	
	//1.2 show the list
	pCurr = pHead;
	while (pCurr != NULL)
	{
		printf("%d ", pCurr->iData);
		pCurr = pCurr->pNext;
	}
	printf("\r\n");
	return;
}
