#include<stdio.h>
//��n�����Ӵ�aͨ��b�ƶ���c���� 
//���ϵ������μ���12345......n; 
void hanoi(int n, char from, char via, char to);
void move(int i, char from, char to);
//�ѵ�i�����Ӵ�from�Ƶ�toȥ�� 
int main() {
	int num;
	char a , b , c;
    scanf("%d", &num);
    scanf(" %c %c %c",&a,&b,&c); //ע������%cǰ����û�пո����Ƿ����ո� 
	hanoi(num, a, b, c);
	return 0;
}
void hanoi(int n, char from, char via, char to) {
	if (n == 1) {
		move(n, from, to);
		return;
	}
	hanoi(n - 1, from, to, via);
	move(n, from, to);
	hanoi(n - 1, via, from, to);
}
void move(int i, char from, char to) {
	printf("move %d from %c to %c\n", i, from, to);
}
