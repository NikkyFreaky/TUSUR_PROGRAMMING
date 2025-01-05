#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

size_t size = 2 << 10;

int search(char* str, char* substr)
{
	size_t flag = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		size_t count = 0;

		if (str[i] == substr[0])
		{
			for (size_t j = i, k = 0; j < strlen(str); j++, k++)
			{
				if (str[j] == substr[k])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if (count == strlen(substr))
			{
				printf("\n\tПодстрока в %d позиции", i);
				flag++;
			}

		}
	}
	return flag;
}

void readfile(FILE* file, char* substr)
{
	char* str = (char*)malloc(sizeof(char) * size);

	size_t count = 0;

	while (!feof(file))
	{
		fgets(str, size, file);
		printf("\nСтрока %Iu:\n", ++count);
		if (search(str, substr) == 0)
		{
			printf("\n\t[Результатов нет]\n");
		}
	}
}


int main()
{
	setlocale(LC_ALL, "RU");

	char* substr = (char*)malloc(sizeof(char) * size);
	char* path = (char*)malloc(sizeof(char) * size);

	printf("Введите название файла: ");
	if (scanf("%s", path) > 0)
	{
		printf("\nВведите подстроку: ");
		if (scanf("%s", substr) > 0)
		{
			FILE* file = NULL;
			file = fopen(path, "r");
			if (file != NULL)
			{
				readfile(file, substr);
			}
		}
	}

}