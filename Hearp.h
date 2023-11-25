#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int HDataType;
typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}HP;
void HPInit(HP* php);
void HPDestory(HP* php);
void HPPush(HP* php, HDataType x);
void HPPop(HP* php);
bool HPEmpty(HP* php);
size_t HPSize(HP* php);
HDataType HPTop(HP* php);