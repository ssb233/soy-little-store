#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[505], b[505], c[5005]; //初始数字a和b，结果在c；
int change_num(int num, int s[]) {
	int i = 0;
	while (num) {
		s[i++] = num % 10;
		num /= 10;
	}
	return i;//低位存储，从低位到高位。返回位数；
}
int cal_multiply_num(int s1[],int len1,int s2[],int len2){
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			c[i+j]+=s1[i]*s2[j];
		}
	}
	for(int i=0;i<len1+len2;i++){
	c[i+1]=c[i+1]+(c[i]/10);
	c[i]%=10;
	}
	if(c[len1+len2-1]==0){
		return len1+len2-1;
	}
	else if(c[len1+len2-1]!=0){
		return len1+len2;
	}
}
void print_num(int s[],int len){
	int flag=0; 
	for(int i=len-1;i>=0;i--){
		if(s[i]!=0&&flag==0)flag=1;//跳过前导0 
		if(flag==1)
		printf("%d",s[i]);//高位在前 
	}
	if(flag==0)printf("0\n"); 
}
int main() {
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	
	int len1=change_num(num1,a);
	int len2=change_num(num2,b);
	
	int total_len=cal_multiply_num(a,len1,b,len2);
	
	print_num(c,total_len);
	return 0;
}
