#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* array, int length);
int* fill_array(int length);
int InsertSort(int length);
void count_operation(int length);

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));

	int length;

	printf("Введите количество элементов в массиве: ");
	scanf("%d", &length);
	count_operation(length);

	return 0;
}

int* fill_array(int length)
{
	int* array = (int*)malloc(sizeof(int) * length);

	for (size_t i = 0; i < length; i++)
	{
		array[i] = rand() % 1000;
	}

	return array;
}

void print_array(int* array, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		printf("\t%d", array[i]);
	}
	printf("\n");
}

//Сортировка вставками
int InsertSort(int length)
{
	int* array = fill_array(length);
	printf("\nНеотсортированный массив:\n");
	print_array(array, length);

	int count = 0, new_elem, location;

	for (size_t i = 1; i < length; i++)
	{
		new_elem = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > new_elem)
		{
			array[location + 1] = array[location];
			location--; count += 3;
		}
		array[location + 1] = new_elem;
		count++;
	}
	printf("\nОтсортированный массив:\n");
	print_array(array, length);

	free(array);
	return count;
}

void count_operation(int length)
{
	int count = 0;
	count += InsertSort(length);
	printf("\nКоличество перестановок: %d\n", count);
}