#include<stdio.h>
#include<math.h>
int prime[1000],not_prime[10020];
//prime����ÿһ��������������cnt���������ܵĸ���
//not_prime����ÿһ��������Ϊ�±���������ж�
//�����not_prime[i]==1;�ǾͲ��������������0������������ 
int main(){
	int cnt=0;
	for(int i=2;i<=10000;i++){
		if(not_prime[i])continue;
		cnt++;
		prime[cnt]=i;
		for(int j=2;i*j<=10000;j++){
			not_prime[i*j]=1;
		}
	}
	
}
