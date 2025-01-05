#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change(int* array, int k);
void fill_rand(int* array, int n); 
void permutation_nested_loops(int* array, int n, int* multitude);

int main() {
	system("chcp 1251");
	system("cls");

	int n, k;

	for (;;) {
		printf(" Введите значение мощности множества: ");
		int m = scanf("%d", &n);
		if (m != 1) {
			fflush(stdin);
			printf(" Введено не целое число\n");
			continue;
		}
		if (n <= 0) {
			printf(" Мощность множества должна быть положительна\n");
			continue;
		}
		break;
	}

	printf("\n Исходное множество: ");
	int* multitude = (int*)malloc(n * sizeof(int));
	fill_rand(multitude, n);
	int count = 1;
	for (size_t i = 0; i < n; i++) {
		count = count * (i + 1);
		printf("%d ", multitude[i]);
	}

	printf("\n Всего перестановок: %d\n", count);
	printf("\n Перестановки:\n");

	int* transposition = (int*)malloc(n * sizeof(int));
	permutation_nested_loops(transposition, n, multitude);

	free(transposition);
	free(multitude);

	return 0;
}

void change(int* array, int k) {
	int temp = array[k - 1];
	for (size_t i = k - 1; i > 0; i--)
		array[i] = array[i - 1];
	array[0] = temp;
}

void fill_rand(int* array, int n) {
	srand(time(NULL));

	array[0] = -100 + rand() % 201;
	for (size_t i = 1; i < n; i++)
		array[i] = array[i - 1] + 1 + rand() % 100;
}

void permutation_nested_loops(int* array, int n, int* multitude) {
	for (size_t i = 0; i < n; i++)
		array[i] = i + 1;
	int k = 0;
	while (k != 1) {
		for (size_t i = 0; i < n; i++)
			printf("\t%d", multitude[array[i] - 1]);
		printf("\n");
		k = n;
		change(array, k);
		while ((array[k - 1] == k) && (k > 1)) {
			k = k - 1;
			change(array, k);
		}
	}
}