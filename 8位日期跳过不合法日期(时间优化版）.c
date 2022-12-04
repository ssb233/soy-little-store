#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int daynum[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //预存每个月天

int checkDate(int date) {
	int day = date % 100, month = (date / 100) % 100, year = date / 10000; //取出year，month，day
	if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {//判断是否为闰年，若
		daynum[2] = 29;
	} 
	else {
		daynum[2] = 28;
	}
	if (1 <= month && month <= 12 && 1 <= day && day <= daynum[month]) { // 判断
		return 1;
	}
	return 0;
}

//这个是计算间隔天数，比如今天和明天间隔一天，
//实际题目可能需要细节修改大于等于符号 
//默认data1<data2; 
//但是如果data1>data2;下面有个交换函数，所以具体题目具体考虑 
int days_dis(int data1,int data2){
	if(data1>data2){
		int tmp=data2;
		data2=data1;
		data1=tmp;
	}
	int days=0;//表示两合法日期中间间隔了多少天
	int year_1=data1/10000;
	int year_2=data2/10000;
	if(year_2-year_1){//只有这两年不相同的情况下才需要这样计算
	//极大的缩短时间； 
	for(int j=year_1+1;j<year_2;j++){//算出中间差了多少年，一天一天判断容易超时 
		if (j % 100 != 0 && j % 4 == 0 || j % 400 == 0){
			days+=366;
		}
		else days+=365;
	}
	for(int j=data1;j<year_1*10000+1231;j++){//算出起始日期那一年结束的时间 
		if(checkDate(j))days++;
	}
	for(int j=year_2*10000+101;j<data2;j++){//算出结束那一年的时间到结束日期的天数； 
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
//算两个日期年月日秒时分的最后秒数差 
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
 
