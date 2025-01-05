#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rec(double b, double q, double n) {
	if (n == 0) 
	{
		return 0;
	}
	if (n == 1)
	{
		return b;
	}

	return  b * pow(q, (n-1)) + rec(b, q, (n-1)); ;
}

double nonrec(double b, double q, double n)
{
	double sum = 0;
	if (q != 1)
	{
		sum = (b * (pow(q, n) - 1)) / (q - 1);
		printf("Ответ: %.lf (не рекурсивная реализация)\n", sum);
	}
	else
	{
		printf("Ошибка деления на ноль");
		return 0;
	}
} 

double main() {
	system("chcp 1251");
	system("cls");

	double n, q, b;
	printf("Введите первый член прогрессии, b1=");
	scanf("%lf", &b);
	printf("Введите знаменатель прогрессии, q=");
	scanf("%lf", &q);
	printf("Введите n-ый член прогрессии, n=");
	scanf("%lf", &n);
	
	double sum = rec(b, q, n);
	printf("\nОтвет: %.lf (рекурсивная реализация)\n", sum);
	nonrec(b, q, n);
	

	return 0;
}