#include<stdio.h>
#include<stdlib.h>
#define M 105
typedef struct elem {

} ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //���ӣ��Һ��ӣ�
} BTNode, *BTNodeprt;

void inorder(BTNodeprt t) {//����ǵݹ����
	BTNodeprt stack[M], p = t;
	int top = -1;
	if (t != NULL)
		do {
			for (; p != NULL; p = p->lchild) {//�Ӷ��ҵ����������������ջ
				stack[++top] = p;
			}
			p = stack[top--];//�˻�һ��ָ��ȥ���ʣ�Ȼ����ʸ�ָ�������
			VISIT(p);//���ʽڵ㣻
			p = p->rchild;
		} while (p != NULL || top != -1);
}

void postorder(BTNodeprt t) {//��������ķǵݹ�
	BTNodeprt stack1[M], p = t;//�洢ָ��ջ
	int stack2[M], top = -1, flag;//����ܷ����ջ��
	if (t != NULL)
		do {
			while (p != NULL) {//����һ��top
				stack1[++top] = p;//��ǰpָ��ĵ�ַ��ջ
				stack2[top] = 0; //��ǰpָ���㲻�ɷ��ʱ�־��ջ
				p = p->lchild;//�����ҵ���������������ջ
			}
			p = stack1[top--];
			flag = stack2[top]; //�˳�һ��Ԫ��,ȥ�ж��ܷ����
			if (flag == 0) {//���ܷ��� �����ǿ�����û�з��ʹ���ֻ���ȷ����Ҳ���ܷ��ʸ� 
				stack1[++top] = p; //������ջp 
				stack2[top] = 1; // ����Ǹ�Ϊ�ɷ��� 
				p = p->rchild;
			} else {
				VISIT(p);
				p = NULL; //��Ϊ�Ǻ������Ա�����p���Ϊ���Ķ�������ɣ�
			}
		} while (p != NULL || top != -1);
}


//ǰ�к������������DFS�����������
//����α�����������BFS�����������
#define NodeNum 100
void layerorder(BTNodeprt t) {//����α���
	BTNodeprt queue[NodeNum], p;//���У����ϵ��£������ұ�����
	int front, rear;
	if (t != NULL) {//���ǿ�
		queue[0] = t;
		front = -1;
		rear = 0;
		while (front < rear) { /* ���в���*/
			p = queue[++front];//��ͷ����һ��Ԫ��
			VISIT(p); /* ??p??? */
			if (p->lchild != NULL) /* ??????*/
				queue[++rear] = p->lchild;
			if (p->rchild != NULL) /* ??????*/
				queue[++rear] = p->rchild;
		}
	}
}

#define MaxSize 100
void inorder(Datatype bt[], int n) {//��������˳��洢��������� 
	int stack[MaxSize], i, top = -1;
	i = 0;
	if (n >= 0) {
		do {
			while (i < n) {
				stack[++top] = i; /* bt[i]��λ��i��ջ */
				i = i * 2 + 1; /* �ҵ�i������λ��*/
			}
			i = STACK[top--]; /* ��ջ*/
			VISIT(bt[i]); /* ���ʽ��bt[i] */
			i = i * 2 + 2; /* �ҵ�i���Һ���λ�� */
		} while (!(i > n - 1 && top == -1));
	}
}
