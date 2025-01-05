#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

void Insert(Node** Root, int key) {
    if (*Root == NULL) {
        (*Root) = (Node*)malloc(sizeof(Node));
        (*Root)->data = key;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
        return;
    }
    else
    {
        if (key >= (*Root)->data) {
            Insert(&((*Root)->right), key);
        }
        else
        {
            Insert(&((*Root)->left), key);
        }
    }
}

void Print(Node* Root)
{
    if (Root == NULL)
    {
        return;
    }
    printf("%d ", Root->data);
    Print(Root->left);   //рекурсивный вызов левого поддерева
    Print(Root->right);  //рекурсивный вызов правого поддерева
}
       
int main() {
	system("chcp 1251");
	system("cls");
	               
    Node* Root = NULL;
    int n, elems;
    srand(time(NULL));
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        elems = rand() % 100;
        printf("%d ", elems);
        Insert(&Root, elems);
    }
    printf("\n");
    Print(Root);

	return 0;
}