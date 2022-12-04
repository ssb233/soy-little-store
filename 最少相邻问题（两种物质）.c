int dia[100005];
int num=0;

void judge(int flag,int i,int dia[]){
	if(dia[flag]==dia[i]){
		//属性相同；
		if((i-flag)&1){
			num++;
		} 
	}
	else if(dia[flag]!=dia[i]){
		if((i-flag-1)&1){
			num++;
		}
	}
}
//相邻问题，一个数组里面只有两种物质，如果同种物质出现相邻
//那么数字加加，采用最优的放置方法；flag是找到的第一个物质
//i是找到的第二个物质，然后在这两个物质之间放置； 
