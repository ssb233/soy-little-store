#include<stdio.h>
#include<stdlib.h>
typedef int  ElemType;
typedef struct node {
	ElemType data;
	struct node * lchild, *rchild; //左孩子，右孩子；
} BTNode, *BTNodeprt;

//Binary search tree
//二叉查找树BST////////递归实现 
BTNodeprt insertBST(BTNodeprt p,ElemType item){//递归插入。返回插入地址； 
	if(p==NULL){//树空，作为根结点 
		p=(BTNodeprt)malloc(sizeof(BTNode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data){//小于放在左侧 
		p->lchild=insertBST(p->lchild,item);//在左子树里找插入点； 
	}
	else if(item>p->data){//大于放在右侧 
		p->rchild=insertBST(p->rchild,item);//右子树找 
	}
	else{
		//do something,//树里面存在该元素； 
	} 
	return p;//返回插入位置 
} 

int main(){
	int i,item;
	BTNodeprt root=NULL;
	for(int i=0;i<10;i++){
		scanf("%d",&item);
		root=insertBST(root,item);//构造根结点为root的二叉查找树 
	}
}

//非递归的BST
BTNodeprt root=NULL;
void insertBST(ElemType item){
	BTNodeprt p,q;
	q=(BTNodeprt)malloc(sizeof(BTNode));
	q->data=item;
	q->lchild=p->rchild=NULL;//元素输入到q里面， 
	if(root==NULL){
		root=q;
	}
	else{
		p=root;//从根开始比较 
		while(1){
			//比较数值大小，小的向左，大的向右
			if(item<p->data){//奠定了往左的操作； 
				if(p->lchild==NULL){
					p->lchild=q;//左子指向q
					break;
				}
				else p=p->lchild;
			}
			else if(item>p->data){
				if(p->rchild==NULL){
					p->rchild=q;//右子是空，可以插入q
					break; 
				}
				else p=p->rchild;
			}
			else{//相等 
				//do something
			}
		}
	
	}
} 
//二叉查找树的查找（非递归方法） 
BTNodeprt searchBST(BTNodeprt t,ElemType key){
	BTNodeprt p=t;
	while(p!=NULL){//树非空 
		if(key==p->data){
			return p;//找到了 
		}
		else if(key<p->data){
			p=p->lchild;//左子树继续查找 
		}
		else if(key>p->data){
			p=p->rchild;//右子树继续查找 
		}
	}
	return NULL;//查找失败返回NULL 
}

//二叉查找树的查找（递归）
BTNodeprt searchBST(BTNodeprt t,ElemType key){
	if(t!=NULL){//树非空 
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
	else return NULL;//树空。查找失败， 
} 

//二叉查找树的删除结点； 
//删除不常用，打个标记就行，查找的时候直接跳过它 
void deleteBST(BTNodeprt t,ElemType key){//根结点和目标删除 
	if(t!=NULL){
		BTNodeprt p=searchBST(t,key);//找到所在位置；
		if(p->rchild==NULL&&p->lchild==NULL){//是叶结点。直接删除 
			
		}
		else if(p->rchild==NULL){//无右子树，用左子树的根取代删除点； 
			
		}
		else if(p->lchild==NULL){//无左子树，用右子树的根取代删除点； 
			
		}
		else {//左右子树都存在，用左子树最大点取代，或者右子树最小点取代 
			
		}
	}
}
