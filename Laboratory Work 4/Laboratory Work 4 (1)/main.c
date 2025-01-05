#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Increment(int* interval_arr, int length);
int ShellSort(int* array, int length);
int InsertSort(int* array, int length, int l);
void PrintStats(int length, int stats);
void GenerateArray(int* array, int length);

int main()
{
	system("chcp 1251");
	system("cls");

	int sum = 0, length = 100;

	while (length <= 10000)
	{
		int* array = (int*)malloc(sizeof(int) * length);

		for (int i = 0; i < 5; i++)
		{
			GenerateArray(array, length);
			sum += ShellSort(array, length);
		}

		sum /= 5;
		PrintStats(length, sum);
		sum = 0;

		if (length < 1000)
		{
			length += 100;
		}
		else
		{
			length += 1000;
		}
	}

	return 0;
}

int Increment(int* interval_arr, int length)
{
	int count = -1;

	do
	{
		if (count++ % 2 == 1)
		{
			interval_arr[count] = (8 * pow(2, count)) - (6 * pow(2, count / 2)) + 1;
		}
		else
		{
			interval_arr[count] = (9 * pow(2, count)) - (9 * pow(2, (count + 1) / 2)) + 1;
		}
	} while (3 * interval_arr[count] < length);

	return count;
}

int InsertSort(int* array, int length, int L)
{
	int key = 0;
	int j = 0;
	int changes = 0;
	for (int i = L; i < length; i++)
	{
		key = array[i];
		j = i - L;
		while (j >= 0 && array[j] > key)
		{
			array[j + L] = array[j];
			j -= L;

			changes += 3;
		}
		array[j + L] = key;
		changes++;
	}

	return changes;
}


int ShellSort(int* array, int length)
{
	int i = 0, j = 0;
	int changes = 0;
	int interval_arr[1000];

	//кол-во проходов или интервалов в interval_arr
	int count = Increment(interval_arr, length);
	int k = count + 1;
	int L = 0;

	for (L = k; L > 0; L--)
	{
		changes += InsertSort(array, length, interval_arr[L]);
	}

	return changes;
}

void PrintStats(int length, int stats)
{
	FILE* f = fopen("stats.csv", "w");
	fprintf(f, "%d; %d\n", length, stats);
	fclose(f);
}

void GenerateArray(int* array, int length)
{
	srand(time(NULL));
	for (int i = 1; i < length; i++)
	{
		array[i] = rand() % 100;
	}
}