#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElementType;//�Զ����������ͣ� 
typedef struct HeapStruct{
	ElementType *Elements;//�洢��Ԫ�ص����飬ָ������
	int size;    //�ѵĵ�ǰԪ�ظ����� 
	int capacity;//�ѵ�������� 
}MinHeap,*MinHeapPrt;
int IsFull(MinHeapPrt H){
	return (H->size==Maxsize);
}
int IsEmpty(MinHeapPrt H){
	return (H->size==0);
}
MinHeapPrt Create(int Maxsize){
	//��������ΪMaxsize�Ŀյ���С��
	//��1��ʼ����Ԫ�أ�0�����ڱ��� 
	MinHeapPrt H=(MinHeapPrt)malloc(sizeof(MinHeap));
	H->Elements=(ElementType *)malloc((Maxsize+1)*sizeof(ElementType));
	H->size=0;
	H->capacity=Maxsize;
	H->Elements[0]=MinData;//�����һ���ر�С����������������С��Ԫ�ؾ��У� 
	//MinData.�����ڱ�ΪС�ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	return H; 
}

void insert(MinHeapPrt H,ElementType item){
	//��Ԫ��item������С��H������H->Elements[0]�Ѿ�����Ϊ�ڱ���
	int i;
	if(IsFull(H)){
		printf("��С������");
		return; 
	} 
	i=++H->size;//iָ����������һ��Ԫ��λ�ã� 
	for(;H->Elements[i/2]>item;i/=2)//��ȫ��������i/2��ʾ���������ʣ����������Ŀ��item��
	//�������i=1��������������ڱ����ڣ��ڱ���֤�������������ݶ����ڱ������û���ڱ������Լ�һ��i>1; 
	//�ڱ�Ч�ʸ��ߣ� 
		H->Elements[i]=H->Elements[i/2];//��֤�����ԣ��Ѵ�С�����ϵ����¹��ˣ� 
	H->Elements[i]=item;
}

ElementType deleteMax(MinHeapPrt H){
	//����С����ȥ����ֵ��С��Ԫ�أ�ɾ�����
	int parent,child;
	ElementType MinItem,temp;
	if(IsEmpty(H)){
		printf("��С���ѿ�");
		return ;
	} 
	MinItem=H->Elements[1];//�Ӹ��������Сֵ��
	//����С�������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��㣬�����Ȱ����һ��Ԫ�طŵ�����λ��
	temp=H->Elements[H->size--];//�ȸ�ֵ���ټ��� 
	for(parent=1;parent*2<=H->size;parent=child){//�жϱ�֤�������ӣ� 
	child=parent*2;//����
	if((child!=H->size)&&(H->Elements[child]>H->Elements[child+1])) //�жϱ�֤�����ӵ�ͬʱ�������ӣ� 
	child++;//���ӱ����Ӵ� 
	if(temp>=H->Elements[child])break;//����ֵ�������Ӷ�С���Ǿͷ��ڸ���λ�� 
	else//�ƶ�tempԪ�ص���һ�� 
		H->Elements[parent]=H->Elements[child];//���Ϲ��ˣ������� 
	}
	H->Elements[parent]=temp;
	return MinItem; 
}

void adjust_MaxHeap(MinHeapPrt H,int p){
	//��֤�����Ѿ��γ���һ����ȫ������������H����Ҫ������p�����Ϊ������С�ѣ�
	int parent,child;
	ElementType temp;
	temp=H->Elements[p];//��pΪ������С�ѣ�,ǰ����p����������������С�ѣ�һ��ģ�ͣ�ĳ���������������������ѻ�����С�ѣ�ͨ�����������������Ϊ���/��С�ѣ� 
	for(parent=p;parent*2<=H->size;parent=child){
		child=parent*2;//��
		if((child!=H->size)&&(H->Elements[child]>H->Elements[child+1])){
			child++;//����Ҵ� 
		}
		if(temp>=H->Elements[child])break;
		else{
			H->Elements[parent]=H->Elements[child];//���¹��ˣ������ƶ��� 
		}
	} 
	H->Elements[parent]=temp;//�����˶� 
}

void BuildHeap( MinHeapPrt H )
{ /* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Elements[]�� */
    int i;
    /* �����һ�����ĸ��ڵ㿪ʼ���������1 */
    //����Ҷ����Ѿ������ѻ�����С�ѣ������һ�����㣨�������ϣ����Ǹ��������������������ѣ���С�ѵĽṹ��ʼ������ 
    for( i = H->size/2; i>0; i-- )
        adjust_MaxHeap( H, i );
}
