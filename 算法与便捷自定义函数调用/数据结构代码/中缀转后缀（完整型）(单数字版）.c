#include<stdio.h>
#include<string.h>

#define MAXSIZE 205
char stack_ch[MAXSIZE];
char stack_later[MAXSIZE];
char s[MAXSIZE];
int stack_cal[MAXSIZE];
int top_ch=-1,top_la=-1,top_cal=-1;

int priority(char c){
	if(c=='^')return 4;
	else if(c=='*'||c=='/'||c=='%')return 3;
	else if(c=='+'||c=='-')return 2;
	else if(c=='(')return 1;
	else if(c=='#')return 0; 
}

int isEmpty(int top){
	if(top==-1)return 1;
	else return 0;
}
void push(char stack[],int *top,char item){
	stack[++(*top)]=item;
}
void push_int(int stack[],int *top,int item){
	stack[++(*top)]=item;
}
char pop(char stack[],int * top){
	if(isEmpty(*top)){
		printf("error!");
	}
	else return stack[(*top)--];
}
int pop_int(int stack[],int *top){
	if(isEmpty(*top)){
		printf("error!");
	}
	else return stack[(*top)--];
}
int my_power(int base,int power){
	int k=1;
	for(int i=0;i<power;i++){
		k*=base;
	}
	return k;
}
int main(){
	scanf("%s",s);//��ȡ��׺���ʽ��
	int len=strlen(s);
	top_ch++;
	char ch;
	
	stack_ch[top_ch]='#';//��Ϊ�������� 
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			push(stack_later,&top_la,s[i]);//����ֱ����ջ�� 
		}
		else{//������ 
			if(s[i]=='('){//��ջ�� 
				push(stack_ch,&top_ch,s[i]);//������ֱ����ջ�� 
			}
			else if(s[i]==')'){//���ε���ֱ��'(',����ɾ�������ţ� 
				ch=pop(stack_ch,&top_ch);//�ӷ���ջ���� 
				while(ch!='('&&ch!='#'){
					push(stack_later,&top_la,ch);//�����׺ջ�� 
					ch=pop(stack_ch,&top_ch);//������������ʱ�˳���top_chָ��������ǰ��һ��λ�� 
				}
				stack_ch[top_ch+1]='\0';//ɾ�������ţ���֪�������費��Ҫ�� 
			}
			else if(s[i]=='^'){//��ֱ�������ջ 
				push(stack_ch,&top_ch,s[i]);
			}
			else{//���Ѳ��֣����ֲ�ͬ���ȼ������ַ��� 
				if(priority(s[i])>priority(stack_ch[top_ch])){//�²��������ȼ�����ջ����ֱ����ջ�� 
					push(stack_ch,&top_ch,s[i]);
				}
				else{//�������ε�����ֱ�����ȼ������ͣ����������ţ�Ȼ���ٽ�ջ�� 
					ch=pop(stack_ch,&top_ch);
					while(priority(ch)>=priority(s[i])||ch!='('){//�ͣ�������������Ϊ�˳������� 
						push(stack_later,&top_la,ch);
						ch=stack_ch[top_ch];
						if(ch=='('){//����ջ�²�������Ȼ������ 
							push(stack_ch,&top_ch,s[i]);break;
						}
						else if(priority(ch)<priority(s[i])){
							push(stack_ch,&top_ch,s[i]);break;
						}
						else{//˵���޷������� 
							ch=pop(stack_ch,&top_ch);//���������������� 
						}
					} 
				}
			}
		}
	}
	while(stack_ch[top_ch]!='#'){
		ch=pop(stack_ch,&top_ch);
		push(stack_later,&top_la,ch);
	}
	///��������Ǻ�׺���ʽ�� 
	//printf("%s",stack_later);
	//����һ���׺���ʽ 
	int len_la=strlen(stack_later);
	for(int i=0;i<len_la;i++){
		if('0'<=stack_later[i]&&stack_later[i]<='9'){//�����֣�������ջ 
			push_int(stack_cal,&top_cal,stack_later[i]-'0');//��ջ 
		}
		else{//�������������ڶ�����ջ����   ���������� ��һ����ջ���� 
		int num1=pop_int(stack_cal,&top_cal);
		int num2=pop_int(stack_cal,&top_cal);//�����������֣� 
			switch (stack_later[i]) {//��������ջ 
				case '+':
					push_int(stack_cal,&top_cal,num2+num1);break;
				case '-':
					push_int(stack_cal,&top_cal,num2-num1);break;
				case '*':
					push_int(stack_cal,&top_cal,num2*num1);break;
				case '/':
					push_int(stack_cal,&top_cal,num2/num1);break;
				case '%':
					push_int(stack_cal,&top_cal,num2%num1);break;
				case '^':
					push_int(stack_cal,&top_cal,my_power(num2,num1));break;
				default:break;
			}
		}
	}
	printf("%d",stack_cal[top_cal]);
	return 0;
}
