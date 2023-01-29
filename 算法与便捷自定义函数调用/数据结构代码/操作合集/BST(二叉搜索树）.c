#include<stdio.h>
#include<stdlib.h>
typedef int  ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //���ӣ��Һ��ӣ�
} BTNode, *BTNodeprt;

//Binary search tree
//���������BST////////�ݹ�ʵ�� 
BTNodeprt insertBST(BTNodeprt p,ElemType item){//�ݹ���롣���ز����ַ�� 
	if(p==NULL){//���գ���Ϊ����� 
		p=(BTNodeprt)malloc(sizeof(BTNode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data){//С�ڷ������ 
		p->lchild=insertBST(p->lchild,item);//�����������Ҳ���㣻 
	}
	else if(item>p->data){//���ڷ����Ҳ� 
		p->rchild=insertBST(p->rchild,item);//�������� 
	}
	else{
		//do something,//��������ڸ�Ԫ�أ� 
	} 
	return p;//���ز���λ�� 
} 

int main(){
	int i,item;
	BTNodeprt root=NULL;
	for(int i=0;i<10;i++){
		scanf("%d",&item);
		root=insertBST(root,item);//��������Ϊroot�Ķ�������� 
	}
}

//�ǵݹ��BST
BTNodeprt root=NULL;
void insertBST(ElemType item){
	BTNodeprt p,q;
	q=(BTNodeprt)malloc(sizeof(BTNode));
	q->data=item;
	q->lchild=p->rchild=NULL;//Ԫ�����뵽q���棬 
	if(root==NULL){
		root=q;
	}
	else{
		p=root;//�Ӹ���ʼ�Ƚ� 
		while(1){
			//�Ƚ���ֵ��С��С�����󣬴������
			if(item<p->data){//�춨������Ĳ����� 
				if(p->lchild==NULL){
					p->lchild=q;//����ָ��q
					break;
				}
				else p=p->lchild;
			}
			else if(item>p->data){
				if(p->rchild==NULL){
					p->rchild=q;//�����ǿգ����Բ���q
					break; 
				}
				else p=p->rchild;
			}
			else{//��� 
				//do something
			}
		}
	
	}
} 
//����������Ĳ��ң��ǵݹ鷽���� 
BTNodeprt searchBST(BTNodeprt t,ElemType key){
	BTNodeprt p=t;
	while(p!=NULL){//���ǿ� 
		if(key==p->data){
			return p;//�ҵ��� 
		}
		else if(key<p->data){
			p=p->lchild;//�������������� 
		}
		else if(key>p->data){
			p=p->rchild;//�������������� 
		}
	}
	return NULL;//����ʧ�ܷ���NULL 
}

//����������Ĳ��ң��ݹ飩
BTNodeprt searchBST(BTNodeprt t,ElemType key){
	if(t!=NULL){//���ǿ� 
		if(key==t->data){
			return t;
		}
		else if(key<t->data){
			return searchBST(t->lchild,key);
		}
		else if(key>t->data){
			return searchBST(t->rchild,key);
		}
	}
	else return NULL;//���ա�����ʧ�ܣ� 
} 

//�����������ɾ����㣻 
//ɾ�������ã������Ǿ��У����ҵ�ʱ��ֱ�������� 
void deleteBST(BTNodeprt t,ElemType key){//������Ŀ��ɾ�� 
	if(t!=NULL){
		BTNodeprt p=searchBST(t,key);//�ҵ�����λ�ã�
		if(p->rchild==NULL&&p->lchild==NULL){//��Ҷ��㡣ֱ��ɾ�� 
			
		}
		else if(p->rchild==NULL){//�������������������ĸ�ȡ��ɾ���㣻 
			
		}
		else if(p->lchild==NULL){//�������������������ĸ�ȡ��ɾ���㣻 
			
		}
		else {//�������������ڣ�������������ȡ����������������С��ȡ�� 
			
		}
	}
}
