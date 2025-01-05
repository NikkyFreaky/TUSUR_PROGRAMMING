#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char path_in[] = "file_in.bin";
const char path_out[] = "file_out.bin";

void file_size_create(int* buffer_row, int* buffer_line);
void fill_file(int row, int line);
void print(int row, int line);
void delete_line(int row, int line);

int main() {
	system("chcp 1251");
	//заполнение файла
	int row = 0;
	int line = 0;
	file_size_create(&row, &line);
	fill_file(row, line);

	//выполнение программы
	print(row, line);
	delete_line(row, line);
	system("PAUSE");
	return 0;
}

//функция заполнения размерности массива в файл
void file_size_create(int* buffer_row, int* buffer_line) {
	FILE* file = fopen(path_in, "wb+"); 
	int x, y;
	do
	{
		printf("\n Введите размерность массива n*m (n>m): ");
		scanf("%d%d", &x, &y);
	} while ((x) < (y));
	*buffer_row = x;
	*buffer_line = y;

	//fprintf(file, "%d ", *buffer_row);
	fwrite(&(*buffer_row), sizeof(int), 1, file);
	fwrite(&(*buffer_row), sizeof(int), 1, file);
	//fprintf(file, "%d\n", *buffer_line);

	fclose(file);
}

//функция заполнения файла случайными числами
void fill_file(int row, int line) {
	FILE* file = fopen(path_in, "ab");
	srand(time(NULL));
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < line; j++) {
			int temp = rand() % 200 - rand() % 70;
			fwrite(&temp, sizeof(int), 1, file);
			//fprintf(file, "%d ", temp);
		}
		//fprintf(file, "\n");
	}
	fclose(file);
}

//функция вывода массива
void print(int row, int line) {
	FILE* file = fopen(path_in, "rb");
	printf("\n");
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < line; j++) {
			int x;
			//fscanf(file, "%d\t", &x);
			fread(&x, sizeof(int), 1, file);
			printf("\t%d", x);
		}
		printf("\n");
	}
	fclose(file);
}

//функция удаления строки
void delete_line(int row, int line) {

	int count = 0;
	int lineX = 0;
	int* data = NULL;
	do {
		printf("\n Введите количество строк для удаления: ");
		scanf("%d", &count);
		data = (int*)malloc(sizeof(int) * count);
		printf(" Введите какие строки вы хотите удалить: ");
		for (size_t i = 0; i < count; i++)
		{
			scanf("%d", &data[i]);
		}
	} while (lineX >= line);

	printf("\n");

	FILE* file = fopen(path_in, "rb");
	FILE* file_out = fopen(path_out, "wb");

	int x = 0;
	int delline = data[x];

	for (size_t i = 1; i <= row; i++)
	{
		if (delline == i) {
			x++;
			delline = data[x];
			for (size_t i = 0; i < line; i++)
			{
				int temp;
				//fscanf(file, "%d", &temp);
				fread(&temp, sizeof(int), 1, file);
			}
		}
		else
		{
			for (size_t j = 0; j < line; j++) {
				int temp;
				//fscanf(file, "%d", &temp);
				fread(&temp, sizeof(int), 1, file);
				//fprintf(file_out, "%d\t", temp);
				printf("\t%d", temp);
			}
			printf("\n");
			//fprintf(file_out, "\n");
		}
	}

	//free(data);
	fclose(file);
	fclose(file_out);
}

