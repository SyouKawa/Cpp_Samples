#include<stdio.h>
#include<stdlib.h>
#define N 20
#define SWAP(a,b) {int temp=0;temp=a;a=b;b=temp;}
#define PRINT_ARRAY for(int no=0;no<N;no++){printf("%d ",a[no]);}

void select(int *arr) {
	int min = 0;
	for (int i=0;i<N;i++) {//待换边界
		for (int j=i+1;j<N;j++) {
			if (arr[min] > arr[j]) min = j;
		}
		SWAP(arr[min], arr[i]);
	}
}

void Quick_sort(int *a, int Left, int Right) {
	if (Left >= Right) return;
	int Pivot = a[Right];
	int i = Left,j = Right-1;
	while (i < j) {
		while (i<j&&a[i]<Pivot ) i++;
		while (i<j&&a[j]>Pivot) j--;
		if (i < j) { 
			SWAP(a[i], a[j]);  
		}
		else break;
		//PRINT_ARRAY;
	}
	if(a[i]>a[Right]) SWAP(a[i], a[Right]);
	//PRINT_ARRAY;
	Quick_sort(a, Left, i-1);
	Quick_sort(a, i+1, Right);
}

void Insertion(int *a,size_t size) {
	for (int j=1;j<size;j++) {//外面是排好序的
		int temp = a[j];//去排好的地方之前，先把准备放入的存起来等着。
		int i = j - 1;
		for (; a[i] > temp; i--)a[i + 1] = a[i];
		a[i+1] = temp;
	}
}

void Bubble(int *arr, size_t size) {
	for (int i = 0; i<size; i++) {
		for (int j = i + 1; j < size; j++)
			if (arr[i] < arr[j])
				SWAP(arr[i], arr[j]);
	}
}
