#include<stdio.h>
#include<stdlib.h>
int map[10][10000];
//��һ�����ֱ�ʾά��k���ڶ������ֱ�ʾ������ٸ��� 
int cmp(const void*p1,const void* p2){//�������У� 
	if(*(int*)p1>*(int *)p2)
	return 1;
	else if(*(int *)p1<*(int *)p2)
	return -1;
	else if(*(int *)p1==*(int *)p2)
	return 0;
}
int main(){
	
	int n;long long sum=0;
	int k;//kά�� 
	scanf("%d%d",&n,&k);//����n�����֣� 
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&map[j][i]);//n��kά������д����������ʽ 
		}
	}
	for(int j=0;j<k;j++){
		qsort(map[j],n,sizeof(map[0][0]),cmp);//ÿһ�ж��������У� 
	}
	for(int j=0;j<k;j++){
	for(int i=0;i<n/2;i++){
		sum+=map[j][n-i-1]-map[j][i]; 
	}
	}
	printf("%lld",sum);
	
	
	

	return 0;
}
