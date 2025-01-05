#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* fill_array(int length) {
	int* array = (int*)malloc(sizeof(int) * length);

	for (size_t i = 0; i < length; i++)
	{
		array[i] = rand() % 1000;
	}

	return array;
}

void print_array(int* array, int length) {
	for (size_t i = 0; i < length; i++)
	{
		printf("\t%d", array[i]);
	}
	printf("\n");
}

//Вычислительная сложность O(n^2)
int InsertSort(int length) {
	int* array = fill_array(length);
	printf("\nНеотсортированный массив:\n");
	print_array(array, length);

	int count = 0, min_elem = 0, new_elem, location;
	int temp = 0;

	temp = array[0];
	min_elem = array[0];

	for (size_t i = 1; i < length; i++)
	{
		new_elem = array[i];
		for (location = i - 1; array[location] > new_elem; location--)
		{
			array[location + 1] = array[location];
			count += 3;
		}
		array[location + 1] = new_elem;
		count++;
	}
	for (location = 1; location < length && array[location] < min_elem; location++) {
		array[location - 1] = array[location];
	}
	array[location - 1] = temp;

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