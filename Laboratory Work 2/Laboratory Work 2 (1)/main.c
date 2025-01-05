#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* fill_array(int length);
int InsertSort(int length);
void count_operation();

int main() {
	system("chcp 1251");
	system("cls");
	srand(time(NULL));

	count_operation();

	return 0;
}

int* fill_array(int length)
{
	int* array = (int*)malloc(sizeof(int) * length);

	for (size_t i = 0; i < length; i++) 
	{
		array[i] = rand() % 10000;
	}

	return array;
}

//Сортировка вставками
int InsertSort(int length)
{
	int* array = fill_array(length);
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

	free(array);
	return count;
}

void count_operation()
{
	int* array = (int*)malloc(sizeof(int) * 10000);
	int length = 100, count = 0;

	FILE* f = fopen("input.csv", "w");
	if (f == NULL) {
		printf("Ошибка создания файла. \n");
		system("pause");
	}

	while (length <= 10000)
	{
		for (size_t i = 0; i < 5; i++)
		{
			count += InsertSort(length);
		}

		fprintf(f, "%d;%d\n", length, count / 5);

		if (length < 1000) {
			length += 100;
		}
		else {
			length += 1000;
		}
	}
	fclose(f);
}
