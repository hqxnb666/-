#define _CRT_SECURE_NO_WARNINGS
#include"Hearp.h"
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HPDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void Swap(HDataType* p1, HDataType* p2)
{
	HDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Adjustup(HDataType* a,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HPPush(HP* php, HDataType x)//Ä¬ÈÏÐ¡¶Ë
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HDataType* tmp = (HDataType*)realloc(php->a, sizeof(HDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	Adjustup(php->a, php->size - 1);
}
void Adjustdown(HDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = child  * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPPop(HP* php)//É¾³ý¶¥¶ËÔªËØ
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	Adjustdown(php->a, php->size, 0);
}bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
size_t HPSize(HP* php)
{
	assert(php);
	return php->size;
}
HDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
