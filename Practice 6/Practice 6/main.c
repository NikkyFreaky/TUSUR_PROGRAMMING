#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	system("chcp 1251");
	system("cls");

    int start;
    const int n = 5;
    int g[n][n];
    const int inf = 999;
    FILE* f = fopen("Input.txt", "r");
    if (in.is_open()) {
        int count = 0;
        int temp;
        while (!feof(f)) {
            in >> temp;
            count++;
        }
        fseek(f, 0, SEEK_SET);
        fclose(f);
        int count_space = 0;
        char symbol;
        while (!feof(f)) {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        fseek(f, 0, SEEK_SET);
        fclose(f);
        int n = count / (count_space + 1);
        int m = count_space + 1;
        double** x;
        x = new double* [n];
        for (int i = 0; i < n; i++) x[i] = new double[m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> x[i][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = x[i][j];
            }
        }
        for (int i = 0; i < n; i++) free (x[i]);
        free (x);
        fclose(f);
    }
    else printf("Файл не найден");
    int d[n + 5];
    int p[n + 5];
    bool used[n + 5];
    for (int i = 0; i < n + 5; i++) {
        d[i] = inf;
        p[i] = -1;
        used[i] = false;
    }
    int finish, min, u;
    printf("Enter start: ");
    scanf("%d", &start);
    printf("Enter end: ");
    scanf("%d", &finish);
    d[start] = 0;
    for (int i = 0; i < n; ++i) {
        min = inf, u = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && d[j] < min)
                min = d[j], u = j;
        if (u == -1) break;
        used[u] = true;
        for (int j = 0; j < n; ++j)
            if (d[j] > d[u] + g[u][j] && g[u][j] > 0)
                d[j] = d[u] + g[u][j], p[j] = u;
    }
    int path[10];
    int counter = 0;
    if (p[finish] == -1)
        printf("way not found");
    else {
        for (int u = finish; u != -1; u = p[u]) {
            path[counter++] = u;
        }
        for (int i = 0; i < counter; ++i) {
            if (i > 0) printf("<-");
            printf("%d", path[i]);
        }
    }

	return 0;
}