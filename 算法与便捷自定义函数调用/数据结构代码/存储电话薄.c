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
		}//��ȡ�ض���ĸ 
		p_table[i].name[j]='\0';//������ĸ 
		strcpy(p_table[i].number,s+j);//ʣ��ĸ����� 
}

int search_(int edge){
	for(int i=0;i<edge;i++){//�������������֮ǰ���ң� 
		if(strcmp(p_table[i].name,p_table[edge].name)==0){
			if(strcmp(p_table[i].number,p_table[edge].number)==0){
				return 0;
			}//��ȫ�غϷ���0������һ������ֱ�Ӹ��Ǿ��У�
			p_table[i].count++;//������һ�� 
			 char tmp[3];
			 tmp[0]='_';tmp[1]=(char)(48+p_table[i].count);
			 tmp[2]='\0';
			 
			 strcat(p_table[edge].name,tmp);
			 return 1;//�޸ĺ������Ҳ�Ϸ��� 
		}
	}
	return 1;//û�в��ҵ���˵�����ݺϷ� 
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
		get_data(num);//�������ݵ��ṹ�壻
		int p=search_(num);
		if(p>0)num++;//�Ϸ����ݾͿ������뵽��һλ�� 
	}
	qsort(p_table,num,sizeof(p_table[0]),cmp);
	printf("\n");
	 for(int i=0;i<num;i++){
	 	printf("%s%s\n",p_table[i].name,p_table[i].number);
	 }
	
	return 0;
}
