#include<stdio.h>
#include<stdlib.h>



int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int L = 0;
    int R = numsSize - 1;
    int *ans = malloc(sizeof(int) * numsSize);
    for(int k  = numsSize - 1; k >= 0 ; k--){
        if((nums[L] * nums [L]) <= (nums[R] * nums[R])){
            ans[k] = nums[R] * nums[R];
            R--;
        }else{
            ans[k] = nums[L] * nums[L];
            L++;
        }
    }
    return ans;
}

void printnums(int* nums, int numsSize)
{
    for(int i = 0; i < numsSize; i++){
        printf("[%d] " , nums[i]);
    }
}
int main(void)
{

    int nums[5] = {-2, -1 , 0 , 2, 4};
    int numsSize = sizeof(nums) / sizeof(int);
    // printf("%d",numsSize);
    int *nums1 = malloc(sizeof(int) * 5);
    int returnSize;
    nums1 = sortedSquares(nums, numsSize, &returnSize);
    // printf("%d",returnSize);
    printnums(nums1,returnSize);

    return 0;
}
