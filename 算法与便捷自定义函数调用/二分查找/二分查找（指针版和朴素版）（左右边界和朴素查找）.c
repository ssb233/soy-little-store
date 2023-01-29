////////////////////////////////////////////////////
//二分查找，；老师的查找地址版本；
//这是可能有重复元素的查找，就是找左侧第一个出现的或者右边第一个出现的 
#include<stdio.h>
//查找一个有序数列，其中某个数字会有重复
//例如
//   1  2   3   4  5  6  7  9  9  9  10  11；
//这个查找就是找第一次出现的位置和最后一次出现的位置，分别记作first和last； 
int* findFirst(int* low, int* high, int key) {//返回的是指针，相对坐标系很好 
	int* mid = NULL;
	if (low > high) return NULL;//如果下边界比上边界还靠右就退出，
	//这里就是low<=high 的情况 
	if (*low > key || *high < key) return NULL;//如果查找值比最小的还小或者比最大的还大就退出
	//这里是一定可以找到的 
	if (*low == key) return low;
	if (low == high) return NULL;
	mid = low + (high - low) / 2;//指针只能减法 
	if (*mid > key) {//因为有多个数字相同，所以这个说明mid在最右侧的那个key的右边 
		return findFirst(low + 1, mid - 1, key);
	} else if (*mid < key) {//说明mid在最左侧key的左边，那mid可以加1，但是high不确定不能动 
		return findFirst(mid + 1, high, key);
	} else {//*mid等于key了，说明mid在一堆key的某个位置，可能是最左边，所以mid不能动，但是low可以加1 
		return findFirst(low + 1, mid, key);
	}
}
//最后传出的是key最左侧的指针，int *p=key的位置，那左侧key的下标可以得出
//下标等于int flag_left=p-数组的名字，这个就是相对坐标系 
int* findLast(int* low, int* high, int key) {
	int* mid = NULL;
	if (low > high) return NULL;
	if (*low > key || *high < key) return NULL;
	if (*high == key) return high;
	if (low == high) return NULL;
	mid = low + (high - low) / 2;
	if (*mid > key) {
		return findLast(low, mid - 1, key);
	} else if (*mid < key) {
		return findLast(mid + 1, high - 1, key);
	} else {
		return findLast(mid, high - 1, key);
	}
}

///////////////////////////////////////
//标准查找法，
//朴素二分 
int binary_search(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}
//左侧边界查找 
int left_bound(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= strlen(nums) || nums[left] != target)
        return -1;
    return left;
}

//右侧边界查找 
int right_bound(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

//近似查找，查找的前提是没有数字在这里面，通常需要先用正常二分去判断是否存在这个数字
//不存在这个数字再使用近似二分； 
int similar_find(int nums[],int key,int len){//默认升序; 
	int left=0,right=len-1;
	while(left<right-1){//跳出情况left=right-1，刚好夹住那个近似数； 
		int mid=left+(right-left)/2;
		if(nums[mid]>key)right=mid;
		else if(nums[mid]<key)left=mid;
	}
	return right;//这里返回左右看情况决定，都是近似点的下标 
} 
