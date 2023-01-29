#include<stdio.h>
#include<stdlib.h>
#define M 105
typedef struct elem {

} ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //左孩子，右孩子；
} BTNode, *BTNodeprt;

void inorder(BTNodeprt t) {//中序非递归遍历
	BTNodeprt stack[M], p = t;
	int top = -1;
	if (t != NULL)
		do {
			for (; p != NULL; p = p->lchild) {//从顶找到左子最深处；依次入栈
				stack[++top] = p;
			}
			p = stack[top--];//退回一个指针去访问，然后访问该指针的右子
			VISIT(p);//访问节点；
			p = p->rchild;
		} while (p != NULL || top != -1);
}

void postorder(BTNodeprt t) {//后序遍历的非递归
	BTNodeprt stack1[M], p = t;//存储指针栈
	int stack2[M], top = -1, flag;//标记能否访问栈；
	if (t != NULL)
		do {
			while (p != NULL) {//共用一个top
				stack1[++top] = p;//当前p指向的地址进栈
				stack2[top] = 0; //当前p指向结点不可访问标志进栈
				p = p->lchild;//依次找到左侧最深处并依次入栈
			}
			p = stack1[top--];
			flag = stack2[top]; //退出一个元素,去判断能否访问
			if (flag == 0) {//不能访问 ，就是看根有没有访问过，只有先访问右侧才能访问根 
				stack1[++top] = p; //重新入栈p 
				stack2[top] = 1; // 将标记改为可访问 
				p = p->rchild;
			} else {
				VISIT(p);
				p = NULL; //因为是后序，所以表明以p结点为根的都访问完成；
			}
		} while (p != NULL || top != -1);
}


//前中后序遍历本质是DFS深度优先搜索
//按层次遍历本质上是BFS广度优先搜索
#define NodeNum 100
void layerorder(BTNodeprt t) {//按层次遍历
	BTNodeprt queue[NodeNum], p;//队列，从上到下，从左到右遍历树
	int front, rear;
	if (t != NULL) {//树非空
		queue[0] = t;
		front = -1;
		rear = 0;
		while (front < rear) { /* 队列不空*/
			p = queue[++front];//队头跳出一个元素
			VISIT(p); /* ??p??? */
			if (p->lchild != NULL) /* ??????*/
				queue[++rear] = p->lchild;
			if (p->rchild != NULL) /* ??????*/
				queue[++rear] = p->rchild;
		}
	}
}

#define MaxSize 100
void inorder(Datatype bt[], int n) {//二叉树的顺序存储和中序遍历 
	int stack[MaxSize], i, top = -1;
	i = 0;
	if (n >= 0) {
		do {
			while (i < n) {
				stack[++top] = i; /* bt[i]的位置i进栈 */
				i = i * 2 + 1; /* 找到i的左孩子位置*/
			}
			i = STACK[top--]; /* 退栈*/
			VISIT(bt[i]); /* 访问结点bt[i] */
			i = i * 2 + 2; /* 找到i的右孩子位置 */
		} while (!(i > n - 1 && top == -1));
	}
}
