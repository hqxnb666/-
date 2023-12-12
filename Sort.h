#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<assert.h>
#include <stdbool.h>

void PrintArray(int* a, int n);
//打印数组
void InsertSort(int* a, int n);
//插入排序
void BubbleSort(int* a, int n);
//冒泡排序
void ShellSort(int* a, int n);
//希尔排序
void TestOP();
//测试排序性能
void SelectSort(int* a, int n);
//选择排序
void QuickSort1(int* a, int begin, int end);//hoare版
int GetMidi(int* a, int begin, int end);
//快速排序
void HeapSort(int* a, int n);
// 挖坑法
int PartSort2(int* a, int begin, int end); //hoare求key省略，这里直接采取挖坑法求key
void QuickSort2(int* a, int begin, int end);
int PartSort3(int* a, int begin, int end);//前后指针法
void QuickSort2(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);//非递归
void MergeSort(int* a, int n);