#include<stdio.h>
int a[150][150];
int b[150][150];//�ڶ����ͺ���ķ������뵽b���棬 
int c[150][150];// c��Ϊ����������ʱ�������� 
void Matrix_cal(int n,int m);//����ͼ��� 
void Matrix_dp(int n,int m);//��ֵת�� 
int main(){
	int n;//n�׷���˷� 
	int m;//m��������� 
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(int k=1;k<m;k++){//ʣ�µ�m-1����������� 
		Matrix_cal(n,m);
		Matrix_dp(n,m);
	}
	//�������
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	return 0;
}

void Matrix_cal(int n,int m){
	//����
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
	//��ֵת��
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=c[i][j];
			c[i][j]=0;//��Ҫ���㣻 
		}
	} 
}
