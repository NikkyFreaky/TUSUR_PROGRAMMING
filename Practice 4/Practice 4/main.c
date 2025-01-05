#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Исходная функция 1
double function_1(double x)
{
	double y;
	y = pow(x, 4) - 0.48 * pow(x, 3) - 5.792 * pow(x, 2) + 0.486 * x + 4.792;
	return y;
}

//Производная функции 1
double derivative_1(double x)
{
	double y;
	y = 4 * pow(x, 3) - 1.44 * pow(x, 2) - 11.584 * x + 0.486;
	return y;
}


//Исходная функция 2
double function_2(double x)
{
	double y;
	y = 0.1 * sin(x) + pow(x, 3) - 1;
	return y;
}

//Производная функции 2
double derivative_2(double x)
{
	double y;
	y = 0.1 * cos(x) + 3 * pow(x, 2);
	return y;
}

//Исходная функция 3
double function_3(double x)
{
	double y;
	y = 0.1 * exp(x) - pow(sin(x), 2) + 0.5;
	return y;
}

//Производная функции 3
double derivative_3(double x)
{
	double y;
	y = 0.1 * exp(x) - sin(2 * x);
	return y;
}

//Функция, реализующая численный метод
double tangent_method(double x, double eps, int number)
{
	double x1, y;

	if (number == 1) {
		x1 = x - (function_1(x) / derivative_1(x));
		y = function_1(x);
		while (fabs(y) > eps)
		{
			x = x1;
			x1 = x - (function_1(x) / derivative_1(x));
			y = function_1(x1);
		}
		return x;
	}
	if (number == 2) {
		x1 = x - (function_2(x) / derivative_2(x));
		y = function_2(x);
		while (fabs(y) > eps)
		{
			x = x1;
			x1 = x - (function_2(x) / derivative_2(x));
			y = function_2(x1);
		}
		return x;
	}
	if (number == 3) {
		x1 = x - (function_3(x) / derivative_3(x));
		y = function_3(x);
		while (fabs(y) > eps)
		{
			x = x1;
			x1 = x - (function_3(x) / derivative_3(x));
			y = function_3(x1);
		}
		return x;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	double eps;

	printf(" Введите значение точности вычисления(eps): ");
	scanf("%lf", &eps);

	printf("\n Значение функции 1 при x = 3: %lf\n", tangent_method(3, eps, 1));
	printf(" Значение функции 1 при x = 1.5: %lf\n", tangent_method(1.5, eps, 1));
	printf(" Значение функции 1 при x = -0.5: %lf\n", tangent_method(-0.5, eps, 1));
	printf(" Значение функции 1 при x = -1.8: %lf\n", tangent_method(-1.8, eps, 1));

	printf("\n Значение функции 2 при x = 1.1: %lf\n", tangent_method(1.1, eps, 2));

	printf("\n Значение функции 3 при x = 1.8: %lf\n", tangent_method(1.8, eps, 3));
	printf(" Значение функции 3 при x = 1.3: %lf\n", tangent_method(1.3, eps, 3));
	printf(" Значение функции 3 при x = -0.7: %lf\n", tangent_method(-0.7, eps, 3));
	printf(" Значение функции 3 при x = -2.2: %lf\n", tangent_method(-2.2, eps, 3));

	return 0;
}
