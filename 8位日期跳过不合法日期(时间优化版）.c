#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int daynum[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Ԥ��ÿ������

int checkDate(int date) {
	int day = date % 100, month = (date / 100) % 100, year = date / 10000; //ȡ��year��month��day
	if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {//�ж��Ƿ�Ϊ���꣬��
		daynum[2] = 29;
	} 
	else {
		daynum[2] = 28;
	}
	if (1 <= month && month <= 12 && 1 <= day && day <= daynum[month]) { // �ж�
		return 1;
	}
	return 0;
}

//����Ǽ�������������������������һ�죬
//ʵ����Ŀ������Ҫϸ���޸Ĵ��ڵ��ڷ��� 
//Ĭ��data1<data2; 
//�������data1>data2;�����и��������������Ծ�����Ŀ���忼�� 
int days_dis(int data1,int data2){
	if(data1>data2){
		int tmp=data2;
		data2=data1;
		data1=tmp;
	}
	int days=0;//��ʾ���Ϸ������м����˶�����
	int year_1=data1/10000;
	int year_2=data2/10000;
	if(year_2-year_1){//ֻ�������겻��ͬ������²���Ҫ��������
	//���������ʱ�䣻 
	for(int j=year_1+1;j<year_2;j++){//����м���˶����꣬һ��һ���ж����׳�ʱ 
		if (j % 100 != 0 && j % 4 == 0 || j % 400 == 0){
			days+=366;
		}
		else days+=365;
	}
	for(int j=data1;j<year_1*10000+1231;j++){//�����ʼ������һ�������ʱ�� 
		if(checkDate(j))days++;
	}
	for(int j=year_2*10000+101;j<data2;j++){//���������һ���ʱ�䵽�������ڵ������� 
		if(checkDate(j))days++;
	}
	}
	return days+1;
}

int main(){
	int data1,data2;
	scanf("%d%d",&data1,&data2);
	printf("%d",days_dis(data1,data2));
}

////////////////////////
//������������������ʱ�ֵ���������� 
int main(){
	int a,b,c,d,e,f,g,h,i,j,k,l;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,  &g,&h,&i,&j,&k,&l);
	int data1=a*10000+b*100+c;
	int data2=g*10000+h*100+i;
	int days=days_dis(data1,data2);
	long long time_s=0;
	if(data1<=data2){
		time_s=(long long)days*24*3600+(long long)((j-d)*3600+(k-e)*60+l-f);
	}
	else if(data1>data2){
		time_s=-(long long)days*24*3600+(long long)((j-d)*3600+(k-e)*60+l-f);
	}
	printf("%lld",llabs(time_s));
	return 0;
}
 
