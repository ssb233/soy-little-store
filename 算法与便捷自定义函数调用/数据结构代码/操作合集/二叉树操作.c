#include<stdio.h>
#include<stdlib.h>
typedef int  ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //左孩子，右孩子；
} BTNode, *BTNodeprt;

//递归的时间和空间消耗太大，需要开创非递归设计 
void preorder(BTNodeprt t) {//前序遍历
	if (t != NULL) {
		//VISIT(t);//访问t结点；
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(BTNodeprt t) { //中序遍历
	if (t != NULL) {
		inorder(t->lchild);
		//VISIT(t);
		inorder(t->rchild);
	}
}

void postorder(BTNodeprt t) { //后序遍历
	if (t != NULL) {
		postorder(t->lchild);
		postorder(t->rchild);
		//VISIT(t);
	}
}

//二叉树遍历算法的应用
BTNodeprt copyTree(BTNodeprt src) {
	BTNodeprt obj;
	if (src == NULL)
		obj = NULL;
	else {
		obj = (BTNodeprt)malloc(sizeof(BTNode));
		obj->data = src->data;
		obj->lchild = copyTree(src->lchild);
		obj->rchild = copyTree(src->rchild);
	}
	return obj;
}

void destoryTree(BTNodeprt p) {//删除二叉树；
	if (p != NULL) {
		destoryTree(p->lchild);//先删除子，再删根
		destoryTree(p->rchild);
		free(p);
		p = NULL;
	}
}

int max(int x, int y) {//求解树的深度 
	if (x > y) return x; else return y;
	}
int heightTree(BTNodeprt p) {
	if (p == NULL)
		return 0;
	else
		return 1 + max(heightTree(p->lchild),
		               heightTree(p->rchild));
}

