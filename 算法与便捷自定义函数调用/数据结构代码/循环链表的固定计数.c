#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *link;
}Node,*Nodeprt;
int main(){
	int n;
	scanf("%d",&n);//��n����Ա�� 
	Nodeprt p,first,q;
	first=p=(Nodeprt)malloc(sizeof(Node));
	p=first;
	first->num=1;//��һ����Ա�ı��
	for(int i=2;i<=n;i++){
		p->link=(Nodeprt)malloc(sizeof(Node));
		p=p->link;
		p->num=i;
	} //��������
	p->link=first;
	p=first;
	while(p!=p->link){
		
		for(int i=1;i<=12;i++){
			q=p;//ɾ�����ǰָ�� 
			p=p->link;
		}//pָ��ɾ���� 
		 q->link=p->link;
		 free(p);
		 p=q->link;
	} 
	printf("%d\n",p->num);
	
	return 0;
}
