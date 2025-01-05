#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 2 << 6; //64

void print_str(int arr[2 << 6])
{
    for (size_t i = 0; i < n; i++) {
        if (arr[i] != 0)
        {
            printf("%c ", i);
        }
    }
    printf("\n");
}

void ascii(char* str)
{
    int arr[2 << 6] = { 0 };

    for (size_t i = 0; i < strlen(str); i++) {
        arr[str[i]]++;
    }
    print_str(arr);
}

int main()
{
    system("chcp 1251");
    system("cls");

    char* str = (char*)malloc(sizeof(char) * 2 << 9); //512
    FILE* f = fopen("Input.txt", "r");
    fgets(str, 2 << 9, f);
    fclose(f);

    printf("ֲûגמה טח פאיכא: \n");
    ascii(str);

	return 0;
}