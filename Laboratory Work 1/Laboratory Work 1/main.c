#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//��������� ������
struct list {
	int data;
	struct list* next; //��������� ����������������� ������
};

void list_input(FILE* _in, struct list** lst);
void list_clear(struct list* lst);
void list_print(FILE* _out, const struct list* p);
void list_unicue(struct list* lst);

int main(void) {
	struct list* lst = NULL;

	FILE* fp = fopen("file.txt", "r");
	list_input(fp, &lst);
	fclose(fp);

	list_unicue(lst);
	list_print(stdout, lst);
	list_clear(lst);
	return 0;
}

//���� � ������
void list_input(FILE* _in, struct list** lst) {
	int  n;
	struct list* p, * t = NULL;
	*lst = NULL;

	while (!feof(_in)) { //���� ���� �� ����������
		fscanf(_in, "%d", &n); //���������� ����� �� ����� � n
		p = (struct list*)malloc(sizeof(struct list));
		if (p != NULL) { 
			p->data = n;
			p->next = NULL;

			if (t == NULL)
				*lst = t = p;
			else {
				t->next = p;
				t = p;
			}
		}
		else
			break;
	}
}

//�������� ����� ������
void list_clear(struct list* lst) {
	struct list* t;
	while (lst != NULL) {
		t = lst;
		lst = lst->next;
		free(t);
	}
}

//������
void list_print(FILE* _out, const struct list* p) {
	for (; p != NULL; p = p->next)
		fprintf(_out, "%d ", p->data);
	fputc('\n', _out);
}

//�������� �� ������������� �����
void list_unicue(struct list* lst) {
	struct list* t, * i, * j, * p = lst;

	while (p != NULL) {
		i = p->next;
		while ((i != NULL) && (i->data == p->data))
			i = i->next;

		if (i != p->next) {
			j = p->next;
			while (j != i) {
				t = j;
				j = j->next;
				free(t);
			}
			p = p->next = i;
			continue;
		}
		p = p->next;
	}
}