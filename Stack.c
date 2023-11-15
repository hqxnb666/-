#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
	//top为-1代表指向栈顶元素  为0代表指向栈顶元素的下一个位置

}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top);
	pst->top--;
}
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top);
	return pst->a[pst->top-1];
}
STDataType STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}