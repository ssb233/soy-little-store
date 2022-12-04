#include<stdio.h>
#include<stdlib.h>
int map[10][10000];
//第一个数字表示维度k，第二个数字表示输入多少个点 
int cmp(const void*p1,const void* p2){//升序排列； 
	if(*(int*)p1>*(int *)p2)
	return 1;
	else if(*(int *)p1<*(int *)p2)
	return -1;
	else if(*(int *)p1==*(int *)p2)
	return 0;
}
int main(){
	
	int n;long long sum=0;
	int k;//k维； 
	scanf("%d%d",&n,&k);//输入n个数字； 
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&map[j][i]);//n个k维向量；写成列向量形式 
		}
	}
	for(int j=0;j<k;j++){
		qsort(map[j],n,sizeof(map[0][0]),cmp);//每一行都升序排列； 
	}
	for(int j=0;j<k;j++){
	for(int i=0;i<n/2;i++){
		sum+=map[j][n-i-1]-map[j][i]; 
	}
	}
	printf("%lld",sum);
	
	
	

	return 0;
}
