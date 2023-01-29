#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *link;
}Node,*Nodeprt;
int main(){
	int n;
	scanf("%d",&n);//有n个船员； 
	Nodeprt p,first,q;
	first=p=(Nodeprt)malloc(sizeof(Node));
	p=first;
	first->num=1;//第一个船员的编号
	for(int i=2;i<=n;i++){
		p->link=(Nodeprt)malloc(sizeof(Node));
		p=p->link;
		p->num=i;
	} //创建链表；
	p->link=first;
	p=first;
	while(p!=p->link){
		
		for(int i=1;i<=12;i++){
			q=p;//删除点的前指针 
			p=p->link;
		}//p指向删除点 
		 q->link=p->link;
		 free(p);
		 p=q->link;
	} 
	printf("%d\n",p->num);
	
	return 0;
}
