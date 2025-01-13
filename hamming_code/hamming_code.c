#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

int main()
{
	short* hamming_code = NULL;
	int k; //кількість інформаційних бітів

	printf("Enter the quantity of informational bits: ");
	scanf("%d", &k);

	CustomCode(hamming_code, k);

	return 0;
}