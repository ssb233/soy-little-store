#include<stdio.h>
#include<stdlib.h>
int data[500005][6];
int i=0;

//排序规则：按照每行第一个元素升序排序，第一个元素相同时按照第二个元素升序排序
int cmp(const void *p, const void *q) {
	int *a = (int *)p;
	int *b = (int *)q;
	if(a[1] > b[1]) return 1; //第一个元素a<b，返回1表示p指向的行应该在q指向的行的后面
	else if(a[1] < b[1]) return -1; //第一个元素a>b，返回-1表示p指向的行应该在q指向的行的前面
	else if(a[0]>b[0]) return -1;
	else if(a[0]<b[0]) return 1;
	else if(a[3] > b[3]) return 1; //此时一定第一个元素a=b，判断第二个元素
	else if(a[3] < b[3]) return -1;
	else if(a[4]>b[4]) return -1;
	else if(a[4]<b[4]) return 1;
	else return 0; //第一个，第二个元素均相等，返回0表示p指向的行和q指向的行无确定前后关系
}

void judge(int j){
	int l=data[j][1];
	char ch_l=data[j][0];
	int k=0;
	for( k=j+1;k<i;k++){//这个计算通过左端点数量； 
		int flag1=0;int flag2=0;
		int tmp=data[j][3];//右边界； 
		if(tmp>data[k][1]){//通过一个左端点 
			flag1=1;
		}
		else if(tmp==data[k][1]){
			if(data[j][4]==']'||data[k][0]=='['){
				flag1=1;//过了左端点； 
			}
		}
		
		if(tmp>data[k][3]){//通过一个右端点； 
			flag2=1;
		}
		else if(tmp==data[k][3]){
			if(data[j][4]==']'||data[k][4]==')'){
				flag2=1;//右端点 
			}
		}
		if(flag2==0&&flag1==1){//2不执行了，说明穷尽了, 
			j=k;//卡在区间中间就刷新右边界， 
		}
		else if(flag2==0&&flag1==0){
			printf("%c%d%c%d%c\n",ch_l,l,data[0][2],data[j][3],data[j][4]);
			ch_l=data[k][0];
			l=data[k][1];
			j=k;
		}
	}
	printf("%c%d%c%d%c\n",ch_l,l,data[0][2],data[j][3],data[j][4]);
	return;
	
}

int main(){
	
	
	while(scanf(" %c%d%c%d%c",&data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][4])!=EOF){
		i++;
	}
	//调用qsort函数对二维数组int data[1000][2]前n行根据规则进行排序：
	qsort(data, i, sizeof(data[0]), cmp);
	judge(0);
	return 0;
}
