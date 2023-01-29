#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[505],b[505],c[505];//初始数字a和b，结果在c； 
//默认第一个数字比第二个大，不符合就交换； 
int change_num(int num,int s[]){
	int i=0;
	while(num){
		s[i++]=num%10;
		num/=10;
	}
	return i;//低位存储，从低位到高位。返回位数； 
}
int cal_minus_num(int s1[],int len1,int s2[],int len2){

	for(int i=0;i<len1;i++){//第一个数字更长 
		c[i]=(s1[i]-s2[i]);
		if(c[i]<0){
			c[i]+=10;c[i+1]--;
		} 
	}
	for(int i=len1;i>=0;i--){
		if(c[i]!=0)return i+1;//长度 
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
	if(num1==num2){
		printf("0");return 0;
	}
	if(num1<num2){//交换 
		int tmp=num2;
		num2=num1;
		num1=tmp;
	}
	
	int len1=change_num(num1,a);
	int len2=change_num(num2,b);
	
	int total_len=cal_minus_num(a,len1,b,len2);
	
	print_num(c,total_len);
	
}
