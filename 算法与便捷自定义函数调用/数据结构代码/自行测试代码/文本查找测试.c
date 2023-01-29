#include<stdio.h>
#include<string.h>

char s[25];
char filename[25];
char target[20];
int main(){
	FILE*fp;
	scanf("%s",filename);
	scanf("%s",target);
	
	fp=fopen(filename,"r");
	if(fp==NULL){
		perror("Can't find the file");
		return 1;
	}
	while(fgets(s,20,fp)!=NULL){
		char *p;
		p=strstr(s,target);
		if(p!=NULL){
			printf("%s\n",s);
		}
		
	}
	int fclose(FILE*fp);
	
	return 0;
}
