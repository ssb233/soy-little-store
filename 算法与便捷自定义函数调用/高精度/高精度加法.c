#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[505],b[505],c[505];//初始数字a和b，结果在c； 
int change_num(int num,int s[]){
	int i=0;
	while(num){
		s[i++]=num%10;
		num/=10;
	}
	return i;//低位存储，从低位到高位。返回位数； 
}
int cal_plus_num(int s1[],int len1,int s2[],int len2){
	int len=len1>len2?len1:len2;
	for(int i=0;i<len;i++){//每一位相加,更长的一方 
		c[i]+=((s1[i]+s2[i])%10);
		c[i+1]+=c[i]/10;
		c[i]%=10;
		c[i+1]+=(s1[i]+s2[i])/10;
	}
	if(c[len]==0){//0到len-1位都没问题， 
		return len;
	}
	else if(c[len]!=0){//0到len位，共len+1位 
		return len+1;
	}
}
void print_num(int s[],int len){
	for(int i=len-1;i>=0;i--){
		printf("%d",s[i]);//高位在前 
	}
}
int main(){
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	
	int len1=change_num(num1,a);
	int len2=change_num(num2,b);
	
	int total_len=cal_plus_num(a,len1,b,len2);
	
	print_num(c,total_len);
	
}
