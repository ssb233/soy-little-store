#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct content{
	char name[20];
	char number[30];
	int count;
}Person,*Pperson;
Person p_table[105];
char s[50];
void get_data(int i){
		p_table[i].count=0;
		gets(s);int j=0;
		for(;isalpha(s[j]);j++){
			p_table[i].name[j]=s[j];
		}//读取截断字母 
		p_table[i].name[j]='\0';//完善字母 
		strcpy(p_table[i].number,s+j);//剩余的给数字 
}

int search_(int edge){
	for(int i=0;i<edge;i++){//在新输入的数据之前查找； 
		if(strcmp(p_table[i].name,p_table[edge].name)==0){
			if(strcmp(p_table[i].number,p_table[edge].number)==0){
				return 0;
			}//完全重合返回0，让下一组数据直接覆盖就行；
			p_table[i].count++;//重数加一； 
			 char tmp[3];
			 tmp[0]='_';tmp[1]=(char)(48+p_table[i].count);
			 tmp[2]='\0';
			 
			 strcat(p_table[edge].name,tmp);
			 return 1;//修改后的数据也合法； 
		}
	}
	return 1;//没有查找到就说明数据合法 
}

int cmp(const void *e1,const void *e2){
	Pperson p1=(Pperson)e1;
	Pperson p2=(Pperson)e2;
	return strcmp(p1->name,p2->name);
	
}
int main(){
	int n;int num=0;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		get_data(num);//输入数据到结构体；
		int p=search_(num);
		if(p>0)num++;//合法数据就可以输入到下一位； 
	}
	qsort(p_table,num,sizeof(p_table[0]),cmp);
	printf("\n");
	 for(int i=0;i<num;i++){
	 	printf("%s%s\n",p_table[i].name,p_table[i].number);
	 }
	
	return 0;
}
