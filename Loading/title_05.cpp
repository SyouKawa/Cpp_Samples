#include"titles_check_functions.h"
using namespace std;

void title_05() {
	int n(0);
	vector<int> input_num(0);
	printf("Please input the number of input data:");
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int temp(0);
		printf("And Please No.%d number: ", i+1
		);
		cin >> temp;
		input_num.push_back(temp);
		//debug using/ printf("%d  ", input_num[i]);
	}

	for (vector<int>::iterator iter = input_num.begin(); iter != input_num.end()-1; ++iter) {
		if (*iter > *(iter + 1)) {
			int temp(0);
			temp = *iter;
			*iter = *(iter + 1);
			*(iter + 1) = temp;
		}
	}
}