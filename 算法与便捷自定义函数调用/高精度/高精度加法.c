#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[505],b[505],c[505];//��ʼ����a��b�������c�� 
int change_num(int num,int s[]){
	int i=0;
	while(num){
		s[i++]=num%10;
		num/=10;
	}
	return i;//��λ�洢���ӵ�λ����λ������λ���� 
}
int cal_plus_num(int s1[],int len1,int s2[],int len2){
	int len=len1>len2?len1:len2;
	for(int i=0;i<len;i++){//ÿһλ���,������һ�� 
		c[i]+=((s1[i]+s2[i])%10);
		c[i+1]+=c[i]/10;
		c[i]%=10;
		c[i+1]+=(s1[i]+s2[i])/10;
	}
	if(c[len]==0){//0��len-1λ��û���⣬ 
		return len;
	}
	else if(c[len]!=0){//0��lenλ����len+1λ 
		return len+1;
	}
}
void print_num(int s[],int len){
	for(int i=len-1;i>=0;i--){
		printf("%d",s[i]);//��λ��ǰ 
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
