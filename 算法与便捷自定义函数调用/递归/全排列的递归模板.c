#include<stdio.h>
int n;
int k;
int a[50];
int b[50];
void all_rank(int n){//n表示还剩几个元素需要取， 
	if(n==0){
		for(int i=0;i<k;i++){
			printf("    %d",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=k;i++){
		a[k-n]=i;
		if(b[i]==1)continue;
		b[i]=1;
		all_rank(n-1);
		b[i]=0;
	}
	return ;
}
int main(){
	
	scanf("%d",&n);
	k=n;
	all_rank(n);
	return 0;
}
