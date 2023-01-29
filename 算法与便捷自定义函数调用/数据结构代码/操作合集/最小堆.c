#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElementType;//自定义数据类型； 
typedef struct HeapStruct{
	ElementType *Elements;//存储堆元素的数组，指针数组
	int size;    //堆的当前元素个数； 
	int capacity;//堆的最大容量 
}MinHeap,*MinHeapPrt;
int IsFull(MinHeapPrt H){
	return (H->size==Maxsize);
}
int IsEmpty(MinHeapPrt H){
	return (H->size==0);
}
MinHeapPrt Create(int Maxsize){
	//创建容量为Maxsize的空的最小堆
	//从1开始插入元素，0留给哨兵； 
	MinHeapPrt H=(MinHeapPrt)malloc(sizeof(MinHeap));
	H->Elements=(ElementType *)malloc((Maxsize+1)*sizeof(ElementType));
	H->size=0;
	H->capacity=Maxsize;
	H->Elements[0]=MinData;//随便找一个特别小，比所有输入数据小的元素就行； 
	//MinData.定义哨兵为小于堆中所有可能元素的值，便于以后更快操作
	return H; 
}

void insert(MinHeapPrt H,ElementType item){
	//将元素item插入最小堆H，其中H->Elements[0]已经定义为哨兵；
	int i;
	if(IsFull(H)){
		printf("最小堆已满");
		return; 
	} 
	i=++H->size;//i指向插入后的最后一个元素位置； 
	for(;H->Elements[i/2]>item;i/=2)//完全二叉树有i/2表示父结点的性质；如果父结点比目标item大，
	//这里会有i=1的情况，但是有哨兵存在，哨兵保证了所有输入数据都比哨兵大，如果没有哨兵，可以加一句i>1; 
	//哨兵效率更高； 
		H->Elements[i]=H->Elements[i/2];//保证有序性，把大小不符合的往下过滤， 
	H->Elements[i]=item;
}

ElementType deleteMax(MinHeapPrt H){
	//从最小堆中去除键值最小的元素，删除结点
	int parent,child;
	ElementType MinItem,temp;
	if(IsEmpty(H)){
		printf("最小堆已空");
		return ;
	} 
	MinItem=H->Elements[1];//从根结点找最小值；
	//用最小堆中最后一个元素从根结点开始向上过滤下层结点，就是先把最后一个元素放到根的位置
	temp=H->Elements[H->size--];//先赋值，再减减 
	for(parent=1;parent*2<=H->size;parent=child){//判断保证存在左子； 
	child=parent*2;//左子
	if((child!=H->size)&&(H->Elements[child]>H->Elements[child+1])) //判断保证有左子的同时还有右子； 
	child++;//左子比右子大 
	if(temp>=H->Elements[child])break;//调整值比左右子都小；那就放在父的位置 
	else//移动temp元素到下一层 
		H->Elements[parent]=H->Elements[child];//向上过滤，往上移 
	}
	H->Elements[parent]=temp;
	return MinItem; 
}

void adjust_MaxHeap(MinHeapPrt H,int p){
	//保证数据已经形成了一颗完全二叉树，根是H，需要调整第p个结点为根的最小堆；
	int parent,child;
	ElementType temp;
	temp=H->Elements[p];//以p为根的最小堆；,前提是p的左右子树都是最小堆；一般模型，某个根的左右子树都是最大堆或者最小堆，通过调整根让其整体成为最大/最小堆； 
	for(parent=p;parent*2<=H->size;parent=child){
		child=parent*2;//左
		if((child!=H->size)&&(H->Elements[child]>H->Elements[child+1])){
			child++;//左比右大 
		}
		if(temp>=H->Elements[child])break;
		else{
			H->Elements[parent]=H->Elements[child];//向下过滤，向上移动； 
		}
	} 
	H->Elements[parent]=temp;//调整了堆 
}

void BuildHeap( MinHeapPrt H )
{ /* 调整H->Data[]中的元素，使满足最小堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Elements[]中 */
    int i;
    /* 从最后一个结点的父节点开始，到根结点1 */
    //所有叶结点已经是最大堆或者最小堆；从最后一个满足（根不符合，但是根的左右子树都满足最大堆，最小堆的结构开始调整） 
    for( i = H->size/2; i>0; i-- )
        adjust_MaxHeap( H, i );
}
