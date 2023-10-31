#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;
	int capicity;
}SL;

void SeqlistInit(SL* p);
void SeqlistDestory(SL* p);
void Print(SL* p);
void CheckCapacity(SL* p);
void SeqListPushBack(SL* p, SLDataType x);
void SeqListPushFront(SL* p, SLDataType x);
void SLPopBack(SL* p);
void SLPopFront(SL* p);
void SLInsert(SL* p, int pos, SLDataType x);
void SLErase(SL* ps1, int pos);