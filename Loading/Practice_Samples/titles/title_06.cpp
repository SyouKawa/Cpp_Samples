#include<iostream>
using namespace std;

void output_array(char out_array[]) {
	for (int i = 0; i < (sizeof(out_array)/sizeof(char)); ++i);
		cout << out_array;
	cout << endl;  
}

void main() {
	char top_bottom[] = "  ****";
	char middle[] = " *    *";
	//cout << sizeof(top_bottom) << endl;
	//cout << sizeof(middle) << endl;
	output_array(top_bottom);
	output_array(middle);
	cout << "*" << endl;
	cout << "*" << endl;
	cout << "*" << endl;
	output_array(middle);
	output_array(top_bottom);

	system("pause");
}