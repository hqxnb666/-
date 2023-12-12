#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "stack2.h"
int main()
{
	int a[] = { 5,8,2,4,1,6,7,3,8,5,3,645,2,1,6,6,3, };
	QuickSortNonR(a,0, sizeof(a) / sizeof(int)-1); 
	PrintArray(a, sizeof(a) / sizeof(int));
	//TestOP();

	
	return 0;
}