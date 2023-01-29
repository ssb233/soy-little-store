#include<stdio.h>
#include<stdlib.h>
typedef int  ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //���ӣ��Һ��ӣ�
} BTNode, *BTNodeprt;

//�ݹ��ʱ��Ϳռ�����̫����Ҫ�����ǵݹ���� 
void preorder(BTNodeprt t) {//ǰ�����
	if (t != NULL) {
		//VISIT(t);//����t��㣻
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(BTNodeprt t) { //�������
	if (t != NULL) {
		inorder(t->lchild);
		//VISIT(t);
		inorder(t->rchild);
	}
}

void postorder(BTNodeprt t) { //�������
	if (t != NULL) {
		postorder(t->lchild);
		postorder(t->rchild);
		//VISIT(t);
	}
}

//�����������㷨��Ӧ��
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

void destoryTree(BTNodeprt p) {//ɾ����������
	if (p != NULL) {
		destoryTree(p->lchild);//��ɾ���ӣ���ɾ��
		destoryTree(p->rchild);
		free(p);
		p = NULL;
	}
}

int max(int x, int y) {//���������� 
	if (x > y) return x; else return y;
	}
int heightTree(BTNodeprt p) {
	if (p == NULL)
		return 0;
	else
		return 1 + max(heightTree(p->lchild),
		               heightTree(p->rchild));
}

