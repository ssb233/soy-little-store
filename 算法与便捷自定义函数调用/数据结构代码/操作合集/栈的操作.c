#include<stdio.h>
#define MAXSIZE 1000
typedef struct elem{
	
}ElemType;
ElemType STACK[MAXSIZE];
int top = -1;
//初始化堆栈 
void initStack(){
	top=-1;
}
//测试堆栈是否为空
int isEmpty(){
	return top==-1;//栈空返回1，否则返回0 
} 
//测试栈是否已满
int isFull(){
	return top==MAXSIZE-1;
} 
//进栈
void Error(char s[]){
	printf("%s\n",s);
	exit(-1);
}
void push(ElemType s[],ElemType item){
	if(isFull()){
		Error("Full Stack!");
	}
	else{
		s[++top]=item;//先++再赋值 
	}
} 
//出栈
ElemType pop(ElemType s[]){
	if(isEmpty()){
		Error("Empty Stack!");
	}
	else{
		return s[top--];//弹出s[top],再-- 
	}
} 

//多栈共享连续空间：进栈
void push(ElemType s[],int i,ElemType item){
	if(top1==top2-1){
		Error("Full Stack!");//栈满 
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
//出栈 
ElemType pop(ElemType s[],int i){
	if(i==1){//操作第一个栈 
		if(top1==-1)Error("Empty Stack!");
		else return s[top1--];
	}
	else if(i==2){//操作第二个栈 
		if(top2==MAXSIZE)Error("Empty Stack!");
		else return s[top2--];
	}
}
//
//链栈的进栈出栈都在链表开头，top指针指向栈顶
typedef struct node{
	ElemType data;
	struct node*link;
}Node,*Nodeprt; 
Nodeprt top;//头指针，指向栈顶
//初始化
void initStack(){
	top=NULL;
} 
//测试是否空栈
int isEmpty(){
	return top==NULL;
} 
//进栈
void push(ElemType item){//入栈不用判断栈满 
	Nodeprt p;
	if((p=(Nodeprt)malloc(sizeof(Node)))==NULL)
		Error("No memory!");
	else{
		p->data=item;
		p->link=top;//插入在链表最前面 
		top=p;
	}
} 
//出栈
ElemType pop(){//出栈要判断栈空 
	Nodeprt p;ElemType item;
	if(isEmpty()){
		Error("Empty Stack!");
	}
	else{
		p=top;
		item=top->data;
		top=top->link;
		free(p);
		return item;//返回出栈元素就行 
	}
} 
