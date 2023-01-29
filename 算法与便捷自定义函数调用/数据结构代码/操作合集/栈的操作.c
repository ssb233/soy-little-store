#include<stdio.h>
#define MAXSIZE 1000
typedef struct elem{
	
}ElemType;
ElemType STACK[MAXSIZE];
int top = -1;
//��ʼ����ջ 
void initStack(){
	top=-1;
}
//���Զ�ջ�Ƿ�Ϊ��
int isEmpty(){
	return top==-1;//ջ�շ���1�����򷵻�0 
} 
//����ջ�Ƿ�����
int isFull(){
	return top==MAXSIZE-1;
} 
//��ջ
void Error(char s[]){
	printf("%s\n",s);
	exit(-1);
}
void push(ElemType s[],ElemType item){
	if(isFull()){
		Error("Full Stack!");
	}
	else{
		s[++top]=item;//��++�ٸ�ֵ 
	}
} 
//��ջ
ElemType pop(ElemType s[]){
	if(isEmpty()){
		Error("Empty Stack!");
	}
	else{
		return s[top--];//����s[top],��-- 
	}
} 

//��ջ���������ռ䣺��ջ
void push(ElemType s[],int i,ElemType item){
	if(top1==top2-1){
		Error("Full Stack!");//ջ�� 
	}
	else{
		if(i==1){
			STACK[++top1]=item;
		}
		else if(i==2){
			STACK[--top2]=item;
		}
		return;
	} 
} 
//��ջ 
ElemType pop(ElemType s[],int i){
	if(i==1){//������һ��ջ 
		if(top1==-1)Error("Empty Stack!");
		else return s[top1--];
	}
	else if(i==2){//�����ڶ���ջ 
		if(top2==MAXSIZE)Error("Empty Stack!");
		else return s[top2--];
	}
}
//
//��ջ�Ľ�ջ��ջ��������ͷ��topָ��ָ��ջ��
typedef struct node{
	ElemType data;
	struct node*link;
}Node,*Nodeprt; 
Nodeprt top;//ͷָ�룬ָ��ջ��
//��ʼ��
void initStack(){
	top=NULL;
} 
//�����Ƿ��ջ
int isEmpty(){
	return top==NULL;
} 
//��ջ
void push(ElemType item){//��ջ�����ж�ջ�� 
	Nodeprt p;
	if((p=(Nodeprt)malloc(sizeof(Node)))==NULL)
		Error("No memory!");
	else{
		p->data=item;
		p->link=top;//������������ǰ�� 
		top=p;
	}
} 
//��ջ
ElemType pop(){//��ջҪ�ж�ջ�� 
	Nodeprt p;ElemType item;
	if(isEmpty()){
		Error("Empty Stack!");
	}
	else{
		p=top;
		item=top->data;
		top=top->link;
		free(p);
		return item;//���س�ջԪ�ؾ��� 
	}
} 
