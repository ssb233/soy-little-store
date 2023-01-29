#include<stdio.h>
#include<math.h>
int prime[1000],not_prime[10020];
//prime里面每一个数字是素数，cnt代表素数总的个数
//not_prime里面每一个数字作为下标可以用来判断
//如果是not_prime[i]==1;那就不是素数，如果是0，就是素数； 
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
