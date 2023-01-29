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
	int i=0;//表示位数； 

	int j;
	int tmp;
	for( j=0;j<n;j++){
		scanf("%s",s);
		sum[j]=change(s);
		if(sum[j]>col)continue;
		num++;tmp=j+1;
	}
	//从j开始是比标记点大的； 
	while(num>0){
		col+=num;
		num=0;
		while(sum[tmp]<=col&&tmp<n){
			tmp++;num++;
		}
	}
	//最终得到一个col，转换成字符串就行 
		while(col>0){
			//低位到高位存储//低位字母表示在靠右侧；高位靠左； 
		 save[i++]=(col-1)%26;//这样就可以有Z 
			 col=(col-1)/26;//Z的特殊 
		}
		for(int j=0;j<i;j++){
			printf("%c",save[i-1-j]+'A');//save 取值在0~25；0代表A 
		}
	return 0;
}
