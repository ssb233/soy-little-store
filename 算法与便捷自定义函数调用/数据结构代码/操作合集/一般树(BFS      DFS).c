#define MAXD 3 //树的度 
struct node {
	DataType data;
	struct node *next[MAXD];
};
typedef struct node TNode;
typedef struct node *TNodeprt;



void DFStree(TNodeprt t) {//深搜一般树 //递归 
	int i;
	if (t != NULL) {
		VISIT(t); /* ??t???? */
		for (i = 0; i < MAXD; i++)
			if (t->next[i] != NULL)
				DFStree(t->next[i]);
	}
}


void BFStree(TNodeprt t) {//广搜普通树 
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
