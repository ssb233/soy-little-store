#define MAXD 3 //���Ķ� 
struct node {
	DataType data;
	struct node *next[MAXD];
};
typedef struct node TNode;
typedef struct node *TNodeprt;



void DFStree(TNodeprt t) {//����һ���� //�ݹ� 
	int i;
	if (t != NULL) {
		VISIT(t); /* ??t???? */
		for (i = 0; i < MAXD; i++)
			if (t->next[i] != NULL)
				DFStree(t->next[i]);
	}
}


void BFStree(TNodeprt t) {//������ͨ�� 
	TNodeprt p;
	int i;
	if (t != NULL) {
		enQueue(t);
		while (!isEmpty()) { //?????
			p = deQueue();
			VISIT(p);
			for (i = 0; i < MAXD; i++) //???? p??????
				if (p->next[i] != NULL) enQueue(p->next[i]);
		}
	}
}
