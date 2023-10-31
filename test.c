#define _CRT_SECURE_NO_WARNINGS
#include "sl.h"
int main()
{
	SL s1;
	SeqlistInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	Print(&s1);

	return 0;
}