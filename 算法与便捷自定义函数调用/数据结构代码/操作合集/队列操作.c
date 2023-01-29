#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1005
//一般使用过程中，顺序队列容易溢出，所以一般采用循环队列
typedef struct Element{
	int num;
}QElemType;
QElemType Queue[MAXSIZE-1];//采用一般类型定义 
int front,rear,count;
void initQueue(){//初始化 //循环队列 
	front=0;//队头位置；删除点 
	rear=MAXSIZE-1;//队尾位置插入位置 
	count=0;//队列元素个数 
} 
int isEmpty(){
	return count==0;
}
int isFull(){
	return count==MAXSIZE;
}
void enQueue(QElemType queue[],QElemType item){
	if(isFull()){
		printf("Full queue!");
	}
	else{
		rear=(rear+1)%MAXSIZE;//取模循环
		queue[rear]=item;
		count++; 
	}
}
QElemType deQueue(QElemType queue[]){
	QElemType e;
	if(isEmpty()){
		printf("Empty queue!"); 
	}
	else{
		e=queue[front];
		count--;
		front=(front+1)%MAXSIZE;
		return e;
	}
}


//////////////////////链式队列
//front指向头结点，rear指向末结点
//链式队列不存在满队的情况； 
typedef struct node{
	QElemType data;
	struct node *link;
}QNode,*QNodeprt;
int *front,*rear; 
void initQueue(){
	front=NULL;//队列为空的标志； 
	rear=NULL;
} 
int isEmpty(){
	return front == NULL;
}
void enQueue(QElemType item){
	QNodeprt p;
	if((p=(QNodeprt)malloc(sizeof(QNode)))==NULL)
	printf("No memory!");
	p->data=item;
	p->link=NULL;
	if(front==NULL)front=p;
	else {
		rear->link=p;
		rear=p;
	}
}
QElemType deQueue(){
	QNodeprt p;
	QElemType item;
	if(isEmpty())printf("Empty queue!");
	else{
		p=front;
		front=p->link;
		item=p->data;
		free(p);
		return item;
	}
}
void destroyQueue(){
	while(front!=NULL){
		rear=front->link;
		free(front);
		front=rear;
	}
}
