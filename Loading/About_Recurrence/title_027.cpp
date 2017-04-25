#include"usual_public_functions.h"
#include"titles_check_functions.h"
//#include <string>
#define TEMP_SIZE 100
using namespace std;

void reverse(int n);

void title_27() {
	printf("Please input the string needed reverse:");
	char temp_string[TEMP_SIZE]; //debug using/ ="123";
	int i(0);
	char c;
	//debug using/ cin >> temp_string;

	while ((c=getchar()) != ('\n'|'\r')) temp_string[i++] = c;
	//debug using/ output_end2begin(temp_string);

	reverse(sizeof(temp_string)/sizeof(char));
}

void reverse(int n) {
	char temp_s;
	if (n <= 1) {
		temp_s = getchar();
		printf("%c", temp_s);
	}
	else {
		temp_s = getchar();
		reverse(n - 1);
		printf("%c", temp_s);//first.get -> final.output
	}
	puts("\n\n");
}
