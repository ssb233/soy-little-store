#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * llink;//��ǰָ�� 
	struct node * rlink;//�ң���ָ�� 
}DNode,*DNodeprt;

int read();

DNodeprt createDNode(int n){//����˫��ѭ������ 
	DNodeprt list=NULL,p,q;
	p=(DNodeprt)malloc(sizeof(DNode));
	for(int i=1;i<n;i++){
		q=(DNodeprt)malloc(sizeof(DNode));
		q->data=read();
		q->rlink=NULL;
		if(list==NULL){
			list=p=q;
		}
		else{
			p->rlink=q;
			q->llink=p;
		}
		p=q;
	}
	p->rlink=list;//�Ƿ�ѭ���Ϳ������һ�� 
	list->llink=p;
	return list;
}


