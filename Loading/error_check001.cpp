#include"titles_check_functions.h"
using namespace std;
void ff(int n);
void test() {
	//char c;
	//int count(0);
	//char vector[10];
	//while ((c = getchar()) != EOF&&c != '\n') {
		//putchar(c);
		//vector[count++]=c;
	//}
	//for (int i = 0; i != (sizeof(vector) / sizeof(char)); i++) { printf("%c", vector[i]); }
	int n;
	cin >> n;
	ff(n);
}
void ff(int n) {
	char temp_s;
	if (n <= 1) {
		temp_s = getchar();
		printf("%c", temp_s);
	}
	else {
		temp_s = getchar();
		ff(n - 1);
		printf("%c", temp_s);//first.get -> final.output
	}
	//puts("\n\n");
}
