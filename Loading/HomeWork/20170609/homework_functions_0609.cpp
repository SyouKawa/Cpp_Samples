#include<stdio.h>
#include"homework_functions_0609.h"

int Path_cacl(int x,int y)
{
	if (x == 0 && y==0 )
		return 1;
	if (x == 0 && y > 0)
		return Path_cacl(x,y-1);
	if (x > 0 && y == 0)
		return Path_cacl(x - 1, y);

	return Path_cacl(x, y - 1) + Path_cacl(x - 1, y - 1);
	}