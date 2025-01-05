#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Increment(int* interval_arr, int length)
{
	int count = -1;

	do
	{
		if (count++ % 2 == 1) //Нечетный проход
		{
			interval_arr[count] = 8 * pow(2, count) - 6 * pow(2, count / 2) + 1;
		}
		else //четный проход
		{
			interval_arr[count] = 9 * pow(2, count) - 9 * pow(2, (count + 1) / 2) + 1;
		}
	} while (3 * interval_arr[count] < length); //если значение интервала < 1/3 длины массива

	return count;
}

void ShellSort(int* array, int length)
{
	int i = 0, j = 0;
	int interval_arr[1000];

	//кол-во проходов или интервалов в interval_arr
	int count = Increment(interval_arr, length);
	int k = count + 1;
	int L = 0;

	for (L = k; L > 0; L--)
	{
		int key = 0;
		int j = 0;
		for (int i = L; i <= length; i++)
		{
			key = array[i];
			j = i - L;
			while (j >= 0 && array[j] > key)
			{
				array[j + L] = array[j];
				j -= L;
			}
			array[j + L] = key;
		}
	}
}

void GenerateArray(int* array, int length)
{
	srand(time(NULL));
	for (int i = 0; i <= length; i++)
	{
		array[i] = rand() % 100;
	}
}

void PrintArray(int* array, int length)
{
	for (int i = 0; i <= length; i++)
	{
		printf("\t%d", array[i]);
	}
	printf("\n\n");
}

int main(int argc, char** argv)
{
	system("chcp 1251");
	printf("Сортировка Шелла с последовательностью Седжвика\n\n");

	int length = 0;
	printf("Введите размерность массива: ");
	scanf("%d", &length);

	//задаем массив array длины length
	int* array = (int*)malloc(sizeof(int) * length);
	//int array[length];
	GenerateArray(array, length);

	printf("Неотсортированный массив: \n");
	PrintArray(array, length);

	ShellSort(array, length);
	printf("Отсортированный массив: \n");
	PrintArray(array, length);

	return 0;
}
