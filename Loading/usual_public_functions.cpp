#include "usual_public_functions.h"
#include "titles_check_functions.h"

void output_vector_int(std::vector<int>& output_vector) {
	for (std::vector<int>::iterator iter = output_vector.begin(); iter != output_vector.end(); ++iter) std::cout << *iter<<"  ";
}

void iter2_in_vector_swap_int(std::vector<int>& input_num) {
	for (std::vector<int>::iterator i = input_num.begin(); i != input_num.end(); ++i) {
		for (std::vector<int>::iterator iter = i+1; iter != input_num.end(); ++iter) {
			if (*i > *iter) {
				int temp(0);
				temp = *i;
				*i = *iter;
				*iter= temp;
			}
		}
	}
}

std::vector<int>& check_leap(int & left_bound, int & right_bound, std::vector<int>& leap) {
	for (int i = left_bound; i<right_bound + 1; ++i)
		for (int j = 2; j < sqrt(i); ++j) {
			if (i%j == 0) leap.push_back(i); break;//add once
		}
	return leap;
}