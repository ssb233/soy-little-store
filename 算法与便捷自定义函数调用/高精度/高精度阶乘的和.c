#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[505], b[505], c[5005],plus_of_factorial[5005]; //��ʼ����a��b�������c��
int change_num(int num, int s[]) {
	int i = 0;
	while (num) {
		s[i++] = num % 10;
		num /= 10;
	}
	return i;//��λ�洢���ӵ�λ����λ������λ����
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
		if(s[i]!=0&&flag==0)flag=1;//����ǰ��0 
		if(flag==1)
		printf("%d",s[i]);//��λ��ǰ 
	}
	if(flag==0)printf("0\n"); 
}
void exchange_array(int s1[],int s2[],int len){//sorce,target;
	for(int i=0;i<len;i++){
		s2[i]=s1[i];
	}
}
void delete_the_array(int s[],int len){
	for(int i=0;i<len;i++){
		s[i]=0;
	}
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
int main() {
	int num1,num2;
	int the_plus_of_factorial_len=0;
	num1=1;a[0]=1;int len1=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num2=i;
		int len2=change_num(num2,b);	
		int total_len=cal_multiply_num(a,len1,b,len2);
		len1=total_len;
		exchange_array(c,a,len1);
		delete_the_array(c,total_len);
		total_len=cal_plus_num(a,len1,plus_of_factorial,the_plus_of_factorial_len);//c����ĳ��� 
		//����ӵ�c�����ˡ���Ҫ���Ƶ�plus_of_factorial,Ȼ��ɾ��c
		exchange_array(c,plus_of_factorial,total_len);
		the_plus_of_factorial_len=total_len;
		delete_the_array(c,total_len);
	}
	
	print_num(plus_of_factorial,the_plus_of_factorial_len);
	return 0;
}
