#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//���� ������
typedef struct node {
	int n;
	int key;
	struct node* left;
	struct node* right;
}Node;

//������� ������ (������ � ����� �������� �������).������ ����� ������ ����� ���������� ����� �������, ������ ������ ���������� ������ ������.
void Rotate_r(Node** h)
{
	Node* x;
	if ((*h)->left == NULL) return;
	int k = (*h)->n;
	x = (*h)->left;
	(*h)->left = x->right;
	x->right = *h;
	(*h) = x;
	(*h)->n = k;
	(*h)->right->n = 1;
	if ((*h)->right->right != NULL)
		(*h)->right->n = (*h)->right->n + (*h)->right->right->n;
	if ((*h)->right->left != NULL)
		(*h)->right->n = (*h)->right->n + (*h)->right->left->n;
}

//������� ����� (������ � ������ �������� �������).����� ����� ������ ����� ���������� ������ �������, ������ ������ ���������� ����� ������.
void Rotate_l(Node** h)
{
	Node* x;
	if ((*h)->right == NULL) return;
	int k = (*h)->n;
	x = (*h)->right;
	(*h)->right = x->left;
	x->left = *h;
	(*h) = x;
	(*h)->n = k;
	(*h)->left->n = 1;
	if ((*h)->left->right != NULL)
		(*h)->left->n = (*h)->left->n + (*h)->left->right->n;
	if ((*h)->left->left != NULL)
		(*h)->left->n = (*h)->left->n + (*h)->left->left->n;
}

//������� � ������
//���� ����������� ������� ������ �������� �����, �� ����� ������� ������ ������, � ������ ������ ��������� � ����� ���������
//���� ����������� ������� ������ �������� �����, �� ����� ������� ������ ������, � ������ ������ ��������� � ������ ���������
void InsertR(Node** Root, int key)
{
	if ((*Root) == NULL)
	{
		(*Root) = (Node*)malloc(sizeof(Node));
		(*Root)->key = key;
		(*Root)->left = NULL;
		(*Root)->right = NULL;
		(*Root)->n = 1;
		return;
	}
	(*Root)->n++;
	if (key >= ((*Root)->key))
	{
		InsertR(&((*Root)->right), key);
		Rotate_l(Root);
	}
	else
	{
		InsertR(&((*Root)->left), key);
		Rotate_r(Root);
	}
}

//�������� ���������� ������ �� ����� (��������� k-�� ����������� ���� � ������)
void Partition(Node** R, int k)
{
	if ((*R) == 0) return;
	int T;
	if ((*R)->left)
	{
		T = (*R)->left->n;
	}
	else
	{
		T = 0;
	}
	if (T > k)
	{
		Partition(&((*R)->left), k);
		Rotate_r(R);
	}
	if (T < k)
	{
		Partition(&((*R)->right), k - T - 1);
		Rotate_l(R);
	}
}

//�������� ������������ (��� ������� ����� ��������� �������� � ���� �������)
void Balansed(Node** h)
{
	if ((*h) == NULL || (*h)->n == 1) return;
	Partition(&(*h), (*h)->n / 2);
	Balansed(&(*h)->left);
	Balansed(&(*h)->right);

}

void Coor(int x, int y)
{
	COORD position = { (short)x, (short)(y + 3) };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void Watch(Node* h, int n, int a, int b)
{
	Coor((a + b) / 2, n);
	if (h != NULL)
	{
		printf("%d(%d)", h->key, h->n);
		Watch(h->right, n + 1, (a + b) / 2, b);
		Watch(h->left, n + 1, a, (a + b) / 2);
	}
}

void Print(Node* Root)
{
	if (Root == NULL)
	{
		return;
	}
	printf("%d ", Root->key);
	Print(Root->left);   //����������� ����� ������ ���������
	Print(Root->right);  //����������� ����� ������� ���������
}

int main(int argc, char* argv[])
{
	system("chcp 1251");
	system("cls");

	Node* tree = NULL;
	int* x;
	int n;
	printf("������� ���-�� ��������� ������: ");
	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	printf("��������� ������: ");
	for (size_t i = 0; i < n; i++)
	{
		x[i] = rand() % 100;
		printf("%d ", x[i]);
		InsertR(&tree, x[i]);
	}
	printf("\n");
	printf("������ ����� ������: ");
	Print(tree);
	Balansed(&tree);
	printf("\n���������������� ������:");
	Watch(tree, 0, 0, 80);
	printf("\n");
	printf("\n");
	printf("\n");

	return 0;
}