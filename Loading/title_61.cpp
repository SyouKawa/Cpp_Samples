#include"titles_check_functions.h"
#include"malloc.h"
using namespace std;

void title_61() {
	
	printf("Please input the number of lines you want: ");
	int n(0),line_num(0);
	cin >> n;//original num;
	line_num = n;
	//1. create the output array.(ignore the first line.)
	vector<char*> angle;


	//2. set per-line memory.
	for (int i(0); i < n; i++) {
		char *temp;
		int size = ((i+1+1 + i+1 + 1) * sizeof(char));//per row:  i+1=exist; i=No. ; +1=' ' //i=add_space,i+1=exist;
		
		if (i == 0) {//the special first-line in angle;
			temp = (char*)malloc(size + n - 1);//the last space-addtions = n-1;
			size_t size_byte = _msize(temp);
			//debug using/ printf("%d\n", size);
			//debug using/ printf("%d\n\n", size_byte);
			angle.push_back(temp);
		}
		if (i != 0) {
			temp = (char*)malloc(size);
			size_t size_byte = _msize(temp);
			//debug using/ printf("%d\n", size);
			//debug using/printf("%d\n\n", size_byte);
			angle.push_back(temp);
		}
	}
	printf("%d\n", angle.size());

	//free(angle);
}