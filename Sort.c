#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "Hearp.h"
#include "stack2.h"
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand()+i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort2(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;

		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void BubbleSort(int* a, int n)//使用bool来进阶冒泡 ，当有一层不交换，就代表已经排完序，防止永久时间复杂度都是O(n^2)
{
	for (int j = 0; j < n; j++)
	{
		bool exange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exange = true;
			}
		}
		if (exange == false)
			break;
	}

}
void ShellSort(int* a, int n)
    // gap > 1时是预排序，目的让他接近有序
	// gap == 1是直接插入排序，目的是让他有序
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin; 
		int max = begin;
		for (int i = begin+1; i <= end; ++i)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (max == begin)
		{
			max = mini;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
	
}
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
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		Adjustdown(a, end, 0);
		--end;
	}


}

int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	// begin end midi三个数选中位数
	if (a[begin] < a[midi])
	{
		if (a[midi] < a[end])
			return midi;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else // 处理 a[begin] >= a[midi] 的情况
	{
		if (a[begin] < a[end])
			return begin;
		else if (a[midi] > a[end])
			return midi;
		else
			return end;
	}
}

void QuickSort1(int* a, int begin, int end)
{

	if (begin >= end)
		return;

	if (end - begin + 1 <= 10)   //小区间优化
	{
		InsertSort(a+begin, end - begin + 1);  //a+begin  防止都是从左数组开始
	}
	else
	{
		int midi = GetMidi(a, begin, end);
		Swap(&a[midi], &a[begin]);

		int keyi = begin;
		int right = end;
		int left = begin;

		while (left < right)
		{
			//右边找小
			while (left < right && a[right] >= a[keyi])
			{
				--right;
			}
			//左边找大
			while (left < right && a[left] <= a[keyi])//加入&&的原因是如果到相遇点时，left还是小于kei，他不会在相遇点停下，并且再次交换就颠倒顺序了
			{
				++left;
			}

			Swap(&a[left], &a[right]);
		}
		Swap(&a[left], &a[keyi]);
		keyi = left;

		//左半  [begin , keyi-1]     keyi     [keyi+1, end]
		QuickSort1(a, begin, keyi - 1);
		QuickSort1(a, keyi + 1, end);
	}

	
}

int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int key = a[begin];
	int hole = begin;

	while (begin < end)
	{
		//右边找小，找左边的坑
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[hole] = a[end];
		hole = end;
		// 左边找大，填到右边的坑
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[hole] = a[begin];
		hole = begin;
	}
	a[hole] = key;
	return hole;
}
void QuickSort2(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	if (end - begin + 1 <= 10)   //小区间优化
	{
		InsertSort(a + begin, end - begin + 1);  //a+begin  防止都是从左数组开始
	}
	int keyi = PartSort2(a, begin, end);
	QuickSort2(a, begin, keyi - 1);
	QuickSort2(a, keyi + 1, end);
}
int PartSort3(int* a, int begin, int end)
{

	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);


	int keyi = begin;
	int prev = begin;
     int cur = prev + 1;
	while (cur<=end)
	{
		if(a[cur] < a[keyi] && ++prev != cur)
		Swap(&a[prev], &a[cur]);
		
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}
void QuickSort3(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	if (end - begin + 1 <= 10)   //小区间优化
	{
		InsertSort(a + begin, end - begin + 1);  //a+begin  防止都是从左数组开始
	}
	int keyi = PartSort3(a, begin, end);
	QuickSort3(a, begin, keyi - 1);
	QuickSort3(a, keyi + 1, end);
}
void QuickSortNonR(int* a, int begin, int end)
{
	ST s;
	STInit(&s);

	STPush(&s, end);
	STPush(&s, begin);

	while (!STEmpty(&s))
	{
		int left = STTop(&s);
		STPop(&s);
		int right = STTop(&s);
		STPop(&s);
		int keyi = PartSort3(a, left, right);
		//  [left, keyi-1] keyi  [keyi+1,right]
		if (left < keyi - 1)
		{
			STPush(&s, keyi - 1);
			STPush(&s, left);
		}
		if (keyi + 1 < right)
		{
			STPush(&s, right);
			STPush(&s, keyi+1);
		}
	}

	STDestory(&s);
}
void MergeSort(int* a, int n)
{

}