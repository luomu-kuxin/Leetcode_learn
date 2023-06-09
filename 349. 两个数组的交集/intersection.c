// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
// 输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

#include<stdio.h>
#include<stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{   
    int numsCount[1000] = {0};
    int numlen = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *res = (int *)calloc(numlen , sizeof(int));
    int index = 0;

    for(int i = 0; i < nums1Size; i++){
        numsCount[nums1[i]]++;
    }

    for(int i = 0; i < nums2Size; i++){
        if(numsCount[nums2[i]] > 0){
            res[index] = nums2[i];
            index++;
            numsCount[nums2[i]] = 0;
        }
    }
    *returnSize = index;
    return res;
}

void printnums(int *nums, int size){
    for(int i = 0 ; i < size; i++){
        printf("[%d] ",nums[i]);
    }
}

int main(void)
{
    int nums1[5] = {1,2,3,4,5};
    int nums2[4] = {2,4,5,8};
    int numSize1 = sizeof(nums1) / sizeof(int);
    int numSize2 = sizeof(nums2) / sizeof(int);

    int size = 0;
    int *nums = (int *)malloc(sizeof(int));
    nums = intersection(nums1,numSize1,nums2,numSize2,&size);
    
    printnums(nums,size);

    return 0;
}
