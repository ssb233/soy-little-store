#include<stdio.h>
#include<stdlib.h>
int data[500005][6];
int i=0;

//������򣺰���ÿ�е�һ��Ԫ���������򣬵�һ��Ԫ����ͬʱ���յڶ���Ԫ����������
int cmp(const void *p, const void *q) {
	int *a = (int *)p;
	int *b = (int *)q;
	if(a[1] > b[1]) return 1; //��һ��Ԫ��a<b������1��ʾpָ�����Ӧ����qָ����еĺ���
	else if(a[1] < b[1]) return -1; //��һ��Ԫ��a>b������-1��ʾpָ�����Ӧ����qָ����е�ǰ��
	else if(a[0]>b[0]) return -1;
	else if(a[0]<b[0]) return 1;
	else if(a[3] > b[3]) return 1; //��ʱһ����һ��Ԫ��a=b���жϵڶ���Ԫ��
	else if(a[3] < b[3]) return -1;
	else if(a[4]>b[4]) return -1;
	else if(a[4]<b[4]) return 1;
	else return 0; //��һ�����ڶ���Ԫ�ؾ���ȣ�����0��ʾpָ����к�qָ�������ȷ��ǰ���ϵ
}

void judge(int j){
	int l=data[j][1];
	char ch_l=data[j][0];
	int k=0;
	for( k=j+1;k<i;k++){//�������ͨ����˵������� 
		int flag1=0;int flag2=0;
		int tmp=data[j][3];//�ұ߽磻 
		if(tmp>data[k][1]){//ͨ��һ����˵� 
			flag1=1;
		}
		else if(tmp==data[k][1]){
			if(data[j][4]==']'||data[k][0]=='['){
				flag1=1;//������˵㣻 
			}
		}
		
		if(tmp>data[k][3]){//ͨ��һ���Ҷ˵㣻 
			flag2=1;
		}
		else if(tmp==data[k][3]){
			if(data[j][4]==']'||data[k][4]==')'){
				flag2=1;//�Ҷ˵� 
			}
		}
		if(flag2==0&&flag1==1){//2��ִ���ˣ�˵�����, 
			j=k;//���������м��ˢ���ұ߽磬 
		}
		else if(flag2==0&&flag1==0){
			printf("%c%d%c%d%c\n",ch_l,l,data[0][2],data[j][3],data[j][4]);
			ch_l=data[k][0];
			l=data[k][1];
			j=k;
		}
	}
	printf("%c%d%c%d%c\n",ch_l,l,data[0][2],data[j][3],data[j][4]);
	return;
	
}

int main(){
	
	
	while(scanf(" %c%d%c%d%c",&data[i][0],&data[i][1],&data[i][2],&data[i][3],&data[i][4])!=EOF){
		i++;
	}
	//����qsort�����Զ�ά����int data[1000][2]ǰn�и��ݹ����������
	qsort(data, i, sizeof(data[0]), cmp);
	judge(0);
	return 0;
}
