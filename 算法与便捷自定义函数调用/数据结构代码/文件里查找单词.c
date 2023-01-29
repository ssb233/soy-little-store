#include<stdio.h>
#include<stdlib.h>
#define wordlen 55
#include<string.h>
#include<ctype.h>
typedef struct _wordRec {
	char word[wordlen];
	int count;
} WordRec,*PwordRec;
//�������ת���Ŀ�typedef struct _wordRec WordRec,��typedef struct _wordRec *PwordRec; 
WordRec wordtable[1000];
int total_word=0;//����ܵ��������� 
int getword(FILE*fp, char word[]) {
	char ch;int i=0;
	while(!isalpha(ch=fgetc(fp))){
		if(ch==EOF)return 0;
		else continue;//���ǰ��ķ���ĸ�ַ� 
	}
	word[i++]=tolower(ch);//��ǰ����������ĸСд��ȡ�� 
	while((ch=fgetc(fp))!=EOF){
		if(!isalpha(ch))break;//������ĸ������ 
		word[i++]=tolower(ch);
	}
	word[i]='\0';//ĩβ�ӽ�����������ĸ������
	return 1;//ȡ�����������ʣ�����1�� 
}
int searchword(char word[]) {
	for(int i=0;i<total_word;i++){
		if(strcmp(word,wordtable[i].word)==0){
			return i;//����λ�ã� 
		}
	}
	return -1;//û�в��ҵ� 
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

	while (getword(fp, word)) {//��ѯ���� 
		int p = searchword(word); //���ز�ѯλ�ã�
		if (p >= 0) {
			wordtable[p].count++;//��Ӧ��ѯλ�õĵ��ʳ��ִ�����һ 
		} else {
			insertword(word);//�ڵ��ʱ�ĩβ�����µ��ʣ� 
		}
	}
	qsort(wordtable,total_word,sizeof(wordtable[0]),cmp);//���մ�����һ�ؼ��������ֵ���ڶ��ؼ������� 
	for(int i=0;i<total_word;i++){
		printf("%s %d\n",wordtable[i].word,wordtable[i].count);
	}
	int fclose(FILE * fp);
	return 0;
}
