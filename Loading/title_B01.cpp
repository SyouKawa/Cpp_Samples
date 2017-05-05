#include"titles_check_functions.h"
#include"usual_public_functions.h"
using namespace std;

vector<int>& fun_return_below(const int& m,int *score, vector<int>& below);

void title_B01() {
	printf("Please input the size of array: ");
	int m;
	cin >> m;
	int *score=(int *)malloc(m*sizeof(int));
	printf("Please intput %d scores,spliting with space:", m);
	int sum(0);
	for (int i = 0; i < m; i++){
		cin >> *(score + i);
		sum += *(score + i);
	}
	vector<int> below(0);
	fun_return_below(m,score,below);
	output_vector_int(below);
	free(score);
}

vector<int>& fun_return_below(const int& m,int *score,vector<int>& below) {
	int sum(0);
	for (int i = 0; i < m; i++)
		sum += *(score + i);
	int average(sum / m);
	
	//debug using/ for (int i = 0; i < m; ++i) printf("%d  ", *(score + i));
	for (int i(0); i < m; i++)
		if (*(score + i) < average) below.push_back(*(score + i));

	return below;
}