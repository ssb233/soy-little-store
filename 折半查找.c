//数值版本朴素的二分查找； 
int recBinFind(int b[], int key, int low, int high) {
	int mid;
	if (low > high)
		return -1;
	mid = (low + high) / 2;
	if (key == b[mid])
		return mid;
	else if (key > b[mid])
		return recBinFind(b, key, mid + 1, high);
	else
		return recBinFind(b, key, low, mid - 1);
}
//////////////////////////
//指针版本的二分查找，返回key的地址； 
int *halfFind(int *low,int *high,int key){
	while(low<=high){
		int *mid=low+(high-low)/2;
		if(*mid==key){
			return mid;//返回去key的地址； 
		}
		else if(*mid<key){
			low=mid+1;
		}
		else if(*mid>key){
			high=mid-1;
		}
	}
}
