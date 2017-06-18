#include <iostream>
using namespace std;

int main()
{
	int array_071[5][6]{0};
	int (*point_p)[6]=array_071;
	//int *point[5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 6; j++)
			array_071[i][j] = i + j;

	cout << "array_071[2][4]=" << array_071[2][4] << endl;

	cout << "array_071=" << array_071 << endl;
	cout << "point_p=" << point_p << endl;
	cout << "*point_p=" << *point_p << endl;

	cout << "*(point_p+1)=" << *(point_p + 1) << endl;
	cout << "*(point_p+2)=" << *(point_p + 2) << endl;
	cout << "size of element(point_p[1][0])=" << sizeof(**(point_p + 1)) << endl;
	cout << "value_ptrdiff((*(point_p + 2)) - (*(point_p + 1)))="<<(*(point_p + 2)) - (*(point_p + 1)) << endl;
	cout << "the address of point_p[2][0] minus the address of point_p[1][0]="<< 24 << endl;
	cout << endl;
	cout << "size of element" << endl;
	cout << "X" << endl;
	cout << "value_ptrdiff" << endl;
	cout << "---------------------" << endl;
	cout << sizeof(**point_p)  *  (*(point_p + 2) - *(point_p + 1)) << endl;
	cout << endl;
	cout << "(*(point_p+2))+3=" << (*(point_p + 2)) + 3 << endl;
	//cout << sizeof(*(*(point_p + 2) + 3)) << endl;
	cout << "(*(point_p+2))+4=" << (*(point_p + 2)) + 4 << endl;
	cout << "*(*(point_p+2)+4)=" << *(*(point_p + 2) + 4) << endl;

	system("pause");

	return 0;
}