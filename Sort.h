#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<assert.h>
#include <stdbool.h>

void PrintArray(int* a, int n);
//��ӡ����
void InsertSort(int* a, int n);
//��������
void BubbleSort(int* a, int n);
//ð������
void ShellSort(int* a, int n);
//ϣ������
void TestOP();
//������������
void SelectSort(int* a, int n);
//ѡ������
void QuickSort1(int* a, int begin, int end);//hoare��
int GetMidi(int* a, int begin, int end);
//��������
void HeapSort(int* a, int n);
// �ڿӷ�
int PartSort2(int* a, int begin, int end); //hoare��keyʡ�ԣ�����ֱ�Ӳ�ȡ�ڿӷ���key
void QuickSort2(int* a, int begin, int end);
int PartSort3(int* a, int begin, int end);//ǰ��ָ�뷨
void QuickSort2(int* a, int begin, int end);
void QuickSortNonR(int* a, int begin, int end);//�ǵݹ�
void MergeSort(int* a, int n);