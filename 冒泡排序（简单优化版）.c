#include<stdio.h>
int a[10006];
void bubblesort(int n)
{
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-1-i;j++){
			
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubblesort(n);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
