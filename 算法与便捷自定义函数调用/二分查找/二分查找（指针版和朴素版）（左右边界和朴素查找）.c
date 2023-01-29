////////////////////////////////////////////////////
//���ֲ��ң�����ʦ�Ĳ��ҵ�ַ�汾��
//���ǿ������ظ�Ԫ�صĲ��ң�����������һ�����ֵĻ����ұߵ�һ�����ֵ� 
#include<stdio.h>
//����һ���������У�����ĳ�����ֻ����ظ�
//����
//   1  2   3   4  5  6  7  9  9  9  10  11��
//������Ҿ����ҵ�һ�γ��ֵ�λ�ú����һ�γ��ֵ�λ�ã��ֱ����first��last�� 
int* findFirst(int* low, int* high, int key) {//���ص���ָ�룬�������ϵ�ܺ� 
	int* mid = NULL;
	if (low > high) return NULL;//����±߽���ϱ߽绹���Ҿ��˳���
	//�������low<=high ����� 
	if (*low > key || *high < key) return NULL;//�������ֵ����С�Ļ�С���߱����Ļ�����˳�
	//������һ�������ҵ��� 
	if (*low == key) return low;
	if (low == high) return NULL;
	mid = low + (high - low) / 2;//ָ��ֻ�ܼ��� 
	if (*mid > key) {//��Ϊ�ж��������ͬ���������˵��mid�����Ҳ���Ǹ�key���ұ� 
		return findFirst(low + 1, mid - 1, key);
	} else if (*mid < key) {//˵��mid�������key����ߣ���mid���Լ�1������high��ȷ�����ܶ� 
		return findFirst(mid + 1, high, key);
	} else {//*mid����key�ˣ�˵��mid��һ��key��ĳ��λ�ã�����������ߣ�����mid���ܶ�������low���Լ�1 
		return findFirst(low + 1, mid, key);
	}
}
//��󴫳�����key������ָ�룬int *p=key��λ�ã������key���±���Եó�
//�±����int flag_left=p-��������֣���������������ϵ 
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
//��׼���ҷ���
//���ض��� 
int binary_search(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // ֱ�ӷ���
            return mid;
        }
    }
    // ֱ�ӷ���
    return -1;
}
//���߽���� 
int left_bound(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // �𷵻أ��������߽�
            right = mid - 1;
        }
    }
    // ���Ҫ��� left Խ������
    if (left >= strlen(nums) || nums[left] != target)
        return -1;
    return left;
}

//�Ҳ�߽���� 
int right_bound(int nums[], int target) {
    int left = 0, right = strlen(nums) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // �𷵻أ������Ҳ�߽�
            left = mid + 1;
        }
    }
    // ���Ҫ��� right Խ������
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

//���Ʋ��ң����ҵ�ǰ����û�������������棬ͨ����Ҫ������������ȥ�ж��Ƿ�����������
//���������������ʹ�ý��ƶ��֣� 
int similar_find(int nums[],int key,int len){//Ĭ������; 
	int left=0,right=len-1;
	while(left<right-1){//�������left=right-1���պü�ס�Ǹ��������� 
		int mid=left+(right-left)/2;
		if(nums[mid]>key)right=mid;
		else if(nums[mid]<key)left=mid;
	}
	return right;//���ﷵ�����ҿ�������������ǽ��Ƶ���±� 
} 
