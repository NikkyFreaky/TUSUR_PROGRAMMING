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

//нисходящая сортировка
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

int main(int argc, char* argv[])
{
	system("chcp 1251");
	srand(time(NULL));

	int i, j, n = 100;
	int average_amount;
	int* X;
	FILE* file;
	X = (int*)malloc(10000 * sizeof(int));
	file = fopen("input.csv", "w");

	while (n <= 10000)
	{
		average_amount = 0;

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < n; j++)
			{
				X[j] = rand() % 100;
			}
			average_amount += TD_Merge(X, 0, n - 1);;
		}
		average_amount = average_amount / 5;
		fprintf(file, "%d; %d\n", n, average_amount);

		if (n < 1000) n += 100;
		else n += 1000;
	}
	free(X);
}