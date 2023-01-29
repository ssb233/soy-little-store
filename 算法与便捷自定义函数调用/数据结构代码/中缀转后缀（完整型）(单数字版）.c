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
	scanf("%s",s);//读取中缀表达式；
	int len=strlen(s);
	top_ch++;
	char ch;
	
	stack_ch[top_ch]='#';//作为结束符； 
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			push(stack_later,&top_la,s[i]);//数字直接入栈； 
		}
		else{//操作符 
			if(s[i]=='('){//入栈； 
				push(stack_ch,&top_ch,s[i]);//左括号直接入栈； 
			}
			else if(s[i]==')'){//依次弹出直到'(',而且删除左括号； 
				ch=pop(stack_ch,&top_ch);//从符号栈弹出 
				while(ch!='('&&ch!='#'){
					push(stack_later,&top_la,ch);//进入后缀栈； 
					ch=pop(stack_ch,&top_ch);//当它是左括号时退出，top_ch指向左括号前面一个位置 
				}
				stack_ch[top_ch+1]='\0';//删除左括号（不知道这样需不需要） 
			}
			else if(s[i]=='^'){//幂直接入符号栈 
				push(stack_ch,&top_ch,s[i]);
			}
			else{//最难部分，各种不同优先级操作字符； 
				if(priority(s[i])>priority(stack_ch[top_ch])){//新操作符优先级高于栈顶，直接入栈； 
					push(stack_ch,&top_ch,s[i]);
				}
				else{//否则依次弹出，直至优先级比它低，或者左括号；然后再进栈； 
					ch=pop(stack_ch,&top_ch);
					while(priority(ch)>=priority(s[i])||ch!='('){//低，或者左括号作为退出条件； 
						push(stack_later,&top_la,ch);
						ch=stack_ch[top_ch];
						if(ch=='('){//；入栈新操作符，然后跳出 
							push(stack_ch,&top_ch,s[i]);break;
						}
						else if(priority(ch)<priority(s[i])){
							push(stack_ch,&top_ch,s[i]);break;
						}
						else{//说明无法跳出； 
							ch=pop(stack_ch,&top_ch);//继续弹出操作符； 
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
	///到这里就是后缀表达式； 
	//printf("%s",stack_later);
	//遍历一遍后缀表达式 
	int len_la=strlen(stack_later);
	for(int i=0;i<len_la;i++){
		if('0'<=stack_later[i]&&stack_later[i]<='9'){//是数字，入数字栈 
			push_int(stack_cal,&top_cal,stack_later[i]-'0');//入栈 
		}
		else{//遇到操作符，第二个出栈数字   操作。。。 第一个出栈数字 
		int num1=pop_int(stack_cal,&top_cal);
		int num2=pop_int(stack_cal,&top_cal);//弹出两个数字； 
			switch (stack_later[i]) {//计算结果入栈 
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
