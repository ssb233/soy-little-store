#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int save[30];
char s[30];
int sum[100005];
int change(char s[]){
	int len=strlen(s),total=0; 
	for(int i=0;i<len;i++){
		total*=26;
		total+=s[i]-'A'+1;
	}
	return total;
}
int main(){
	int col,n;
	scanf("%d%d",&col,&n);
	int num=0;
	int i=0;//��ʾλ���� 

	int j;
	int tmp;
	for( j=0;j<n;j++){
		scanf("%s",s);
		sum[j]=change(s);
		if(sum[j]>col)continue;
		num++;tmp=j+1;
	}
	//��j��ʼ�Ǳȱ�ǵ��ģ� 
	while(num>0){
		col+=num;
		num=0;
		while(sum[tmp]<=col&&tmp<n){
			tmp++;num++;
		}
	}
	//���յõ�һ��col��ת�����ַ������� 
		while(col>0){
			//��λ����λ�洢//��λ��ĸ��ʾ�ڿ��Ҳࣻ��λ���� 
		 save[i++]=(col-1)%26;//�����Ϳ�����Z 
			 col=(col-1)/26;//Z������ 
		}
		for(int j=0;j<i;j++){
			printf("%c",save[i-1-j]+'A');//save ȡֵ��0~25��0����A 
		}
	return 0;
}
