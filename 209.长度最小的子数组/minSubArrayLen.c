// //给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
//并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include<stdio.h>

// 超出时间限制
// int minSubArrayLen1(int target, int* nums, int numsSize){
//     int slow = 0 ,fast = 0;
//     int n,t;
//     for(n = 0,t = 0; fast < numsSize; fast++){
//         if(t < target){
//             t += nums[fast];
//         }
//         if(t >= target){
//             if(n == 0){
//                 n = fast - slow + 1;
//                 slow++;
//                 fast = slow - 1;
//                 t = 0;
//             }else{
//                 if(n > (fast - slow + 1)){
//                     n = fast - slow + 1;
//                     slow++;
//                     fast = slow - 1;
//                     t = 0;
//                 }else{
//                     slow++;
//                     fast = slow - 1;
//                     t = 0;
//                 }
//             }
//         }
//     }
//     return n;
// }

// 滑动窗口
int minSubArrayLen(int target, int* nums, int numsSize){
    int sum = 0;
    int len = 0;
    int slow, fast;
    for(slow = 0, fast = 0;fast < numsSize; fast++){
        sum += nums[fast];
        while (sum >= target)
        {
            int l = fast - slow + 1;
            if(len == 0 ){
                len = l;
            }else{
                if(len >= l){
                    len = l;
                }
            }
            sum -= nums[slow];
            slow++;
        }
        
    }
    return len;
}

void printnums(int * nums, int numsSize)
{
    for(int i = 0; i < numsSize; i++){
        printf("[%d] -> ", nums[i]);
    }
}

int main(void)
{
    int nums[6] = {2,3,1,2,4,3};
    int numsSize = sizeof(nums) / sizeof(int);
    printnums(nums,numsSize);
    printf("\n");
    int new = minSubArrayLen(7,nums,numsSize);
    printf("%d", new);

    return 0;
}