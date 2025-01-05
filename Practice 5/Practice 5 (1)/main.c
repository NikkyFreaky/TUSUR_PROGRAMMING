#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int n = 2 << 6;

void print(int arr[2 << 6])
{
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != 0)
        {
            printf("%c ", i);
        }
    }
}

// Привидение к прописной букве
void ascii(char* str)
{
    int arr[2 << 6] = { 0 };

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90)
        {
            arr[str[i] + 32]++;
        }
        else
        {
            arr[str[i]]++;
        }
    }
    print(arr);
}

// Привидение к заглавной букве
void ascii_2(char* str)
{
    int arr[2 << 6] = { 0 };

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122)
        {
            arr[str[i] - 32]++;
        }
        else
        {
            arr[str[i]]++;
        }
    }
    print(arr);

}

void ascii_3(char* str)
{
    int arr[2 << 6] = { 0 };

    for (size_t i = 0; i < strlen(str); i++) {
        arr[str[i]]++;
    }
    print(arr);
}

int main()
{
    setlocale(LC_ALL, "RU");

    char* str = (char*)malloc(sizeof(char) * 2 << 9);
    FILE* f = fopen("Input.txt", "r");
    fgets(str, 2 << 9, f);
    fclose(f);

    printf("Вывод из файла: \n");
    ascii_3(str);

    printf("\n\nПривидение к заглавной букве: \n");
    ascii_2(str);

    printf("\n\nПривидение к прописной букве: \n");
    ascii(str);
    printf("\n");

    return 0;
}