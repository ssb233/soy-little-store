#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1005
//һ��ʹ�ù����У�˳������������������һ�����ѭ������
typedef struct Element{
	int num;
}QElemType;
QElemType Queue[MAXSIZE-1];//����һ�����Ͷ��� 
int front,rear,count;
void initQueue(){//��ʼ�� //ѭ������ 
	front=0;//��ͷλ�ã�ɾ���� 
	rear=MAXSIZE-1;//��βλ�ò���λ�� 
	count=0;//����Ԫ�ظ��� 
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
		rear=(rear+1)%MAXSIZE;//ȡģѭ��
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


//////////////////////��ʽ����
//frontָ��ͷ��㣬rearָ��ĩ���
//��ʽ���в��������ӵ������ 
typedef struct node{
	QElemType data;
	struct node *link;
}QNode,*QNodeprt;
int *front,*rear; 
void initQueue(){
	front=NULL;//����Ϊ�յı�־�� 
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
