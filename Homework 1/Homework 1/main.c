// INFO: ������� MFC
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// INFO: ����������� ���������� ��� ����������� � ������
static int n = 0;
static int m = 0;


// INFO: ������� ���������� ������

// ���������� �� ������ �����
float* Gaus(float** array);
// �������� ���
void reverse(float** array, float* xx);


// INFO: ������� ������ � ����������

// ����� �������
void print(float* array);
// ����� ���������� �������
void print2D(float** array);
// ���������� �������
void fill(float** array);


// INFO: ����������� �������

//��������� ������ ���������� �������
float** createCalloc(int rows, int columns);
//������� ������ ���������� �������
void freeMemory(float** array, int rows);
//��������� ������ ����������� �������
float* createMalloc__(int rows);

int main()
{
    system("chcp 1251");
    printf(" ��������� �������� ������� ��.421-1 ������ ������ ���������, ������� 9.\n\n");

    printf(" ������� ���������� �������� ���������: ");
    scanf_s("%d", &n);

    printf(" ������� ���������� �����������: ");
    scanf_s("%d", &m);

    float** matrix = createCalloc(n, m++);
    fill(matrix);

    printf("\n ����������� �������: \n");
    print2D(matrix);

    // ������ ���, ���������� � ������������������ ����
    // � ���������� *xx ���������� ������� ������ ����� �������
    float* xx = Gaus(matrix);
    reverse(matrix, xx);

    print(xx);

    //������� ����������� �������
    free(xx);
    freeMemory(matrix, n);

    return 0;
}

void print2D(float** array) {
    for (int i = 0; i < n; i++)
    {
        printf("\t|");
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1) {
                printf("|");
            }
            printf("%5.1f\t", array[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

float* Gaus(float** array) {
    float* xx = createMalloc__(m);

    for (int i = 0; i < n; i++)
    {
        float tmp = array[i][i];
        for (int j = n; j >= i; j--)
            array[i][j] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            tmp = array[j][i];
            for (int k = n; k >= i; k--)
                array[j][k] -= tmp * array[i][k];
        }
    }
    return xx;
}

void print(float* array) {
    printf("����� � ��������� ����: � = ( ");
    for (int i = 0; i < n; i++) {
        printf("{%.3f} ", array[i]);
    }
    printf(");\n");
}

void fill(float** array) {
    for (int i = 0; i < n; i++) {
        printf(" ������� %d ������ [count %d]: ", i + 1, m);
        for (int j = 0; j < m; j++)
        {
            scanf_s("%f", &array[i][j]);
        }
    }
}

void reverse(float** array, float* xx) {
    xx[n - 1] = array[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        xx[i] = array[i][n];
        for (int j = i + 1; j < n; j++) {
            xx[i] -= array[i][j] * xx[j];
        }
    }
}

float** createCalloc(int rows, int columns) {
    float** arr = (float**)calloc(rows, sizeof(float*));
    if (arr) {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = (float*)calloc(columns, sizeof(float));
        }
    }
    return arr;
}

void freeMemory(float** array, int rows) {
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}

float* createMalloc__(int rows) {
    float* arr = (float*)malloc(rows * sizeof(float));
    return arr;
}