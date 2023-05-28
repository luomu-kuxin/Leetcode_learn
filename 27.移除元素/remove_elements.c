// https://leetcode.cn/problems/remove-element/
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <stdio.h>

// burp
int removeElement_burp(int* nums, int numsSize, int val){
    for( int i = 0; i < numsSize; i++){
        if( nums[i] == val){
            for(int j = i + 1 ; j < numsSize ; j++){
                nums[j - 1] = nums[j];
            }
            i--;
            numsSize -= 1;
        }
    }
    return numsSize;
}

int removeElement(int *nums, int numsSize, int val)
{
    int slow = 0 , fast = 0;

    while(fast < numsSize){
        if(nums[fast] == val){
            fast++;
        }else{
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
        
    }
    return slow;
}

void print_num(int *nums, int numSize)
{
    for(int i = 0; i < numSize; i++){
        printf("[%d] -> " , nums[i]);
    }
}

int main(void)
{
    int num[7] = {2,4,6,7,4,9,1};
    int numSize = sizeof(num) / sizeof(int);
    print_num(num,numSize);
   // printf("%d" , numSize); 
   printf("\n");
   int newnumSize = removeElement(num,numSize,4);
    print_num(num,newnumSize);

    return 0;

}
