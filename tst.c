#define _CRT_SECURE_NO_WARNINGS
#include "Hearp.h"
//int main()
//{
//	HP hp;
//	int a[] = { 1,2,3,4,5,6,9 };
//	HPInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HPPush(&hp, a[i]);
//		
//	}
//	int k = 3;
//	while (k--)
//	{
//		printf("%d", HPTop(&hp));
//		HPPop(&hp);
//	}
//
//
//	
//	return 0;
//}
void HeapSort(int* a, int n)
{
	//第一种 向上调整 大堆
	//for (int i = 1; i < n; i++)
	//{
	//	Adjustup(a,i);
	//}//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		Adjustdown(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		Adjustdown(a, end, 0);
		--end;
	}

}




void CreateNode()
{
	int n = 10000000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin= fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 10000000;//+i是为了减少重复值 因为rand最多就三万个随机值 
		fprintf(fin, "%d\n", x);
	}
}

void PrintTopK(const char* file,int k)
{
	FILE* four = fopen(file, "r");
	if (four == NULL)
	{
		perror("fopen fail");
		return;
	}
	//建一个k个数的小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(four, "%d", &minheap[i]);
		Adjustup(minheap, i);
	}
	int x = 0;
	while (fscanf(four, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;  //代替并不断向下调整
			Adjustdown(minheap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
		
	}
	printf("\n");

	fclose(four);
	four = NULL;
	free(minheap);
	minheap = NULL;
}

int main()
{
	/*int a[] = { 4,6,7,2,8,4,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d",a[i]);
	}*/


	//CreateNode();
	PrintTopK("data.txt", 5);
	return 0;
}