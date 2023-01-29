#include<stdio.h>
#include<stdlib.h>

typedef struct element {
	int num;

} ElemType; //创建元素类型；

typedef struct node {
	ElemType data;
	struct node *link;//自引用指针；

} Node, *Nodeprt; //创建链表和自引用指针类型；


Nodeprt createList(int n);//创建n个结点的链表；
int getLength(Nodeprt list);//获得链表长度；
void destroyList(Nodeprt list);//销毁一个表；
void printList(Nodeprt list);//输出一个表；
Nodeprt insertFirst(Nodeprt list, ElemType elem);//链表开头插入一个元素；
Nodeprt insertList_rank(Nodeprt list, ElemType elem);
//有序链表插入相应结点；
void insertNode1(Nodeprt list, int n, ElemType elem);
//第n个结点之后插入一个结点
void insertList(Nodeprt list, Nodeprt p, ElemType elem);
//链表某一结点后面插入带某个元素的结点；
Nodeprt searchNode(Nodeprt list, ElemType elem); //链表里查找某个元素，返回地址；
Nodeprt deleteNode(Nodeprt list, Nodeprt p); //链表里面删除某一元素和结点p；
ElemType read();
void buildlist(int n);//构建循环链表； 


int main() {
	//p=p->link;指向下一个结点；
	/*q->link=p->link;
	p->link=q;
	在p后面插入结点q*/
	/*q=p->link;
	p->link=q->link;
	free(q);
	删除p的下一个结点*/
	return 0;
}

Nodeprt createList(int n) {
	Nodeprt p, q, list = NULL;
	p = (Nodeprt)malloc(sizeof(Node)); //Node结构大小的指针
	for (int i = 0; i < n; i++) {
		q = (Nodeprt)malloc(sizeof(Node));
		q->data = read(); //读取一个元素；read自己写
		//根据题目的输入方法自己写合适的输入函数；
		q->link = NULL;

		if (list == NULL) {
			list = p = q;
		} else {
			p->link = q;
		}
		p = q; //时间复杂度为n
	}
	return list;
}

int getLength(Nodeprt list) {
	Nodeprt p;//p为遍历所有结点的指针；
	int n = 0; //长度初值；
	for (p = list; p != NULL; p->link = p) {
		n++;
	}
	return n;
}

Nodeprt insertFirst(Nodeprt list, ElemType elem) {
	Nodeprt p = (Nodeprt)malloc(sizeof(Node));
	p->data = elem; //读入新的数据结点到开头；
	p->link = list;
	return p;//p是新的起点；
}

void insertNode(Nodeprt list, Nodeprt p, ElemType elem) {//p之后插入 
	Nodeprt q = (Nodeprt)malloc(sizeof(Node));
	q->data = elem;
	q->link = p->link;
	p->link = q;
}

void insertNode1(Nodeprt list, int n, ElemType elem) {
	//在第n个结点之后插入
	Nodeprt p = list, q;
	for (int i = 1; i <= n - 1; i++) {
		if (p->link == NULL) {
			break;
		}
		p = p->link; //n-1次后，p表示指向n的指针;
		//list算作第一个结点;
	}
	q = (Nodeprt)malloc(sizeof(Node));
	q->data = elem;
	q->link = p->link; //新元素指向
	p->link = q;
}

Nodeprt insertList_rank(Nodeprt list, ElemType elem) {
	Nodeprt p, q, r;
	r = (Nodeprt)malloc(sizeof(Node));
	r->data = elem;
	r->link = NULL; //创建新数据点
	if (list == NULL) { //空表
		return r;
	}
	for (p = list; p != NULL && elem > p->data; q = p, p = p->link); //找到插入点
	// 应该data是升序排列 q就是插入点指针
	//这里的比较大小，如果是单个元素可以直接比较，
	//如果是结构体,比较元素或者//需要另外写比较函数； 
	//插入点在q后，p前 
	if (p == list) { //没有q，在头指针前插入 
		r->link=p;
		return r;
	}
	else{
		q->link=r;
		r->link=p;
	}
	return list;
}

Nodeprt deleteNode(Nodeprt list, Nodeprt p){
	if(p==list){//删除首结点 
		list=p->link;
	}
	else{
		Nodeprt q=(Nodeprt)malloc(sizeof(Node));
		q=p->link;
		p->link=q->link;
		free(q); 
	}
}

void buildlist(int n){
	
	Nodeprt p,list;
	for(int i=0;i<n-1;i++){
		Nodeprt r=(Nodeprt)malloc(sizeof(Node));
		r->data=read();
		if(list==NULL){
			list=p=r;
		}
		else{
			p->link=r;
			p=p->link;
		}
	}
	p->link=list;//循环链表，把结尾和开头接上 
}
