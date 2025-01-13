#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int ControlBitesCounter(int inform_bits)
{
	int r = 0; //кількість контрольних бітів
	for (int i = 1; i < inform_bits; i++)
	{
		if (((1 << (i - 1)) < inform_bits + i) && (inform_bits + i < (1 << i)))
		{
			r = i;
		}
	}

	return r;
}

void CalculateControlBites(int control_bits, int all_bits, short* code)
{
	int pos = 0;
	for (int i = 0; i < control_bits; i++) //підрахунок контрольних бітів в окремому циклі 
		//(кожна ітерація зовнішнього циклу змінює позицію контрольного біта,
		//який треба обрахувати, а внутрішній цикл проходить по масиву з кодом Геммінга 
		//та обирає потрібні інформаційні біти)
	{
		pos = 1 << i;
		for (int j = 0; j < all_bits; ++j)
		{
			if ((j + 1) & pos)
			{
				code[pos - 1] ^= code[j];
			}
		}
	}
}

void PrintCode(short* code, int all_bits)
{
	for (int i = 0; i < all_bits; ++i)
	{
		printf("%hd ", code[i]);
	}
}

void EnterSequence(short* code, int all_bits)
{
	int j = 0;
	printf("Enter the sequence of bits: ");
	for (int i = 0; i < all_bits; ++i)
	{
		if (i == ((1 << j) - 1))
		{
			j++;
			continue;
		}
		scanf("%hd", &code[i]);
	}
}

void CustomCode(short* code, int inform_bits)
{
	int control_bits = ControlBitesCounter(inform_bits);

	int all_bits = inform_bits + control_bits; // довжина коду Геммінга

	code = (short*)calloc(all_bits, sizeof(short));
	if (!code)
	{
		printf("Fail while allocating the memory!");
		return;
	}

	EnterSequence(code, all_bits);
	CalculateControlBites(control_bits, all_bits, code);
	PrintCode(code, all_bits);

	free(code);
}