#include<stdio.h>
int not_prime[10020]={0},prime[10020]={0};//not_prime[10020]表示1为非质数，0为质数；
//其实在not_prime里面0的位置也是质数， 
int main()
{
	
	int cnt=0; 
	int i,j;
	 for(i=2;i<=10000;i++)
	 {
	 	if(not_prime[i])continue;//如果不是质数就跳过；
		 cnt++;//得到一个质数； 
		 prime[cnt]=i;//存取该质数；
		 for(j=2;i*j<=10000;j++)
		 {
		 	not_prime[i*j]=1;//标记非质数； 
		 } 
	 }
	return 0;
}
