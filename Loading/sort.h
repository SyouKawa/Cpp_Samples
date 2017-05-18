#pragma once
#ifndef __SORT_H_
#define __SORT_H_

#include "titles_check_functions.h"
#include"Student_info.h"

int& Median3(std::vector<Student_info>&students, int Left, int Right);
void Qsort(std::vector<Student_info>&student, int Left, int Right);

/*template <class T>
void quicksort(T a[], size_t Left, size_t Right) {
	if (Right > Left) {
		// partition
		int p = rand() % (h - Left) + l;
		T d = a[p];
		// divide
		swap(a[Left], a[p]);
		size_t i = Left;
		size_t j = i + 1;
		while (j < Right) {
			while (a[j] > d && j < Right) j++;
			if (j < Right) {
				i++;
				swap(a[i], a[j]);
				j++;
			}
		}
		swap(a[i], a[Left]);
		quicksort(a, Left, i);
		quicksort(a, i + 1, Right);
	}
}*/


#endif // !__SORT_H_
