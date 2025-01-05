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
	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	int* array, n, i;
	printf("Введите колличество элементов: ");
	scanf("%d", &n);
	array = (int*)malloc(sizeof(int) * n);
	printf("Первоначальный массив:\n");
	for (i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		printf("%5d", array[i]);

	}
	int ps = 0;
	printf("\nОтсортированный массив:\n");
	ps = Radix_Sort(array, 0, n - 1, 10);
	for (i = 0; i < n; i++)
	{
		printf("%5d", array[i]);
	}
	printf("\nКоличество перестановок и сравнений: %d", ps);
	free(array);
	return 0;
}