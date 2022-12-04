#include<stdio.h>
void f(){
	char ch;
	if((ch=getchar())==EOF)return;
	f();
	putchar(ch);
}
int main(){
	f();
	return 0;
}
