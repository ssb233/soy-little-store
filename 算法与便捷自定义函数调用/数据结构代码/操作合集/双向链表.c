#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * llink;//左，前指针 
	struct node * rlink;//右，后指针 
}DNode,*DNodeprt;

int read();

DNodeprt createDNode(int n){//创建双向循环链表 
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
	p->rlink=list;//是否循环就看这最后一步 
	list->llink=p;
	return list;
}


