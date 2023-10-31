#define _CRT_SECURE_NO_WARNINGS
#include "sl.h"
void SeqlistInit(SL* ps1)
{
	assert(ps1);
	ps1->a = NULL;
	ps1->size = 0;
	ps1->capicity = 0;
}
void SeqlistDestory(SL* ps1)
{
	assert(ps1);
	free(ps1->a);
	ps1->a = NULL;
	ps1->size = 0;
	ps1->capicity = 0;
}
void Print(SL* ps1)
{
	assert(ps1);
	for (int i = 0; i < ps1->size; i++)
	{
		printf("%d\n", ps1->a[i]);
	}
	printf("\n");

}
void CheckCapacity(SL* ps1)
{
	assert(ps1);
	if (ps1->size == ps1->capicity)
	{
		int newcapacity = ps1->capicity == 0 ? 4 : ps1->capicity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps1->a, sizeof(SLDataType) * newcapacity);

		if (tmp == NULL)
		{
			perror("realloc fail:");
			return;
		}
		ps1->a = tmp;
		ps1->capicity = newcapacity;
	}
}
void SeqListPushBack(SL* ps1, SLDataType x)
{
	assert(ps1);
	CheckCapacity(ps1);
	ps1->a[ps1->size] = x;
	ps1->size++;
}
void SeqListPushFront(SL* ps1, SLDataType x)
{
	assert(ps1);
	CheckCapacity(ps1);
	//挪动数据
	int end = ps1->size - 1;
	while (end >= 0)
	{
		ps1->a[end + 1] = ps1->a[end];
		end--;
	}
	ps1->a[0] = x;
	ps1->size++;

}
void SLPopBack(SL* ps1)
{
	assert(ps1);
	assert(ps1->size > 0);
	ps1->size--;
}
void SLPopFront(SL* ps1)
{
	int begin = 1;
	while (begin < ps1->size)
	{
		ps1->a[begin - 1] = ps1->a[begin];
		++begin;
	}
	ps1 ->size--;
}
//pos  下标    
void SLInsert(SL* ps1, int pos, SLDataType x)
{
	assert(ps1);
	assert(pos >= 0 && pos <= ps1->size);

	CheckCapacity(ps1);
	//挪动数据
	int end = ps1->size - 1;
	while (end >= pos)
	{
		ps1->a[end + 1] = ps1->a[end];
		--end;
	}
	ps1->a[pos] = x;
	ps1->size++;
}
void SLErase(SL* ps1, int pos)
{
	assert(ps1);
	assert(pos >= 0 && pos < ps1->size);
	int begin = pos + 1;
	while (begin < ps1->size)
	{
		ps1->a[begin - 1] = ps1->a[begin];
		++begin;
	}
	ps1->size--;
}