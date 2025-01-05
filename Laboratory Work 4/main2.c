#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Increment(int* inc, int length);
int ShellSort(int* array, int length);

int main() {
	system("chcp 1251");
	system("cls");

	int* array;
	int i, n = 100, max_n = 10000;
	long int sum = 0;

	FILE* f = fopen("input.csv", "w");
	if (f == NULL) {
		printf("Ошибка создания файла. \n");
		system("pause");
		return 1;
	}

	srand(time(NULL));
	array = (int*)malloc(sizeof(int) * max_n);
	while (n <= max_n)
	{
		for (int j = 0; j < 5; j++)
		{
			for (i = 0; i < n; i++)
			{
				array[i] = rand() % 1000;
			}
			sum += ShellSort(array, n);
		}

		fprintf(f, "%d;%li\n", n, sum / 5);
		sum = 0;

		if (n < 1000) {
			n += 100;
		}
		else {
			n += 1000;
		}
	}

	fclose(f);
	free(array);
	return 0;
}

int Increment(int* inc, int length)
{
	int koof1 = 1, koof2 = 1, koof3 = 1, count = -1;

	do
	{
		if (count++ % 2 == 1) //Нечетный проход
		{
			//koof2 *= 2;
			//inc[count] = 8 * koof1 - 6 * koof2 + 1;
			inc[count] = (8 * pow(2, count)) - (6 * pow(2, count / 2)) + 1;
		}
		else //четный проход
		{
			inc[count] = (9 * pow(2, count)) - (9 * pow(2, (count + 1) / 2)) + 1;
			//inc[count] = 9 * koof1 - 9 * koof3 + 1;
			//koof2 *= 2;
			//koof3 *= 2;
		}
		//koof1 *= 2;
	} while (3 * inc[count] < length); //если значение интервала < 1/3 длины массива

	return count > 0 ? count-- : 0;
}

int ShellSort(int* array, int length)
{
	int i, j, inc, seq[10];

	int count = Increment(seq, length); //номер прохода
	int changes = 0;

	while (count >= 0)
	{
		inc = seq[count--];

		for (i = inc; i < length; i++)
		{
			int temp = array[i];
			for (j = i - inc; (j >= 0) && (array[j] > temp); j -= inc)
			{
				array[j + inc] = array[j];
				changes++;
			}
			array[j + inc] = temp;
			changes++;
		}
	}
	return changes;
}
