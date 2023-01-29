#include<stdio.h>
#include<stdlib.h>
#define wordlen 55
#include<string.h>
#include<ctype.h>
typedef struct _wordRec {
	char word[wordlen];
	int count;
} WordRec,*PwordRec;
//这里可以转换的看typedef struct _wordRec WordRec,和typedef struct _wordRec *PwordRec; 
WordRec wordtable[1000];
int total_word=0;//表格总单词数量； 
int getword(FILE*fp, char word[]) {
	char ch;int i=0;
	while(!isalpha(ch=fgetc(fp))){
		if(ch==EOF)return 0;
		else continue;//清除前面的非字母字符 
	}
	word[i++]=tolower(ch);//将前面跳出的字母小写存取； 
	while((ch=fgetc(fp))!=EOF){
		if(!isalpha(ch))break;//不是字母就跳出 
		word[i++]=tolower(ch);
	}
	word[i]='\0';//末尾加结束符号让字母完整；
	return 1;//取到了完整单词，返回1； 
}
int searchword(char word[]) {
	for(int i=0;i<total_word;i++){
		if(strcmp(word,wordtable[i].word)==0){
			return i;//返回位置； 
		}
	}
	return -1;//没有查找到 
}
void insertword(char word[]) {
	strcpy(wordtable[total_word].word,word);
	wordtable[total_word].count=1;
	total_word++;
}
int cmp(const void *e1,const void *e2){
	wordtable[0]=*(PwordRec)e1;
	wordtable[1]=*(PwordRec)e2;
	if(wordtable[0].count<wordtable[1].count)return 1;
	else if(wordtable[0].count>wordtable[1].count)return -1;
	else return strcmp(wordtable[0].word,wordtable[1].word);
}
int main() {
	char filename[50];
	scanf("%s", filename);
	char word[wordlen];
	
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Can't find the file");
		return -1;
	}

	while (getword(fp, word)) {//查询单词 
		int p = searchword(word); //返回查询位置；
		if (p >= 0) {
			wordtable[p].count++;//对应查询位置的单词出现次数加一 
		} else {
			insertword(word);//在单词表末尾加入新单词； 
		}
	}
	qsort(wordtable,total_word,sizeof(wordtable[0]),cmp);//按照次数第一关键字排序，字典序第二关键字排序； 
	for(int i=0;i<total_word;i++){
		printf("%s %d\n",wordtable[i].word,wordtable[i].count);
	}
	int fclose(FILE * fp);
	return 0;
}
