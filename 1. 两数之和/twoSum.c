// 给定一个整数数组 nums 和一个整数目标值 target，
// 请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

#include<stdio.h>
#include<stdlib.h>

int *twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 0;
    int *tmp = (int*)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                *returnSize = 2;
                tmp[0] = i;
                tmp[1] = j;
                return tmp;
            }
        }
    }
    return NULL;
}

void printnum(int* nums, int size)
{
    for(int i = 0 ; i < size ; i++){
        printf("[%d] ", nums[i]);
    }
}

int main(void)
{
    int  nums[4] = {1,2,3,6};
    int size = sizeof(nums) / sizeof(int);
    printnum(nums,size);
    printf("\n");
    int rtsize = 0;
    int *tmp = (int*)malloc(sizeof(int)*rtsize);
    tmp = twoSum(nums,size,9,&rtsize);
    printf("%d\n",rtsize);
    printnum(tmp,rtsize);

    return 0;
}
