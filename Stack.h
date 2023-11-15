#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
		int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestroy(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
bool STEmpty(ST* pst);
STDataType STTop(ST* pst);
STDataType STSize(ST* pst);