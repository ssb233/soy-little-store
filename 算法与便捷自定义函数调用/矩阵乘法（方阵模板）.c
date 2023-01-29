#include<stdio.h>
int a[150][150];
int b[150][150];//第二个和后面的方阵都输入到b里面， 
int c[150][150];// c作为运算结果和临时储存器； 
void Matrix_cal(int n,int m);//输入和计算 
void Matrix_dp(int n,int m);//数值转换 
int main(){
	int n;//n阶方阵乘法 
	int m;//m个矩阵相乘 
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(int k=1;k<m;k++){//剩下的m-1个矩阵的输入 
		Matrix_cal(n,m);
		Matrix_dp(n,m);
	}
	//输出矩阵；
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	return 0;
}

void Matrix_cal(int n,int m){
	//输入
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}
void Matrix_dp(int n,int m){
	//数值转换
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=c[i][j];
			c[i][j]=0;//需要清零； 
		}
	} 
}
