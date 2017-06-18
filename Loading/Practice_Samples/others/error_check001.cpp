#include"titles_check_functions.h"
using namespace std;
void ff(int n);
void test() {
	int n;
	cin >> n;
	re(n);
}
void re(int n) {
	char temp_s;
	char c=getchar();
	while (c == '\n') c = getchar();
	if (n <= 1) {
		temp_s = c;
		printf("%c", temp_s);
	}
	else {
		temp_s = c;
		re(n - 1);
		printf("%c", temp_s);//first.get -> final.output
	}
	//puts("\n\n");
}
