#include<stdio.h>
#include<string.h>

char s[50];
//文件路径直接复制就行，但需要在"\"后面加斜杠 
//简单操作说明 
/*1、“r”以只读方式打开一个文件；
文件不存在就出错 

2、“w”以只写方式打开一个文件；
有内容就清空，如果文件不存在就建立新文件（这里的新文件的地址目前还不清楚） 

3、“a”打开一个文件追加；
保留原文件的EOF，在其之后添加数据。
若不存在就建立新文件（也不清楚）。 

4、“rb”以只读方式打开一个二进制文件；
只读，读一个二进制文件 。 没有文件就出错。 

5、“wb”以只写方式打开一个二进制文件；
类推上面的二进制， 

6、“ab”打开一个二进制文件追加；
类推 

7、"r+"以读写方式打开一个文件；
打开一个文件进行"读写"操作，没有就出错。 

8、“w+”以读写方式建立一个文件；
打开一个文件进行"读写"操作，删除文件内容，
如果文件不存在就打开新文件。 

9、“a+”以读写方式打开一个文件追加；
打开一个文件进行"读写"操作，但是会清除EOF，
若没有文件就打开新文件。 

10、“rb+”以读写方式打开一个二进制文件；
"读写"一个二进制文件。没有就出错。 

11、“wb+”以读写方式建立一个二进制文件；
"读写"一个二进制文件。清空内容。
没有就建立新文件。 

12、“ab+”以读写方式打开一个二进制文件追加。
向二进制文件末尾添加数据，保留原数据，（应该也要删除EOF）
没有文件就建立新文件。*/


//fgets函数测试，
//第一位是读入的位置，第二个是位数（最好留一个给\0），第三个是文件。 
/*int main(){
	FILE* fp;
	fp = fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\文件开闭测试.exe","r"); 
	if (fp == NULL) {
	perror("Can't open file_a");
	return 1;
	}
	fgets(s,20,fp);///////////////将fp中的文件输入到s数组里面。
	目标数组，字符数量，来源文件 
	int fclose(FILE*fp);
	puts(s);
	////////fputs(char s[],FILE*fp);将文件输出到某个文件里面（无换行）； 
	return 0;
}*/ 

//fscanf和fprintf测试 
//就是最开头加个文件指针*fp;然后其读取方式和scanf相同；
// fprintf暂时就是用标准输出，其它用法不清楚， 
/*int main(){
	FILE * fp;
	fp=fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\测试文本2-fscanf和fprintf.txt","r");
	if(fp==NULL){
		perror("Can't find file_a");
		return 1;
	}
	fscanf(fp,"%s",s);////////////////将fp中的文件输入到s里面，格式和scanf相同 
	fprintf(stdout,"%s",s);///////第一个文件表示输出位置，默认就是标准输出，可以定向到文件里面，直接输出到文件里面 
	//似乎暂时只能这么用 
	int fclose(FILE*fp);
	return 0;
}*/


//fprintf的作用，输入到文件里面； 
/*int main(){
	FILE* fp_s,* fp_p;
	fp_s=fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\测试文本2-fscanf读取来源.txt","r");
	fp_p=fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\测试文本5-fprintf输入文件输出去向.txt","w");
	fscanf(fp_s,"%s",s);//把fp_s里面的数据打印到s; 
	fprintf(fp_p,"%s",s);//再把s里面的数据打印到fp_p里面。 
	int fclose(FILE*fp_s);
	int fclose(FILE*fp_p);
	return 0;
}*/


//fgetc读取，fputc输出到另一个文件里面；
/*int main(){
	FILE* fp_p,*fp_g;
	fp_g=fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\测试文本3-fgetc和fputc.txt","r");
	fp_p=fopen("C:\\Users\\86159\\Desktop\\数据结构代码\\自行测试代码\\测试文本4-fgetc输入文件.txt","w");
	if(fp_p==NULL){
		perror("Can't find file_a");
		return 1;
	}
	if(fp_g==NULL){
			perror("Can't find file_a");
			return 1;
		}
	char ch;
	while((ch=fgetc(fp_g))!=EOF){//读入一个输出到另外一个文件里面；
	从目标文件里面读取字符， 
		fputc(ch,fp_p);输出内容，输入文件位置， 
	}
	int fclose(FILE* fp_g);
	int fclose(FILE* fp_p);
	return 0;
}*/ 

//文件重定向freopen,
//在open函数的基础上，在最后多加一个参数，就是重定向文件。
//即    （打开的文件，文件操作，重定向文件）； 
//这里是课件的一个示例。
/*int main(){
	int num1,num2;
	char op;
	if(freopen("expr.txt","r",stdin)==NULL){
		printf("Can't open the file!\n");
		return -1;
	}
	while(scanf("%d%c%d",&num1,&op,&num2)!=EOF){
		printf("%d%c%d=%d\n",num1,op,num2,calc(num1,op,num2));
	}
	fclose(stdin);//重定向文件也需要关闭链接函数。 
	return 0;
} */ 
