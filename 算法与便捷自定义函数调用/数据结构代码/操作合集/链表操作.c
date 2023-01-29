#include<stdio.h>
#include<stdlib.h>

typedef struct element {
	int num;

} ElemType; //����Ԫ�����ͣ�

typedef struct node {
	ElemType data;
	struct node *link;//������ָ�룻

} Node, *Nodeprt; //���������������ָ�����ͣ�


Nodeprt createList(int n);//����n����������
int getLength(Nodeprt list);//��������ȣ�
void destroyList(Nodeprt list);//����һ����
void printList(Nodeprt list);//���һ����
Nodeprt insertFirst(Nodeprt list, ElemType elem);//����ͷ����һ��Ԫ�أ�
Nodeprt insertList_rank(Nodeprt list, ElemType elem);
//�������������Ӧ��㣻
void insertNode1(Nodeprt list, int n, ElemType elem);
//��n�����֮�����һ�����
void insertList(Nodeprt list, Nodeprt p, ElemType elem);
//����ĳһ����������ĳ��Ԫ�صĽ�㣻
Nodeprt searchNode(Nodeprt list, ElemType elem); //���������ĳ��Ԫ�أ����ص�ַ��
Nodeprt deleteNode(Nodeprt list, Nodeprt p); //��������ɾ��ĳһԪ�غͽ��p��
ElemType read();
void buildlist(int n);//����ѭ������ 


int main() {
	//p=p->link;ָ����һ����㣻
	/*q->link=p->link;
	p->link=q;
	��p���������q*/
	/*q=p->link;
	p->link=q->link;
	free(q);
	ɾ��p����һ�����*/
	return 0;
}

Nodeprt createList(int n) {
	Nodeprt p, q, list = NULL;
	p = (Nodeprt)malloc(sizeof(Node)); //Node�ṹ��С��ָ��
	for (int i = 0; i < n; i++) {
		q = (Nodeprt)malloc(sizeof(Node));
		q->data = read(); //��ȡһ��Ԫ�أ�read�Լ�д
		//������Ŀ�����뷽���Լ�д���ʵ����뺯����
		q->link = NULL;

		if (list == NULL) {
			list = p = q;
		} else {
			p->link = q;
		}
		p = q; //ʱ�临�Ӷ�Ϊn
	}
	return list;
}

int getLength(Nodeprt list) {
	Nodeprt p;//pΪ�������н���ָ�룻
	int n = 0; //���ȳ�ֵ��
	for (p = list; p != NULL; p->link = p) {
		n++;
	}
	return n;
}

Nodeprt insertFirst(Nodeprt list, ElemType elem) {
	Nodeprt p = (Nodeprt)malloc(sizeof(Node));
	p->data = elem; //�����µ����ݽ�㵽��ͷ��
	p->link = list;
	return p;//p���µ���㣻
}

void insertNode(Nodeprt list, Nodeprt p, ElemType elem) {//p֮����� 
	Nodeprt q = (Nodeprt)malloc(sizeof(Node));
	q->data = elem;
	q->link = p->link;
	p->link = q;
}

void insertNode1(Nodeprt list, int n, ElemType elem) {
	//�ڵ�n�����֮�����
	Nodeprt p = list, q;
	for (int i = 1; i <= n - 1; i++) {
		if (p->link == NULL) {
			break;
		}
		p = p->link; //n-1�κ�p��ʾָ��n��ָ��;
		//list������һ�����;
	}
	q = (Nodeprt)malloc(sizeof(Node));
	q->data = elem;
	q->link = p->link; //��Ԫ��ָ��
	p->link = q;
}

Nodeprt insertList_rank(Nodeprt list, ElemType elem) {
	Nodeprt p, q, r;
	r = (Nodeprt)malloc(sizeof(Node));
	r->data = elem;
	r->link = NULL; //���������ݵ�
	if (list == NULL) { //�ձ�
		return r;
	}
	for (p = list; p != NULL && elem > p->data; q = p, p = p->link); //�ҵ������
	// Ӧ��data���������� q���ǲ����ָ��
	//����ıȽϴ�С������ǵ���Ԫ�ؿ���ֱ�ӱȽϣ�
	//����ǽṹ��,�Ƚ�Ԫ�ػ���//��Ҫ����д�ȽϺ����� 
	//�������q��pǰ 
	if (p == list) { //û��q����ͷָ��ǰ���� 
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
	if(p==list){//ɾ���׽�� 
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
	p->link=list;//ѭ�������ѽ�β�Ϳ�ͷ���� 
}
