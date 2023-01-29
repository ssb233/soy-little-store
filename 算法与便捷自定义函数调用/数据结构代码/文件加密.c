#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[200];
int  count[100];
char new_s[200];
char password[200];
typedef struct node {
	char ch;
	struct node* link;
} Node, *Nodeprt;
Nodeprt first, p, q;
void deleteNode(Nodeprt list, Nodeprt p) {
	if (p == list) { //ɾ���׽��
		list = p->link;
	} else {
		Nodeprt q = (Nodeprt)malloc(sizeof(Node));
		q = p->link;
		p->link = q->link;
		free(q);
	}
}
void createList_loop(int *cnt) {
	first = p = (Nodeprt)malloc(sizeof(Node));
	first->ch = new_s[0];
	p = first;
	for (int i = 1; i < *cnt; i++) {
		p->link = (Nodeprt)malloc(sizeof(Node));
		p = p->link;
		p->ch = new_s[i];
	}
	q = p; //ɾ����ǰ��㣻
	p->link = first; //����ѭ������
}
void create_password() {
	p = first;
	char scr = first->ch; //����ԭ�ַ���
	while (p != p->link) {
		q->link = p->link;
		free(p);
		for (int i = 1; i <= (int)scr; i++) {
			q = p;
			p = p->link;
		}
		password[scr - 32] = p->ch;
		scr = p->ch; //�µĽ���ַ���
	}
	password[scr - 32] = p->ch; //���һ���ַ���
}
void encodeFILE(char password[], char *src, char *dest) {
	FILE*in, *out;

	in = fopen(src, "r");
	out = fopen(dest, "w");
	if (in == NULL) {
		printf("Can't open the file: %s\n", src);
		return;
	}
	if (out == NULL) {
		printf("Can't open the file: %s\n", dest);
		return;
	}
	char ch, pass;
	while ((ch = fgetc(in)) != NULL) {
		if (32 <= ch && ch <= 126) //�����л��з���
			pass = password[ch - 32];
		else {
			pass = ch;
		}
		fputc(pass, out);
	}
	fclose(in);
	fclose(out);
}

int main() {
	gets(s);
	int cnt = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (count[s[i] - 32] == 0) {
			new_s[cnt++] = s[i];
			count[s[i] - 32]++;
		}
	}
	for (int i = 0; i < 95; i++) {
		if (count[i] == 0)new_s[cnt++] = (char)(i + 32);
	}//�±�new_s,����cnt��
	//��ȡ���ӳ���Կ

	createList_loop(&cnt);//����ѭ������
	create_password();//����ת���ɹ�
	//���ﲻ��ת�����Լ������ļ��� 
	encodeFILE(password,"in.txt", "in_crpyt.txt")//�������ļ�
	return 0;
}
