#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//x - исходное число, d - номер подразряда
int digit(int x, int d)
{
	int p, x1;
	x1 = x >> d;
	p = x1 & 1;
	return p;
}

int Radix_Sort(int* array, int f, int l, int d)
{
	int ps = 0;
	if (d < 0 || f == l) return ps;
	int i, j;
	i = f;
	j = l;
	int temp;
	while (i <= j)
	{
		ps += 2;
		while (digit(array[i], d) == 0 && i <= j)
		{
			i++;
			ps++;
		}
		ps += 2;
		while (digit(array[j], d) == 1 && j >= i)
		{
			j--;
			ps++;
		}
		ps++;
		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
			ps++;
		}
	}
	ps++;
	Radix_Sort(array, f, j, d - 1);
	Radix_Sort(array, i, l, d - 1);
	return ps;
}

int main(int argc, char* argv[])
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));

	int i, j, n = 100;
	int average_amount;
	int* array;
	FILE* file;
	array = (int*)malloc(10000 * sizeof(int));
	file = fopen("input.csv", "w");

	while (n <= 10000)
	{
		average_amount = 0;

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < n; j++)
			{
				array[j] = rand() % 100;
			}
			average_amount = average_amount + Radix_Sort(array, 0, n - 1, 10);
		}
		average_amount = average_amount / 5;
		fprintf(file, "%d; %d\n", n, average_amount);

		if (n < 1000) n += 100;
		else n += 1000;
	}
	free(array);
}