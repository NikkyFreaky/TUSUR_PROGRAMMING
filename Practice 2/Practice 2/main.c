#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* number;
	char* color;
	char* brand;
	char* name;
	char* surname;
	char* patronymic;
}dataBase;

const char path_in[] = "file_in.txt";

int line_count(const char* filename);
void print_data(dataBase* data, int count);
void reload_data(dataBase* data, int count);
void search_data(dataBase* data, int count);

int main() {
	system("chcp 1251");

	int count = line_count(path_in);
	dataBase* data = (dataBase*)malloc(count * sizeof * data);
	reload_data(data, count);
	int choice;
	do
	{
		printf("\n >[0]-Вывести базу данных\n >[1]-Обновить базу данных\n >[2]-Перейти к поиску\n >[3]-Выход из программы\n >>> ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			system("cls");
			printf("\n База данных:\n\n");
			print_data(data, count);
			break;
		}
		case 1:
		{
			system("cls");
			printf("\n База данных [%s] обновилась\n", path_in);
			reload_data(data, count);
			break;
		}
		case 2:
		{
			system("cls");
			printf("\n База данных:\n\n");
			print_data(data, count);
			printf("\nВведите:\nЦВЕТ\tМАРКА\n");
			search_data(data, count);
			break;
		}
			default: break;
		}
	} while (choice != 3);

	return 0;
}

//определяем количество строк в файле
int line_count(const char* filename)
{
	int ch = 0;
	int count = 1;
	FILE* fileHandle;

	if ((fileHandle = fopen(filename, "r")) == NULL) {
		return -1;
	}

	do {
		ch = fgetc(fileHandle);
		if (ch == '\n')
			count++;
	} while (ch != EOF);

	fclose(fileHandle);

	return count;
}

//вывод базы данных
void print_data(dataBase* data, int count) {
	for (size_t i = 0; i < count; i++)
	{
		printf("#%d)\t%s\t%s\t%s\t%s\t%s\t%s\n", i + 1, data[i].number, data[i].color, data[i].brand, data[i].name, data[i].surname, data[i].patronymic);
	}
}

//
void reload_data(dataBase* data, int count) {
	FILE* file = fopen(path_in, "r");
	for (size_t i = 0; i < count; i++)
	{
		data[i].number = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].number);
		data[i].color = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].color);
		data[i].brand = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].brand);
		data[i].name = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].name);
		data[i].surname = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].surname);
		data[i].patronymic = (char*)malloc(sizeof(char*));
		fscanf(file, "%s", data[i].patronymic);
	}
}

//поиск по заданным данным 
void search_data(dataBase* data, int count) {
	char searchX[256];
	char searchY[256];

	scanf("%s", &searchX);
	scanf("%s", &searchY);
	printf("\nРезультаты поиска:\n\n");
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(searchX, data[i].color) == 0 && strcmp(searchY, data[i].brand) == 0) {
			printf("%s\t%s\t%s\n", data[i].name, data[i].surname, data[i].patronymic);
		}
	}
}