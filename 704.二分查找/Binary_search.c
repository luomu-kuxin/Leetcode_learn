// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

#include<stdio.h>

const int nums[6] = {-1,0,3,5,9,12};
int numSize = sizeof(nums) / sizeof(int);

int binary_search(const int nums[], int target, int numSize)
{
    int i = 0;
    //二分查找
    //1 计算整个长度
    // 对半查找
    int right = 0 ,left = numSize - 1;
    int mid; 
    while(right <= left)
    {
        mid = (right + left) / 2;
        if(nums[mid] < target){
            right = mid + 1;
        }else if(nums[mid] > target){
            left =  mid - 1;
        }else{
            return mid;
        }

    }
    return -1;
}

int main(void){
    printf(" %d ",binary_search(nums,9,numSize));


    return 0;
}