#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MergeSorting(int* X, int F, int M, int L)
{
	int ps = 0;
	int i = F;
	int j = M;
	int k = 0;
	int* X1 = (int*)malloc((L - F + 1) * sizeof(int));


	while (i < M && j <= L)
	{
		ps += 3;
		if (X[i] > X[j])
		{
			X1[k] = X[j];
			j++;
			k++;
			ps++;
		}

		else
		{
			ps++;
			if (X[j] > X[i])
			{
				X1[k] = X[i];
				i++;
				k++;
				ps++;
			}

			else
			{
				X1[k] = X[i];
				X1[k + 1] = X[j];
				k += 2;
				i++;
				j++;
				ps += 2;
			}
		}
	}

	ps++;
	if (i < M)
	{
		for (i; i <= M - 1; i++)
		{
			X1[k] = X[i];
			k++;
			ps++;
		}
	}

	ps++;
	if (j <= L)
	{
		for (j; j <= L; j++)
		{
			X1[k] = X[j];
			k++;
			ps++;
		}
	}

	for (i = 0; i < k; i++)
	{
		X[i + F] = X1[i];
	}

	free(X1);
	return ps;
}

int TD_Merge(int* X, int F, int L)
{
	int ps = 0;
	ps++;
	if (F >= L) return ps;
	int M = (F + L) / 2;

	ps += TD_Merge(X, F, M);
	ps += TD_Merge(X, M + 1, L);
	ps += MergeSorting(X, F, M + 1, L);

	return ps;
}


int main()
{
	system("chcp 1251");
	printf("Введите размер массива: ");
	int m, n, i, j;
	m = scanf("%d", &n);
	if ((m != 1) || (n <= 0))
	{
		printf("Некорректный ввод.");
		return 0;
	}

	// Выделение памяти
	int* X;
	X = (int*)malloc(n * sizeof(int));

	// Заполнение массива случайными значениями
	srand(time(NULL));
	printf("\n Первоначальный массив:");

	for (i = 0; i < n; i++)
	{
		X[i] = rand() % 100;
		printf("%8.2d", X[i]);
	}

	int ps = 0;
	ps = TD_Merge(X, 0, n - 1);
	printf("\n\nОтсортированный массив:");
	for (i = 0; i < n; i++)
		printf("%8.2d", X[i]);
	printf("\n\n  Количество перестановок и сравнений: %d.", ps);
	free(X);
}