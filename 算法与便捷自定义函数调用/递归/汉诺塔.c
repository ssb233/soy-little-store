#include<stdio.h>
//将n个盘子从a通过b移动到c上面 
//从上到下依次记作12345......n; 
void hanoi(int n, char from, char via, char to);
void move(int i, char from, char to);
//把第i个盘子从from移到to去； 
int main() {
	int num;
	char a , b , c;
    scanf("%d", &num);
    scanf(" %c %c %c",&a,&b,&c); //注意这里%c前面有没有空格来是否跳空格 
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
