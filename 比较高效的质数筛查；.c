#include<stdio.h>
int not_prime[10020]={0},prime[10020]={0};//not_prime[10020]��ʾ1Ϊ��������0Ϊ������
//��ʵ��not_prime����0��λ��Ҳ�������� 
int main()
{
	
	int cnt=0; 
	int i,j;
	 for(i=2;i<=10000;i++)
	 {
	 	if(not_prime[i])continue;//�������������������
		 cnt++;//�õ�һ�������� 
		 prime[cnt]=i;//��ȡ��������
		 for(j=2;i*j<=10000;j++)
		 {
		 	not_prime[i*j]=1;//��Ƿ������� 
		 } 
	 }
	return 0;
}
